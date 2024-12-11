```S → PROGRAMA IDENTIFICADOR INICIO CORPO FIM
CORPO → DECLARACOES ALGORITMO
DECLARACOES → TIPO LISTA_VAR | ε
TIPO → INTEIRO | REAL | CARACTER | CADEIA | LISTA_INT | LISTA_REAL
LISTA_VAR → IDENTIFICADOR | IDENTIFICADOR , LISTA_VAR
ALGORITMO → COMANDO ALGORITMO | ε
COMANDO → LEIA LISTA_VAR
         | ESCREVA LISTA_VAR
         | IDENTIFICADOR := EXPRESSAO
         | SE EXPRESSAO_RELACIONAL ENTAO COMANDO FIM_SE
         | ENQUANTO EXPRESSAO_RELACIONAL COMANDO FIM_ENQUANTO
EXPRESSAO → EXPRESSAO + TERMO | EXPRESSAO - TERMO | TERMO
TERMO → TERMO * FATOR | TERMO / FATOR | FATOR
FATOR → IDENTIFICADOR | CONSTANTE
EXPRESSAO_RELACIONAL → EXPRESSAO .M. EXPRESSAO
                      | EXPRESSAO .I. EXPRESSAO