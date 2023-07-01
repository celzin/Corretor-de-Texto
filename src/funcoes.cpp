#include "funcoes.hpp"

vector<pair<int, string>> lerArquivo(const string &nomeArquivo) {
    vector<pair<int, string>> linhas;
    ifstream arquivo(nomeArquivo);
    string data;
    int contlinha = 1;

    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            linhas.push_back(make_pair(contlinha++, linha));
            data += linha + "\n";
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir arquivo" << endl;
    }

    return linhas;
}

vector<vector<vector<pair<int, string>>>> DivideParagrafos(vector<pair<int, string>> &texto) {
    vector<pair<int, string>> paragrafo;
    vector<decltype(paragrafo)> paragrafos;

    for (auto &linha : texto) {
        if (!linha.second.empty()) {
            paragrafo.push_back(linha);
        } else {
            paragrafos.push_back(paragrafo);
            paragrafo.clear();
        }
    }

    if (!paragrafo.empty()) {
        paragrafos.push_back(paragrafo);
    }

    string c;
    vector<pair<int, string>> sentenca;
    vector<decltype(sentenca)> sentencas;
    vector<decltype(sentencas)> paragrafosMapeados;

    for (auto &p : paragrafos) {
        sentenca.clear();
        sentencas.clear();

        for (auto &[linha, content] : p) {
            istringstream iss(content);

            while (getline(iss, c, ' ')) {
                if (c.find_first_of(".?!:") == string::npos) {
                    sentenca.push_back(make_pair(linha, c));
                } else {
                    sentenca.push_back(make_pair(linha, c));
                    sentencas.push_back(sentenca);
                    sentenca.clear();
                }
            }
        }
        if (!sentencas.empty())
            paragrafosMapeados.push_back(sentencas);
    }
    return paragrafosMapeados;
}

unordered_set<string> leStopWords(const string &nomeArquivo) {
    unordered_set<string> stopWords;
    ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        string stopword;
        while (getline(arquivo, stopword)) {
            stopWords.insert(stopword);
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir stopwords.txt" << endl;
    }

    return stopWords;
}

unordered_set<string> leExpressoes(const string &nomeArquivo) {
    unordered_set<string> expressions;
    ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        string expressao;
        while (getline(arquivo, expressao)) {
            expressions.insert(expressao);
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir expressoes.txt" << endl;
    }

    return expressions;
}

