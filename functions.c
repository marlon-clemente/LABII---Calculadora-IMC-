#include "types.h"

void preenche (Pessoa* vet, int i, int codigo, char* nome, float peso, int altura) {
  vet[i].codigo = codigo;
  strcpy(vet[i].nome, nome);
  vet[i].peso = peso;
  vet[i].altura = altura;
  vet[i].imc = calcula_imc(peso, altura);
  strcpy(vet[i].faixa, define_faixa(calcula_imc(peso, altura)));
  
  printf("Registro #%d/%d foi inserido com sucesso...\n", i + 1, TAM);
}

int cadastrar (Pessoa* vet){
  int inserindo = 1, codigo;
  char nome[81];
  float peso;
  int altura;

  for (int i = 0; i < TAM; i++){
    printf("[Pessoa #%d/%d] ~ Insira o codigo (numerico): \n", i + 1, TAM);
    scanf("%d", &codigo);
    printf("[Pessoa #%d/%d] ~ Insira o nome (Maximo 81 caracteres): \n", i + 1, TAM);
    scanf("%s%*c", &nome);
    printf("[Pessoa #%d/%d] ~ Insira o peso (Em kg): \n", i + 1, TAM);
    scanf("%f", &peso);
    printf("[Pessoa #%d/%d] ~ Insira a altura (Em cm): \n", i + 1, TAM);
    scanf("%d", &altura);

    preenche (vet, i, codigo, nome, peso, altura);

    printf("Deseja continuar inserindo registros?\n");
    printf("[1] SIM\n");
    printf("[2] NAO\n");

    scanf("%d", &inserindo);
    if(inserindo != 1) return 1;
  }
}

float calcula_imc (float peso, int altura){
  return peso / ((altura * 0.01) * (altura * 0.01));
}

const char *define_faixa(float imc){
  if (imc < 18.5){
    return "magreza";
  } else 
  if (imc >= 18.5 && imc < 24.9 ){
    return "normal";
  } else 
  if (imc >= 24.9 && imc <30.0){
    return "sobrepeso";
  }else 
  if (imc >= 30.0){
    return "obesidade";
  } else {
    return "Error";
  }
}

void imprime_todos (Pessoa* vet){
  printf("______Todas as pessoas cadastradas_______\n");
  for (int i = 0; i < TAM; i++){
    printf("___________#%d____________\n",i + 1);
    printf("Codigo: %d\n", vet[i].codigo);
    printf("Nome: % s \n", vet[i].nome);
    printf("Peso: %f\n", vet[i].peso);
    printf("Altura: %d\n", vet[i].altura);
    printf("IMC: %f \n", vet[i].imc);
    printf("Faixa: % s \n", vet[i].faixa);

    printf("__________________________\n");
  }
}

void imprime_todos_sobrepeso (Pessoa* vet){
  printf("______Nome das pessoas que se encontam em sobrepeso_______\n");
  for (int i = 0; i < TAM; i++){
    if (strcmp(vet[i].faixa, "sobrepeso") == 0){
      printf("% s \n", vet[i].nome);
    }
  }
}

void imprime_todos_obesidade(Pessoa* vet){
  printf("______Codigo das pessoas que se encontam em obsidade_______\n");
  for (int i = 0; i < TAM; i++){
    if (strcmp(vet[i].faixa, "sobrepeso") == 0){
      printf("% s \n", vet[i].codigo);
    }
  }
}

float media_pesos (Pessoa* vet){
  float soma = 0;

  for (int i = 0; i < TAM; i++){
    soma = soma + vet[i].peso;
  }

  return soma/TAM;
}

int pesos_acima_media (Pessoa* vet, float media){
  int count = 0;
  for (int i = 0; i < TAM; i++){
    if (vet[i].peso > media ) count ++;
  }
  return count;
}

int total_fora_faixa_normal(Pessoa* vet){
  int count = 0;
  for (int i = 0; i < TAM; i++){
    if (!strcmp(vet[i].faixa, "normal") == 0) count ++;
  }
  return count;
}

void normal_abaixo_media(Pessoa* vet, float media){
  for (int i = 0; i < TAM; i++){
    if (strcmp(vet[i].faixa, "normal") == 0 
      && vet[i].peso < media) printf("% s\n", vet[i].nome);
  }
}

void ordena_crescente (Pessoa* vet){
  Pessoa aux;

  for(int i = 0; i < TAM; i++){
    for(int j = i + 1; j < TAM; j++){
      if(vet[i].imc > vet[j].imc){
          aux = vet[i];
          vet[i] = vet[j];
          vet[j] = aux;
      }
    }
  }

  printf("__ Nome das pessoas que obtiveram o menor IMC __\n");
  for (int i = 0; i < TAM; i++){
    printf("Nome: % s | IMC: %f\n", vet[i].nome, vet[i].imc);
  }

}
void ordena_decrescente (Pessoa* vet){
  Pessoa aux;

  for(int i = 0; i < TAM; i++){
    for(int j = 0; j < TAM; j++){
      if(vet[i].imc > vet[j].imc){
          aux = vet[i];
          vet[i] = vet[j];
          vet[j] = aux;
      }
    }
  }

  printf("__ Nome das pessoas que obtiveram o menor IMC __\n");

  for (int i = 0; i < TAM; i++){
    printf("Nome: % s | IMC: %f\n", vet[i].nome, vet[i].imc);
  }

}

void auto_preenche (Pessoa* vet) {
  /*        vet, indice, codigo, nome, peso, altura */
  
  preenche (vet, 0, 1, "Marcelo Lomba", 85, 191); //normal
  preenche (vet, 1, 2, "Renzo Saravia", 57, 172); //normal
  preenche (vet, 2, 3, "Vitor Cuesta", 58, 192); //mag
  preenche (vet, 3, 4, "Leo Borges", 59, 184); //mag
  preenche (vet, 4, 5, "Moises", 73, 171); //sobre
  preenche (vet, 5, 6, "Rodrigo Dourado", 81, 175); //sobre
  preenche (vet, 6, 7, "Edenilson", 66, 183); //normal
  preenche (vet, 7, 8, "Taison", 84, 174);//sobre
  preenche (vet, 8, 9, "Palacios", 89, 184);//sobre
  preenche (vet, 9, 10, "Yuri Alberto", 74, 172);//sobre
  preenche (vet, 10, 11, "Tiago Galhardo", 67, 177);//normal
}

int menu () {
  int number_menu;

  printf("\n\n----------- RELATORIOS -----------\n");
  printf("Digite o numero do relatorio:\n");
  printf("1 - Dados de todos as pessoas do vetor\n");
  printf("2 - Nome das pessoas que estao em sobrepeso\n");
  printf("3 - Codigo das pessoas que estao com obsidade\n");
  printf("4 - Valor medio dos pesos\n");
  printf("5 - Quantidade de pessoas que tem peso acima do valor medio dos pesos\n");
  printf("6 - Quantidade de pessoas que nao estao na faixa normal dos pesos\n");
  printf("7 - Nome das pessoas que tem o peso normal e que pesam menos do que o valor medio dos pesos\n");
  printf("8 - Nome das pessoas que obtiveram o maior IMC\n");
  printf("9 - Nome das pessoas que obtiveram o menor IMC\n");
  scanf("%d", &number_menu);

  return number_menu;
}