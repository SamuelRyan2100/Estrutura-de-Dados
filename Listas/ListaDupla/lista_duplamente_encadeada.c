#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct arquivo{
    char nome[30];
    Data data_criacao;
    int tamanho;
    char id[10];

    struct arquivo *prox;
    struct arquivo *ant;

} Arquivo;


Arquivo* criarArquivo(){

    Arquivo *novo = (Arquivo*) malloc(sizeof(Arquivo));

    if(novo == NULL){
        printf("Erro de memoria\n");
        return NULL;
    }

    printf("\nNome do arquivo: ");
    scanf("%s", novo->nome);

    printf("Data (dia mes ano): ");
    scanf("%d %d %d", &novo->data_criacao.dia,
                     &novo->data_criacao.mes,
                     &novo->data_criacao.ano);

    printf("Tamanho do arquivo: ");
    scanf("%d", &novo->tamanho);

    printf("ID do arquivo: ");
    scanf("%s", novo->id);

    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}


void inserirInicio(Arquivo **lista){

    Arquivo *novo = criarArquivo();

    if(novo == NULL) return;

    if(*lista == NULL){
        *lista = novo;
    }else{
        novo->prox = *lista;
        (*lista)->ant = novo;
        *lista = novo;
    }

}


void imprimirLista(Arquivo *lista){

    Arquivo *aux = lista;

    if(aux == NULL){
        printf("\nLista vazia\n");
        return;
    }

    while(aux != NULL){

        printf("\n------------------");
        printf("\nNome: %s", aux->nome);
        printf("\nData: %d/%d/%d",
               aux->data_criacao.dia,
               aux->data_criacao.mes,
               aux->data_criacao.ano);
        printf("\nTamanho: %d", aux->tamanho);
        printf("\nID: %s", aux->id);

        aux = aux->prox;
    }

    printf("\n");
}


void imprimirReverso(Arquivo *lista){

    Arquivo *aux = lista;

    if(aux == NULL){
        printf("\nLista vazia\n");
        return;
    }

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    printf("\n--- Lista invertida ---\n");

    while(aux != NULL){

        printf("\nNome: %s", aux->nome);
        printf("\nID: %s\n", aux->id);

        aux = aux->ant;
    }
}


void buscarArquivo(Arquivo *lista){

    char id[10];

    printf("\nDigite o ID do arquivo: ");
    scanf("%s", id);

    Arquivo *aux = lista;

    while(aux != NULL){

        if(strcmp(aux->id, id) == 0){

            printf("\nArquivo encontrado:");
            printf("\nNome: %s", aux->nome);
            printf("\nTamanho: %d", aux->tamanho);

            return;
        }

        aux = aux->prox;
    }

    printf("\nArquivo nao encontrado\n");
}


void removerArquivo(Arquivo **lista){

    char id[10];

    printf("\nDigite o ID do arquivo para remover: ");
    scanf("%s", id);

    Arquivo *aux = *lista;

    while(aux != NULL){

        if(strcmp(aux->id, id) == 0){

            if(aux->ant != NULL)
                aux->ant->prox = aux->prox;
            else
                *lista = aux->prox;

            if(aux->prox != NULL)
                aux->prox->ant = aux->ant;

            free(aux);

            printf("\nArquivo removido\n");
            return;
        }

        aux = aux->prox;
    }

    printf("\nArquivo nao encontrado\n");
}


void liberarMemoria(Arquivo *lista){

    Arquivo *aux = lista;

    while(aux != NULL){

        Arquivo *temp = aux;
        aux = aux->prox;
        free(temp);
    }

}


int main(){

    Arquivo *lista = NULL;

    int op;

    do{

        printf("\n---- MENU ----");
        printf("\n1 Inserir arquivo");
        printf("\n2 Imprimir lista");
        printf("\n3 Imprimir reverso");
        printf("\n4 Buscar arquivo");
        printf("\n5 Remover arquivo");
        printf("\n0 Sair");
        printf("\nOpcao: ");

        scanf("%d",&op);

        switch(op){

            case 1:
                inserirInicio(&lista);
            break;

            case 2:
                imprimirLista(lista);
            break;

            case 3:
                imprimirReverso(lista);
            break;

            case 4:
                buscarArquivo(lista);
            break;

            case 5:
                removerArquivo(&lista);
            break;

        }

    }while(op != 0);

    liberarMemoria(lista);

    return 0;
}