#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

typedef struct animal{
    char especie[30];
    int quantidade;
    float custo;
    char classificacao;
    struct animal *prox;
}Animal;


/* ================= MENU ================= */

void menu(){
    printf("\n");
    printf("#########################################\n");
    printf("#        LISTA ENCADEADA - ANIMAIS      #\n");
    printf("#########################################\n");

    printf("\n1 - Inserir animal");
    printf("\n2 - Listar todos os animais");
    printf("\n3 - Buscar animal");
    printf("\n4 - Remover animal");
    printf("\n5 - Calcular custo total");
    printf("\n6 - Sair\n");
}


/* ========= CONVERTER STRING ========= */

void converter_minusculo(char *texto){

    for(int i = 0; texto[i] != '\0'; i++){
        texto[i] = tolower((unsigned char)texto[i]);
    }

}


/* ========= INSERIR NA LISTA ========= */

void inserir_animal(Animal **lista){

    Animal *novo = (Animal*) malloc(sizeof(Animal));

    if(novo == NULL){
        printf("\nErro de memoria!\n");
        return;
    }

    printf("\nEspecie: ");
    scanf("%s", novo->especie);

    converter_minusculo(novo->especie);

    printf("Quantidade: ");
    scanf("%d",&novo->quantidade);

    printf("Custo diario por animal: ");
    scanf("%f",&novo->custo);

    printf("\nClassificacao\n");
    printf("1 - Terrestre\n");
    printf("2 - Aquatico\n");
    printf("3 - Aereo\n");

    scanf(" %c",&novo->classificacao);

    novo->prox = NULL;

    if(*lista == NULL){
        *lista = novo;
    }
    else{

        Animal *aux = *lista;

        while(aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    printf("\nAnimal inserido!\n");

}


/* ========= LISTAR ========= */

void listar_animais(Animal *lista){

    if(lista == NULL){
        printf("\nLista vazia!\n");
        return;
    }

    while(lista != NULL){

        printf("\nEspecie: %s", lista->especie);
        printf("\nQuantidade: %d", lista->quantidade);
        printf("\nCusto diario: %.2f", lista->custo);
        printf("\nClassificacao: %c\n", lista->classificacao);

        printf("------------------------");

        lista = lista->prox;
    }

}


/* ========= BUSCAR ========= */

void buscar_animal(Animal *lista){

    char especie[30];
    int encontrou = 0;

    printf("\nDigite a especie: ");
    scanf("%s", especie);

    converter_minusculo(especie);

    while(lista != NULL){

        if(strcmp(lista->especie, especie) == 0){

            printf("\nAnimal encontrado\n");

            printf("Especie: %s\n", lista->especie);
            printf("Quantidade: %d\n", lista->quantidade);
            printf("Custo: %.2f\n", lista->custo);

            encontrou = 1;
        }

        lista = lista->prox;
    }

    if(encontrou == 0){
        printf("\nAnimal nao encontrado\n");
    }

}


/* ========= REMOVER ========= */

void remover_animal(Animal **lista){

    char especie[30];

    Animal *atual = *lista;
    Animal *anterior = NULL;

    printf("\nDigite a especie que deseja remover: ");
    scanf("%s", especie);

    converter_minusculo(especie);

    while(atual != NULL && strcmp(atual->especie, especie) != 0){

        anterior = atual;
        atual = atual->prox;

    }

    if(atual == NULL){
        printf("\nAnimal nao encontrado\n");
        return;
    }

    if(anterior == NULL){
        *lista = atual->prox;
    }
    else{
        anterior->prox = atual->prox;
    }

    free(atual);

    printf("\nAnimal removido com sucesso!\n");

}


/* ========= CALCULAR CUSTO ========= */

void calcular_custo(Animal *lista){

    float total = 0;
    int quantidade = 0;

    while(lista != NULL){

        total += lista->custo * lista->quantidade;
        quantidade += lista->quantidade;

        lista = lista->prox;
    }

    if(quantidade == 0){
        printf("\nNao ha animais cadastrados\n");
        return;
    }

    printf("\nCusto total diario: %.2f\n", total);
    printf("Custo medio por animal: %.2f\n", total/quantidade);

}


/* ================= MAIN ================= */

int main(){

    setlocale(LC_ALL,"portuguese");

    Animal *lista = NULL;

    int op;

    while(1){

        menu();

        printf("\nEscolha: ");
        scanf("%d",&op);

        switch(op){

            case 1:
                inserir_animal(&lista);
            break;

            case 2:
                listar_animais(lista);
            break;

            case 3:
                buscar_animal(lista);
            break;

            case 4:
                remover_animal(&lista);
            break;

            case 5:
                calcular_custo(lista);
            break;

            case 6:
                printf("\nEncerrando...\n");
                return 0;

            default:
                printf("\nOpcao invalida\n");

        }

    }

}