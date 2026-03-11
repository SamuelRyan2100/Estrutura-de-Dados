#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct paciente{
    char nome[50];
    int idade;
    int prioridade;
    struct paciente *prox;
}Paciente;


/* ================= MENU ================= */

void menu(){

    printf("\n");
    printf("#########################################\n");
    printf("#        FILA DE ATENDIMENTO            #\n");
    printf("#           POSTO DE SAUDE              #\n");
    printf("#########################################\n");

    printf("\n1 - Chegada de paciente");
    printf("\n2 - Atender paciente");
    printf("\n3 - Mostrar fila");
    printf("\n4 - Quantidade de pacientes");
    printf("\n5 - Limpar fila");
    printf("\n6 - Sair\n");

}


/* ================= INSERIR PACIENTE ================= */

void chegada_paciente(Paciente **inicio){

    Paciente *novo = (Paciente*) malloc(sizeof(Paciente));

    if(novo == NULL){
        printf("\nErro de memoria!\n");
        return;
    }

    printf("\nNome do paciente: ");
    scanf("%s", novo->nome);

    printf("Idade: ");
    scanf("%d", &novo->idade);

    if(novo->idade >= 60){
        novo->prioridade = 1;
        printf("Paciente com prioridade!\n");
    }
    else{
        novo->prioridade = 0;
    }

    novo->prox = NULL;

    /* prioridade entra na frente */

    if(novo->prioridade == 1){

        novo->prox = *inicio;
        *inicio = novo;
    }

    else{

        if(*inicio == NULL){
            *inicio = novo;
        }
        else{

            Paciente *aux = *inicio;

            while(aux->prox != NULL){
                aux = aux->prox;
            }

            aux->prox = novo;
        }
    }

    printf("\nPaciente adicionado na fila!\n");

}


/* ================= ATENDER ================= */

void atender_paciente(Paciente **inicio){

    if(*inicio == NULL){
        printf("\nFila vazia!\n");
        return;
    }

    Paciente *remover = *inicio;

    printf("\nAtendendo paciente: %s\n", remover->nome);

    *inicio = remover->prox;

    free(remover);

}


/* ================= MOSTRAR FILA ================= */

void mostrar_fila(Paciente *inicio){

    if(inicio == NULL){
        printf("\nFila vazia!\n");
        return;
    }

    printf("\nFila de atendimento:\n\n");

    while(inicio != NULL){

        printf("Nome: %s\n", inicio->nome);
        printf("Idade: %d\n", inicio->idade);

        if(inicio->prioridade == 1){
            printf("Tipo: Prioridade\n");
        }
        else{
            printf("Tipo: Normal\n");
        }

        printf("----------------------\n");

        inicio = inicio->prox;
    }

}


/* ================= CONTAR ================= */

void quantidade_pacientes(Paciente *inicio){

    int cont = 0;

    while(inicio != NULL){

        cont++;

        inicio = inicio->prox;
    }

    printf("\nPacientes na fila: %d\n", cont);

}


/* ================= LIMPAR FILA ================= */

void limpar_fila(Paciente **inicio){

    Paciente *aux;

    while(*inicio != NULL){

        aux = *inicio;

        *inicio = (*inicio)->prox;

        free(aux);
    }

    printf("\nFila limpa com sucesso!\n");

}


/* ================= MAIN ================= */

int main(){

    setlocale(LC_ALL,"portuguese");

    Paciente *fila = NULL;

    int op;

    while(1){

        menu();

        printf("\nEscolha: ");
        scanf("%d",&op);

        switch(op){

            case 1:
                chegada_paciente(&fila);
            break;

            case 2:
                atender_paciente(&fila);
            break;

            case 3:
                mostrar_fila(fila);
            break;

            case 4:
                quantidade_pacientes(fila);
            break;

            case 5:
                limpar_fila(&fila);
            break;

            case 6:
                limpar_fila(&fila);
                printf("\nEncerrando sistema...\n");
                return 0;

            default:
                printf("\nOpcao invalida!\n");
        }

    }

}