#include "./include/hash.hpp"

void Operacao::readStopWords() {
    ifstream file(pathSw_);
    string word;
    while (getline(file, word)) {
        stopWords_.push_back(word);
    }
}

void Operacao::readExpressions() {
    ifstream file(pathExp_);
    string word;
    while (getline(file, word)) {
        expressions_.push_back(word);
    }
}

void Operacao::setExpressionInfo() {
    for (const string &expression : expressions_)
        expressionsInfo_[expression].freq = 0;
}

int Operacao::countWords(const string &sentence, bool includeStopWords) {
    istringstream stream(sentence);
    string word;
    int count = 0;
    while (stream >> word) {
        while (word.back() == '.' || word.back() == ',' || word.back() == '!' || word.back() == '?' || word.back() == ':' || word.back() == ';') word.pop_back();
        if (find(interval(stopWords_), u.lowerCaseVersion(word)) != stopWords_.end()) {
            if (includeStopWords) {
                count++;
            }
        } else {
            count++;
        }
    }
    return count;
}

void Operacao::processParagraph(string &paragraph, int &paragraphCount, int &paragraphStart, int &lineCount) {
    istringstream stream(paragraph);
    istringstream stream2(paragraph);

    string sentence;
    string word;
    ofstream output(pathOutput_, std::ios::app);

    int sentenceCount = 0;
    int wordCount = 0;
    while (getline(stream, sentence, '.')) {
        int totalWords = sentence.empty() ? 0 : countWords(sentence, true);
        int excludingStopWords = sentence.empty() ? 0 : countWords(sentence, false);
        if (!sentence.empty() && totalWords) {
            sentenceCount++;
            output << "Sentence " << sentenceCount << " has " << totalWords
                << " words including stop words, and " << excludingStopWords
                << " words excluding stop words.\n";
        }

    }

    while (stream2 >> word) {
        while (word.back() == '.' || word.back() == ',' || word.back() == '!' || word.back() == '?' || word.back() == ':' || word.back() == ';' || word.back() == ')') word.pop_back();
        while (word.front() == '.' || word.front() == ',' || word.front() == '!' || word.front() == '?' || word.front() == ':' || word.front() == ';' || word.front() == '(') word.erase(0, 1);

        wordCount++;
        if (find(interval(stopWords_), u.lowerCaseVersion(word)) == stopWords_.end()) {
            wordInfo_[u.lowerCaseVersion(word)].paragraphPositions[paragraphCount].push_back(wordCount);
        }
    }

    output << "Paragraph " << paragraphCount++ << " starting at line " << paragraphStart << " and ending at line " << lineCount - 1
        << " has " << sentenceCount << " sentences.\n\n";
    paragraph.clear();
    paragraphStart = lineCount + 1;

    output.close();
}

void Operacao::updateWordInfo(const string &word, int line) {
    if (wordInfo_.find(word) == wordInfo_.end()) {
        WordInfo newWordInfo;
        wordInfo_[word] = newWordInfo;
    }
    wordInfo_[word].freq++;
    if (wordInfo_[word].lines.empty() || wordInfo_[word].lines.back() != line) {
        wordInfo_[word].lines.push_back(line);
    }
}

void Operacao::analyzeText() {
    ifstream file(pathInput_);
    string line;
    string paragraph;
    int paragraphCount = 1;
    int paragraphStart = 1;
    int lineCount = 0;

    vector<string> expressions;
    for (auto &expressionInfo : expressionsInfo_) {
        expressions.push_back(expressionInfo.first);
    }

    // unordered_map<string, WordInfo> wordInfo;
    while (getline(file, line)) {
        lineCount++;
        if (!line.empty()) {
            paragraph += line + ' ';
            istringstream wordStream(line);
            string word;
            while (wordStream >> word) {
                while (word.back() == '.' || word.back() == ',' || word.back() == '!' || word.back() == '?' || word.back() == ':' || word.back() == ';' || word.back() == ')') word.pop_back();
                while (word.front() == '.' || word.front() == ',' || word.front() == '!' || word.front() == '?' || word.front() == ':' || word.front() == ';' || word.front() == '(') word.erase(0, 1);

                string lowerVersion = u.lowerCaseVersion(word);
                if (find(interval(stopWords_), lowerVersion) == stopWords_.end()) {
                    updateWordInfo(lowerVersion, lineCount);
                }
            }
        } else if (!paragraph.empty()) {
            processParagraph(paragraph, paragraphCount, paragraphStart, lineCount);
        }

        for (const string &expression : expressions) {
            if ((int)line.find(expression) >= 0) {
                expressionsInfo_[expression].lines.push_back(lineCount);
                expressionsInfo_[expression].freq += 1;
            }
        }

    }
    lineCount++;
    processParagraph(paragraph, paragraphCount, paragraphStart, lineCount);
}

void Operacao::analyzeWords() {
    ofstream output(pathOutput_, std::ios::app);
    vector<string> orderedWords;
    for (const pair<string, WordInfo> &wordNInfo : wordInfo_) {
        orderedWords.push_back(wordNInfo.first);
    }
    sort(orderedWords.begin(), orderedWords.end());

    output << "_______________________________________________________________________________________________________________________________________" << endl;
    output << "WORD                 APPEARANCES         LINE" << endl;
    output << "---------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
    // output << "_______________________________________________________________________________________________________________________________________" << endl;
    // output << "WORD                 PARAGRAPH 		    SENTENCE 		      LINE 		   APPEARANCES 		     POSITIONS" << endl;
    // output << "---------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    bool first = true;

    for (const string &word : orderedWords) {
        WordInfo wordInfo = wordInfo_[word];

        // output << "Word: " << word << ", Frequency: " << wordInfo.freq << ", Lines: ";
        output << word;
        std::wstring col1 = converter.from_bytes(word);
        auto str_freq = to_string(wordInfo.freq).append(" ");
        auto tam_atual = col1.length() + str_freq.length();

        if (first) {
            first = false;
            str_freq.assign("2965123136");
        }

        output << setw(21 - col1.length()) << "" << str_freq
            << setw(20 - str_freq.size()) << "";

        for (int line : wordInfo.lines) {
            output << line << " ";
        }
        output << endl;
        if (wordInfo.freq <= 1 || wordInfo.paragraphPositions.size() == wordInfo.freq) continue;

        output << "_______________________________________________________________________________________________________________________________________" << endl;

        output << "Distances in same paragraph, per paragraph: " << endl;

        vector<int> orderedParagraphs;
        for (const pair<int, vector<int>> paragraphPosition : wordInfo.paragraphPositions) {
            orderedParagraphs.push_back(paragraphPosition.first);
        }
        sort(orderedParagraphs.begin(), orderedParagraphs.end());

        for (int paragraph : orderedParagraphs) {
            vector<int> distances;
            for (int i = 1; i < wordInfo.paragraphPositions[paragraph].size(); i++) {
                distances.push_back(wordInfo.paragraphPositions[paragraph][i] - wordInfo.paragraphPositions[paragraph][i - 1]);
            }
            if (distances.size() >= 1) {
                output << "Paragraph " << paragraph << ": ";

                for (int distance : distances)
                    output << distance << " ";
                output << "\n---------------------------------------------------------------------------------------------------------------------------------------" << endl;

                output << "\n_______________________________________________________________________________________________________________________________________" << endl;
                output << "WORD                 APPEARANCES         LINE" << endl;
                output << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
        output << endl;
    }

    output.close();
}
