#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){

    int A, B, C, equacao, delta;

    printf("Equacao 2 Grau!\n");

    printf("Num A - ");
    scanf("%d", &A);

    printf("Num B - ");
    scanf("%d", &B);

    printf("Num C - ");
    scanf("%d", &C);

    // 2x2 + 7x + 5 = 0

    delta = pow(B, 2) - 4*A*C;

    if (delta < 0){
        printf("Não há solução real");
    }

    else if (delta = 0){
        printf("Há duas soluções reais iguais");

        if (A > 0){
            printf("Concavidade voltada para cima");
        }
        else if (A = 0){
            printf("Não é uma equação de 2° grau");
        }
        else{
            printf("Concavidade voltada para baixo");
        }
    }
    
    else{
        printf("Há duas soluções reais diferentes");

        if (A > 0){
            printf("Concavidade voltada para cima");
        }
        else if (A = 0){
            printf("Não é uma equação de 2° grau");
        }
        else{
            printf("Concavidade voltada para baixo");
        }
    }





    return 0;
}