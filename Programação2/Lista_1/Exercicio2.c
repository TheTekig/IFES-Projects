/*

2 - Uma P.G. (progressão geométrica) fica determinada pela sua razão (q) e pelo primeiro 
termo (a1). Implemente um programa em C que seja capaz de determinar qualquer 
termo de uma P.G., dado a razão e o primeiro termo.
an = a1 x q(n - 1)


*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int a1, n, q, an, expoente;

    printf("Digite o Primeiro termo: ");
    scanf("%d", &a1);

    printf("\nDigite o Número de Termos: ");
    scanf("%d", &n);

    printf("\nDigite a Razão dos Termos: ");
    scanf("%d", &q);

    expoente = n - 1;
    an = a1 * pow(q , expoente);
    printf("P.A = %d,  onde a1 = %d, n = %d e r = %d", an, a1, n, q);

    return 0;
}

int main();
