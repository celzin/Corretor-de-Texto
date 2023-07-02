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

#define loopStr(str) for (long unsigned d_inc = 0; d_inc < str.length(); d_inc++)
#define tolowerStr(str) loopStr(str) str[d_inc] = tolower(str[d_inc])

using namespace std;

class WordInfo {
public:
    string palavra;
    int ocorrencias;
    int palavraIndex;
    string linha;
    string posicao;

    WordInfo(const string &p, int o, int pi, const string &l, const string &pos)
        : palavra(p), ocorrencias(o), palavraIndex(pi), linha(l), posicao(pos) {}
};

struct WordInfo2 {
    std::string palavra;
    std::vector<int> paragrafos;
    std::vector<int> sentencas;
    std::vector<int> linhas;
    int ocorrencias;
    std::vector<int> posicoes;

    WordInfo2(const std::string &p, int pg, int st, int ln, int oc, int ps)
        : palavra(p), ocorrencias(oc) {
        paragrafos.push_back(pg);
        sentencas.push_back(st);
        linhas.push_back(ln);
        posicoes.push_back(ps);
    }
};

void analisarTexto(vector<vector<vector<pair<int, string>>>> &paragrafosMapeados, unordered_set<string> &stopwords);
void gerarRelatorio(const std::vector<std::vector<std::vector<std::pair<int, std::string>>>> &paragrafosMapeados,
    const std::unordered_set<std::string> &stopwords,
    const std::unordered_set<std::string> &expressoes);
void contarPalavras(const std::vector<std::vector<std::vector<std::pair<int, std::string>>>> &paragrafosMapeados, const std::unordered_set<std::string> &stopwords);
void contarExpressoes(const std::vector<std::vector<std::vector<std::pair<int, std::string>>>> &paragrafosMapeados, const std::unordered_set<std::string> &expressions);
void analisarTexto(vector<vector<pair<string, int>>> &sentencasPorParagrafo, unordered_set<string> &stopwords);
vector<pair<int, string>> lerArquivo(const string &nomeArquivo);
vector<vector<vector<pair<int, string>>>> DivideParagrafos(vector<pair<int, string>> &texto);
unordered_set<string> leStopWords(const string &nomeArquivo);
unordered_set<string> leExpressoes(const string &nomeArquivo);