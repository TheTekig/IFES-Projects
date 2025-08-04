/*

8 - Para vários tributos, a base de cálculo é o salário mínimo. Fazer um programa em
Linguagem C que leia o valor do salário mínimo e o valor do salário de uma pessoa. 
Calcular e imprimir quantos salários mínimos essa pessoa ganha.

*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(){

    float salariominimo, salario, qtd_salarios;

    printf("Quantos Salarios Minimos voce recebe!");
    printf("\nSeu Salario: ");
    scanf("%f", &salario);

    salariominimo = 1518;
    qtd_salarios = (float) salario / salariominimo;

    printf("Você Recebe %.1f Salarios Minimos!", qtd_salarios);

    return 0;
}

