# Fila de Prioridade em C — Posto de Saúde

Este projeto apresenta a implementação de uma **fila de prioridade** em linguagem C utilizando **lista encadeada e alocação dinâmica de memória**. O programa simula o sistema de atendimento de um **posto de saúde**, onde pacientes aguardam atendimento em uma fila.

O sistema considera **prioridade para idosos**, inserindo esses pacientes na frente da fila.

---

## Estrutura de Dados Utilizada

A fila foi implementada utilizando **lista simplesmente encadeada**, onde cada nó representa um paciente contendo:

* Nome
* Idade
* Indicador de prioridade
* Ponteiro para o próximo paciente da fila

Estrutura conceitual:

```
Inicio da fila
     |
     v
[Idoso] -> [Idoso] -> [Adulto] -> [Adulto] -> NULL
```

---

## Conceito de Fila

A estrutura segue o princípio **FIFO (First In, First Out)**:

> O primeiro paciente da fila é o primeiro a ser atendido.

No entanto, o sistema inclui **prioridade para idosos (idade ≥ 60)**.

Regras de inserção:

* Pacientes com **prioridade** entram **na frente da fila**
* Pacientes **comuns** entram **no final da fila**

---

## Funcionalidades do Programa

O menu do sistema permite realizar as seguintes operações:

1. Registrar chegada de paciente
2. Atender paciente (remover da fila)
3. Mostrar fila de atendimento
4. Mostrar quantidade de pacientes na fila
5. Limpar toda a fila
6. Encerrar o programa

---

## Conceitos de Estrutura de Dados Aplicados

Este algoritmo demonstra:

* Fila (Queue)
* Estrutura FIFO
* Fila de prioridade simples
* Lista encadeada
* Manipulação de ponteiros
* Alocação dinâmica (`malloc`)
* Liberação de memória (`free`)

---

## Objetivo

O objetivo do projeto é praticar a implementação manual de estruturas de dados fundamentais em C, simulando um cenário real de atendimento em sistemas de saúde.

---

## Linguagem Utilizada

C

