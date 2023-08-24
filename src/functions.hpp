#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <fstream>
#include <regex>
#include <unordered_map>
#include <queue>
#include <string>
#include <iomanip> 

using namespace std;

void verifPalavra(string& str, unordered_map<string, int> &glossario, vector<string> &stopWord);
bool verifStopWord(string& str, vector<string> &stopWord);
bool validar(string& str);

void processArq(string& filename, unordered_map<string, int>& glossario, vector<string> &stopWord);
void processStopWords(string& filename, vector<string>& stopWord);

void addGlossario(string& str, unordered_map<string, int>& glossario);
void addHeap(unordered_map<string, int> &glossario, vector<pair<string, int>>& heap, int k);

void heapify(vector<pair<string, int>>& arr, int n, int i);
void ajustarHeap(vector<pair<string, int>>& vetor, int k);

void printGlossario(unordered_map<string, int>& glossario);
void printVetor(vector<pair<string, int>>& vetor);
void procurarGlossario(string& str, unordered_map<string, int>& glossario);

#endif