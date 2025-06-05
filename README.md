# 🧮 Projeto de Estruturas de Dados em C — Filas e Pilhas

Este projeto é uma série de atividades práticas em linguagem C, voltadas para a implementação e uso de estruturas de dados lineares: filas, pilhas e filas com prioridade. Ele é ideal para estudantes ou iniciantes em programação que desejam entender o funcionamento dessas estruturas.

## 📁 Estrutura do Projeto

- `EaD_01_Pedro_20240844.c`: Simulador de atendimento em banco (fila simples).
- `EaD_02_Pedro_20240844.c`: Verificador de palíndromos usando fila e pilha.
- `EaD_03_Pedro_20240844.c`: Fila de prioridade simples.
- `fila.c` / `fila.h`: Implementação genérica de fila circular com ponteiros de início e fim.
- `pilha.c` / `pilha.h`: Implementação de pilha sequencial (vetor).

## 🚀 Como Compilar e Executar

Use `gcc` para compilar os exercícios. Exemplo:

gcc EaD_01_Pedro_20240844.c fila.c -o atendimento
./atendimento

gcc EaD_02_Pedro_20240844.c fila.c pilha.c -o palindromo
./palindromo

gcc EaD_03_Pedro_20240844.c fila.c -o prioridade
./prioridade

## 🧠 Conceitos Envolvidos

### 🔁 Fila (Queue)

- Estrutura FIFO (First-In, First-Out).
- Utilizada para organizar tarefas ou atendimentos em ordem de chegada.
- Implementada aqui como um vetor circular com ponteiros `inicio`, `fim` e `tamanho`.

### 📚 Pilha (Stack)

- Estrutura LIFO (Last-In, First-Out).
- Útil para análise reversa, como verificação de palíndromos.
- Implementada com vetor e índice de topo.

### 🔢 Fila com Prioridade

- Cada item possui um nível de prioridade (1 = alta, 2 = média, 3 = baixa).
- Os elementos são inseridos em ordem, e sempre o mais prioritário é atendido primeiro.

## 📘 Detalhes dos Exercícios

### `EaD_01_Pedro_20240844.c` — Simulador de Atendimento

- Permite adicionar clientes manualmente (nome, número, tempo).
- Atende os clientes em ordem de chegada.
- Mostra o tempo médio de atendimento.
- Opção de teste automático para simulação rápida.

### `EaD_02_Pedro_20240844.c` — Verificador de Palíndromos

- Usuário digita uma palavra.
- A palavra é inserida em uma fila e em uma pilha.
- Os caracteres são comparados para verificar se a palavra é palíndromo.
- Ignora diferenças entre maiúsculas/minúsculas e ignora acentos.

### `EaD_03_Pedro_20240844.c` — Fila de Prioridade

- Permite adicionar tarefas com prioridade.
- As tarefas são organizadas automaticamente pela prioridade.
- Atende as tarefas mais prioritárias primeiro.
- Contém opção de teste automático com tarefas pré-definidas.

## 🛠️ Detalhes Técnicos

- As filas e pilhas usam `void*` para permitir armazenamento genérico.
- Os dados são inseridos e removidos com ponteiros, mas a alocação é feita de forma estática (limite de 100 elementos).
- Modularização: cada estrutura foi separada em `.h` e `.c` para facilitar manutenção e reutilização.

## ✅ Teste Automático

- Exercício 1 e 3 têm opção de menu para rodar testes automaticamente.
- Isso insere dados simulados (clientes/tarefas) sem precisar digitar manualmente.

## 💡 Possíveis Melhorias

- Substituir filas estáticas por dinâmicas (listas encadeadas).
- Adicionar salvamento em arquivos.
- Criar interface gráfica ou via terminal com `ncurses`.
- Suporte a múltiplas filas simultâneas.

## 👨‍💻 Autor

Projeto desenvolvido por Pedro, como parte de atividades EaD sobre estruturas de dados.  
Material didático e acadêmico.

## 📜 Licença

Este projeto está sob a licença MIT.  
Você pode usar, modificar e distribuir para fins acadêmicos ou pessoais.
