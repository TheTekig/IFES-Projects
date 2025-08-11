#include <stdlib.h>
#include <stdio.h>

int main(){

   int codigo, qtd;
   float desconto, preco;

   printf("Codigo do Produto: ");
   scanf("%d", &codigo);

   printf("Quantidade de Produtos: ");
   scanf("%d", &qtd);

   if (codigo <= 40){
    preco = 40.00;
   }
   else if (codigo <= 30){
    preco = 20.00;
   }
   else if (codigo <= 20){
    preco = 15.00;
   }
   else if (codigo <= 10){
    preco = 10.00;
   }
   else if (codigo < 1){
    preco = 0;
    printf("Codigo Inesistente ");
   }

   printf("Valor da Unidade = %.2f\n", preco);
   preco = preco * qtd;
   printf("Valor Total do Pedido = $%.2f\n", preco);

   if (preco >= 500){
    desconto = 0.15;
   }
   else if (preco >= 250){
    desconto = 0.10;
   }else{
    desconto = 0.05;
   }

   desconto = preco * desconto;
   preco = preco - desconto;
   
   printf("Valor total com Desconto: $%.2f | Valor do Desconto: $%.2f", preco, desconto);



    return 0;
}