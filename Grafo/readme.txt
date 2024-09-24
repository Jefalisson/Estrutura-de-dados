Grafos em C
Implementa uma estrutura de grafo utilizando representações em matriz de adjacência e lista de adjacência. 
O programa permite a geração de uma matriz de distâncias aleatórias, a leitura desta matriz de um arquivo e a execução de buscas em largura (BFS) e profundidade (DFS) no grafo resultante.

Funcionalidades
    -Geração de uma matriz de distâncias aleatórias e gravação em um arquivo.
    -Leitura da matriz de distâncias a partir de um arquivo.
    -Conversão da matriz de distâncias para uma lista de adjacência.
    -Implementação de Busca em Largura (BFS) com impressão do caminho entre dois vértices.
    -Implementação de Busca em Profundidade (DFS) sem uso de recursão.

Estruturas de Dados
    -Matriz de Adjacência: Representa o grafo como uma matriz onde o valor na posição (i, j) indica a distância entre os vértices i e j.
    -Lista de Adjacência: Representa o grafo como um array de listas, onde cada lista contém os vértices adjacentes e o peso das arestas.

Como Usar

    -Compilação: Para compilar o código, use o seguinte comando no terminal, dentro da pasta do projeto:

gcc -o busca_grafo busca_grafo.c

    -Execução: Após compilar, execute o programa com o comando:

./busca_grafo

Entrada:
    -O programa solicitará que você informe o tamanho da matriz.
    -Em seguida, você pode digitar dois vértices para encontrar o caminho entre eles.



