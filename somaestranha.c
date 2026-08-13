#include <stdio.h>
#include <stdlib.h>

int main () {
    float num1=1 , num2=3, soma = 0, n;

    while (num1<21) {
        soma = num1/num2 + soma;
        num2 = num2 + 2;
        num1++;


    }
    printf("%f", soma);
}
