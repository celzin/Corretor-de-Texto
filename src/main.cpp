#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include "hash.hpp"
#include <iterator>


using namespace std;

int main(){

    ofstream output("./dataset/output.txt");

    unordered_map<string, WordInfo> expressionsInfo;
    vector<string> stopWords = readStopWords("./dataset/stopwords.txt");
    vector<string> expressions = readExpressions("./dataset/expressoes.txt");
    for(const string &expression : expressions){
        expressionsInfo[expression].freq = 0;
    }
    string filename = "dataset/input.txt";
    cout << "1) Analyzing text paragraphs:" << endl << endl;
    clock_t startTime = clock(); // Start measuring time
    unordered_map<string, WordInfo> wordInfo = analyzeText(filename, stopWords, expressionsInfo);
    clock_t endTime = clock(); // End measuring time
    cout << "Analysis completed in " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds.\n";
    cout << "2) Analysing non stop words:" << endl << endl;
    startTime = clock(); // Start measuring time
    analyzeWords(wordInfo);
    endTime = clock(); // End measuring time
    cout << "Analysis completed in " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds.\n";
    output << "3) Occurrence of expressions:" << endl << endl;
    for(auto &expressionInfo : expressionsInfo){
        string expression = expressionInfo.first;
        WordInfo info = expressionInfo.second;
        if(info.freq > 0){
            output << "Expression: " << expression << ". Lines: ";
            for(int line : info.lines){
                output << line << " ";
            }
            output << endl;
        }
    }

    output.close();

    return 0;
}
