#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){

    int A, B, C, D, E, position, i;
    float media;

    printf("Vamos Organizar alguns numeros!\n");

    printf("Num 1 - ");
    scanf("%d", &A);

    printf("Num 2 - ");
    scanf("%d", &B);

    printf("Num 3 - ");
    scanf("%d", &C);

    printf("Num 4 - ");
    scanf("%d", &D);

    printf("Num 5 - ");
    scanf("%d", &E);

    for(i = 0; i < 5; i++){
        if (A < B){
            position = B;
            B = A;
            A = position;
        }
        if (B < C){
            position = C;
            C = B;
            B = position;
        }
        if (C < D){
            position = D;
            D = C;
            C = position;
        }
        if (D < E){
            position = E;
            E = D;
            D = position;
        }
    }


    media = (float) (B + C + D) / 3;
    printf("Ordem: %d - %d - %d - %d - %d\n", A, B, C, D, E);
    printf("Maior Nota :%d, Menor Nota:%d, Media: %.2f", A, E, media);

    return 0;
}