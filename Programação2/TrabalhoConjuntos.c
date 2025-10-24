#include <stdio.h>
#include <stdlib.h>

int pesquisar(int valor, int conjunto[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(conjunto[i] == valor){
            return 1; // Valor encontrado
        }
    }
    return 0; // Valor nao encontrado
}

int inserir(int valor, int conjunto[], int *tamanho){
    if(!pesquisar(valor, conjunto, *tamanho)){      // Verifica se ja existe
        conjunto[*tamanho] = valor;
        (*tamanho)++;
        return 1; // Inserido com sucesso
    }
    return 0; // Valor ja existe
}

int remover(int valor, int conjunto[], int *tamanho){
    for(int i = 0; i < *tamanho; i++){
        if(conjunto[i] == valor){
            conjunto[i] = conjunto[*tamanho - 1]; // Substitui pelo ultimo elemento
            (*tamanho)--;
            return 1; // Removido com sucesso
        }
    }
    return 0; // Valor nao encontrado
}

int listar(int conjunto[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", conjunto[i]);
    }
    printf("\n");
    return 1; // Listado com sucesso
}

void unir(int conjunto1[], int tamanho1, int conjunto2[], int tamanho2, int conjunto3[], int *tamanho3){
    for(int i = 0; i < tamanho1; i++){
        inserir(conjunto1[i], conjunto3, tamanho3); // Insere todos os elementos do primeiro conjunto no terceiro
    }
    for(int i = 0; i < tamanho2; i++){
        inserir(conjunto2[i], conjunto3, tamanho3); // Insere todos os elementos do segundo conjunto no terceiro
    }
}

void intersectar(int conjunto1[], int tamanho1, int conjunto2[], int tamanho2, int conjunto3[], int *tamanho3){
    for(int i = 0; i < tamanho1; i++){
        if(pesquisar(conjunto1[i], conjunto2, tamanho2)){ // Se estiver no segundo conjunto / Para cada elemento do primeiro conjunto vai fazer a pesquisa no segundo
            inserir(conjunto1[i], conjunto3, tamanho3); // Insere no terceiro conjunto
        }
    }
}

void diferenciar(int conjunto1[], int tamanho1, int conjunto2[], int tamanho2, int conjunto3[], int *tamanho3){
    for(int i = 0; i < tamanho1; i++){
        if(!pesquisar(conjunto1[i], conjunto2, tamanho2)){ // Se nao estiver no segundo conjunto / Para cada elemento do primeiro conjunto vai fazer a pesquisa no segundo
            inserir(conjunto1[i], conjunto3, tamanho3);
        }
    }
}

void diferenciarSimetrico(int conjunto1[], int tamanho1, int conjunto2[], int tamanho2, int conjunto3[], int *tamanho3){
    diferenciar(conjunto1, tamanho1, conjunto2, tamanho2, conjunto3, tamanho3); // (A - B)
    diferenciar(conjunto2, tamanho2, conjunto1, tamanho1, conjunto3, tamanho3); // (B - A)
}

void produtoCartesiano(int conjunto1[], int tamanho1, int conjunto2[], int tamanho2){
    for(int i = 0; i < tamanho1; i++){ // Para cada elemento do primeiro conjunto
        for(int j = 0; j < tamanho2; j++){ // Para cada elemento do primeiro conjunto, percorre todo o segundo conjunto
            printf("(%d, %d) ", conjunto1[i], conjunto2[j]); // Imprime o par ordenado
        }
    }
    printf("\n");
}

/*

OBSERVAÇÕES SOBRE AS FUNÇÕES ACIMA:

-Tentei utilizar um terceiro conjunto para as operacoes entre os conjuntos 1 e 2 para evitar modificar os conjuntos originais, e
zerar o tamanho do conjunto 3 antes de cada operacao para evitar que qualquer resultado anterior modifique o resultado ou acumule no conjunto 3.

-Re-utilizei a funcao de pesquisa em praticamente todas as funcoes para poder verificar se o elemento ja existe ou nao no conjunto tentando simular mais ou menos o 
in e out de um set em python, e a funcao inserir e utilizado para adicionar em todos os conjuntos, acabei nao colocando uma funcao para limpar os conjuntos, para limpar
ou voce pode remover os elementos um a um ou re-inicia o codigo.

-A funcao listar retorna um int apenas para manter o padrao das outras funcoes, mas poderia ser void.

-No tamanho dos conjuntos, coloquei 100 para os conjuntos 1 e 2 e 200 para o conjunto 3 para garantir que o conjunto 3 sempre tenha espaco suficiente para todas as operacoes.

-No produto cartesiano eu nao utilizei o conjunto 3, achei que seria meio trabalhoso armazenar todos os pares ordenados em um array (No python eu fiz coloquei tuplas dentro de uma lista mas nao se tem algo similar em C), entao apenas imprimi direto na funcao.

-As funcoes retornam 1 ou 0 para indicar sucesso ou falha, esta agindo como se fosse um booleano.

-Acabei nao colocando validacoes se oque foi digitado e uma letra ou um numero mas poderia ser feito com funcoes como isdigit() com um loop para cada carctere da string, mas achei que fugiria um pouco do escopo do trabalho, por isso por favor nao digite uma letra onde se pede numeros!

-Eu acabei meio que "traduzindo" o que eu fiz em python no trabalho do Max para C, entao acho que acabei utilizando as principais operacoes de conjuntos que ele pediu.

*/

