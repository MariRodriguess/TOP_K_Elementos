#include "functions.hpp"
#include <time.h>
#define k 20

int main() {
    
    clock_t startTime, endTime;
    startTime = clock();

    unordered_map<string, int> glossario;
    vector<string> stopWords;
    vector<pair<string, int>> heap;
    string filename = "data/entrada.txt";
    string filestopWords = "data/stopwords.txt";

    processStopWords(filestopWords, stopWords);
    processArq(filename, glossario, stopWords);
    addHeap(glossario, heap, k);

    cout << "\n\n-> TOP " << k << " PALAVRAS MAIS FREQUENTES (PALAVRA: OCORRENCIA)\n" << endl;
    printVetor(heap);
    cout << "\n\n\n";

    endTime = clock();
    clock_t elapsedTime = endTime - startTime;
    double elapsedTimeMs = ((double)elapsedTime/CLOCKS_PER_SEC)*1000;
    cout << "TEMPO DE EXECUÇÃO: " << elapsedTimeMs << " ms " << endl << endl;

    return 0;
}