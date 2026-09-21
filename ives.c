#include <stdio.h>
#include <stdlib.h>

typedef struct no {
 int info;
struct no *prox;

}No;
typedef struct pilha {
  No* inicio;
}Pilha;

void auxinsere(Pilha *p, int v){
    No *Insere = p->inicio;

    No *novo = (No*) malloc(sizeof(No));
    novo ->info = v;
    novo->prox = Insere;
    p->inicio = novo;
}
int push (Pilha *p, int v) {
  No *Aux = (No*) malloc (sizeof(No));
    if (p -> inicio == NULL) {
            Aux = p->inicio;
        Aux->info = v;
    }
        auxinsere(p, v);


 return 1;
}
int pop (Pilha *p) {
  if (p->inicio = NULL){
    printf("Pilha vazia burrao.\n");
  }

  int info = p->inicio->info;
  No* novo = (No*) malloc (sizeof(No));
  novo = p->inicio->prox;
  No* aux = p->inicio;
  p->inicio = novo;
  free (aux);

  return info;
}
void inverterpilha (Pilha *p) {
    int aux;
    int arry[10];
    int i=0;
    if (p->inicio ==NULL){
        printf("\nNao da");
    }else
    while (p->inicio!=NULL){
        aux = pop(p);
        i++;
        arry[i] = aux;

    }for (int j=0; j<i; j++){
        push (p, arry[j]);
    }

}


void print(Pilha *p){
    No* aux = p->inicio;
    printf("cu");
    while (aux!=NULL){
            printf("cu2");
        printf("\n%d", aux->info);
        aux = aux->prox;
    }
}





int main() {
    Pilha *p = (Pilha*) malloc (sizeof(Pilha));
    p->inicio = NULL;
    push (p, 1);
    push (p, 2);
    push (p, 3);
    print(p);
    inverterpilha(p);
    print(p);
}