void analisarTexto(vector<vector<vector<pair<int, string>>>> &paragrafosMapeados, unordered_set<string> &stopwords) {
    ofstream outputFile("dataset/output.txt");

    if (!outputFile.is_open()) {
        cout << "Erro ao abrir o arquivo output.txt";
        return;
    }

    ifstream expressoesFile("dataset/expressoes.txt");

    if (!expressoesFile.is_open()) {
        cout << "Erro ao abrir o arquivo expressoes.txt";
        outputFile.close();
        return;
    }

    unordered_map<string, pair<int, int>> expressoesMap; // Mapa para armazenar as expressões e suas ocorrências

    // Lê as expressões do arquivo expressoes.txt e as armazena no mapa expressoesMap
    string linhaExpressao;
    while (getline(expressoesFile, linhaExpressao)) {
        expressoesMap[linhaExpressao] = make_pair(0, 0); // Inicializa a contagem de ocorrências das expressões
        // cout << expressoesFile << endl;
    }

    expressoesFile.close();

    for (int paragrafoAtual = 0; paragrafoAtual < paragrafosMapeados.size(); paragrafoAtual++) {
        int sentencaIndex = 0;
        int paragrafoLinha = paragrafosMapeados[paragrafoAtual][0][0].first; // Linha do primeiro parágrafo

        for (auto &my_sentence : paragrafosMapeados[paragrafoAtual]) {
            sentencaIndex++;
            int sentencaPalavrasComStopwords = 0;
            int sentencaPalavrasSemStopwords = 0;

            for (auto &palavra : my_sentence) {
                sentencaPalavrasComStopwords++;
                tolowerStr(palavra.second);
                if (stopwords.find(palavra.second) == stopwords.end()) {
                    sentencaPalavrasSemStopwords++;
                }
            }

            // Atualiza a contagem de sentenças do parágrafo
            if (sentencaIndex == 1) {
                paragrafoLinha = my_sentence[0].first; // Atualiza a linha do parágrafo
            }

            vector<WordInfo> wordTable;
            int palavraIndex = 1;
            int position = 0;
            unordered_map<string, vector<int>> wordPositionMap;

            for (auto &palavra : my_sentence) {
                position++;
                if (stopwords.find(palavra.second) == stopwords.end()) {
                    bool palavraExiste = false;
                    size_t tabelaIndex = 0;

                    // Remove o ponto final, se estiver presente no final da palavra
                    string palavraAtual = palavra.second;
                    if (!palavraAtual.empty() && palavraAtual.back() == '.') {
                        palavraAtual.pop_back();
                    }

                    if (!palavraAtual.empty() && palavraAtual.back() == ',') {
                        palavraAtual.pop_back();
                    }

                    for (size_t i = 0; i < wordTable.size(); i++) {
                        if (wordTable[i].palavra == palavraAtual) {
                            palavraExiste = true;
                            tabelaIndex = i;
                            break;
                        }
                    }

                    if (palavraExiste) {
                        wordTable[tabelaIndex].ocorrencias++;
                        if (wordPositionMap.find(palavraAtual) == wordPositionMap.end()) {
                            wordPositionMap[palavraAtual].push_back(position);
                        } else {
                            // Atualizar a lógica de contagem das posições
                            if (wordPositionMap[palavraAtual].back() != position) {
                                wordPositionMap[palavraAtual].push_back(position);
                            }
                        }
                    } else {
                        int linha = palavra.first;
                        WordInfo novaPalavra(palavraAtual, 1, palavraIndex, std::to_string(linha), "");

                        wordTable.push_back(novaPalavra);
                        wordPositionMap[palavraAtual].push_back(position);
                        palavraIndex++; // Incrementar apenas quando uma nova palavra é adicionada
                    }
                }
            }

            sort(wordTable.begin(), wordTable.end(), [](const WordInfo &a, const WordInfo &b) {
                return a.palavra < b.palavra;
            });

            // Imprimir a tabela de palavras da sentença no arquivo
            outputFile << left << setw(30) << "WORD" << setw(15) << "PARAGRAPH" << setw(15) << "SENTENCE" << setw(15) << "LINE" << setw(15) << "APPEARANCES" << setw(15) << "POSITIONS" << "\n";
            outputFile << "---------------------------------------------------------------------------------------------------------------------------------------\n";

            for (auto &infoPalavra : wordTable) {
                outputFile << setw(30) << infoPalavra.palavra;
                outputFile << setw(15) << paragrafoAtual + 1;
                outputFile << setw(15) << sentencaIndex;
                outputFile << setw(15) << infoPalavra.linha; // Corrigido para exibir a linha corretamente
                outputFile << setw(15) << infoPalavra.ocorrencias;

                // Construir a string das posições separadas por vírgula
                string posicoesPalavra;
                for (int posicao : wordPositionMap[infoPalavra.palavra]) {
                    posicoesPalavra += to_string(posicao) + ",";
                }

                outputFile << setw(15) << posicoesPalavra << "\n";
            }

            outputFile << "---------------------------------------------------------------------------------------------------------------------------------------\n";
            outputFile << "=> Number of words with stop words: " << sentencaPalavrasComStopwords << setw(81) << "=> Number of words without stop words: " << sentencaPalavrasSemStopwords << "\n";
            outputFile << "=======================================================================================================================================\n\n";

            // Analisar as expressões
            if (sentencaIndex == paragrafosMapeados[paragrafoAtual].size()) {
                outputFile << "EXPRESSION" << setw(70) << "" << "LINE" << setw(20) << "" << "APPEARANCES" << "\n";
                outputFile << "---------------------------------------------------------------------------------------------------------------------------------------\n";

                for (auto &expressao : expressoesMap) {
                    expressao.second.first = 0; // Redefine a linha da expressão para 0
                    expressao.second.second = 0; // Redefine as ocorrências da expressão para 0

                    for (auto &sentenca : paragrafosMapeados[paragrafoAtual]) {
                        string sentencaTexto;
                        for (auto &palavra : sentenca) {
                            sentencaTexto += palavra.second + " ";
                        }

                        size_t posicao = 0;
                        while ((posicao = sentencaTexto.find(expressao.first, posicao)) != string::npos) {
                            expressao.second.second++; // Incrementa as ocorrências da expressão
                            if (expressao.second.first == 0) {
                                expressao.second.first = sentenca[0].first; // Atualiza a linha da primeira ocorrência da expressão
                            }
                            posicao += expressao.first.length();
                        }
                    }

                    if (expressao.second.second > 0) {
                        outputFile << setw(100) << expressao.first;
                        outputFile << setw(20) << expressao.second.first;
                        outputFile << setw(20) << expressao.second.second << "\n";
                    }
                }

                outputFile << "---------------------------------------------------------------------------------------------------------------------------------------\n";
                outputFile << "=======================================================================================================================================\n";
                outputFile << "=> Beginning paragraph in line: " << paragrafoLinha << "  Number of sentences: " << sentencaIndex << "\n";
                outputFile << "=======================================================================================================================================\n\n";
            }
        }
    }

    outputFile.close();
    cout << "A análise do texto foi concluída. Verifique o arquivo output.txt para ver os resultados." << endl;
}

