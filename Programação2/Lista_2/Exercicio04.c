#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int num1;

    printf("Numero : ");
    scanf("%d", &num1);

    if ((num1 % 2) == 0){
        printf("Numero %d é Divisivel por 2\n" , num1);
    }
    if ((num1 % 5) == 0){
        printf("Numero %d é Divisivel por 5\n" , num1);
    }
    if ((num1 % 10) == 0){
        printf("Numero %d é Divisivel por 10\n" , num1);
    }
    if ((num1 % 2) != 0 && (num1 % 5) != 0 && (num1 % 10) != 0){
        printf("Numero %d NÃO é Divisivel por 2, 5 e 10\n" , num1);
    }

    return 0;
}