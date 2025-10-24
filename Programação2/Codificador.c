#include <stdio.h>
#include <string.h>

#define MAX 500

// Função que criptografa ou descriptografa a mensagem
void criptografar(char mensagem[]) {
    char etapa1[MAX];
    char string1[MAX], string2[MAX];
    char resultado[MAX];
    int i, j, k, len;

    len = strlen(mensagem);

    // Remove o \n deixado pelo fgets, se existir
    if (mensagem[len - 1] == '\n') {
        mensagem[len - 1] = '\0';
        len--;
    }

    //Substitui os caracteres
    for (i = 0; i < len; i++) {
        switch (mensagem[i]) {
            case 'a': etapa1[i] = '@'; break;
            case 'e': etapa1[i] = '&'; break;
            case 'i': etapa1[i] = '$'; break;
            case 'o': etapa1[i] = '*'; break;
            case 'u': etapa1[i] = '#'; break;
            case '@': etapa1[i] = 'a'; break;
            case '&': etapa1[i] = 'e'; break;
            case '$': etapa1[i] = 'i'; break;
            case '*': etapa1[i] = 'o'; break;
            case '#': etapa1[i] = 'u'; break;
            default: etapa1[i] = mensagem[i];
        }
    }
    etapa1[len] = '\0';

    // Divide a string em duas
    int p = 0, q = 0;
    for (i = 0; i < len; i++) {
        if (i % 2 == 0) {
            string1[p++] = etapa1[i];
        } else {
            string2[q++] = etapa1[i];
        }
    }
    string1[p] = '\0';
    string2[q] = '\0';

    // Inverter a string2
    for (i = 0, j = q - 1; i < j; i++, j--) {
        char temp = string2[i];
        string2[i] = string2[j];
        string2[j] = temp;
    }

    //Intercalar as duas strings
    i = j = k = 0;
    while (string1[i] != '\0' || string2[j] != '\0') {
        if (string1[i] != '\0') resultado[k++] = string1[i++];
        if (string2[j] != '\0') resultado[k++] = string2[j++];
    }
    resultado[k] = '\0';

    printf("\nMensagem resultante: %s\n", resultado);
}

int main() {
    char mensagem[MAX];
    printf("=== Codificador/Decodificador ===\n");
    printf("Digite a mensagem para criptografar:\n>>");
    fgets(mensagem, MAX, stdin);

    criptografar(mensagem);

    return 0;
}
