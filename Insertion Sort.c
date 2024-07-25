#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define MAX_PATH_LEN 256
// Insertion Sort
void insertionSort(int *ar, int n) {
    int i, j, aux;
    for (i = 1; i < n; i++) {
        aux = ar[i];
        j = i - 1;
        while (j >= 0 && ar[j] > aux) {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = aux;
    }
}
int main() {
    DIR *dir;
    struct dirent *entry;
    const char *intancesFolder = "C:/Users/jeffe/documents/ufpb/instancias-num";
    const char *resultsFolder = "C:/Users/jeffe/documents/ufpb/resultados-num/insertion/";
    FILE *inputFile, *outputFile;
    char inputPath[MAX_PATH_LEN], outputPath[MAX_PATH_LEN];
    clock_t start, end;
    double cpu_time_used;
    dir = opendir(intancesFolder);
    if (dir == NULL) {
        perror("Erro ao abrir o diretório");
        return EXIT_FAILURE;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        int ar[100000];
        int x, i = 0;

        snprintf(inputPath, MAX_PATH_LEN, "%s/%s", intancesFolder, entry->d_name);
        snprintf(outputPath, MAX_PATH_LEN, "%s/%st", resultsFolder, entry->d_name);
        outputPath[strlen(outputPath) - 3] = 'o';
        outputPath[strlen(outputPath) - 2] = 'u';
        inputFile = fopen(inputPath, "r");
        if (inputFile == NULL) {
            return EXIT_FAILURE;
        }
        outputFile = fopen(outputPath, "w");
        if (outputFile == NULL) {
            fclose(inputFile);
            return EXIT_FAILURE;
        }
        while (fscanf(inputFile, "%d", &x) != EOF) {
            ar[i] = x;
            i++;
        }

        start = clock();
        insertionSort(ar, i);
        end = clock();
        cpu_time_used = 0;

        for (int j = 0; j < 10; j++) {
            int arCopy[i];
            for (int k = 0; k < i; k++) arCopy[k] = ar[k];

            start = clock();
            if (j != 9) insertionSort(arCopy, i);
            else insertionSort(ar, i);
            end = clock();

            cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
        }

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        cpu_time_used /= 10;
        fprintf(outputFile, "Insertion Sort:\n");
        fprintf(outputFile, "Tempo de CPU usado: %f segundos\n", cpu_time_used);
        fprintf(outputFile, "Tempo de CPU usado(média): %f segundos\n", cpu_time_used);
        for (int j = 0; j < i; j++) {
            fprintf(outputFile, "%d\n", ar[j]);
        }
        fclose(inputFile);
        fclose(outputFile);
    }
    return 0;
}
