#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INFINITY 1000000000

// Estrutura para a lista de adjacência
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Função para gerar a matriz de distâncias e salvá-la em um arquivo
void gerarMatrizArquivo(int tamanho) {
    FILE *arquivo = fopen("pcv.txt", "w");
    fprintf(arquivo, "%d\n", tamanho);

    srand(time(0)); // Usar tempo como semente para números aleatórios

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == j) {
                fprintf(arquivo, "0 "); // Distância zero para a diagonal
            } else {
                fprintf(arquivo, "%d ", rand() % 100 + 1); // Distância aleatória entre 1 e 100
            }
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    printf("Arquivo pcv.txt gerado com sucesso!\n");
}

// Função para ler a matriz de distâncias do arquivo
int** read_instance(const char* instance_name, int* dimension) {
    FILE *fp = fopen(instance_name, "r");
    if (!fp) {
        printf("Nao foi possivel abrir o arquivo\n");
        return NULL;
    }

    fscanf(fp, "%d", dimension);
    int **distance_matrix = (int**) malloc(*dimension * sizeof(int*));
    for (int i = 0; i < *dimension; i++) {
        distance_matrix[i] = (int*) malloc(*dimension * sizeof(int));
    }

    for (int i = 0; i < *dimension; i++) {
        for (int j = 0; j < *dimension; j++) {
            fscanf(fp, "%d", &distance_matrix[i][j]);
        }
    }

    fclose(fp);
    return distance_matrix;
}

// Função para converter a matriz de distâncias para uma matriz de adjacência
Node** matrizParaListaAdj(int** matrix, int dimension) {
    Node** listaAdj = (Node**) malloc(dimension * sizeof(Node*));
    for (int i = 0; i < dimension; i++) {
        listaAdj[i] = NULL; // Inicializa a lista de adjacência para cada vértice
        for (int j = 0; j < dimension; j++) {
            if (matrix[i][j] != 0) {
                Node* newNode = (Node*) malloc(sizeof(Node));
                newNode->vertex = j;
                newNode->weight = matrix[i][j];
                newNode->next = listaAdj[i];
                listaAdj[i] = newNode;
            }
        }
    }
    return listaAdj;
}

// Função para imprimir a lista de adjacência
void printListaAdj(Node** listaAdj, int dimension) {
    for (int i = 0; i < dimension; i++) {
        printf("Vertice %d:", i);
        Node* temp = listaAdj[i];
        while (temp != NULL) {
            printf(" -> (%d, %d)", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Função para imprimir a matriz de distâncias
void print_distance_matrix(int** distance_matrix, int n) {
    printf("Matriz de Distancias:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", distance_matrix[i][j]);
        }
        printf("\n");
    }
}

// Função para encontrar o caminho usando o vetor de pais gerado pelo BFS
void print_path(int* parent, int start, int end) {
    if (parent[end] == -1) {
        printf("Nao ha caminho entre os vertices %d e %d\n", start, end);
        return;
    }

    int route[100], route_index = 0;
    for (int v = end; v != start; v = parent[v]) {
        route[route_index++] = v;
    }
    route[route_index++] = start;

    printf("Rota: ");
    for (int i = route_index - 1; i >= 0; i--) {
        printf("%d%s", route[i], (i == 0 ? "\n" : " -> "));
    }
}

// Implementação da BFS (Busca em Largura)
int* BFS(int start, Node** adj_list, int dimension) {
    int* status = (int*) malloc(dimension * sizeof(int));
    int* distance = (int*) malloc(dimension * sizeof(int));
    int* parent = (int*) malloc(dimension * sizeof(int));
    for (int i = 0; i < dimension; i++) {
        status[i] = 0; // Status de cada vértice
        distance[i] = INFINITY; // Distâncias iniciais como INFINITY
        parent[i] = -1; // Vetor de pais
    }

    status[start] = 1;
    distance[start] = 0;
    parent[start] = -1;

    int queue[100], front = 0, rear = 0; // Fila para BFS
    queue[rear++] = start;

    while (front < rear) {
        int index_aux = queue[front++];

        Node* edge = adj_list[index_aux];
        while (edge) {
            if (status[edge->vertex] == 0) {
                status[edge->vertex] = 1;
                distance[edge->vertex] = distance[index_aux] + edge->weight;
                parent[edge->vertex] = index_aux;
                queue[rear++] = edge->vertex;
            }
            edge = edge->next;
        }

        status[index_aux] = 2;
    }

    free(status);
    free(distance);
    return parent;
}

// Implementação da DFS (Busca em Profundidade) sem recursão
void DFS(int start, Node** adj_list, int dimension) {
    int* status = (int*) malloc(dimension * sizeof(int));
    for (int i = 0; i < dimension; i++) {
        status[i] = 0; // Status de cada vértice
    }

    int stack[100], stack_top = -1; // Pilha para DFS
    stack[++stack_top] = start;
    status[start] = 1;

    printf("DFS a partir do vertice %d: ", start);
    while (stack_top != -1) {
        int top = stack[stack_top--];
        printf("%d ", top);

        Node* edge = adj_list[top];
        while (edge) {
            if (status[edge->vertex] == 0) {
                status[edge->vertex] = 1;
                stack[++stack_top] = edge->vertex;
            }
            edge = edge->next;
        }
    }
    printf("\n");
    
    free(status);
}

int main() {
    int tamanho;
    printf("Indique o tamanho da matriz: ");
    scanf("%d", &tamanho);

    // Gera a matriz e salva no arquivo
    gerarMatrizArquivo(tamanho);

    // Carrega a matriz do arquivo
    int** distance_matrix = read_instance("pcv.txt", &tamanho);
    if (distance_matrix == NULL) {
        return -1; // Erro ao ler o arquivo
    }

    // Converte a matriz de distâncias para a lista de adjacência
    Node** listaAdj = matrizParaListaAdj(distance_matrix, tamanho);

    // Exibe a matriz de distâncias
    print_distance_matrix(distance_matrix, tamanho);

    // Imprime a lista de adjacência
    printListaAdj(listaAdj, tamanho);

    // Solicita dois vértices para realizar a busca
    int start, end;
    printf("Digite dois vertices para a busca de caminho: ");
    scanf("%d %d", &start, &end);

    // Executa BFS e imprime a rota
    int* parent = BFS(start, listaAdj, tamanho);
    print_path(parent, start, end);
    
    // Executa DFS a partir do vértice inicial
    DFS(start, listaAdj, tamanho);

    // Libera a memória
    for (int i = 0; i < tamanho; i++) {
        free(distance_matrix[i]);
        Node* temp;
        while (listaAdj[i] != NULL) {
            temp = listaAdj[i];
            listaAdj[i] = listaAdj[i]->next;
            free(temp);
        }
    }
    free(distance_matrix);
    free(listaAdj);
    free(parent);

    return 0;
}
