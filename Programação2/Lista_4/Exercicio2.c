#include <stdio.h>
#include <stdlib.h>

float quantidade(float valor){
    int qtd;

    do{
        printf("\nQuantidade de Produtos: ");
        scanf("%d", &qtd);
    }while (qtd < 0);
    
    valor = valor * qtd;

    printf("Total a Pagar de Produtos R$%.2f", valor);

    return valor;
}

float acrescimo_desconto(int opcao, float valproduto){
    float acrescimo, desconto;

    if (opcao == 1)
    {
        desconto = (0.1 * valproduto) - valproduto;
        printf("Valor do Produto - R$%.2f", desconto);
        return desconto;
    }
    else
    {
        acrescimo = (0.1 * valproduto) + valproduto;
        printf("Valor do Produto - R$%.2f", acrescimo);
        return acrescimo;
    }
}

float produto(){
    float valproduto;
    do{
        printf("Valor Produto = R$ ");
        scanf("%f", &valproduto);
    }while(valproduto < 0);
    return valproduto;
}

int op(){
    int option;
    
    do{
        printf("OP - ");
        scanf("%d", &option);
    }while (option < 1 || option > 2);
    return option;
}

int main(){
    
    int option;
    float valproduto, valor;
    
    printf("\t-=-PRODUTO-=-\n");
    valproduto = produto();

    printf("\t1 - A Vista\n");
    printf("\t2 - A Prazo\n");
     
    option = op();

    valor = acrescimo_desconto(option, valproduto);

    quantidade(valor);


                   
    return 0;
}