#include <stdio.h>

void menor_maior_array(int arr[], int tamanho, int *menor, int *maior) {
    *menor = arr[0];
    *maior = arr[0];
    
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] < *menor) {
            *menor = arr[i];
        }
        if (arr[i] > *maior) {
            *maior = arr[i];
        }
    }
}

int main() {
    int array_exemplo[] = {5, 7, 9, 6};
    int tamanho = sizeof(array_exemplo) / sizeof(array_exemplo[0]);
    
    int menor, maior;
    menor_maior_array(array_exemplo, tamanho, &menor, &maior);
    
    printf("Saída: %d, %d\n", menor, maior);  
    
    return 0;
}
