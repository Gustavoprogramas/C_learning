#include <stdio.h>
#include <stdlib.h>

int main () {
    int n, bin1, bin2 = 0, seila;
    int controle = 1;
    printf("Digite o inteiro em decimal:\n");
    scanf("%d", &n);
    seila = n;
    while (n > 0){
        bin1 = n % 2;
        n = n / 2;
        bin1 = bin1 * controle;
        bin2 += bin1;
        controle *= 10;

    }
    printf("\n%d em binario e igual a %d", seila, bin2);



}
