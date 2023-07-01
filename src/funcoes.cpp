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
    }

    /**
        * 1. Para cada parágrafo, dividir em sentenças - OK
        * 2. Para cada sentença, dividir em palavras com o id de linha - OK
        * 3. Para cada palavra, verificar se é stopword - AINDA NAO
        * 4. Para cada palavra, verificar se é expressão - AINDA NAO
        * 5. Para cada palavra, verificar se já existe na tabela - AINDA NAO
        * 6. Se já existe, incrementar o número de ocorrências e adicionar a posição e linha - AINDA NAO
        * 7. Se não existe, adicionar na tabela com o número de ocorrências 1 e adicionar a posição e linha - AINDA NAO
        * 8. Imprimir a tabela de palavras da sentença no arquivo - AINDA NAO
     */

    vector<WordInfo> wordTable;

    int palavraIndex = 1;
    int paragrafoAtual = 0;

    for (auto &p : paragrafosMapeados) {
        paragrafoAtual++;
        int sentencaIndex = 0;

        for (auto &my_sentense : p) {
            wordTable.clear();
            sentencaIndex++;
            int position = 0;

            for (auto &palavra : my_sentense) {
                position++;
                if (stopwords.find(palavra.second) == stopwords.end()) {
                    bool palavraExiste = false;
                    size_t tabelaIndex = 0;
                    for (size_t i = 0; i < wordTable.size(); i++) {
                        if (wordTable[i].palavra == palavra.second) {
                            palavraExiste = true;
                            tabelaIndex = i;
                            break;
                        }
                    }

                    if (palavraExiste) {
                        wordTable[tabelaIndex].ocorrencias++;
                        // wordTable[tabelaIndex].posicao = position;
                        // wordTable[tabelaIndex].posicoes.push_back(position);
                        wordTable[tabelaIndex].linhas.push_back(palavra.first);
                    } else {
                        WordInfo novaPalavra(palavra.second, 1, palavraIndex, palavra.first, position);
                        wordTable.push_back(novaPalavra);
                    }
                }
                palavraIndex++;
            }

            // Imprimir a tabela de palavras da sentença no arquivo
            outputFile << left << setw(30) << "WORD" << setw(15) << "PARAGRAPH" << setw(15) << "SENTENCE" << setw(15) << "APPEARANCES" << setw(15) << "POSITIONS" << setw(15) << "LINES" << "\n";
            outputFile << "--------------------------------------------------------------------------------------------------------------------------------------\n";

            for (auto &infoPalavra : wordTable) {
                std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
                std::wstring texto = converter.from_bytes(infoPalavra.palavra);

                outputFile
                    << infoPalavra.palavra << setw(30 - texto.length())
                    << "" << paragrafoAtual << setw(14) << "" << sentencaIndex
                    << setw(14) << "" << infoPalavra.ocorrencias << setw(14)
                    << "" << infoPalavra.posicao << " ";


                // acredito que vetor nao tenha sido preenchido
                // stringstream posicoesStream;
                // for (int posicao : infoPalavra.posicoes) {
                //     // outputFile << "teste" << endl;
                //     // outputFile << 666 << " ";
                //     outputFile << posicao << " ";
                // }
                // string posicoesString = posicoesStream.str();

                stringstream linhasStream;
                for (size_t i = 0; i < infoPalavra.linhas.size(); i++) {
                    linhasStream << infoPalavra.linhas[i];
                    if (i != infoPalavra.linhas.size() - 1) {
                        linhasStream << ", ";
                    }
                }
                string linhasString = linhasStream.str();

                outputFile << setw(15) << "";
                for (auto &linha : infoPalavra.linhas)
                    outputFile << linha << " ";
                outputFile << endl;
            }

            outputFile << "======================================================================================================================================\n\n";
        }
    }
    outputFile.close();

    cout << "Análise concluída. Os resultados foram gravados no arquivo output.txt.\n";
}