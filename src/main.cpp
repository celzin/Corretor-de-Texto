#include "funcoes.hpp"


int main() {
    auto texto = lerArquivo("./dataset/input.txt");
    auto paragrafos = DivideParagrafos(texto);
    auto stopwords = leStopWords("./dataset/stopwords.txt");
    auto expressions = leExpressoes("./dataset/expressoes.txt");

    // vector<vector<pair<string,int>>> sentencasPorParagrafo;
    // for (const string &paragrafo : paragrafos)
    // {
    //     auto sentencas = dividirSentencas(paragrafo);
    //     //sentencasPorParagrafo.push_back(sentencas);
    // }

    analisarTexto(paragrafos, stopwords);



    return 0;
}
