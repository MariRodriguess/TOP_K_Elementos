#include "functions.hpp"
#include <time.h>
#define k 20
#define qtdArq 2

int main() {
    
    clock_t startTime, endTime;
    startTime = clock();
    int cont=1;
    string filename = "";

    unordered_map<string, int> glossario;
    vector<string> stopWords;
    vector<pair<string, int>> heap;

    string filestopWords = "data/stopwords.txt";
    processStopWords(filestopWords, stopWords);

    while(cont <= qtdArq){
        filename = "data/txt" + to_string(cont) + ".txt";
        processArq(filename, glossario, stopWords);
        cont++;
    }
    
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