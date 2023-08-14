#include <stdio.h>
#include <stdlib.h>


int isPrime(int num) {
    if (num <= 1) {
        return 0; 
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    
    return 1; 
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1; 
    
    int numero = atoi(argv[1]); 
    
    if (isPrime(numero)) {
        printf("1\n"); 
    } else {
        printf("0\n"); 
    }
    
    return 0; 
}