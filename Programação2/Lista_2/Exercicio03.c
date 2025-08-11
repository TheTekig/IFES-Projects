#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){

    int A, B, C, position;

    printf("Vamos Organizar alguns numeros!\n");

    printf("Num 1 - ");
    scanf("%d", &A);

    printf("Num 2 - ");
    scanf("%d", &B);

    printf("Num 3 - ");
    scanf("%d", &C);

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
    if (A < B){
        position = B;
        B = A;
        A = position;
    }

    printf("Posições = %d, %d, %d", A, B, C);

    return 0;
}