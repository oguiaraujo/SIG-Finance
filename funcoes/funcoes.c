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

// Função que verifica se o ano é bissexto
// Créditos: ChatGPT
int is_bissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return 1;  // É bissexto
    }
    return 0;  // Não é bissexto
}

// Função que valida uma data
// Créditos: ChatGPT
int valida_data(const char *data) {
    int dia, mes, ano;
    
    // Tenta ler a data no formato DD/MM/AAAA
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) {
        return 0;  // Se não conseguir ler no formato correto, é inválido
    }

    // Verifica se o mês está entre 1 e 12
    if (mes < 1 || mes > 12) {
        return 0;  // Mês inválido
    }

    // Verifica o número de dias válidos para o mês
    int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Se for fevereiro, considera o ano bissexto
    if (mes == 2 && is_bissexto(ano)) {
        dias_por_mes[1] = 29;  // Fevereiro tem 29 dias em ano bissexto
    }

    // Verifica se o dia está dentro do intervalo válido para o mês
    if (dia < 1 || dia > dias_por_mes[mes - 1]) {
        return 0;  // Dia inválido para o mês
    }

    return 1;  // Data válida
}