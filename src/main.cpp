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
    // 1
    analisarTexto(paragrafos, stopwords);
    fim_1 = clock();

    inicio_2 = clock();
    // 2
    gerarRelatorio(paragrafos, stopwords, expressions);
    contarPalavras(paragrafos, stopwords);
    fim_2 = clock();

    inicio_3 = clock();
    // 3
    contarExpressoes(paragrafos, expressions);
    fim_3 = clock();

    fim = clock();

    tempo_decorrido = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    tempo_decorrido_1 = (double)(fim_1 - inicio_1) * 1000 / CLOCKS_PER_SEC;
    tempo_decorrido_2 = (double)(fim_2 - inicio_2) * 1000 / CLOCKS_PER_SEC;
    tempo_decorrido_3 = (double)(fim_3 - inicio_3) * 1000 / CLOCKS_PER_SEC;

    cout << "\n======================================" << endl;
    cout << "\nTempo decorrido [total]: " << tempo_decorrido << " milissegundos\n" << endl;
    cout << "\nTempo decorrido [analisar texto]: " << tempo_decorrido_1 << " milissegundos\n" << endl;
    cout << "\nTempo decorrido [gerar relatorio + contar expressões]: " << tempo_decorrido_2 << " milissegundos\n" << endl;
    cout << "\nTempo decorrido [contar expressões]: " << tempo_decorrido_3 << " milissegundos\n" << endl;
    cout << "\n======================================\n" << endl;

    return 0;
}