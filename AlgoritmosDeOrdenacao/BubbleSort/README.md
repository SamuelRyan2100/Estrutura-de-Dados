# Bubble Sort – Ordenação de Notas de Alunos

Este programa implementa o algoritmo **Bubble Sort** para ordenar uma lista de alunos com base em suas notas.

O objetivo do sistema é simular uma situação comum em ambientes educacionais: organizar os alunos de acordo com seu desempenho acadêmico. Para isso, o programa recebe o nome e a nota de cada aluno e utiliza o algoritmo Bubble Sort para ordenar os dados em ordem crescente de nota.

## Contexto do Problema

Em muitas situações acadêmicas é necessário organizar informações de estudantes para análise de desempenho, geração de rankings ou identificação de melhores resultados.

Neste programa, cada aluno possui:

- Nome
- Nota

Após a inserção dos dados, o algoritmo de ordenação reorganiza os registros para que os alunos fiquem classificados de acordo com suas notas.

## Como o Bubble Sort funciona

O Bubble Sort é um algoritmo simples que percorre repetidamente a lista comparando elementos adjacentes.

Se dois elementos estiverem fora de ordem, eles são trocados de posição. A cada iteração, o maior elemento restante "sobe" para o final da lista, semelhante ao movimento de uma bolha na água.

### Passos do algoritmo

1. Comparar dois elementos consecutivos
2. Trocar se estiverem fora de ordem
3. Repetir o processo para toda a lista
4. Continuar até que não haja mais trocas

## Complexidade do Algoritmo

- Melhor caso: **O(n)** (lista já ordenada)
- Caso médio: **O(n²)**
- Pior caso: **O(n²)**

Por possuir alta complexidade para grandes volumes de dados, o Bubble Sort é geralmente utilizado para fins educacionais e para compreender conceitos básicos de ordenação.

## Compilação

No terminal, dentro da pasta do arquivo:
