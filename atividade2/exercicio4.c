#include <stdio.h>

int conta_int_array(int arr[], int tamanho, int busca) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == busca) {
            contador++;
        }
    }
    return contador;
}

int main() {
    int array_exemplo[] = {5, 7, 9, 6, 7, 11, 6, 5};
    int tamanho = sizeof(array_exemplo) / sizeof(array_exemplo[0]);
    int busca = 7;
    
    int resultado = conta_int_array(array_exemplo, tamanho, busca);
    printf("Saída: %d\n", resultado);  
    
    return 0;
}
