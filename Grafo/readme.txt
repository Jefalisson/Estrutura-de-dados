Grafos em C
Implementa uma estrutura de grafo utilizando representações em matriz de adjacência e lista de adjacência. 
O programa permite a leitura de uma matriz de distâncias de um arquivo existente e a execução de buscas em largura (BFS) e profundidade (DFS) no grafo resultante.

-Funcionalidades
    Leitura da matriz de distâncias a partir de um arquivo existente.
    Conversão da matriz de distâncias para uma lista de adjacência.
    Implementação de Busca em Largura (BFS) com impressão do caminho entre dois vértices.
    Implementação de Busca em Profundidade (DFS) sem uso de recursão.

-Estruturas de Dados
    Matriz de Adjacência: Representa o grafo como uma matriz onde o valor na posição (i, j) indica a distância entre os vértices i e j.
    Lista de Adjacência: Representa o grafo como um array de listas, onde cada lista contém os vértices adjacentes e o peso das arestas.

-Compilação
    Para compilar o código, use o seguinte comando no terminal, dentro da pasta do projeto:

gcc -o busca_grafo main.c

-Execução
    Após compilar, execute o programa com o comando:

./busca_grafo ./pcv4.txt

Entrada:
    O programa irá ler a matriz de distâncias diretamente do arquivo especificado (pcv4.txt, pcv10.txt, pcv50.txt ou um qualquer gerado).
    Em seguida, você pode digitar dois vértices para encontrar o caminho entre eles.
