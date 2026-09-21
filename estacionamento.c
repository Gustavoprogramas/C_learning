#include <stdlib.h>
#include <stdio.h>
typedef struct No
{
    int info;
    struct No* prox;
}No;
typedef struct Pilha
{
    No* topo;
}Pilha;

void auxinsere(Pilha *p, int v){
    No* insere = p->topo;
    No* novo = (No*)malloc(sizeof(No));
    novo -> info = v;
    novo->prox = insere;
    p->topo = novo;
}
void push (Pilha *p, int valor){
    
    auxinsere(p,valor);


}
int pop (Pilha*p){


  int info = p->topo->info;
  No* novo = (No*) malloc (sizeof(No));
  novo = p->topo->prox;
  No* aux = p->topo;
  p->topo = novo;
  free (aux);

  return info;
}
int controle (Pilha *p, int valor, Pilha *controle){
    if (p->topo == NULL){
        printf("\nEstacionamento vazio.");
        return 0;
    }

    int manobras=0;
    while(p->topo != NULL && p->topo->info != valor){
        push (controle, pop(p)); 
        manobras++;
               
    }
    if(p->topo == NULL){
        while(controle->topo!=NULL){
            push(p, pop(controle));
        }
        printf("\nNao existe a placa %d", valor);
        return 0;
    }
    pop(p);


    while (controle->topo !=NULL){
        push(p, pop(controle));
    }
    printf("\nManobras feitas: %d", manobras);
    return valor;

}

void printarestacionamento(Pilha *p){
    No* aux = p->topo;

    while (aux!=NULL){

        printf("\n%d", aux->info);
        aux = aux->prox;
    }
}

int main () {
    Pilha* estacionamento = (Pilha*) malloc(sizeof(Pilha));
    Pilha* manobras = (Pilha*) malloc(sizeof(Pilha));
    estacionamento->topo = NULL;
    manobras->topo = NULL;
    int remover = 202;

    push (estacionamento, 101);
    push (estacionamento, 202);
    push (estacionamento, 303);
    push (estacionamento, 404);
    printarestacionamento(estacionamento);
    int qualRemoveu = controle (estacionamento,remover, manobras);
    if (qualRemoveu!=0){
        printf("\nO vaiculo %d foi removido\n", qualRemoveu);
        printarestacionamento(estacionamento);
    }

}

