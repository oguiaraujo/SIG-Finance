#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/////////////////
// Usos Gerais //
/////////////////

// Função que remove o "\n" após input do usuário
// Adaptado do ChatGPT
void remove_enter(char *str){
	str[strcspn(str, "\n")] = 0; // Substitui o "\n" por \0 (terminador de string) 
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

// Função que valida um nome
// Adaptado do ChatGPT
int valida_nome(const char *nome){
	int tamanho = strlen(nome); // Guarda a quantidade de caracteres de uma string
	int valido = 0;
	const char *permitidos = "ÁÉÍÓÚÃÕÂÊÎÔÛÀÇzáéíóúãõâêîôûàç";

	for (int i = 0; i < tamanho; i++){ // Percorre cada caractere do input
		if (isalpha(nome[i]) || strchr(permitidos, nome[i])){ // Verifica se tem uma letra ou outro caracter permitido
			valido = 1;
		} else if (!isalpha(nome[i]) && nome[i] != ' ' && strchr(permitidos, nome[i]) == NULL){ // Verifica se o caractere é diferente de uma letra ou espaço
			return 0; // Inválido
		}
	}

	return valido;
}