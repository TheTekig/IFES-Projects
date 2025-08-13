#include <stdio.h>
#include <stdlib.h>
                   
int main(){
    
    int inicio, final;

    do{
        printf("Inicio: ");
        scanf("%d", &inicio);
    } while (inicio < 0);      

    do{
        printf("Final: ");
        scanf("%d", &final);
    } while (final < inicio);                      
    
    for (inicio; inicio <= final; inicio++){
        if((inicio % 2) == 0){
            printf("%d\n", inicio);
        }
    }
                   
    return 0;
}