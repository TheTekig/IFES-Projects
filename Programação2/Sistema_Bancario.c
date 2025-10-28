#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

MAX = 100;

#pragma region Structs

typedef struct Cliente
{
    char nome[100];
    char telefone[15];
    char email[100];
}Cliente;

typedef struct Conta
{
    char numero[11];
    float saldo;
    Cliente cliente;
}Conta;

#pragma endregion

#pragma region Funções do Menu

void inserirConta(Conta conta, int *tamanho) {
    // Função para inserir uma nova conta
    Conta cliente;

	cliente = getDados();
}

int pesquisarPorConta(char valor, Conta *conta, int *tamanho) {

    // Função para pesquisar conta por número
	
	for(int i = 0; i < *tamanho; i++) {
		if(strcmp(conta[i].numero, &valor) == 0) {
			return i; // Conta encontrada
		}
	}

	return -1; // Conta não encontrada
}

void pesquisarPorNome(char valor, Conta conta, int *tamanho) {
    // Função para pesquisar conta por nome do cliente

}

void atualizarConta(char valor, Conta conta, int *tamanho) {
    // Função para atualizar dados da conta
}

void maiorSaldo(Conta conta, int *tamanho) {
    // Função para encontrar a conta com maior saldo
}

void excluirConta(char valor, Conta conta, int *tamanho) {
    // Função para excluir uma conta
}

void listarContas(Conta conta, int *tamanho) {
    // Função para listar todas as contas
}


#pragma endregion

#pragma region Funções Auxiliares

Conta getDados() {
    // Função para obter dados iniciais (se necessário)
	Conta novaConta;

	printf("Obtendo dados para criação da conta\n");
	
	printf("Digite o nome do cliente: ");
	fgets(novaConta.cliente.nome, sizeof(novaConta.cliente.nome), stdin); 
	
	printf("Digite o telefone do cliente: ");
	fgets(novaConta.cliente.telefone, sizeof(novaConta.cliente.telefone), stdin);
	
	printf("Digite o email do cliente: ");
	fgets(novaConta.cliente.email, sizeof(novaConta.cliente.email), stdin);

	printf("Digite o saldo inicial da conta: ");
	scanf("%f", &novaConta.saldo);

	printf("Gerando número de conta...\n");
	strcpy(novaConta.numero, geradorDeNumeroConta());

	printf("Conta criada com sucesso!\n");

	return novaConta;
}

void imprimirDados() {
	// Função para imprimir dados (se necessário)
}

int pesquisar(){
	// Função para pesquisar (se necessário)

	return 0;
}

char geradorDeNumeroConta() {
	// Função para gerar número de conta único
	int numero_de_digitos = 11;
	for (int i = 0; i < numero_de_digitos; i++) {
		// Gera cada dígito do número da conta
		
		int numero = rand() % 10; // Gera um número aleatório de 10 dígitos
		char numeroStr = '0' + numero;
		
	}
	return numeroStr;
}

#pragma endregion

#pragma region Validações



int menu() {
	int op;
	system("@cls||clear");  // LIMPA A TELA
	printf("\n\nSISTEMA BANCARIO\n\n");
	printf("1 - Inserir Conta\n");
	printf("2 - Pesquisar por conta\n");
	printf("3 - Pesquisar por nome\n");
	printf("4 - Atualizar\n");
	printf("5 - Maior Saldo\n");
	printf("6 - Excluir conta\n");
	printf("7 - Listar\n");
	printf("0 - Sair\n");
	do {
		printf("Escolha sua opção: ");
		scanf(" %d", &op);
	} while(op < 0 || op > 7);
	return op;
}

#pragma endregion

int main() {
	srand(time(NULL));
	Conta conta[MAX];
	int tamanho = 0;
	int op;
	
	do {
		op = menu();
		switch ( op ) {
			case 0:
				// SAIR. NÃO PRECISA FAZER NADA
				break;
			case 1:
				// INSERIR
				break;
			case 2:
				// PESQUISAR POR CODIGO/MATRICULA
				break;
			case 3:
				// PESQUISAR POR NOME
				break;
			case 4:
				// ATUALIZAR
				break;
			case 5:
				// MAIOR
				break;
			case 6:
				// EXCLUIR
				break;
			case 7:
				// LISTAR
				break;
			default:
				printf ("\n\nOpçãoo inválida!\n\n");
		}

		system("PAUSE");  // Windows
	} while (op != 0);
	
	return 0;
}