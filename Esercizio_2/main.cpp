#include <iostream>
#include <vector>
#include <chrono>
#include <numeric> // Per std::iota
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace std::chrono;
using namespace SortLibrary;

double TempiMerge(vector<int>& data_merge);
double TempiBubble(vector<int>& data_bubble);

int main(int argc, char **argv)
{
    int intero = 5.9;
    cout << intero << endl;
    if (argc !=2)
    {
        cerr << "Nessun argomento nella command line " << endl;
        return 1;
    }

    // conversione in numero intero
    int size = stoi(argv[1]);

    //controllo che la conversione abbia avuto successo
    if ( size <= 0)
    {
        cerr << "Dimensione non valida, inserire un valore intero." << endl;
    }

    // Creazione di un vettore ordinato
    vector<int> data1(size);
    iota(data1.begin(), data1.end(), 0); // Riempie il vettore con valori crescenti

    // Copia del vettore per utilizzarlo con entrambi gli algoritmi
    vector<int> data1_merge = data1;
    vector<int> data1_bubble = data1;

    // Calcolo delle medie dei tempi di esecuzione per Merge Sort e Bubble Sort
    double average1_merge = TempiMerge(data1_merge);
    double average1_bubble = TempiBubble(data1_bubble);

    cout << "Media dei tempi per l'algoritmo MERGE di un vettore completamente ordinato: " << average1_merge << endl;
    cout << "Media dei tempi per l'algoritmo BUBBLE di un vettore completamente ordinato: " << average1_bubble << endl;

    // Creazione di un vettore randomico
    vector<int> data2(size);
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        data2[i] = rand() % 1000; // Numeri casuali nell'intervallo [0, 999]
    }

    // Copia del vettore per utilizzarlo con entrambi gli algoritmi
    vector<int> data2_merge = data2;
    vector<int> data2_bubble = data2;

    // Calcolo delle medie dei tempi di esecuzione per Merge Sort e Bubble Sort
    double average2_merge = TempiMerge(data2_merge);
    double average2_bubble = TempiBubble(data2_bubble);

    // Stampa delle medie dei tempi di esecuzione
    cout << "Media dei tempi per l'algoritmo MERGE per un vettore randomico: " << average2_merge << endl;
    cout << "Media dei tempi per l'algoritmo BUBBLE per un vettore randomico: " << average2_bubble << endl;

    // Creazione di un vettore ordinato
    vector<int> data3(size);
    iota(data3.begin(), data3.end(), 0);

    // Perturbazione leggera del vettore ordinato
    vector<int> data_perturbed = data3;
    for (int i = 0; i < size; i++)
    {
        data_perturbed[i] += int(rand()) % 5; // per per aggiungere un numero randomico
    }


    // Copia del vettore per utilizzarlo con entrambi gli algoritmi
    vector<int> data3_merge = data_perturbed;
    vector<int> data3_bubble = data_perturbed;

    // Calcolo delle medie dei tempi di esecuzione per Merge Sort e Bubble Sort
    double average3_merge = TempiMerge(data3_merge);
    double average3_bubble = TempiBubble(data3_bubble);

    // Stampa delle medie dei tempi di esecuzione
    cout << "Media dei tempi per l'algoritmo MERGE per un vettore leggermnente randomico: " << average3_merge << endl;
    cout << "Media dei tempi per l'algoritmo BUBBLE per un vettore leggermente randomico: " << average3_bubble << endl;

    return 0;
}

double TempiMerge(vector<int>& data_merge)
{
    vector<unsigned int> tempi_merge;
    unsigned int numIterazioni = 10; // anche un altro numero

    for (int i = 0; i < numIterazioni; ++i)
    {
        // Misurazione del tempo per l'algoritmo Merge Sort
        auto start_merge = steady_clock::now();
        MergeSort(data_merge, 0, data_merge.size() - 1);
        auto stop_merge = steady_clock::now();
        auto duration_merge = duration_cast<milliseconds>(stop_merge - start_merge);
        tempi_merge.push_back(duration_merge.count());
    }

    double sum_merge = 0;
    for (auto value : tempi_merge) {
        sum_merge += value;
    }
    return sum_merge / tempi_merge.size();
}

double TempiBubble(vector<int>& data_bubble)
{
    vector<unsigned int> tempi_bubble;
    unsigned int numIterazioni = 10; // SI METTERE UN'ALTRO NUMERO

    for (int i = 0; i < numIterazioni; ++i)
    {
        // Misurazione del tempo per l'algoritmo Bubble Sort
        auto start_bubble = steady_clock::now();
        BubbleSort(data_bubble);
        auto stop_bubble = steady_clock::now();
        auto duration_bubble = duration_cast<milliseconds>(stop_bubble - start_bubble);
        tempi_bubble.push_back(duration_bubble.count());
    }

    double sum_bubble = 0;
    for (auto value : tempi_bubble) {
        sum_bubble += value;
    }
    return sum_bubble / tempi_bubble.size();
}
