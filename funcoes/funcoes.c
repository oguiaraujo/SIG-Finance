#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

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

    // Valida o cpf
    // Adicionar mais condicoes depois
    int valida_cpf(char *cpf) {
	int tam;
	tam = strlen(cpf);
	if (tam != 11) {
	    return 0;
	}
	for(int i = 0; i < tam; i++) {
        if (!checar_digito(cpf[i])) {
            return 0;
        }
    }
    return 1;
}

// Valida telefone
// Adaptado do programa Linguasolta do Professor Flavius Gorgonio

int valida_tel(char *tel) {
	int tam;
	tam = strlen(tel);
	if (tam != 11) {
		return 0;
	}
	for (int i = 0; i < tam; i++) {
        if (!checar_digito(tel[i])) {
            return 0;
        }
    }
    return 1;
}

// Função que Valida um E-mail
// Créditos: ChatGPT
int valida_email(const char *email) {
    int i = 0;
    int at_count = 0;
    int dot_count = 0;
    int comprimento = strlen(email);

    // Verificar se o e-mail não é vazio
    if (comprimento == 0) {
        return 0;
    }

    // Verificar se o e-mail contém pelo menos um símbolo '@'
    for (i = 0; i < comprimento; i++) {
        if (email[i] == '@') {
            at_count++;
        }
        if (email[i] == '.') {
            dot_count++;
        }
    }

    // O e-mail deve conter exatamente um '@' e pelo menos um '.'
    if (at_count != 1 || dot_count < 1) {
        return 0;
    }

    // Divida o e-mail em duas partes: antes e depois do '@'
    const char *parte_local = email;
    const char *parte_dominio = strchr(email, '@');
    if (parte_dominio == NULL || parte_dominio == email || *(parte_dominio + 1) == '\0') {
        return 0;  // Não há domínio válido após o '@'
    }

    // Verificar se a parte local (antes do '@') é válida
    for (i = 0; i < (parte_dominio - parte_local); i++) {
        if (!isalnum(email[i]) && email[i] != '.' && email[i] != '_' && email[i] != '%' && email[i] != '+' && email[i] != '-') {
            return 0;  // Caracter inválido na parte local
        }
    }

    // Verificar se a parte do domínio (após o '@') contém pelo menos um ponto '.'
    const char *dominio = parte_dominio + 1;
    if (strchr(dominio, '.') == NULL) {
        return 0;  // Não há ponto no domínio
    }

    // Verificar se o domínio não começa ou termina com ponto
    if (dominio[0] == '.' || dominio[strlen(dominio) - 1] == '.') {
        return 0;
    }

    // Verificar se o domínio tem pelo menos dois caracteres após o último ponto
    const char *ultimo_ponto = strrchr(dominio, '.');
    if (ultimo_ponto != NULL && strlen(ultimo_ponto) < 3) {
        return 0;  // O sufixo do domínio é muito curto
    }

    return 1;  // E-mail válido
}