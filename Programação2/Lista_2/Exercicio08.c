#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int X;

    printf("X :");
    scanf("%d", &X);

    if (X <= 1){
        X = 1;
    }
    else if (X <= 2){
        X = 2;
    }
    else if (X <= 3){
        X = pow(X, 2);
    }else{
        X = pow(X, 3);
    }

    printf("F(x) é igual a %d", X);
    
    return 0;
}