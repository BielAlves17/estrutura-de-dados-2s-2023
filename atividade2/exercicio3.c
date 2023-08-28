#include <stdio.h>
#include <string.h>

int busca_string(char *arr[], int tamanho, char *busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(arr[i], busca) == 0) {
            return 1; 
        }
    }
    return 0; 

int main() {
    char *array_exemplo[] = {"texto", "J", "EDA"};
    int tamanho = sizeof(array_exemplo) / sizeof(array_exemplo[0]);
    char *busca = "EDO";
    
    int resultado = busca_string(array_exemplo, tamanho, busca);
    printf("Saída: %d\n", resultado);  
    
    return 0;
}
