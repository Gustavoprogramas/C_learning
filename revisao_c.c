#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main () {
    int choice, condicaosaida;

    printf("\nQual exercicio deseja realizar?");
    scanf("%d", &choice);
 for (;;) {
         if (condicaosaida == 0){
                 switch (choice){

    case 0:
        printf("\nQual exercicio deseja realizar?");
    scanf("%d", &choice);
    break;
        case 1:
//Uma empresa contrata um encanador a R$ 30,00 por dia. Faça um programa que solicite o número de dias trabalhados pelo encanador e imprima a quantia líquida que deverá ser paga, sabendo-se que são descontados 8% para imposto de renda.
    float salario = 30;
    float imposto = 0.08;
    int dias;
    do {
    printf("\nQuantos dias o encanador vai trabalhar?\n");
    scanf("%d", &dias);
    if (dias == 1){
        printf("\nSe ele trabalhar apenas um dia ele vai receber apenas R$28.60!");
        printf("\nDigite uma quantidade maior do que 1 dia!");
    }
    if (dias <= 0) {
        printf("\nDigite uma quantidade valida de dias!");
    }
    }while(dias <= 1);

    salario = salario * dias;
    salario = salario + (salario * imposto);
    printf("\nTrabalhando %d dias, o encanador vai receber R$%.2f.", dias, salario);
    choice = 0;
        break;
        case 2:
//Faça um programa que: - Leia a cotação do dólar- Leia um valor em dólares- Converta esse valor para Real (consulte a cotação atualdo dólar na Internet)- Mostre o resultado

                float valoremdolar, valoremreal;
                float cotacaodolar = 5.12;
                printf("\nQuantos dolares voce possui?\n");
                scanf("%f", &valoremdolar);
                valoremreal = valoremdolar * cotacaodolar;
                printf("\nJa que a cotacao do dolar para real esta em R$%.2f\nVoce possui R$%.2f com U$%.2f.", cotacaodolar, valoremreal, valoremdolar);
                choice = 0;
            break;
        case 3:
//Leia uma velocidade em km/h (quilômetros por hora)e apresente-a convertida em m/s(metros por segundo).A fórmula de conversão é: M = K/3.6, sendo K avelocidade em km/h e M em m/s.
            float velocidade;
            printf ("\nQual sua velocidade em km/h?\n");
            scanf("%f", &velocidade);
            printf("\nNuma velocidade de %.2f KM/h, ", velocidade);
            velocidade = velocidade / 3.6;
            printf("voce esta apenas a %.2f M/s.", velocidade);
            choice = 0;
            break;
        case 4:
//Receba a altura do degrau de uma escada e a altura que o usuário deseja alcançar subindo a escada .Calcule e mostre quantos degraus o usuário devera subir para atingir seu objetivo.
        float alturadegrau, alturadesejada;

        do {
                    printf("\nQual a altura de cada degrau?\n");
        scanf("%f", &alturadegrau);
        printf("\nQual a altura que deseja subir?\n");
        scanf("%f", &alturadesejada);
        if (alturadegrau > alturadesejada) {
            printf("\nEscreva uma condicao valida!");
        }
        }while (alturadegrau > alturadesejada);

        alturadesejada = alturadesejada / alturadegrau;
        if (alturadesejada == 1) {
            printf("\nApenas precisara de 1 degrau para subir isso!");
        } else

        {

            printf("\nVoce precisa subir %.0f degraus para atingir a altura desejada!", alturadesejada);
        }

        choice = 0;
            break;

        case 5:
//Faça um programa para ler as dimensões de um terreno (comprimento c e largura l), bem como o preço do metro de tela p. Imprima o custo para cercar este mesmo terreno com tela.
        float dimensoes, custo;
        printf("\nQual o comprimento do terreno?\n");
        scanf("%f", &dimensoes);
        printf("\nQual a largura do terreno?\n");
        scanf("%f", &custo);
        dimensoes = (dimensoes * 2) + (custo * 2);
        printf("\nQual o custo do metro da tela?\n");
        scanf("%f", &custo);
        custo = dimensoes * custo;
        printf("\nPara cercar este terreno voce tera um custo de R$%.2f.", custo);
        choice = 0;
            break;


        case 6:
//Faça um programa que leia um número inteiro positivo de três dígitos (de 100 a 999). Gere outro número formado pelos dígitos invertidos do número lido. Exemplo: Número lido: 123 Número Gerado:32
            int n, casa1, casa2;
            do {
            printf("\nDigite um numero de 3 digitos.\n");
            scanf("%d", &n);
            }while (n > 1000 || n < 100);
            casa1 = (n % 10) * 100; // 001 -> 100
            casa2 = ((n / 10) % 10) * 10; // 010 -> 010
            n = n / 100;
            n = casa1 + casa2 + n;
            printf("\nInvertendo, voce obtem: %d.", n);
            break;
            choice = 0;
        case 7:
//Crie um algoritmo que leia dois valores (x e y) representando um intervalo. Em seguida, leia um novo valor (z) e verifique se z pertence ao intervalo [x, y]
        int x, y, z, maior, menor;
        printf("\nDigite o valor de x.\n");
        scanf("%d", &x);
        printf("\nDigite o valor de y.\n");
        scanf("%d", &y);
        printf("\nDigite o valor de z.\n");
        scanf("%d", &z);
        if (x > y) {
            maior = x;
            menor = y;
        }else {
            maior = y;
            menor = x;
        }
        if (z > menor && z < maior) {
            printf("\nZ se encontra no intervalo entre x e y.");
        }else {
            printf("\nZ nao se encontra no intervalo entre x e y.");
        }
        choice = 0;

            break;
        case 8:


            break;
        default:
            condicaosaida = 1;
            }
    }else {
    printf("\nVoce escolheu sair.");
    break;
    }
 }






 }