int main(){
    int valor, conjunto1[100], conjunto2[100], conjunto3[200]; // Conjunto 3 para operacoes entre os conjuntos 1 e 2
    int tamanho1=0, tamanho2=0, tamanho3=0; // Tamanhos iniciais dos conjuntos
    int opcao, conjuntoEscolhido; // Opcao do menu e conjunto escolhido para operacoes

    do{

        //       MENU

        printf("Menu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Listar conjunto\n");
        printf("4. Uniao de conjuntos\n");
        printf("5. Intersecao de conjuntos\n");
        printf("6. Diferenca de conjuntos\n");
        printf("7. Diferenca simetrica de conjuntos\n");
        printf("8. Produto cartesiano de conjuntos\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        //      FIM DO MENU

        //    ESCOLHA DO CONJUNTO
        if(opcao >= 1 && opcao <= 3){
            printf("Escolha o conjunto (1 ou 2): ");
            scanf("%d", &conjuntoEscolhido);
            if(conjuntoEscolhido != 1 && conjuntoEscolhido != 2){
                printf("Conjunto invalido!\n");
                continue;
            }
        }

        switch(opcao){

            case 1: // Inserir elemento

                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                if(conjuntoEscolhido == 1){
                    if(inserir(valor, conjunto1, &tamanho1)){
                        printf("Valor inserido no conjunto 1.\n");
                    } else {
                        printf("Valor ja existe no conjunto 1.\n");
                    }
                } else {
                    if(inserir(valor, conjunto2, &tamanho2)){
                        printf("Valor inserido no conjunto 2.\n");
                    } else {
                        printf("Valor ja existe no conjunto 2.\n");
                    }
                }
                break;

            case 2: // Remover elemento

                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                if(conjuntoEscolhido == 1){
                    if(remover(valor, conjunto1, &tamanho1)){
                        printf("Valor removido do conjunto 1.\n");
                    } else {
                        printf("Valor nao encontrado no conjunto 1.\n");
                    }
                } else {
                    if(remover(valor, conjunto2, &tamanho2)){
                        printf("Valor removido do conjunto 2.\n");
                    } else {
                        printf("Valor nao encontrado no conjunto 2.\n");
                    }
                }
                break;

            case 3: // Listar conjunto

                if(conjuntoEscolhido == 1){
                    printf("Conjunto 1: ");
                    listar(conjunto1, tamanho1);
                } else {
                    printf("Conjunto 2: ");
                    listar(conjunto2, tamanho2);
                }
                break;
            
            case 4: // Uniao dos conjuntos

                tamanho3 = 0;
                unir(conjunto1, tamanho1, conjunto2, tamanho2, conjunto3, &tamanho3);
                printf("Uniao dos conjuntos: ");
                listar(conjunto3, tamanho3);
                break;

            case 5: // Intersecao dos conjuntos

                tamanho3 = 0;
                intersectar(conjunto1, tamanho1, conjunto2, tamanho2, conjunto3, &tamanho3);
                printf("Intersecao dos conjuntos: ");
                listar(conjunto3, tamanho3);
                break;

            case 6: // Diferenca dos conjuntos (1 - 2)

                tamanho3 = 0;
                diferenciar(conjunto1, tamanho1, conjunto2, tamanho2, conjunto3, &tamanho3);
                printf("Diferenca dos conjuntos (1 - 2): ");
                listar(conjunto3, tamanho3);
                break;

            case 7: // Diferenca simetrica dos conjuntos

                tamanho3 = 0;
                diferenciarSimetrico(conjunto1, tamanho1, conjunto2, tamanho2, conjunto3, &tamanho3);
                printf("Diferenca simetrica dos conjuntos: ");
                listar(conjunto3, tamanho3);
                break;

            case 8: // Produto cartesiano dos conjuntos

                printf("Produto cartesiano dos conjuntos:\n");
                produtoCartesiano(conjunto1, tamanho1, conjunto2, tamanho2);
                break;

            case 9: 

                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;

}
    } while(opcao != 9);
    return 0;
}

