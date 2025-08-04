/*

3 - Em épocas de pouco dinheiro, os comerciantes estão procurando aumentar suas
vendas oferecendo desconto. Faça um programa em C que possa entrar com o valor de 
um produto e imprima o novo valor tendo em vista que o desconto foi de 9%. Além disso, 
imprima o valor do desconto

*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(){
    SetConsoleOutputCP(65001);

    float valproduto, valdesconto, valtotal, desconto;

    printf("Valor do Produto: ");
    scanf("%f" , &valproduto);

    desconto = (float) 9 / 100;
    valdesconto = (desconto * valproduto);
    valtotal = valproduto - valdesconto;

    printf("Produto com Desconto: R$%.2f -=- R$%.2f", valtotal, valdesconto);

    return 0;
}

main();