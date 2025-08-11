#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int nota1, nota2, nota3, media;

    printf("Nota 1: ");
    scanf("%d", &nota1);

    printf("Nota 2: ");
    scanf("%d", &nota2);

    printf("Nota 3: ");
    scanf("%d", &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    printf("Media: %d\n" , media);

    if (media >= 7){
        printf("Aprovado");
    }
    else if (media >= 3){
        printf("Prova Final");
    }else{
        printf("Reprovado!");
    }


    return 0;
}