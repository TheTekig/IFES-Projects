#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX 100

#pragma region Structs

typedef struct Cliente {
    char nome[100];
    char telefone[15];
    char email[100];
} Cliente;

typedef struct Conta {
    char numero[11];
    float saldo;
    Cliente cliente;
} Conta;

#pragma endregion

void salvarContas(Conta *contas, int tamanho){
    FILE *file = fopen("contas.txt", "w");
if (!file){
    printf("Erro ao abrir o arquivo!\n");
    return;
}
for (int i = 0; i < tamanho; i++) {
    fprintf(file, "%s;%s;%s;%s;%.2f\n", 
        contas[i].numero,
        contas[i].cliente.nome,
        contas[i].cliente.telefone,
        contas[i].cliente.email,
        contas[i].saldo);
}
fclose(file);
printf("Contas Salvas com Sucesso!\n");
}

int carregarContas(Conta *contas){
    FILE *file = fopen("contas.txt", "r");
    if (!file){
        printf("Nenhum arquivo encontrado, iniciando vazio.\n");
        return 0;
    }
    int count = 0;
    while (fscanf(file, "%10[^;];%99[^;];%14[^;];%99[^;];%f\n",
                  contas[count].numero,
                  contas[count].cliente.nome,
                  contas[count].cliente.telefone,
                  contas[count].cliente.email,
                  &contas[count].saldo) == 5) {
        count++;
    }
    fclose(file);
    printf("%d contas carregadas do arquivo.\n", count);
    return count;
}
#pragma region Funções Auxiliares

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char *gerarNumeroConta(Conta *contas, int tamanho) {
    static char numero[11];
    int unico;

    do {
        unico = 1;
        for (int i = 0; i < 10; i++) {
            numero[i] = '0' + rand() % 10;
        }
        numero[10] = '\0';

        for (int i = 0; i < tamanho; i++) {
            if (strcmp(contas[i].numero, numero) == 0) {
                unico = 0;
                break;
            }
        }
    } while (!unico);

    return numero;
}

Conta getDados(Conta *contas, int tamanho) {
    Conta nova;

    limparBuffer();
    do {

    printf("Digite o nome do cliente: ");
    fgets(nova.cliente.nome, sizeof(nova.cliente.nome), stdin);
    nova.cliente.nome[strcspn(nova.cliente.nome, "\n")] = '\0';

    } while (!validarNome(nova.cliente.nome));

    do{
    printf("Digite o telefone: ");
    fgets(nova.cliente.telefone, sizeof(nova.cliente.telefone), stdin);
    nova.cliente.telefone[strcspn(nova.cliente.telefone, "\n")] = '\0';
    } while (!validarTelefone(nova.cliente.telefone));

    do{
    printf("Digite o email: ");
    fgets(nova.cliente.email, sizeof(nova.cliente.email), stdin);
    nova.cliente.email[strcspn(nova.cliente.email, "\n")] = '\0';
    } while (!validarEmail(nova.cliente.email));

    nova.saldo = 0;

    strcpy(nova.numero, gerarNumeroConta(contas, tamanho));

    printf("Conta gerada: %s\n", nova.numero);

    return nova;
}

int pesquisarPorConta(char *valor, Conta *contas, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(contas[i].numero, valor) == 0) {
            return i;
        }
    }
    return -1;
}

int pesquisarPorNome(char *valor, Conta *contas, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(contas[i].cliente.nome, valor) == 0) {
            return i;
        }
    }
    return -1;
}

#pragma endregion

#pragma region Funções do Menu

void inserirConta(Conta *contas, int *tamanho) {
    if (*tamanho >= MAX) {
        printf("Limite máximo de contas atingido!\n");
        return;
    }
    contas[*tamanho] = getDados(contas, *tamanho);
    (*tamanho)++;
    printf("Conta criada com sucesso!\n");
}

void atualizarConta(Conta *contas, int tamanho) {
    char numero[11];
    printf("Digite o número da conta: ");
    scanf("%s", numero);

    int pos = pesquisarPorConta(numero, contas, tamanho);
    if (pos == -1) {
        printf("Conta não encontrada.\n");
        return;
    }

    int escolha;
    printf("1 - Saque\n2 - Depósito\nEscolha: ");
    scanf("%d", &escolha);

    float valor;
    if (escolha == 1) {
        printf("Valor a sacar: ");
        scanf("%f", &valor);
        if (valor <= contas[pos].saldo) {
            contas[pos].saldo -= valor;
            printf("Saque realizado com sucesso.\n");
        } else {
            printf("Saldo insuficiente.\n");
        }
    } else if (escolha == 2) {
        printf("Valor a depositar: ");
        scanf("%f", &valor);
        contas[pos].saldo += valor;
        printf("Depósito realizado com sucesso.\n");
    } else {
        printf("Opção inválida.\n");
    }
}

