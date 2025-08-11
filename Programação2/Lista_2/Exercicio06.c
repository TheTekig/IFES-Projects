#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int num1;

    printf("IDADE : ");
    scanf("%d", &num1);

    if (num1 > 64){
        printf("eleitor facultativo");
    }
    else if (num1 > 17){
        printf("eleitor obrigatório");
    }
    else if (num1 > 15){
        printf("eleitor facultativo");
    }
    else if(num1 > 0){
        printf("não eleitor");
    }else{
        printf("Idade Invalida!");
    }



    return 0;
}