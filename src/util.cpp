#include "./include/util.hpp"

string Util::lowerCaseVersion(const string &word) {
    string lowerVersion;
    for (char c : word) lowerVersion.push_back(tolower(c));
    return lowerVersion;
}

// void analisarExpressoesTexto(const vector<vector<vector<pair<int, string>>>> &paragrafosMapeados, const unordered_set<string> &stopwords) {
//     ofstream outputFile("dataset/output.txt", ios::app);

//     if (!outputFile.is_open()) {
//         cout << "Erro ao abrir o arquivo output.txt";
//         return;
//     }

//     ifstream expressoesFile("dataset/expressoes.txt");

//     if (!expressoesFile.is_open()) {
//         cout << "Erro ao abrir o arquivo expressoes.txt";
//         outputFile.close();
//         return;
//     }

//     unordered_map<string, pair<int, int>> expressoesMap;

//     // Lê as expressões do arquivo expressoes.txt e as armazena no mapa expressoesMap
//     string linhaExpressao;
//     while (getline(expressoesFile, linhaExpressao)) {
//         expressoesMap[linhaExpressao] = make_pair(0, 0); // Inicializa a contagem de ocorrências das expressões
//     }

//     expressoesFile.close();

//     for (const auto &paragrafo : paragrafosMapeados) {
//         for (const auto &sentenca : paragrafo) {
//             string sentencaTexto;
//             for (const auto &palavra : sentenca) {
//                 sentencaTexto += palavra.second + " ";
//             }

//             for (const auto &expressao : expressoesMap) {
//                 size_t posicao = 0;
//                 while ((posicao = sentencaTexto.find(expressao.first, posicao)) != string::npos) {
//                     expressoesMap[expressao.first].second++; // Incrementa as ocorrências da expressão
//                     if (expressoesMap[expressao.first].first == 0) {
//                         expressoesMap[expressao.first].first = sentenca[0].first; // Atualiza a linha da primeira ocorrência da expressão
//                     }
//                     posicao += expressao.first.length();
//                 }
//             }
//         }
//     }

//     // Ordenar as expressões em ordem alfabética
//     vector<string> expressoesOrdenadas;
//     for (const auto &expressao : expressoesMap) {
//         expressoesOrdenadas.push_back(expressao.first);
//     }
//     sort(expressoesOrdenadas.begin(), expressoesOrdenadas.end());

//     // Imprime as expressões encontradas no arquivo de saída
//     outputFile << "---------------------------------------------------------------------------------------------------------------------------------------\n";
//     outputFile << "EXPRESSION" << setw(70) << "" << "LINE" << setw(20) << "" << "APPEARANCES" << "\n";
//     outputFile << "---------------------------------------------------------------------------------------------------------------------------------------\n";

//     for (const auto &expressao : expressoesOrdenadas) {
//         const auto &expressaoInfo = expressoesMap[expressao];
//         if (expressaoInfo.second > 0) {
//             outputFile << setw(0) << expressao;
//             //outputFile << setw(70) << expressaoInfo.first;
//             //outputFile << setw(20) << expressaoInfo.second << "\n";

//             // Construir a string das linhas separadas por vírgula
//             string linhasExpressao;
//             bool firstLine = true;
//             for (const auto &paragrafo : paragrafosMapeados) {
//                 for (const auto &sentenca : paragrafo) {
//                     string sentencaTexto;
//                     for (const auto &palavra : sentenca) {
//                         sentencaTexto += palavra.second + " ";
//                     }

//                     size_t posicao = 0;
//                     while ((posicao = sentencaTexto.find(expressao, posicao)) != string::npos) {
//                         int linha = sentenca[0].first;
//                         if (!firstLine) {
//                             linhasExpressao += ", ";
//                         }
//                         linhasExpressao += to_string(linha);
//                         posicao += expressao.length();
//                         firstLine = false;
//                     }
//                 }
//             }

//             outputFile << setw(70) << linhasExpressao;
//             outputFile << setw(20) << expressaoInfo.second << "\n";
//         }
//     }

//     outputFile << "---------------------------------------------------------------------------------------------------------------------------------------\n";
//     outputFile << "======================================================================================================================================\n";
//     outputFile << "=>                                                    ### END PROCESS ###                                                           <=\n";
//     outputFile << "======================================================================================================================================\n";

//     outputFile.close();

//     cout << "A análise das expressões do texto foi concluída. Verifique o arquivo output.txt para ver os resultados." << endl;
// }