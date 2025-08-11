#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int num1;

    printf("IDADE : ");
    scanf("%d", &num1);

    if (num1 > 64){
        printf("Pessoa Idosa");
    }
    else if (num1 > 17){
        printf("Maior de Idade!");
    }
    else if(num1 > 0){
        printf("Menor de Idade!");
    }else{
        printf("Idade Invalida!");
    }



    return 0;
}