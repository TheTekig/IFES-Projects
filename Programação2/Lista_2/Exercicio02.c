#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){

    int num1, produto;

    printf("Vamos somar alguns numeros!\n");

    printf("Num 1 - ");
    scanf("%d", &num1);

    if (num1 > 0 ){

        produto = sqrt(num1);

    }else{
        produto = pow(num1, 2);
    }

    printf("O numero depois das operações é igual a %d" , produto);


    return 0;
}