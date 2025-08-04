/*

7 - Criar um programa em Linguagem C que leia dois valores para as variáveis A e B, que
efetue a troca dos valores de forma que a variável A passe a ter o valor da variável B e que
a variável B passe a ter o valor da variável A. Apresente os valores trocados.

*/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(){

    int a, b, trocar;

    printf("Variavel a: ");
    scanf("%d", &a);

    printf("Variavel b: ");
    scanf("%d", &b);

    trocar = a;
    a = b;
    b = trocar;

    printf("Variavel a = %d , Variavel b = %d", a, b);

    return 0;
}

main();