void analisarExpressoesTexto(const vector<vector<vector<pair<int, string>>>> &paragrafosMapeados, const unordered_set<string> &stopwords) {
    ofstream outputFile("dataset/output.txt", ios::app);

    if (!outputFile.is_open()) {
        cout << "Erro ao abrir o arquivo output.txt";
        return;
    }

    ifstream expressoesFile("dataset/expressoes.txt");

    if (!expressoesFile.is_open()) {
        cout << "Erro ao abrir o arquivo expressoes.txt";
        outputFile.close();
        return;
    }

    unordered_map<string, pair<int, int>> expressoesMap;

    // Lê as expressões do arquivo expressoes.txt e as armazena no mapa expressoesMap
    string linhaExpressao;
    while (getline(expressoesFile, linhaExpressao)) {
        expressoesMap[linhaExpressao] = make_pair(0, 0); // Inicializa a contagem de ocorrências das expressões
    }

    expressoesFile.close();

    for (const auto &paragrafo : paragrafosMapeados) {
        for (const auto &sentenca : paragrafo) {
            string sentencaTexto;
            for (const auto &palavra : sentenca) {
                sentencaTexto += palavra.second + " ";
            }

            for (const auto &expressao : expressoesMap) {
                size_t posicao = 0;
                while ((posicao = sentencaTexto.find(expressao.first, posicao)) != string::npos) {
                    expressoesMap[expressao.first].second++; // Incrementa as ocorrências da expressão
                    if (expressoesMap[expressao.first].first == 0) {
                        expressoesMap[expressao.first].first = sentenca[0].first; // Atualiza a linha da primeira ocorrência da expressão
                    }
                    posicao += expressao.first.length();
                }
            }
        }
    }

    // Ordenar as expressões em ordem alfabética
    vector<string> expressoesOrdenadas;
    for (const auto &expressao : expressoesMap) {
        expressoesOrdenadas.push_back(expressao.first);
    }
    sort(expressoesOrdenadas.begin(), expressoesOrdenadas.end());

    // Imprime as expressões encontradas no arquivo de saída
    outputFile << "---------------------------------------------------------------------------------------------------------------------------------------\n";
    outputFile << "EXPRESSION" << setw(70) << "" << "LINE" << setw(20) << "" << "APPEARANCES" << "\n";
    outputFile << "---------------------------------------------------------------------------------------------------------------------------------------\n";

    for (const auto &expressao : expressoesOrdenadas) {
        const auto &expressaoInfo = expressoesMap[expressao];
        if (expressaoInfo.second > 0) {
            outputFile << setw(0) << expressao;
            outputFile << setw(70) << expressaoInfo.first;
            outputFile << setw(20) << expressaoInfo.second << "\n";
        }
    }

    outputFile << "---------------------------------------------------------------------------------------------------------------------------------------\n";
    outputFile << "======================================================================================================================================\n";
    outputFile << "=>                                                    ### END PROCESS ###                                                           <=\n";
    outputFile << "======================================================================================================================================\n";

    outputFile.close();

    cout << "A análise das expressões do texto foi concluída. Verifique o arquivo output.txt para ver os resultados." << endl;
}

