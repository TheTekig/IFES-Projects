#include <stdio.h>
#include <stdlib.h>

int ler_notas(int cont){
    int nota;

    do{
    printf("%d - Coloque uma nota: ", cont);
    scanf("%d", &nota);
    }while (nota < 0 || nota > 10);
    
    return nota;
}

int ler_matricula(){

    int matricula;

    do{
    printf("Matricula: ");
    scanf("%d", &matricula);
    }while (matricula < 0);

    return matricula;
}

int main(){
    
    int nota1,nota2,nota3, matricula;
    float media;

        matricula = ler_matricula();
        nota1 = ler_notas(1);
        nota2 = ler_notas(2);
        nota3 = ler_notas(3);
        media = ((nota1 + nota2 + nota3) / 3);

        if (media >= 7){
            printf("O aluno de matricula - %d , Passou com a média de %.2f pontos", matricula, media);
        }
        else if (media >= 6){
            printf("O aluno de matricula - %d , Fará a prova final pois esta com a média de %.2f pontos", matricula, media);
        }
        else if (media >= 0){
            printf("O aluno de matricula - %d , Reprovou com a média de %.2f pontos", matricula, media);
        }
        else{
            printf("ERROR");
        }
                    
        return 0;
}