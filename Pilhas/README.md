# Pilha em C — Histórico de Navegação

Este projeto apresenta uma implementação de **pilha (stack)** em linguagem C utilizando **lista encadeada e alocação dinâmica de memória**. O programa simula um **histórico de navegação de páginas**, onde a última página visitada é a primeira a ser removida quando o usuário decide voltar.

A implementação foi desenvolvida com fins acadêmicos para praticar a construção manual de estruturas de dados fundamentais, sem o uso de bibliotecas prontas.

---

## Estrutura de Dados Utilizada

A pilha foi implementada utilizando **lista simplesmente encadeada**, onde cada nó armazena:

* URL da página visitada
* Ponteiro para a próxima página da pilha

Estrutura conceitual:

```
Topo
 |
 v
github.com
youtube.com
google.com
NULL
```

O topo da pilha representa sempre a **página atual**.

---

## Conceito de Pilha

A pilha segue o princípio **LIFO (Last In, First Out)**, ou seja:

> O último elemento inserido é o primeiro a ser removido.

Exemplo de funcionamento:

1. Usuário visita `google.com`
2. Usuário visita `youtube.com`
3. Usuário visita `github.com`

Estado da pilha:

```
github.com
youtube.com
google.com
```

Se o usuário escolher **voltar página**, o sistema remove:

```
github.com
```

A nova página atual passa a ser:

```
youtube.com
```

---

## Funcionalidades do Programa

O sistema possui um menu interativo com as seguintes operações:

1. Visitar nova página (Push)
2. Voltar página (Pop)
3. Mostrar página atual
4. Mostrar histórico de navegação
5. Limpar histórico (liberar memória)
6. Encerrar o programa

---

## Conceitos de Estrutura de Dados Aplicados

O código demonstra a aplicação dos seguintes conceitos:

* Pilha (Stack)
* Estrutura LIFO
* Lista encadeada
* Manipulação de ponteiros
* Alocação dinâmica com `malloc`
* Liberação de memória com `free`

---

## Organização do Código

O programa é dividido em funções responsáveis por cada operação da pilha:

* `visitar_pagina()` → adiciona página ao topo da pilha
* `voltar_pagina()` → remove a página do topo
* `pagina_atual()` → mostra o elemento do topo
* `mostrar_historico()` → percorre toda a pilha
* `limpar_historico()` → libera toda a memória alocada

---

## Linguagem Utilizada

C


