#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class WordInfo{
public:
    int freq = 0;
    vector<int> lines;
    unordered_map<int, vector<int>> paragraphPositions;
    WordInfo(){};
};

string lowerCaseVersion(const string &word);

vector<string> readStopWords(const string &filename);

vector<string> readExpressions(const string &filename);

int countWords(const string &sentence, const vector<string> &stopWords, bool includeStopWords);

void processParagraph(string &paragraph, const vector<string> &stopWords, int &paragraphCount, int &paragraphStart, int &lineCount, unordered_map<string, WordInfo> &wordInfo);

void updateWordInfo(const string &word, int line, unordered_map<string, WordInfo> &wordInfo);

unordered_map<string, WordInfo> analyzeText(const string &filename, const vector<string> &stopWords, unordered_map<string, WordInfo> &expressionsInfo);

void analyzeWords(unordered_map<string, WordInfo> &wordsInfo);

#endif
