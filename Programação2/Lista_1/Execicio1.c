/*

1 - Uma P.A. (progressão aritmética) fica determinada pela sua razão (r) e pelo primeiro
termo(a1). Faça um programa em linguagem C, que seja capaz de determinar qualquer 
termo de uma P.A., dada a razão, o primeiro termo e a quantidade de termos. 
an = a1 + (n-1) x r

*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int a1, n, r, an;

    printf("Digite o Primeiro termo: ");
    scanf("%d", &a1);

    printf("\nDigite o Numero de Termos: ");
    scanf("%d", &n);

    printf("\nDigite a Razao dos Termos: ");
    scanf("%d", &r);

    an = a1 + (n-1) * r;
    printf("P.A = %d,  onde a1 = %d, n = %d e r = %d", an, a1, n, r);
}

main();
