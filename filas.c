    #include <stdio.h>
    #include <stdlib.h>
    #include "filas.h"


void colocarcoisas(Fila* Fila1) {
    int v;
    int controle = 0;
   do{
        printf("\nQuer adicionar um valor a fila? s - 0 n - 1 \n");
        scanf("%d", &controle);
        system("cls");

        if (controle!=1){
            printf("\nQual valor quer adicionar? \n");
            scanf("%d", &v);
            InsereFila(Fila1, v);

        }
   }while (controle!=1);
}


    int main() {
    Fila* Fila1 = CriaFila();
    Fila* FilaImp = CriaFila();
    Fila* FilaPar = CriaFila();
    Pilha* Maiorq20 = CriaPilha();
    Pilha* Menorq20 = CriaPilha();
    int aux;
    for (;;){
        printf("\nO que quer fazer?\n");
        printf("\n 1- Trnsformar uma fila em duas com separacao entre impares e pares.");
        printf("\n 2- Inverter uma fila dada");
        printf("\n 3- Colocar a fila numa pilha.");
        scanf("%d", &aux);
    switch (aux){
case 1:
    colocarcoisas(Fila1);
    printf("\nA fila criada foi:\n");
    imprimeFila (Fila1);
    system("Pause >nul");
    SepararFilas(Fila1, FilaImp, FilaPar);
    system("cls");
    printf("\nA fila somente com os pares eh: \n");
    imprimeFila(FilaPar);
    printf("\nA fila somente com os impares eh:\n");
    imprimeFila(FilaImp);
    system("Pause");
    system("cls");
    break;
case 2:
    colocarcoisas(Fila1);
    printf("\nA fila criada foi:\n");
    imprimeFila (Fila1);
    system("Pause >nul");
    inverterFila(Fila1);
    printf("\nA fila invertida eh:\n");
    imprimeFila (Fila1);
    break;

case 3:
    colocarcoisas(Fila1);
    colocarfilhanapilha(Fila1, Maiorq20, Menorq20);
    system("Pause >nul");
    printf("\nA pilha com valores maiores que 20 eh:\n");
    imprime(Maiorq20);
    printf("\nA pilha com valores menores que 20 eh:\n");
    imprime(Menorq20);
    break;


    } // fim switch
    } //fim do for






return 0;
    }
