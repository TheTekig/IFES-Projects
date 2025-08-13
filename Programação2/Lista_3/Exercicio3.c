#include <stdio.h>
#include <stdlib.h>
                   
int main(){
    int i, num, now, menor=0;
    
    do
    {
        printf("Quantidade de numeros a serem lidos: ");
        scanf("%d", &num);
    } while (num < 0);
    
    for(i = 1; i <= num; i++){
        do{
        printf("Numero %d : ", i);
        scanf("%d", &now);
        } while (now < 0);

        if (now < menor || menor == 0){
          menor = now;
        }
    }
    printf("Menor Número é : %d", menor);
                        
    return 0;
}

