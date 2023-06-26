#include "hash.hpp"
#include <algorithm>

string lowerCaseVersion(const string &word){
    string lowerVersion;
    for(char c : word) lowerVersion.push_back(tolower(c));
    return lowerVersion;
}

vector<string> readStopWords(const string &filename){
    ifstream file(filename);
    string word;
    vector<string> stopWords;
    while(getline(file, word)){
        stopWords.push_back(word);
    }
    return stopWords;
}

vector<string> readExpressions(const string &filename){
    ifstream file(filename);
    string word;
    vector<string> expressions;
    while(getline(file, word)){
        expressions.push_back(word);
    }
    return expressions;
}

int countWords(const string &sentence, const vector<string> &stopWords, bool includeStopWords){
    istringstream stream(sentence);
    string word;
    int count = 0;
    while(stream >> word){
        while(word.back() == '.' || word.back() == ',' || word.back() == '!' || word.back() == '?' || word.back() == ':' || word.back() == ';') word.pop_back();
        if(find(stopWords.begin(), stopWords.end(), lowerCaseVersion(word)) != stopWords.end()){
            if(includeStopWords){
                count++;
            }
        } else{
            count++;
        }
    }
    return count;
}

void processParagraph(string &paragraph, const vector<string> &stopWords, int &paragraphCount, int &paragraphStart, int &lineCount, unordered_map<string, WordInfo> &wordInfo){
    istringstream stream(paragraph);
    istringstream stream2(paragraph);
    string sentence;
    string word;
    ofstream output("./dataset/output.txt");
    int sentenceCount = 0;
    int wordCount = 0;
    while(getline(stream, sentence, '.')){
        int totalWords = sentence.empty() ? 0 : countWords(sentence, stopWords, true);
        int excludingStopWords = sentence.empty() ? 0 : countWords(sentence, stopWords, false);
        if(!sentence.empty() && totalWords){
            sentenceCount++;
            output << "Sentence " << sentenceCount << " has " << totalWords
                << " words including stop words, and " << excludingStopWords
                << " words excluding stop words.\n";
        }
        
    }

    while(stream2 >> word){
        while(word.back() == '.' || word.back() == ',' || word.back() == '!' || word.back() == '?' || word.back() == ':' || word.back() == ';' || word.back() == ')') word.pop_back();
        while(word.front() == '.' || word.front() == ',' || word.front() == '!' || word.front() == '?' || word.front() == ':' || word.front() == ';' || word.front() == '(') word.erase(0, 1);

        wordCount++;
        if(find(stopWords.begin(), stopWords.end(), lowerCaseVersion(word)) == stopWords.end()){
            wordInfo[lowerCaseVersion(word)].paragraphPositions[paragraphCount].push_back(wordCount);
        }
    }

    output << "Paragraph " << paragraphCount++ << " starting at line " << paragraphStart << " and ending at line " << lineCount - 1
        << " has " << sentenceCount << " sentences.\n\n";
    paragraph.clear();
    paragraphStart = lineCount + 1;

    output.close();
}

void updateWordInfo(const string &word, int line, unordered_map<string, WordInfo> &wordInfo){
    if(wordInfo.find(word) == wordInfo.end()){
        WordInfo newWordInfo;
        wordInfo[word] = newWordInfo;
    }
    wordInfo[word].freq++;
    if(wordInfo[word].lines.empty() || wordInfo[word].lines.back() != line){
        wordInfo[word].lines.push_back(line);
    }
}

unordered_map<string, WordInfo> analyzeText(const string &filename, const vector<string> &stopWords, unordered_map<string, WordInfo> &expressionsInfo){
    ifstream file(filename);
    string line;
    string paragraph;
    int paragraphCount = 1;
    int paragraphStart = 1;
    int lineCount = 0;

    vector<string> expressions;
    for(auto &expressionInfo : expressionsInfo){
        expressions.push_back(expressionInfo.first);
    }

    unordered_map<string, WordInfo> wordInfo;
    while(getline(file, line)){
        lineCount++;
        if(!line.empty()){
            paragraph += line + ' ';
            istringstream wordStream(line);
            string word;
            while(wordStream >> word){
                while(word.back() == '.' || word.back() == ',' || word.back() == '!' || word.back() == '?' || word.back() == ':' || word.back() == ';' || word.back() == ')') word.pop_back();
                while(word.front() == '.' || word.front() == ',' || word.front() == '!' || word.front() == '?' || word.front() == ':' || word.front() == ';' || word.front() == '(') word.erase(0, 1);

                string lowerVersion = lowerCaseVersion(word);
                if(find(stopWords.begin(), stopWords.end(), lowerVersion) == stopWords.end()){
                    updateWordInfo(lowerVersion, lineCount, wordInfo);
                }
            }
        } else if(!paragraph.empty()){
            processParagraph(paragraph, stopWords, paragraphCount, paragraphStart, lineCount, wordInfo);
        }

        for(const string &expression : expressions){
            if((int)line.find(expression) >= 0){
                expressionsInfo[expression].lines.push_back(lineCount);
                expressionsInfo[expression].freq += 1;
            }
        }

    }
    lineCount++;
    processParagraph(paragraph, stopWords, paragraphCount, paragraphStart, lineCount, wordInfo);

    return wordInfo;
}

void analyzeWords(unordered_map<string, WordInfo> &wordsInfo){
    ofstream output("./dataset/output.txt");
    vector<string> orderedWords;
    for(const pair<string, WordInfo> &wordNInfo : wordsInfo){
        orderedWords.push_back(wordNInfo.first);
    }
    sort(orderedWords.begin(), orderedWords.end());

    for(const string &word : orderedWords){
        WordInfo wordInfo = wordsInfo[word];

        output << "Word: " << word << ", Frequency: " << wordInfo.freq << ", Lines: ";
        for(int line : wordInfo.lines){
            output << line << ' ';
        }
        output << endl;
        if(wordInfo.freq <= 1 || wordInfo.paragraphPositions.size() == wordInfo.freq) continue;
        output << "Distances in same paragraph, per paragraph: " << endl;

        vector<int> orderedParagraphs;
        for(const pair<int, vector<int>> paragraphPosition : wordInfo.paragraphPositions){
            orderedParagraphs.push_back(paragraphPosition.first);
        }
        sort(orderedParagraphs.begin(), orderedParagraphs.end());

        for(int paragraph : orderedParagraphs){
            vector<int> distances;
            for(int i = 1; i < wordInfo.paragraphPositions[paragraph].size(); i++){
                distances.push_back(wordInfo.paragraphPositions[paragraph][i] - wordInfo.paragraphPositions[paragraph][i - 1]);
            }
            if(distances.size() >= 1){
                output << "Paragraph " << paragraph << ": ";

                for(int distance : distances){
                    output << distance << " ";
                }
                output << endl;
            }
        }
        output << endl;
    }

    output.close();
}
