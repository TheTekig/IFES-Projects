/*

5 - Desenvolva um programa em C que leia uma temperatura em graus centígrados e
apresente a temperatura convertida em graus Fahrenheit. A fórmula de conversão é:
F = (9 x C + 160) / 5
Onde F é a temperatura em Fahrenheit e C é a temperatura em centígrados

*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(){

    int celcius;
    float fahrenheit;

    printf("Coloque a temperatura em graus Celcius para converter em Fahrenheit");
    printf("\nCelcius: ");
    scanf("%d", &celcius);

    fahrenheit = (float)(9 * celcius + 160) / 5;
    printf("Fahrenheit: %.1f", fahrenheit);

    return 0;
}

main();