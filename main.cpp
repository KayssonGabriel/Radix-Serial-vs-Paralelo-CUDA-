#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include <chrono>
#include <iomanip>

using namespace std;

// Função de Counting Sort para ordenar com base em um dígito
void countingSort(vector<int>& arr, int exp)
{
    const size_t n = arr.size();
    vector<int> output(n);
    size_t count[10] = {0};

    // Contagem de ocorrências
    for (const int value : arr)
        count[(value / exp) % 10]++;

    // Atualiza o array count[] de modo que count[i] contenha a posição real do próximo número
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Preenche o array de saída
    for (auto it = arr.rbegin(); it != arr.rend(); ++it)
    {
        const int digit = (*it / exp) % 10;
        output[--count[digit]] = *it;
    }

    // Copia os números ordenados para o array original
    arr.swap(output);
}

// Função principal do Radix Sort
void radixSort(vector<int>& arr)
{
    if (arr.empty()) {
        return;
    }
    const auto [menor, maior] = minmax_element(arr.begin(), arr.end());
    if (*menor < 0) {
        throw invalid_argument("O Radix Sort deste exemplo aceita apenas inteiros não negativos.");
    }
    const int maxElem = *maior;
    for (long long exp = 1; maxElem / exp > 0; exp *= 10) {
        countingSort(arr, static_cast<int>(exp));
    }
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
