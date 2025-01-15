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
// Créditos: Tomé
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
// Adaptado do SIG-DietPlain: https://github.com/Diego-Axel/SIG-DietPlan.git
int valida_cpf(char *cpf) {
    if (strlen(cpf) != 11) {
        return 0;
    }
    
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return 0;
        }
    }

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    int primeiroDigitoVerificador = (soma * 10) % 11;
    if (primeiroDigitoVerificador == 10) {
        primeiroDigitoVerificador = 0;
    }
    if (primeiroDigitoVerificador != (cpf[9] - '0')) {
        return 0;
    }

    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    int segundoDigitoVerificador = (soma * 10) % 11;
    if (segundoDigitoVerificador == 10) {
        segundoDigitoVerificador = 0;
    }
    if (segundoDigitoVerificador != (cpf[10] - '0')) {
        return 0; 
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

// Função que valida um E-mail
// Créditos: ChatGPT
int valida_email(const char *email) {
    int at_pos = -1;  // Posição do '@'
    int dot_pos = -1; // Posição do último '.'
    int len = strlen(email);

    // Um e-mail válido deve ter pelo menos 5 caracteres: "a@b.c"
    if (len < 5) return 0;

    for (int i = 0; i < len; i++) {
        char c = email[i];

        if (c == '@') {
            // Já encontrou um '@' anteriormente? Inválido
            if (at_pos != -1) return 0;
            at_pos = i;
        } else if (c == '.') {
            // Registra a posição do último ponto
            dot_pos = i;
        } else if (!isalnum(c) && c != '_' && c != '-' && c != '+') {
            // Permite apenas letras, números, '-', '_', e '+'
            return 0;
        }
    }

    // Verificações finais:
    // - '@' deve existir e não ser o primeiro ou o último caractere
    // - '.' deve existir depois de '@' e não ser o último caractere
    if (at_pos == -1 || at_pos == 0 || at_pos == len - 1) return 0;
    if (dot_pos == -1 || dot_pos < at_pos || dot_pos == len - 1) return 0;

    return 1; // E-mail válido
}

// Função para validar um preço
// Créditos: ChatGPT
int valida_preco(const char *preco) {
    int tem_digito = 0;    // Verifica se há pelo menos um dígito
    int tem_ponto = 0;     // Verifica se o separador decimal foi usado corretamente
    int tamanho = strlen(preco);

    if (tamanho == 0) {
        return 0; // String vazia é inválida
    }

    for (int i = 0; i < tamanho; i++) {
        if (isdigit(preco[i])) {
            tem_digito = 1;
        } else if (preco[i] == '.') {
            if (tem_ponto) {
                return 0; // Mais de um ponto decimal é inválido
            }
            tem_ponto = 1;
        } else {
            return 0; // Qualquer caractere que não seja dígito ou ponto é inválido
        }
    }

    // Um preço válido precisa ter pelo menos um dígito
    return tem_digito;
}
