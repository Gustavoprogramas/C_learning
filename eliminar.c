#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int info;
    struct No* prox;
    

}No;

typedef struct Fila
{
    No* inicio;
    No* fim;
}Fila;

void eliminar(Fila *f, int x) {
    No *aux = f->inicio;
    No *antigo = NULL;

    while (aux != NULL) {
        No *novo = aux->prox;

        if (aux->info >= x) {
            if (antigo == NULL)
                f->inicio = novo;
            else
                antigo->prox = novo;

            if (f->fim == aux)
                f->fim = antigo;

            free(aux);
        } else {
            antigo = aux;  
        }

        aux = novo;
    }
}

Fila* inserir(Fila *f, int v){
   
    No* novo = (No*)malloc(sizeof(No));
    
    novo->info = v;
    novo->prox=NULL;
    if (f->inicio == NULL){
        f->inicio = novo;


    } else{
    f->fim->prox = novo;
    }

    f->fim = novo;
    return f;
    
    
    
}

void printar(Fila* f){
    No* aux = f->inicio;
    while(aux!=NULL){
        printf("%d   ", aux->info);
        aux = aux->prox;
    }
}

int main () {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->inicio = NULL;
    int x = 5;
    inserir (f, 1);
    inserir (f, 2);
    inserir (f, 7);
    inserir (f, 9);
    inserir (f, 2);
    inserir (f, 5);
    inserir (f, 4);
    printar(f);
    eliminar(f, x);
    printf("\n");
    printar(f);

}

