#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;

// Função de Counting Sort para ordenar com base em um dígito
void countingSort(vector<int>& arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Contagem de ocorrências
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Atualiza o array count[] de modo que count[i] contenha a posição real do próximo número
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Preenche o array de saída
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia os números ordenados para o array original
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Função principal do Radix Sort
void radixSort(vector<int>& arr)
{
    int maxElem = *max_element(arr.begin(), arr.end());

    // Realiza Counting Sort para cada dígito
    for (int exp = 1; maxElem / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main()
{
    vector<int> sizes = {100, 1000, 10000, 1000000, 10000000};

    for (int n : sizes)
    {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 10000000;
        }

        auto start = chrono::high_resolution_clock::now();
        radixSort(arr);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        cout << "Tempo de execucao Serial para " << n << " elementos: " << fixed << setprecision(6) << duration.count() <<
            " segundos" << endl;
    }

    return 0;
}
