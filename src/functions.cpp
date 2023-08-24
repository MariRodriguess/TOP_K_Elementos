#include "functions.hpp"

using namespace std;

void verifPalavra(string& str, unordered_map<string, int> &glossario, vector<string> &stopWord){

    bool confStopWord = verifStopWord(str, stopWord);
    bool valida = true;
    if ((str.size() == 1) || (str.size() == 2)){
        valida = validar(str);
    }
    if ((!confStopWord) && (valida)){
        addGlossario(str, glossario);
    }
}

bool validar(string& str) {
    string validar = "abcdefghijklmnopqrstuvwxyzàáâãäçèéêëìíîïðñòóôõöùúûüýÿ";
    for (int i=0; i<(int)validar.size(); i++){
        if (validar[i] == str[0]){
            return true;
        }
    }
    return false;
}

bool verifStopWord(string& str, vector<string> &stopWord){

    for (int i=0; i<(int)stopWord.size(); i++){
        if (stopWord[i] == str){
            return true;
        }
    }
    return false;
}

void processArq(string& filename, unordered_map<string, int>& glossario, vector<string> &stopWord) {
    ifstream file(filename);

    if (!file) {
        cout << "Erro ao abrir o arquivo: " << filename << endl;
        return;
    }

    regex wordRegex("[a-zA-Z0-9'À-Ÿ-]+");
    
    string line;
    while (getline(file, line)) {

        sregex_iterator wordIterator(line.begin(), line.end(), wordRegex);
        //wordIterator = iterador inicializado com o início (line.begin()) e o fim (line.end()) da linha atual. 
        //Ele usará a expressão regular wordRegex para encontrar todas as ocorrências de palavras na linha.

        sregex_iterator wordEnd;
        //wordEnd = iterador que marca o final da sequência de palavras encontradas na linha, verificando quando chegamos ao final das palavras na linha

        while (wordIterator != wordEnd){
            
            string word = wordIterator->str();
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            
            string auxiliar = word;
            string str = word;
            int inicio=0, final=0;

            if ((auxiliar[0] == '-') || (auxiliar[auxiliar.size()-1] == '-')){
                
                str="";
                for (int i=0; i<(int)auxiliar.size(); i++){
                    if (auxiliar[i] != '-'){
                        inicio=i;
                        break;
                    }
                }
                for (int i=(int)auxiliar.size()-1; i>0; i--){
                    if (auxiliar[i] != '-'){
                        final=i;
                        break;
                    }
                }
                for (int i=inicio; i<final+1; i++){
                    str += auxiliar[i];
                }

            }
            
            verifPalavra(str, glossario, stopWord);
            ++wordIterator;
        }
    }
    file.close();
}

void processStopWords(string& filename, vector<string>& stopWord){
    ifstream file(filename);

    if (!file) {
        cout << "Erro ao abrir o arquivo: " << filename << endl;
        return;
    }

    string palavra;
    while (file >> palavra) {
        stopWord.push_back(palavra);
    }
    file.close();
}

void addGlossario(string& str, unordered_map<string, int> &glossario){

    auto itmap = glossario.find(str);
    if ((!str.empty()) && (itmap == glossario.end()) && (str!="")){
        glossario[str] = 1;
    }else if ((!str.empty()) && (str!="")){
        glossario[str]++;
    }
}

void addHeap(unordered_map<string, int> &glossario, vector<pair<string, int>>& heap, int k){
    int cont = 0;
    for (const auto& entry : glossario) {
        if (cont < k) {
            heap.push_back(make_pair(entry.first, entry.second));
            heapify(heap, cont, 0);
            if (cont == k-1){
                heapify(heap, k, 0);
            }
        } else if (entry.second > heap[0].second) {
            heap[0] = make_pair(entry.first, entry.second);
            heapify(heap, k, 0);
        }
        cont++;
    }
}

void heapify(vector<pair<string, int>>& vetor, int k, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < k && vetor[esquerda].second < vetor[maior].second)
        maior = esquerda;

    if (direita < k && vetor[direita].second < vetor[maior].second)
        maior = direita;

    if (maior != i) {
        swap(vetor[i], vetor[maior]);
        heapify(vetor, k, maior);
    }
}

void ajustarHeap(vector<pair<string, int>>& vetor, int k){
    
    for (int i=k/2-1; i>=0; i--){
        heapify(vetor, k, i);
    }

    for (int i=k-1; i>0; i--){
        swap(vetor[0], vetor[i]);
        heapify(vetor, i, 0);
    }
}

void printGlossario(unordered_map<string, int>& glossario){
    int cont=0;
    for (auto it:glossario){
        cout << it.first << " - " << it.second << endl;
        cont++;
    }
    cout << "\n\ncont: " << cont << endl;
}

void printVetor(vector<pair<string, int>>& vetor){
    for (int i = 0; i < (int)vetor.size(); i++) {
        cout << vetor[i].first << ": " << vetor[i].second << endl;
    }
}

void procurarGlossario(string& str, unordered_map<string, int>& glossario){
    for (auto it:glossario){
        if (it.first == str){
            cout << it.first << " - " << it.second << endl;
        }
    }
}
