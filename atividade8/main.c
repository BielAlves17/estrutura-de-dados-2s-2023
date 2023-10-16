#include <stdio.h>
#include "lista.h"

int main() {
    No* lista = lista_criar();

    lista_inserir_inicio(lista, 'A');
    lista_inserir_inicio(lista, 'B');
    lista_inserir_inicio(lista, 'A');
    lista_inserir_inicio(lista, 'C');
    lista_inserir_inicio(lista, 'D');
    lista_inserir_inicio(lista, 'A');
    lista_inserir_inicio(lista, 'E');

    printf("Lista: ");
    lista_imprimir(lista);

    char busca = 'A';

    if (lista_verificar_existencia(lista, busca)) {
        printf("O valor %c existe na lista.\n", busca);
    } else {
        printf("O valor %c não existe na lista.\n", busca);
    }

    printf("Quantidade de ocorrencias de %c: %d\n", busca, lista_verificar_ocorrencias(lista, busca));

    printf("Imprimindo a lista inversa: ");
    lista_imprimir_inversa(lista);
    printf("NULL\n");

    int posicao_inserir = 3;
    lista_inserir_no_i(lista, posicao_inserir, 'F');
    printf("Inserindo 'F' na posicao %d: ", posicao_inserir);
    lista_imprimir(lista);

    int posicao_remover = 2;
    lista_remover_no_i(lista, posicao_remover);
    printf("Removendo o no na posicao %d: ", posicao_remover);
    lista_imprimir(lista);

    char valor_remover = 'A';
    lista_remover_no(lista, valor_remover);
    printf("Removendo todos os nos com valor %c: ", valor_remover);
    lista_imprimir(lista);

    lista_destruir(lista);

    return 0;
}