void listarContas(Conta *contas, int tamanho) {
    if (tamanho == 0) {
        printf("Nenhuma conta cadastrada.\n");
        return;
    }
    for (int i = 0; i < tamanho; i++) {
        printf("\nConta %d:\n", i + 1);
        printf("Número: %s\n", contas[i].numero);
        printf("Cliente: %s\n", contas[i].cliente.nome);
        printf("Saldo: %.2f\n", contas[i].saldo);
    }
}

void maiorSaldo(Conta *contas, int tamanho) {
    if (tamanho == 0) {
        printf("Nenhuma conta cadastrada.\n");
        return;
    }
    int indiceMaior = 0;
    for (int i = 1; i < tamanho; i++) {
        if (contas[i].saldo > contas[indiceMaior].saldo) {
            indiceMaior = i;
        }
    }
    printf("Conta com maior saldo:\n");
    printf("Número: %s\nCliente: %s\nSaldo: %.2f\n",
           contas[indiceMaior].numero,
           contas[indiceMaior].cliente.nome,
           contas[indiceMaior].saldo);
}

void excluirConta(Conta *contas, int *tamanho) {
    char numero[11];
    printf("Digite o número da conta a ser excluída: ");
    scanf("%s", numero);

    int pos = pesquisarPorConta(numero, contas, *tamanho);
    if (pos == -1) {
        printf("Conta não encontrada.\n");
        return;
    }

    for (int i = pos; i < *tamanho - 1; i++) {
        contas[i] = contas[i + 1];
    }
    (*tamanho)--;
    printf("Conta excluída com sucesso.\n");
}

#pragma endregion

#pragma region Validações

int validarNome(char *nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != '\n')
            return 0; // contém caracteres inválidos
    }
    return strlen(nome) > 1; // nome muito curto também é inválido
}

int validarEmail(char *email) {
    int temArroba = 0, temPonto = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') temArroba = 1;
        if (email[i] == '.' && temArroba) temPonto = 1;
    }
    return temArroba && temPonto;
}

int validarTelefone(char *telefone) {
    int digitos = 0;
    for (int i = 0; telefone[i] != '\0'; i++) {
        if (isdigit(telefone[i])) digitos++;
        else if (telefone[i] != '-' && telefone[i] != ' ' && telefone[i] != '\n' && telefone[i] != '(' && telefone[i] != ')')
            return 0; // caractere inválido
    }
    return digitos >= 8 && digitos <= 13; // aceita (XX)XXXXX-XXXX
}

#pragma endregion

#pragma region Menu

void case3_function(Conta *contas, int *tamanho) {
    // Função para o case 3 do menu
    char nome[100];
    limparBuffer();
    printf("Digite o nome do cliente: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    int pos = pesquisarPorNome(nome, contas, tamanho);
    if (pos == -1) printf("Cliente não encontrado.\n");
    else printf("Conta de %s encontrada: %s - Saldo %.2f\n", contas[pos].cliente.nome, contas[pos].numero, contas[pos].saldo);
}

void case2_function(Conta *contas, int *tamanho) {
    // Função para o case 2 do menu
    char numero[11];
    printf("Digite o número da conta: ");
    scanf("%s", numero);
    int pos = pesquisarPorConta(numero, contas, tamanho);
    if (pos == -1) printf("Conta não encontrada.\n");
    else printf("Conta %s encontrada: Cliente %s - Saldo %.2f\n", contas[pos].numero, contas[pos].cliente.nome, contas[pos].saldo);
}

int menu() {
    int op;
    printf("\n\nSISTEMA BANCÁRIO\n");
    printf("1 - Inserir Conta\n");
    printf("2 - Pesquisar por Número\n");
    printf("3 - Pesquisar por Nome\n");
    printf("4 - Atualizar Conta\n");
    printf("5 - Maior Saldo\n");
    printf("6 - Listar Contas\n");
    printf("7 - Excluir Conta\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &op);
    return op;
}

#pragma endregion

int main() {
    srand(time(NULL));
    Conta contas[MAX];
    int tamanho = 0;
    int op;
    tamanho = carregarContas(contas);
    do {
        op = menu();
        switch (op) {
            case 1:
                inserirConta(contas, &tamanho);
                break;
            case 2: 
                case2_function(contas, &tamanho);
                break;
            case 3: 
                case3_function(contas, &tamanho);
                break;
            case 4:
                atualizarConta(contas, tamanho);
                break;
            case 5:
                maiorSaldo(contas, tamanho);
                break;
            case 6:
                listarContas(contas, tamanho);
                break;
            case 7:
                excluirConta(contas, &tamanho);
                break;
            case 0:
                printf("Saindo...\n");
                salvarContas(contas, tamanho);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (op != 0);

    return 0;
}
