# Lista Encadeada em C

Este projeto implementa uma **lista simplesmente encadeada** em linguagem C utilizando alocação dinâmica de memória. O programa simula o gerenciamento de espécies de animais, permitindo inserir, buscar, listar e remover registros.

## Estrutura de Dados

A lista encadeada é formada por nós que armazenam:

* Espécie do animal
* Quantidade de animais
* Custo diário por animal
* Classificação do animal
* Ponteiro para o próximo nó da lista

Cada elemento da lista aponta para o próximo elemento, formando uma sequência dinâmica na memória.

Exemplo conceitual:

[leão] -> [tigre] -> [girafa] -> NULL


## Funcionalidades do Programa

O sistema possui um menu interativo com as seguintes operações:

1. Inserir animal na lista
2. Listar todos os animais cadastrados
3. Buscar um animal pelo nome da espécie
4. Remover um animal da lista
5. Calcular o custo total e médio de manutenção
6. Encerrar o programa

## Conceitos de Estrutura de Dados Aplicados

O código demonstra os seguintes conceitos fundamentais:

* Lista simplesmente encadeada
* Alocação dinâmica com `malloc`
* Liberação de memória com `free`
* Manipulação de ponteiros
* Percorrimento de listas

## Objetivo

Este projeto foi desenvolvido com fins acadêmicos para praticar a implementação manual de estruturas de dados em linguagem C.

## Linguagem utilizada

C
