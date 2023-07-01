#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <regex>
#include <iomanip>
#include <algorithm>

#include <locale>
#include <codecvt>

using namespace std;

struct WordInfo {
    string palavra;
    int ocorrencias;
    int posicao;
    vector<int> posicoes;
    vector<int> linhas;

    WordInfo(const string &p, int o, int pos, int linha, int posicao) : palavra(p), ocorrencias(o), posicao(posicao) {
        posicoes.push_back(pos);
        linhas.push_back(linha);
    }
};

void analisarTexto(vector<vector<vector<pair<int, string>>>> &paragrafosMapeados, unordered_set<string> &stopwords);

vector<pair<int, string>> lerArquivo(const string &nomeArquivo); // recebe o nome do arquivo como parâmetro e retorna uma string com o conteúdo lido.
// Ela percorre o arquivo linha por linha, adicionando cada linha à string conteudo.


vector<vector<vector<pair<int, string>>>> DivideParagrafos(vector<pair<int, string>> &texto); // recebe o texto completo como parâmetro e retorna um vetor de strings, 
//  onde cada elemento é um parágrafo individual.

unordered_set<string> leStopWords(const string &nomeArquivo);

unordered_set<string> leExpressoes(const string &nomeArquivo);

vector<pair<string, int>> dividirSentencas(const string &paragrafo);

void analisarTexto(vector<vector<pair<string, int>>> &sentencasPorParagrafo, unordered_set<string> &stopwords);

// pair<int, int> contaPalavras(const vector<vector<string>>& sentencasPorParagrafo, const unordered_set<string>& stopwords);

