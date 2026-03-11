# Lista Duplamente Encadeada em C

Este programa implementa uma **lista duplamente encadeada** para gerenciar arquivos.  
Cada nó da lista representa um arquivo contendo informações como nome, data de criação, tamanho e identificador.

A estrutura foi desenvolvida para praticar conceitos fundamentais de **Estruturas de Dados**, como manipulação de ponteiros, alocação dinâmica de memória e operações em listas encadeadas.

## Estrutura do Nó

Cada elemento da lista possui:

- Nome do arquivo
- Data de criação
- Tamanho do arquivo
- ID do arquivo
- Ponteiro para o próximo elemento
- Ponteiro para o elemento anterior

## Operações Implementadas

O sistema possui um menu interativo com as seguintes funcionalidades:

1. Inserir novo arquivo
2. Imprimir lista
3. Imprimir lista em ordem inversa
4. Buscar arquivo pelo ID
5. Remover arquivo
6. Liberação de memória ao final do programa

## Conceitos Aplicados

- Lista Duplamente Encadeada
- Alocação dinâmica com `malloc`
- Liberação de memória com `free`
- Manipulação de ponteiros
- Percurso bidirecional da lista

