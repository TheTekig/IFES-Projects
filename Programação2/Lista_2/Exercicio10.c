#include <stdlib.h>
#include <stdio.h>

int main(){

    int num1;

    printf("Vamos ver o DIA DA SEMANA\n");

    printf("Numero do Dia da Semana : ");
    scanf("%d", &num1);

    switch (num1)
    {
    case 1:
        printf("Domingo");
        break;
    case 2:
        printf("Segunda");
        break;
    case 3:
        printf("Terça");
        break;
    case 4:
        printf("Quarta");
        break;
    case 5:
        printf("Quinta");
        break;
    case 6:
        printf("Sexta");
        break;
    case 7:
        printf("Sabado");
        break;
    
    default:
        printf("Valor Invalido!");
        break;
    }

    return 0;
}