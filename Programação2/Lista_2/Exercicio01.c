#include <stdlib.h>
#include <stdio.h>

int main(){

    int num1, num2, soma;

    printf("Vamos somar alguns numeros!\n");

    printf("Num 1 - ");
    scanf("%d", &num1);

    printf("Num 2 - ");
    scanf("%d", &num2);

    soma = num1 + num2;

    if (soma > 20){

        soma += 8;

    }else{
        soma -= 5;
        
    }

    printf("O numero depois das operações é igual a %d" , soma);


    return 0;
}