# TP-PAA
Repositório destinado ao trabalho prático da matéria Projeto e Análise de Algoritmos

###Parte escrita com o detalhamento do trabalho está disponível no arquivo Trabalho_de_PAA.pdf

### Como executar o algoritmo de Dijkstra
Compilar o código `make build_Dijkstra`
Executar `.make run_Dijkstra` ou  `make run_Dijkstra_Default` para executar com a entrada exemplo. 
#### Entrada do programa
A entrada começa com dois valores V, E representando os vértices e as arestas do grafos respectivamente.
Em seguinda deve-se entrar com E linhas, contendo três valores, V U W indicando que há uma resta do vértice V ao vértice U com peso W.
Em seguida deve-se entrar com dois valores Start e End, representando o vértice de começo e o vértice destino.

>5 10  
>0 1 10  
>0 3 5  
>1 3 2  
>1 2 1  
>2 4 4  
>3 1 3  
>3 2 9  
>3 4 2  
>4 0 7  
>4 2 6  
>0 3  


### Saida do programa
O programa irá imprimir um único valor com a menor distância entre o vértice Start e o vértice End.

### Como executar o algoritmo de Bellman-Ford para calcular se o grafo há um ciclo negativo
Compilar o código `make build_Bellman_Ford_Distance_Negative_Cycle`
Executar `make run_Bellman_Ford_Negative_Cycle` ou  `make run_Bellman_Ford_Negative_Cycle_Default` para executar com a entrada exemplo. 
#### Entrada do programa
A entrada começa com dois valores V, E representando os vértices e as arestas do grafos respectivamente.
Em seguinda deve-se entrar com E linhas, contendo três valores, V U W indicando que há uma resta do vértice V ao vértice U com peso W.

>4 8  
>0 1 -5   
>1 0 -5  
>0 2 3  
>2 0 3  
>1 2 1  
>2 1 1  
>2 3 2  
>3 2 2  


### Como executar o algoritmo de Bellman-Ford para calculo de Menor distância entre dois vértices com aresta negativa, porém sem ciclo negativo
Compilar o código `make build_Bellman_Ford_Distance`
Executar `make run_Bellman_Ford_Distance` ou  `make run_Bellman_Ford_Distance_Default` para executar com a entrada exemplo. 
#### Entrada do programa
A entrada começa com dois valores V, E representando os vértices e as arestas do grafos respectivamente.
Em seguinda deve-se entrar com E linhas, contendo três valores, V U W indicando que há uma resta do vértice V ao vértice U com peso W.
Em seguida deve-se entrar com dois valores Start e End, representando o vértice de começo e o vértice destino.

>5 10  
>0 1 10  
>0 3 5  
>1 3 2  
>1 2 1  
>2 4 4  
>3 1 3  
>3 2 9  
>3 4 2  
>4 0 7  
>4 2 6  
>0 3  

### Para buildar todos os programas execute
`make build_all`