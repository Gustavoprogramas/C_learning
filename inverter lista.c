#include <stdio.h>
#include <stdlib.h>

#define TAM 50

typedef struct No {
 int info;
 struct No *prox;

} No;

typedef struct lista {
    No *inicio;

} Lista;


void printarLista (Lista *l) {
    No *p = l->inicio;

    while (p != NULL) {
        printf("%d  ", p->info);
        p = p->prox;
    }
}

void inserirLista (Lista *L, int valor){
    Lista *aux;
    No *novo = (No*) malloc(sizeof(No));
    aux = L;
    novo->info = valor;
    novo->prox = aux->inicio;
    L->inicio = novo;

}

Lista* CriarLista() {
    Lista *aux = (Lista*) malloc (sizeof(Lista));

    aux->inicio = NULL;
    return aux;
}

void inverterLista (Lista *L){
    No *aux1 = NULL;
    No *aux = NULL;
    while (L->inicio!= NULL){
        aux1 = L->inicio;
        L->inicio = L->inicio->prox;
        aux1->prox = aux;
        aux = aux1;
}
L->inicio = aux;

}

int main() {

    int resp=1;

    Lista *minhalista = CriarLista();
    Lista *outralista = CriarLista();
    int valor;


    while (resp==1) {
         printf("\nDigite o valor que quer adicionar na lista:\n");
            scanf("%d", &valor);
            inserirLista(minhalista, valor);

            printf("\nQuer inserir mais coisas na lista? S=1, N=0\n");
            scanf("%d", &resp);
    }
    inverterLista(minhalista);
   // printf("printando a listainvertida");
    printarLista(minhalista);

}
