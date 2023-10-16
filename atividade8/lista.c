#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* lista_criar() {
    No* cabeca = (No*)malloc(sizeof(No));
    cabeca->proximo = NULL;
    return cabeca;
}

void lista_destruir(No* L) {
    No* atual = L;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

void lista_inserir_inicio(No* L, char valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = L->proximo;
    L->proximo = novo;
}

void lista_imprimir(No* L) {
    No* atual = L->proximo;
    while (atual != NULL) {
        printf("%c -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            ocorrencias++;
        }
        atual = atual->proximo;
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L->proximo != NULL) {
        lista_imprimir_inversa(L->proximo);
    }
    printf("%c -> ", L->valor);
}

void lista_inserir_no_i(No* L, int i, char valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    No* anterior = L;
    for (int j = 0; j < i && anterior->proximo != NULL; j++) {
        anterior = anterior->proximo;
    }
    novo->proximo = anterior->proximo;
    anterior->proximo = novo;
}

void lista_remover_no_i(No* L, int i) {
    No* anterior = L;
    for (int j = 0; j < i && anterior->proximo != NULL; j++) {
        anterior = anterior->proximo;
    }
    if (anterior->proximo != NULL) {
        No* temp = anterior->proximo;
        anterior->proximo = temp->proximo;
        free(temp);
    }
}

void lista_remover_no(No* L, char valor_busca) {
    No* anterior = L;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            anterior->proximo = atual->proximo;
            free(atual);
            atual = anterior->proximo;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}
