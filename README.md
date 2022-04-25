Laboratório de Programação II | Trabalho #1

##### 1. Desenvolvimento

O trabalho foi desenvolvido na linguagem C como solicitado.
Compilado no GCC através dos comandos:  
  
  
``` gcc -o exe main.c functions.c types.h ```  
```./exe ```

O tamanho do vetor `TAM` pode ser alterado no arquivo `types.h`;  

Para analisar os relatórios, há a possibilidade de criar de forma automática os dados, para isso:  
  1º - comente a linnha `int controle = cadastrar (pessoa_vec);` do arquivo `main.c`;  
  2º - descomente a linnha `auto_preenche(pessoa_vec);` do arquivo `main.c`;  
  3º - tenha certeza que o tmanho do vetor seja 10 em  `#define TAM 10` no arquivo `types.h`;


##### 2. Requisitos implementados:

Segue abaixo o cheklist dos artefatos que foram solicitados no enunciado do trabalho. Estão marcados como check os atributos que foram implementados:

- [x] Exige-se que a estrutura dos dados pessoais solicitados no enunciado sejam de acordo com a estrutura abaixo:
``` 
struct pessoa {
  int codigo;
  char nome[81];
  float peso;
  int altura;
  float imc;
  char faixa[15];
};
typedef struct pessoa Pessoa;
``` 
- [x] Exige-se que o tamanho do vetor seja uma contante informada uma unica vez pelo usuário atravéz da cláusula `#define TAM 25` do C.
- [x] Exige-se que a inserção de informações no vetor seja através dos protótipo de função: 
`void preenche (Pessoa* vet, int i, int codigo, char* nome, float peso, int altura);`

Funções exigidas no trabalho que resultam em:

- [x] dados de todos as pessoas do vetor;
- [x] nome das pessoas que estão em sobrepeso;
- [x] código das pessoas que estão com obsidade;
- [x] valor médio dos pesos;
- [x] quantidade de pessoas que tem peso acima do valor médio dos pesos;
- [x] quantidade de pessoas que não estão na faixa normal dos pesos;
- [x] nome das pessoas que tem o peso normal e que pesam menos do que o valor médio dos pesos;
- [x] nome das pessoas que obtiveram o maior IMC;
- [x] nome das pessoas que obtiveram o menor IMC;