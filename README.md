### README.md

# CalcBasica: Analisadores Léxico, Sintático e Semântico

Este projeto, **CalcBasica**, foi desenvolvido com o objetivo de implementar analisadores léxico, sintático e semântico para uma linguagem de programação básica. O projeto é composto por três módulos principais:

1. **Analisador Léxico**  
2. **Analisador Sintático**  
3. **Analisador Semântico**  

Além disso, dois exemplos de código (entrada) estão disponíveis para testes e validação da funcionalidade completa dos analisadores.

---

## Estrutura do Projeto

### Arquivos Principais:

- `analisadorLexico.l`: Implementa o analisador léxico, responsável por identificar os tokens da linguagem.
- `analisadorSintatico.y`: Implementa o analisador sintático, responsável por verificar a conformidade com as regras gramaticais da linguagem.
- `analisadorSemantico.y`: Implementa o analisador semântico, responsável por validar tipos, variáveis declaradas e compatibilidade semântica.
- `tokens.h`: Contém a definição de todos os tokens utilizados pelos analisadores.

### Arquivos de Exemplos:

- **`exemplo1.txt`**: Um programa de exemplo que calcula o fatorial de um número inteiro.
- **`exemplo2.txt`**: Outro programa de exemplo, destacando a manipulação de listas e operações aritméticas.

---

## Executando o Projeto

### Pré-requisitos:

Certifique-se de que você possui as seguintes ferramentas instaladas:
- `flex`: Para o analisador léxico.
- `bison`: Para os analisadores sintático e semântico.
- `gcc`: Compilador para gerar o executável final.

### Passos:

1. **Compile o analisador léxico e sintático:**
   ```bash
   flex analisadorLexico.l
   bison -d analisadorSintatico.y
   gcc analisadorSintatico.tab.c lex.yy.c -o analisador_sintatico -lfl
   ```

2. **Compile o analisador semântico:**
   ```bash
   bison -d analisadorSemantico.y
   gcc analisadorSemantico.tab.c lex.yy.c -o analisador_semantico -lfl
   ```

3. **Execute o analisador sintático:**
   ```bash
   ./analisador_sintatico exemplo1.txt
   ```

4. **Execute o analisador semântico:**
   ```bash
   ./analisador_semantico exemplo1.txt
   ```

---

## Exemplos Disponíveis

### **Exemplo 1: Calcular o Fatorial**

**Arquivo:** `exemplo1.txt`

```plaintext
PROGRAMA fatorial_exemplo
INICIO
DECLARACOES
INTEIRO argumento, fatorial
ALGORITMO
{ Calcula o fatorial de um número inteiro }
LEIA argumento
fatorial := argumento
SE argumento .I. 0
ENTAO fatorial := 1
FIM_SE
ENQUANTO argumento .M. 1
fatorial := fatorial * argumento
argumento := argumento - 1
FIM_ENQUANTO
ESCREVA 'fatorial = ', fatorial
FIM
```

---

## Funcionalidades de Cada Analisador

### **Analisador Léxico**
- Identifica tokens da linguagem, como palavras-chave (`PROGRAMA`, `INICIO`, `ALGORITMO`), identificadores, números inteiros, números reais e operadores (`:=`, `+`, `-`, `*`, `/`, etc.).
- Gera mensagens indicando os tokens reconhecidos.

### **Analisador Sintático**
- Valida a conformidade com as regras gramaticais definidas.
- Gera mensagens indicando as estruturas sintáticas reconhecidas (e erros, se existirem).

### **Analisador Semântico**
- Verifica a consistência semântica do programa, como:
  - Tipos compatíveis em operações e atribuições.
  - Variáveis declaradas antes do uso.
  - Tamanhos de listas corretamente definidos.
- Exibe mensagens detalhadas para cada passo da análise.

---

## Saída de Exemplo

### Execução do Exemplo 1:

1. **Analisador Léxico:**
   ```plaintext
   Token: PROGRAMA
   Token: IDENT
   Token: INICIO
   Token: DECLARACOES
   Token: INTEIRO
   Token: IDENT
   Token: VIRGULA
   Token: IDENT
   ...
   ```

2. **Analisador Sintático:**
   ```plaintext
   Reconhecido corpo.
   Reconhecidas declarações.
   Reconhecido algoritmo.
   Programa sintaticamente correto.
   ```

3. **Analisador Semântico:**
   ```plaintext
   Reconhecida variável 'argumento' do tipo 'inteiro'.
   Reconhecida variável 'fatorial' do tipo 'inteiro'.
   Verificada compatibilidade de tipos na atribuição.
   Reconhecido comando de atribuição para 'fatorial'.
   Análise semântica concluída com sucesso.
   ```

---

## Contribuindo

Contribuições são bem-vindas! Para contribuir, siga os passos:
1. Faça um fork do repositório.
2. Crie um branch para sua funcionalidade (`git checkout -b minha-funcionalidade`).
3. Envie um pull request detalhando as mudanças realizadas.

---

## Licença

Este projeto está licenciado sob a licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.
