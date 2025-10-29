#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // Para INT_MAX

// Constantes baseadas nos dados de entrada
#define NUM_CIDADES 30
#define MAX_NAME_LEN 100

// --- Estruturas de Dados ---

// Armazena os nomes das cidades
char g_cidades[NUM_CIDADES][MAX_NAME_LEN];

// Armazena a matriz de adjacência (distâncias)
float g_adj_matrix[NUM_CIDADES][NUM_CIDADES];

// --- Protótipos das Funções ---
void ler_arquivo_dados(const char* nome_arquivo);
void encontrar_mais_vizinhos();
void encontrar_menos_vizinhos();
void encontrar_vizinho_mais_distante();
void encontrar_vizinho_mais_proximo();
int get_cidade_index(const char* nome_cidade);
void encontrar_distancia_entre_cidades();

/**
 * Função principal: Carrega os dados e chama as funções para responder
 * a cada uma das perguntas.
 */

int main() {
    // Carrega os dados do arquivo "30.txt" para as variáveis globais
    ler_arquivo_dados("Cidades.txt");

    // Responde às perguntas
    printf("--- Análise da Matriz de Adjacência (%d Cidades) ---\n\n", NUM_CIDADES);

    // 1. Qual cidade possui o maior número de vizinhos?
    encontrar_mais_vizinhos();

    // 2. Qual cidade possui o menor número de vizinhos?
    encontrar_menos_vizinhos();

    // 3. Qual cidade possui o vizinho mais distante?
    encontrar_vizinho_mais_distante();

    // 4. Qual cidade possui o vizinho mais próximo?
    encontrar_vizinho_mais_proximo();

    // 5. Dado os nomes de duas cidades, qual a distância entre elas?
    encontrar_distancia_entre_cidades();

    printf("\n--- Análise Concluída ---\n");
    return 0;
}

/**
 * Lê o arquivo Cidades.txt", processa os nomes das cidades e a matriz de adjacência,
 * e preenche as variáveis globais g_cidades e g_adj_matrix.
 */
void ler_arquivo_dados(const char* nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo Cidades.txt");
        exit(1);
    }

    char buffer[4096]; // Buffer para ler linhas

    // 1. Ler os nomes das 30 cidades
    for (int i = 0; i < NUM_CIDADES; i++) {
        // Lê a linha no formato "index;NomeDaCidade"
        if (fgets(buffer, sizeof(buffer), fp) == NULL) {
             fprintf(stderr, "Erro: Arquivo incompleto ao ler nomes de cidades.\n");
             exit(1);
        }
        // Encontra o delimitador ';'
        char* delimitador = strchr(buffer, ';');
        if (delimitador == NULL) {
            fprintf(stderr, "Erro: Formato de nome de cidade inválido na linha %d.\n", i + 1);
            exit(1);
        }
        
        // Copia o nome (após o ';') para o array
        // (+1 para pular o ';')
        strcpy(g_cidades[i], delimitador + 1);

        // Remove o caractere de nova linha '\n' do final do nome
        g_cidades[i][strcspn(g_cidades[i], "\r\n")] = 0;
    }

    // 2. Ler a matriz de adjacência 30x30
    for (int i = 0; i < NUM_CIDADES; i++) {
        // Lê a linha inteira da matriz
        if (fgets(buffer, sizeof(buffer), fp) == NULL) {
             fprintf(stderr, "Erro: Arquivo incompleto ao ler matriz de adjacência.\n");
             exit(1);
        }

        char* token = strtok(buffer, ";"); // Começa a dividir a linha pelo ';'
        
        for (int j = 0; j < NUM_CIDADES; j++) {
            if (token == NULL) {
                fprintf(stderr, "Erro: Linha %d da matriz está incompleta.\n", i + 1);
                exit(1);
            }
            // Converte o token (string) para float
            g_adj_matrix[i][j] = atof(token);
            token = strtok(NULL, ";"); // Pega o próximo token
        }
    }

    fclose(fp);
}

/**
 * 1. Encontra a cidade com o MAIOR número de vizinhos.
 * Um vizinho existe se a distância for > 0.
 */

void encontrar_mais_vizinhos() {
    int max_vizinhos = 0;
    int cidade_idx = -1;

    for (int i = 0; i < NUM_CIDADES; i++) {
        int vizinhos_atuais = 0;
        for (int j = 0; j < NUM_CIDADES; j++) {
            // Se a distância for positiva, é um vizinho
            if (g_adj_matrix[i][j] > 0.0) {
                vizinhos_atuais++;
            }
        }

        // Verifica se é o novo máximo
        if (vizinhos_atuais > max_vizinhos) {
            max_vizinhos = vizinhos_atuais;
            cidade_idx = i;
        }
    }

    printf("1. Cidade com MAIS vizinhos: %s (%d vizinhos)\n",
           g_cidades[cidade_idx], max_vizinhos);
}

