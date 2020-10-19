# TP-PAA
Repositório destinado ao trabalho prático da matéria Projeto e Análise de Algoritmos

### Como executar o algoritmo de Dijkstra
Compilar o código `g++ Dijkstra.cpp -o Dijkstra.exe`
Executar `./Dijkstra.exe`
#### Entrada do programa
A entrada começa com dois valores V, E representando os vértices e as arestas do grafos respectivamente.
Em seguinda deve-se entrar com E linhas, contendo três valores, V U W indicando que há uma resta do vértice V ao vértice U com peso W.
Em seguida deve-se entrar com dois valores Start e End, representando o vértice de começo e o vértice destino.

>5 10
0 1 10
0 3 5
1 3 2
1 2 1
2 4 4
3 1 3
3 2 9
3 4 2
4 0 7
4 2 6
0 3


### Saida do programa
O programa irá imprimir um único valor com a menor distância entre o vértice Start e o vértice End.