#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_de_entrada.txt>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    int num_lines = 0;

    
    while (getline(&line, &len, input_file) != -1) {
        num_lines++;
    }

    
    fseek(input_file, 0, SEEK_SET);

    
    char *words[num_lines];
    for (int i = 0; i < num_lines; i++) {
        if (getline(&line, &len, input_file) != -1) {
            line[strcspn(line, "\n")] = '\0'; 
            words[i] = strdup(line);
        }
    }

    
    bubbleSort(words, num_lines);

    
    FILE *output_file = fopen("arq_palavras_ordenado.txt", "w");
    if (output_file == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    
    for (int i = 0; i < num_lines; i++) {
        fprintf(output_file, "%s\n", words[i]);
        free(words[i]);
    }

    fclose(input_file);
    fclose(output_file);
    free(line);

    return 0;
}
