#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    float nota;
} Aluno;


void lerAlunos(Aluno *vetor, int n){

    for(int i = 0; i < n; i++){

        printf("\nAluno %d\n", i+1);

        printf("Nome: ");
        scanf("%s", vetor[i].nome);

        printf("Nota: ");
        scanf("%f", &vetor[i].nota);
    }

}


void imprimirAlunos(Aluno *vetor, int n){

    printf("\n---- LISTA DE ALUNOS ----\n");

    for(int i = 0; i < n; i++){

        printf("\nNome: %s", vetor[i].nome);
        printf("\nNota: %.2f\n", vetor[i].nota);
    }

}


void bubbleSort(Aluno *vetor, int n){

    Aluno temp;

    for(int i = 0; i < n-1; i++){

        for(int j = 0; j < n-1-i; j++){

            if(vetor[j].nota > vetor[j+1].nota){

                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;

            }
        }
    }

}


int main(){

    int n;

    printf("Quantidade de alunos: ");
    scanf("%d", &n);

    Aluno *vetor = (Aluno*) malloc(n * sizeof(Aluno));

    if(vetor == NULL){
        printf("Erro de memoria\n");
        return 1;
    }

    lerAlunos(vetor, n);

    printf("\nAntes da ordenacao:\n");
    imprimirAlunos(vetor, n);

    bubbleSort(vetor, n);

    printf("\nDepois da ordenacao (Bubble Sort):\n");
    imprimirAlunos(vetor, n);

    free(vetor);

    return 0;
}