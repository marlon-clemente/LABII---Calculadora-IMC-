/*
  Marlon Clemente Soares
  https://github.com/marlon-clemente/LabII/tree/main/Trab%231

*/

#include <stdio.h>
#include "types.h"

int main () {
  Pessoa pessoa_vec[TAM];

  // int controle = cadastrar (pessoa_vec);

  /*
    ATENCAO
    Para usar o auto prenchimento, defina TAM = 10
    no types.h
  */
  auto_preenche(pessoa_vec);

  switch (menu()){
    case 1:
      imprime_todos(pessoa_vec);
      break;
    case 2:
      imprime_todos_sobrepeso(pessoa_vec);
      break;
    case 3:
      imprime_todos_obesidade(pessoa_vec);
      break;
    case 4:
      printf("Media de pesos eh %f \n", media_pesos(pessoa_vec));
      break;
    case 5:
      printf("O total de %d pessoas encontram-se com o peso acima da media", pesos_acima_media(pessoa_vec, media_pesos(pessoa_vec)));
      break;
    case 6:
      printf("O total de %d pessoas estão fora da faixa normal de peso.", total_fora_faixa_normal(pessoa_vec));
      break;
    case 7:
      normal_abaixo_media(pessoa_vec, media_pesos(pessoa_vec));
      break;
    case 8:
      ordena_decrescente(pessoa_vec);
      break;
    case 9:
      ordena_crescente(pessoa_vec);
      break;
    default:
      break;
  }

  return 0;
}