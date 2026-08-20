#include <stdlib.h>
#include <stdio.h>




typedef struct No {
 int info;
 struct No *prox;

} No;

typedef struct lista {
    No *inicio;

} Lista;

Lista* CriarLista() {
    Lista *aux = (Lista*) malloc (sizeof(Lista));

    aux->inicio = NULL;
    return aux;
}

void printarLista (Lista *l) {
    No *p = l->inicio;
    while (p != NULL) {
        printf("%d  ", p->info);
        p = p->prox;
    }
}

int elementosPares (Lista *L) {
    No *Ler = L->inicio;
    int pares = 0;
    while (Ler != NULL) {
        if (Ler->info % 2 == 0) {
            pares++;
        }
        Ler = Ler->prox;
    }
    printf("\nA lista possui %d elementos pares.", pares);

return pares;
}


void remover (Lista *L, int v) {
No *ant = NULL;
No *p = L->inicio;
    while (p!=NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }
    if (p!=NULL){
    if (ant == NULL){
    L->inicio = p->prox;
    }else {
    ant->prox = p->prox;
    }
    }

}

void inserirLista (Lista *L, int valor){
    Lista *aux;
    No *novo = (No*) malloc(sizeof(No));
    aux->inicio = L->inicio;
    novo->info = valor;
    L->inicio = novo;
    novo->prox = aux->inicio;
}


int main () {
    int choice;
    int valor, pares;
    Lista *minhalista = CriarLista();

    for (;;){
                printf("\nOque o senhor quer fazer?\n");
    printf("1- Inserir coisa na lista.\n2- Printar a lista.\n3- Ver quantos pares tem na lista.\n4- Remover algum VALOR da lista.\n");
    scanf("%d", &choice);
        switch (choice){
    case 1:

        printf("\nDigite o valor que quer adicionar na lista:\n");
        scanf("%d", &valor);
        inserirLista(minhalista, valor);
        system("cls");
        break;
    case 2:
        printarLista(minhalista);
        system("Pause");
        system("cls");
        break;
    case 3:
        elementosPares(minhalista);
        system("Pause");
        system("cls");
        break;
    case 4:
        printf("\nDigite o valor que quer remover na lista:\n");
        scanf("%d", &valor);
        remover(minhalista, valor);
        system("cls");
        break;
    default:

            printf("\nINVALIDO\n\n\n\n");

    }
    }


}
