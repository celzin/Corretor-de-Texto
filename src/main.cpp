#include "funcoes.hpp"
#include <time.h>

int main() {
    clock_t inicio, fim, inicio_1, fim_1, inicio_2, fim_2, inicio_3, fim_3;
    double tempo_decorrido, tempo_decorrido_1, tempo_decorrido_2, tempo_decorrido_3;

    inicio = clock();

    auto texto = lerArquivo("./dataset/input.txt");
    auto paragrafos = DivideParagrafos(texto);
    auto stopwords = leStopWords("./dataset/stopwords.txt");
    auto expressions = leExpressoes("./dataset/expressoes.txt");

    inicio_1 = clock();
    analisarTexto(paragrafos, stopwords);
    fim_1 = clock();
    tempo_decorrido_1 = (double)(fim_1 - inicio_1) * 1000 / CLOCKS_PER_SEC;
    cout << setw(4) << "" << "Tempo da Analise 1: " << tempo_decorrido_1 << " milissegundos" << endl << endl;

    inicio_2 = clock();
    gerarRelatorio(paragrafos, stopwords, expressions);
    contarPalavras(paragrafos, stopwords);
    fim_2 = clock();
    tempo_decorrido_2 = (double)(fim_2 - inicio_2) * 1000 / CLOCKS_PER_SEC;
    cout << setw(4) << "" << "Tempo da Analise 2: " << tempo_decorrido_2 << " milissegundos" << endl << endl;

    inicio_3 = clock();
    contarExpressoes(paragrafos, expressions);
    fim_3 = clock();
    tempo_decorrido_3 = (double)(fim_3 - inicio_3) * 1000 / CLOCKS_PER_SEC;
    cout << setw(4) << "" << "Tempo da Analise 3: " << tempo_decorrido_3 << " milissegundos" << endl << endl;

    fim = clock();
    tempo_decorrido = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    cout << setw(4) << "" << "Tempo Total: " << tempo_decorrido << " milissegundos" << endl;

    return 0;
}