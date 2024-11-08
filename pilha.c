#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void **dados;      // Ponteiro genérico para os elementos da pilha
    int inicio;        // Índice do primeiro elemento
    int fim;           // Índice do último elemento
    int tamanho;       // Número de elementos na pilha
    int capacidade;    // Capacidade total da pilha
} Pilha;

Pilha* criarPilha(int capacidadeInicial) {
    Pilha *pilha = malloc(sizeof(Pilha));
    if (pilha == NULL) return NULL;
    
    pilha->dados = malloc(sizeof(void*) * capacidadeInicial);
    if (pilha->dados == NULL) {
        free(pilha);
        return NULL;
    }
    
    pilha->inicio = 0;
    pilha->fim = -1;
    pilha->tamanho = 0;
    pilha->capacidade = capacidadeInicial;

    return pilha;
}

void limparPilha(Pilha *pilha) {
    if (pilha != NULL) {
        free(pilha->dados);
        free(pilha);
    }
}

void inserirNaPilha(Pilha *pilha, void* dado) {
    if (pilha->tamanho == pilha->capacidade) {
        void **novosDados = malloc(sizeof(void*) * pilha->capacidade * 2);
        if (novosDados == NULL) return;

        for (int i = 0; i < pilha->tamanho; i++) {
            novosDados[i] = pilha->dados[i];
        }

        free(pilha->dados);
        pilha->dados = novosDados;
        pilha->capacidade *= 2;
    }

    pilha->dados[pilha->tamanho] = dado;
    pilha->tamanho++;

    printf("Tamanho pilha: %d \n", pilha->tamanho);
    printf("Capacidade pilha: %d \n", pilha->capacidade);
}

void* removerDaPilha(Pilha *pilha) {
    if (pilha->tamanho == 0) {
        printf("A pilha está vazia!\n");
        return NULL;
    }

    pilha->tamanho--; 
    void* dadoRemovido = pilha->dados[pilha->tamanho];

    pilha->dados[pilha->tamanho] = NULL;

    printf("Tamanho pilha após remoção: %d \n", pilha->tamanho);
    
    return dadoRemovido;
}

int main() {
    Pilha *pilha = criarPilha(4);

    int a = 22;
    inserirNaPilha(pilha, &a);

    double b = 13.5;
    inserirNaPilha(pilha, &b);

    char c = 'Z';
    inserirNaPilha(pilha, &c);
    
    char caaaa = 'B';
    inserirNaPilha(pilha, &caaaa);
    
    char caaaa1 = 'A';
    inserirNaPilha(pilha, &caaaa1);

    printf("Valor do primeiro item: %d\n", *(int*) pilha->dados[0]);
    printf("Valor do segundo item: %.2f\n", *(double*) pilha->dados[1]);
    printf("Valor do terceiro item: %c\n", *(char*) pilha->dados[2]);
    printf("Valor do quarto item: %c\n", *(char*) pilha->dados[3]);
    printf("Valor do quinto item: %c\n", *(char*) pilha->dados[4]);

    void* elementoRemovido = removerDaPilha(pilha);

    printf("Elemento removido %c \n", *(char*) elementoRemovido);

     void* elementoRemovido2 = removerDaPilha(pilha);

    printf("Elemento removido2 %c \n", *(char*) elementoRemovido2);

    limparPilha(pilha);

    return 0;
}
