# Radix Sort serial e paralelo em CUDA

Este repositório guarda a implementação serial em C++ de um estudo sobre Radix Sort. A versão CUDA está no repositório complementar [RadixParalelo](https://github.com/KayssonGabriel/RadixParalelo).

[main.cpp](main.cpp) ordena inteiros não negativos com ordenação por contagem estável, dígito a dígito. Ele mede cinco tamanhos de vetor, de 100 a 10 milhões de elementos. O executável atual mede a versão serial na CPU.

## Como executar

Use CMake 3.29 ou superior e um compilador C++20.

~~~sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
~~~

Execute `build/RadixSort` no Linux ou `build/Release/RadixSort.exe` no Windows com o gerador do Visual Studio. Para comparar com CUDA, valide primeiro a saída de ambos os programas e use dados de entrada idênticos.
