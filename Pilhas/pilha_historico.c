#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct pagina{
    char url[100];
    struct pagina *prox;
}Pagina;


/* ================= MENU ================= */

void menu(){

    printf("\n");
    printf("#########################################\n");
    printf("#           PILHA - NAVEGADOR           #\n");
    printf("#########################################\n");

    printf("\n1 - Visitar nova pagina");
    printf("\n2 - Voltar pagina (pop)");
    printf("\n3 - Mostrar pagina atual");
    printf("\n4 - Mostrar historico");
    printf("\n5 - Limpar historico");
    printf("\n6 - Sair\n");

}


/* ================= PUSH ================= */

void visitar_pagina(Pagina **pilha){

    Pagina *nova = (Pagina*) malloc(sizeof(Pagina));

    if(nova == NULL){
        printf("\nErro de memoria!\n");
        return;
    }

    printf("\nDigite a URL da pagina: ");
    scanf("%s", nova->url);

    nova->prox = *pilha;
    *pilha = nova;

    printf("\nPagina adicionada ao topo da pilha!\n");
}


/* ================= POP ================= */

void voltar_pagina(Pagina **pilha){

    if(*pilha == NULL){
        printf("\nNao ha paginas no historico!\n");
        return;
    }

    Pagina *remover = *pilha;

    printf("\nSaindo da pagina: %s\n", remover->url);

    *pilha = remover->prox;

    free(remover);

}


/* ================= TOPO ================= */

void pagina_atual(Pagina *pilha){

    if(pilha == NULL){
        printf("\nNenhuma pagina aberta!\n");
        return;
    }

    printf("\nPagina atual: %s\n", pilha->url);

}


/* ================= MOSTRAR PILHA ================= */

void mostrar_historico(Pagina *pilha){

    if(pilha == NULL){
        printf("\nHistorico vazio!\n");
        return;
    }

    printf("\nHistorico de navegacao:\n\n");

    while(pilha != NULL){

        printf("%s\n", pilha->url);

        pilha = pilha->prox;
    }

}


/* ================= LIMPAR PILHA ================= */

void limpar_historico(Pagina **pilha){

    Pagina *aux;

    while(*pilha != NULL){

        aux = *pilha;

        *pilha = (*pilha)->prox;

        free(aux);
    }

    printf("\nHistorico apagado!\n");

}


/* ================= MAIN ================= */

int main(){

    setlocale(LC_ALL,"portuguese");

    Pagina *pilha = NULL;

    int op;

    while(1){

        menu();

        printf("\nEscolha: ");
        scanf("%d",&op);

        switch(op){

            case 1:
                visitar_pagina(&pilha);
            break;

            case 2:
                voltar_pagina(&pilha);
            break;

            case 3:
                pagina_atual(pilha);
            break;

            case 4:
                mostrar_historico(pilha);
            break;

            case 5:
                limpar_historico(&pilha);
            break;

            case 6:
                limpar_historico(&pilha);
                printf("\nEncerrando programa...\n");
                return 0;

            default:
                printf("\nOpcao invalida!\n");
        }

    }

}