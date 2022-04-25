#include <stdio.h>
#include <string.h>

#define TAM 10

struct pessoa
{
  int codigo;
  char nome[81];
  float peso;
  int altura;
  float imc;
  char faixa[15];
};

typedef struct pessoa Pessoa;

int cadastrar (Pessoa* vet);

void auto_preenche (Pessoa* vet);

float calcula_imc (float peso, int altura);

void preenche (Pessoa* vet, int i, int codigo, char* nome, float peso, int altura);

const char *define_faixa(float imc);

void imprime_todos (Pessoa* vet);

void imprime_todos_sobrepeso (Pessoa* vet);

void imprime_todos_obesidade(Pessoa* vet);

float media_pesos (Pessoa* vet);

int pesos_acima_media (Pessoa* vet, float media);

int total_fora_faixa_normal(Pessoa* vet);

void normal_abaixo_media(Pessoa* vet, float media);

void ordena_crescente (Pessoa* vet);

void ordena_decrescente (Pessoa* vet);

int menu ();