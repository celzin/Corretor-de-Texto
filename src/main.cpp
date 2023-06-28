#include <time.h>
#include "./include/hash.hpp"

using namespace std;

void initFile();

int main() {
    initFile();
    ofstream output("./dataset/output.txt", std::ios::app);

    Operacao op;

    op.readStopWords();
    op.readExpressions();

    cout << "1) Analyzing text paragraphs:" << endl << endl;
    clock_t startTime = clock(); // Start measuring time
    op.analyzeText();
    clock_t endTime = clock(); // End measuring time

    auto time1 = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Analysis completed in " << time1 << " seconds.\n";
    cout << "2) Analysing non stop words:" << endl << endl;

    startTime = clock(); // Start measuring time
    op.analyzeWords();
    endTime = clock(); // End measuring time

    auto time2 = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Analysis completed in " << time2 << " seconds.\n";
    cout << "3) Occurrence of expressions:" << endl << endl;
    // output << "Occurrence of expressions:" << endl << endl;
    startTime = clock(); // Start measuring time

    for (auto &expressionInfo : op.getExpressionsInfo()) {
        string expression = expressionInfo.first;
        WordInfo info = expressionInfo.second;
        if (info.freq > 0) {
            output << "Expression: " << expression << ". Lines: ";
            for (int line : info.lines) {
                output << line << " ";
            }
            output << endl;
        }

    }
    output.close();
    endTime = clock(); // End measuring time
    auto time3 = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Analysis completed in " << time3 << " seconds.\n";

    cout << "\nMedia de tempo: " << (time1 + time2 + time3) / 3 << " seconds"<< endl;

    return 0;
}

void initFile() {
    ofstream output("./dataset/output.txt");

cout << "======================================================================================================================================"<<endl;
cout << "=>                                                    ### START PROCESS ###"<<endl;
cout << "======================================================================================================================================"<<endl<<endl;

cout << "======================================================================================================================================"<<endl;
cout << "=>                                                    ### PARTIAL RESULT ###"<<endl;
cout << "======================================================================================================================================"<<endl<<endl;
}