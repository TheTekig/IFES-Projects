/*

9 - Escreva um programa que pergunte a quantidade de km percorridos por um carro alugado 
pelo usuário, assim como a quantidade de dias pelos quais o carro foi alugado. Calcule o 
preço a pagar, sabendo que o carro custa R$ 60,00 por dia e R$ 0,15 por km rodado.

*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(){

    int dias, km;
    float porkm, pordia, valtotal;

    printf("Quantidade de KM percorridos: ");
    scanf("%d", &km);

    printf("Quantidade de Dias: ");
    scanf("%d", &dias);

    porkm = 0.15;
    pordia = 60;
    valtotal = (float)(km * porkm) + (dias * pordia);

    printf("Você ira pagar R$%.2f pelo rentamento do carro!", valtotal);

    return 0;
}
