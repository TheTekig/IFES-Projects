/*

6 - Faça agora o contrário, de Fahrenheit para Celsius. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(){

    int celcius;
    float fahrenheit;

    printf("Coloque a temperatura em graus Celcius para converter em Fahrenheit");
    printf("\nFahrenheit: ");
    scanf("%f", &fahrenheit);

    celcius = (int)(fahrenheit - 32) / 1.8;
    //celcius = (float)(9 * celcius + 160) / 5;
    printf("Celcius:  %d", celcius);

    return 0;
}

main();