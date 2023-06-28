#ifndef HASH_HPP
#define HASH_HPP

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <codecvt>
#include <chrono>
#include <thread>
#include <locale>

#include "util.hpp"

#define interval(x) x.begin(), x.end()

#define dbg(x) cout << #x << " = " << x << endl;

class WordInfo {
public:
    int freq = 0;
    vector<int> lines;
    unordered_map<int, vector<int>> paragraphPositions;
    WordInfo() {};
};

class Operacao {
private:
    Util u;

    string pathSw_; // path para o arquivo de stop words
    string pathExp_; // path para o arquivo de expressões
    string pathInput_; // path para o arquivo de input
    string pathOutput_; // path para o arquivo de output

    vector<string> stopWords_;
    vector<string> expressions_;

    unordered_map<string, WordInfo> wordInfo_;
    unordered_map<string, WordInfo> expressionsInfo_;
public:
    Operacao():
        pathSw_("./dataset/stopwords.txt"),
        pathExp_("./dataset/expressoes.txt"),
        pathOutput_("./dataset/output.txt"),
        pathInput_("dataset/input.txt") {}
    ~Operacao() {}

    void readStopWords();
    void readExpressions();
    void setExpressionInfo();

    decltype(stopWords_) getStopWords() const { return stopWords_; }
    decltype(wordInfo_) getWordInfo() const { return wordInfo_; }
    decltype(expressionsInfo_) getExpressionsInfo() const { return expressionsInfo_; }

    int countWords(const string &sentence, bool includeStopWords);
    void processParagraph(string &paragraph, int &paragraphCount, int &paragraphStart, int &lineCount);
    void updateWordInfo(const string &word, int line);

    void analyzeText();
    void analyzeWords();
};

#endif
