#include <time.h>
#include <stdlib.h>
#include <string.h>

/////////////////
// Usos Gerais //
/////////////////

// Função que remove o "\n" após input do usuário
// Adaptado do ChatGPT
void remove_enter(char *str){
	str[strcspn(str, "\n")] = 0;
}

////////////////
// Validações //
////////////////

/* funçao de validação de digito*/
int checar_digito(int c){
	  if (c >= '0' && c <= '9') {
		  return 1;
	  } else{
		  return 0;
	  }
	
}