/**
 * 2. Encontra a cidade com o MENOR número de vizinhos.
 * Um vizinho existe se a distância for > 0.
 */
void encontrar_menos_vizinhos() {
    int min_vizinhos = INT_MAX; // Começa com um valor muito alto
    int cidade_idx = -1;

    for (int i = 0; i < NUM_CIDADES; i++) {
        int vizinhos_atuais = 0;
        for (int j = 0; j < NUM_CIDADES; j++) {
            if (g_adj_matrix[i][j] > 0.0) {
                vizinhos_atuais++;
            }
        }

        // Verifica se é o novo mínimo
        if (vizinhos_atuais < min_vizinhos) {
            min_vizinhos = vizinhos_atuais;
            cidade_idx = i;
        }
    }

    printf("2. Cidade com MENOS vizinhos: %s (%d vizinhos)\n",
           g_cidades[cidade_idx], min_vizinhos);
}

/**
 * 3. Encontra a cidade que possui o vizinho MAIS DISTANTE.
 */
void encontrar_vizinho_mais_distante() {
    float max_dist = 0.0;
    int cidade_idx = -1;
    int vizinho_idx = -1;

    // Itera por toda a matriz
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            if (g_adj_matrix[i][j] > max_dist) {
                max_dist = g_adj_matrix[i][j];
                cidade_idx = i;
                vizinho_idx = j;
            }
        }
    }

    printf("3. Vizinho MAIS distante: Cidade: %s, Vizinho: %s, Distancia: %.2f\n",
           g_cidades[cidade_idx], g_cidades[vizinho_idx], max_dist);
}

/**
 * 4. Encontra a cidade que possui o vizinho MAIS PRÓXIMO.
 * Ignora distâncias 0.0 (não-vizinhos ou si mesmo).
 */
void encontrar_vizinho_mais_proximo() {
    float min_dist = 9999999.0; // Começa com um valor muito alto
    int cidade_idx = -1;
    int vizinho_idx = -1;

    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            // Procura a menor distância QUE SEJA MAIOR QUE ZERO
            if (g_adj_matrix[i][j] > 0.0 && g_adj_matrix[i][j] < min_dist) {
                min_dist = g_adj_matrix[i][j];
                cidade_idx = i;
                vizinho_idx = j;
            }
        }
    }

    printf("4. Vizinho MAIS próximo: Cidade: %s, Vizinho: %s, Distancia: %.2f\n",
           g_cidades[cidade_idx], g_cidades[vizinho_idx], min_dist);
}

/**
 * 5. Pede ao usuário os nomes de duas cidades e informa a distância.
 * Retorna 0 se não forem vizinhas.
 */
void encontrar_distancia_entre_cidades() {
    char cid1_nome[MAX_NAME_LEN];
    char cid2_nome[MAX_NAME_LEN];

    printf("\n5. Consultar distancia entre duas cidades:\n");
    
    printf("   Digite o nome da primeira cidade: ");
    fgets(cid1_nome, MAX_NAME_LEN, stdin);
    cid1_nome[strcspn(cid1_nome, "\r\n")] = 0; // Remove o '\n'

    printf("   Digite o nome da segunda cidade: ");
    fgets(cid2_nome, MAX_NAME_LEN, stdin);
    cid2_nome[strcspn(cid2_nome, "\r\n")] = 0; // Remove o '\n'

    // Encontra os índices das cidades
    int idx1 = get_cidade_index(cid1_nome);
    int idx2 = get_cidade_index(cid2_nome);

    // Validação
    if (idx1 == -1) {
        printf("   ERRO: Cidade '%s' não encontrada.\n", cid1_nome);
        return;
    }
    if (idx2 == -1) {
        printf("   ERRO: Cidade '%s' não encontrada.\n", cid2_nome);
        return;
    }

    // Busca a distância na matriz
    float distancia = g_adj_matrix[idx1][idx2];

    printf("   > A distancia entre %s e %s e: %.2f\n",
           g_cidades[idx1], g_cidades[idx2], distancia);
}

/**
 * Função auxiliar para encontrar o índice de uma cidade no array
 * g_cidades a partir do seu nome.
 * Retorna -1 se não encontrar.
 */

int get_cidade_index(const char* nome_cidade) {
    for (int i = 0; i < NUM_CIDADES; i++) {
        if (strcmp(g_cidades[i], nome_cidade) == 0) {
            return i;
        }
    }
    return -1; // Não encontrou
}