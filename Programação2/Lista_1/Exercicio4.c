/*

4 - Refaça a questão anterior agora com o desconto sendo informado como entrada para o
algoritmo.

*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(){
    SetConsoleOutputCP(65001);

    float valproduto, valdesconto, valtotal, desconto;

    printf("Valor do Produto: ");
    scanf("%f" , &valproduto);

    printf("Valor do Desconto: ");
    scanf("%f", &desconto);

    desconto = (float) desconto / 100;
    valdesconto = (desconto * valproduto);
    valtotal = valproduto - valdesconto;

    printf("Produto com Desconto: R$%.2f -=- R$%.2f", valtotal, valdesconto);

    return 0;
}

main();