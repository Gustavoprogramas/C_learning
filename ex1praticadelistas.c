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

void buscar(Lista*L, int v) {
    No *ant = NULL;
    No *p = L->inicio;
    while (p!=NULL && p-> info !=v){
        ant =p;
        p = p->prox;
    }
    if (p!=NULL){
        printf("\nO valor existe na lista!");
        system("pause");
    }else {
        printf("\nO valor nao existe na lista!");
        system("pause");
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
void vazia(Lista *L) {
    No *ant = NULL;
    No *p = L->inicio;
    while (p!=NULL){
        ant = p;
        p = p->prox;
    }
    if (ant==NULL){
        printf("\nSua lista esta vazia!\n");
    }else {
        printf("\nSua lista tem coisa!\n");
    }

system("Pause");

}
void contarelemento(Lista *L){
    int contador = 0;
    No *ant = NULL;
    No* p = L->inicio;
    while(p!=NULL) {
        ant = p;
        p = p->prox;
        if (ant!=NULL){
            contador++;
        }

    }
    printf("\nSua lista possui %d elementos.", contador);

}

void somarcoisas (Lista *L){
    int soma = 0;
    No *ant = NULL;
    No* p = L->inicio;
    while(p!=NULL){
        ant = p;
        p = p->prox;
        if (ant!=NULL){
            soma = soma + ant->info;
        }
    }
    printf("\nA soma dos elementos desta lista eh: %d", soma);



}
void liberarlistas(Lista *Primeira, Lista *Segunda){
    No* atual = Primeira->inicio;
    while (atual!=NULL){
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
        Primeira->inicio = NULL;
        No* atual2 = Segunda->inicio;
    while (atual2!=NULL){
        No *prox = atual2->prox;
        free(atual2);
        atual2 = prox;
    }
    Segunda->inicio = NULL;

}



int main () {
    int choice;
    int valor, pares, select;
    Lista *minhalista = CriarLista();
    Lista *outralista = CriarLista();


    for (;;){
    printf("\nOque o senhor quer fazer?\n");
    printf("1- Inserir coisa na lista.\n2- Remover coisa da lista.\n3- Imprimir a lista.\n4- Ver se tem certo valor na lista.\n5-Ver a quantia de elementos da lista principal.\n6-Ver se tal lista ta ou nao vaiza.\n");
    printf("7- Somar os valores de certa lista.\n");
    scanf("%d", &choice);
        switch (choice){
    case 1:
        printf("\nEm qual lista voce quer mexer? 1 ou 2?\n");
        scanf("%d", &select);
        if (select == 1){
            printf("\nDigite o valor que quer adicionar na lista:\n");
            scanf("%d", &valor);
            inserirLista(minhalista, valor);
        }else if (select == 2){
            printf("\nDigite o valor que quer adicionar na lista:\n");
            scanf("%d", &valor);
            inserirLista(outralista, valor);
        } else {
            printf("\nPode nao man.");
        }

        system("cls");
        break;
    case 2:
        printf("\nEm qual lista voce quer mexer? 1 ou 2?\n");
        scanf("%d", &select);
        if (select == 1){
        printf("\nDigite o valor que quer remover na lista:\n");
        scanf("%d", &valor);
        remover(minhalista, valor);
        system("cls");
        }else if (select == 2){
        printf("\nDigite o valor que quer remover na lista:\n");
        scanf("%d", &valor);
        remover(outralista, valor);
        system("cls");
        }else {
            printf("\nPode nao man.");
        }

        break;
    case 3:
        printf("\nEm qual lista voce quer mexer? 1 ou 2?\n");
        scanf("%d", &select);
        if (select == 1){
        printarLista(minhalista);
        system("Pause");
        system("cls");
        }else if (select == 2){
        printarLista(outralista);
        system("Pause");
        system("cls");
        }else {
            printf("\nPode nao man.");
        }

        break;
    case 4:
        printf("\nEm qual lista voce quer mexer? 1 ou 2?\n");
        scanf("%d", &select);
        if (select == 1){
        printf("\nDigite o valor que quer saber se existe na lista:\n");
        scanf("%d", &valor);
        buscar(minhalista, valor);
        }else if (select == 2){
        printf("\nDigite o valor que quer saber se existe na lista:\n");
        scanf("%d", &valor);
        buscar(outralista, valor);
        }else {
            printf("\nPode nao man.");
        }


        system("cls");
        break;
    case 5:
        printf("\nEm qual lista voce quer mexer? 1 ou 2?\n");
        scanf("%d", &select);
        if (select == 1){
        vazia(minhalista);
        }else if (select == 2){
        vazia(outralista);
        }else {
            printf("\nPode nao man.");
        }



       break;
    case 6:
        int select;
        printf("\nDe qual lista voce quer ver quantos elementos tem?\n");
        scanf("%d", &select);
        if (select==1){
                contarelemento(minhalista);

        }else if(select==2){
            contarelemento(outralista);

        }else {
            printf("\nPode nao man.\n");
        }
        system("Pause");
        break;
    case 7:
        printf("\nEm qual lista voce quer mexer? 1 ou 2?\n");
        scanf("%d", &select);
        if (select == 1){
        somarcoisas(minhalista);
        }else if (select == 2){
        somarcoisas(outralista);
        }else {
            printf("\nPode nao man.");
        }
        break;
    case 8:
        liberarlistas(minhalista, outralista);
        break;
    default:

    printf("\nINVALIDO\n\n\n\n");

    }
    }


}
