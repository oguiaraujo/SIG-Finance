/*BIBLIOTECAS:*/
#include <stdio.h>
#include <stdlib.h>
#include "moradores.h"
#include "../funcoes/funcoes.h"

void menu_moradores(void){
    int opcao;
    do{
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///            ===================================================          ///\n");
        printf("///            = = = =              SigFinance             = = = =          ///\n");
        printf("///            ===================================================          ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///            = = = = = = = = = Menu Morador = = = = = = = = =             ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar um novo morador                                 ///\n");
        printf("///            2. Pesquisar os moradores                                    ///\n");
        printf("///            3. Atualizar o cadastro de um morador                        ///\n");
        printf("///            4. Excluir um morador                                        ///\n");
        printf("///            0. Voltar ao menu anterior                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            cadastrar_morador();
            break; /*Termina o bloco case. Isso impede que os outros casos sejam executados depois de executar este.*/
        case 2:
            pesquisar_morador();
            break;
        case 3:
            atualizar_morador();
            break;
        case 4:
            excluir_morador();
            break;
        case 0:
        
            break;
        default: // Se nenhum dos valores anteriores (1, 2, 3, 4 ou 0) for selecionado, este bloco é executado.
            printf("\t\t\t>Opção inválida! Tente novamente.\n");
            printf("///                                                                         ///\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }
    } while (opcao != 0);
}

void cadastrar_morador(void){

    Moradores* morador;
    morador = (Moradores*) malloc(sizeof(Moradores));
    if (morador == NULL) {
        printf("Erro ao alocar memória para o morador.\n");
        exit(1);
    }

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Novo Morador = = = = = = = = = = = = =   ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados do morador:                                            ///\n");

    insira_nome(morador->nome, sizeof(morador->nome));

    insira_data(morador->dat_nasc, sizeof(morador->dat_nasc));

    insira_email(morador->email, sizeof(morador->email));

    insira_telefone(morador->tel, sizeof(morador->tel));

    // Laço que garante um CPF válido
    do {
        printf("///            CPF: ");
        fgets(morador->cpf, sizeof(morador->cpf), stdin);
        remove_enter(morador->cpf);
        if (valida_cpf(morador->cpf)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um CPF válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido

    morador->status = 'a';

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Morador cadastrado com sucesso!                              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Nome: %s", morador->nome);
    printf("\n");
    printf("///            Data de Nascimento: %s", morador->dat_nasc);
    printf("\n");
    printf("///            E-mail: %s", morador->email);
    printf("\n");
    printf("///            Tel: %s", morador->tel);
    printf("\n");
    printf("///            CPF: %s", morador->cpf);
    printf("\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Aguarda o usuário pressionar ENTER antes de voltar ao menu

    salva_morador(morador);
    free(morador);
}

void pesquisar_morador(void) {
    FILE* fp;
    Moradores* morador;
    char cpf_informado[13];
    int encontrado = 0;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Morador = = = = = = = = = = = = =        ///\n");
    printf("///                                                                         ///\n");

    do {
        printf("/// Informe o CPF do morador para pesquisa: ");
        fgets(cpf_informado, sizeof(cpf_informado), stdin);
        remove_enter(cpf_informado);
        if (valida_cpf(cpf_informado)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um CPF válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido

    morador = (Moradores*) malloc(sizeof(Moradores)); // Aloca memória dinâmica
    if (morador == NULL) {
        printf("Erro ao alocar memória para o morador.\n");
        exit(1);
    }

    fp = fopen("moradores.dat", "rb"); // Abre arquivo no modo de leitura
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        free(morador);
        return NULL;
    }

    while (fread(morador, sizeof(Moradores), 1, fp)) {
        if ((strcmp(morador->cpf, cpf_informado) == 0) && (morador->status != 'i')) {  // Compara strings e verifica o status
            encontrado = 1;
            exibir_morador(morador);
            break;
        }
    }

    if (!encontrado) {
        printf("///            CPF não encontrado!\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();  // Pausa antes de voltar ao menu

    }

    fclose(fp);
    free(morador);
}

void exibir_morador(const Moradores* morador) {
    if (morador == NULL) {
        printf("/// Nenhum morador encontrado.\n");
        return;
    }

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Dados do Morador = = = = = = = = = = = = =         ///\n");
    printf("///                                                                         ///\n");
    printf("///            Nome: %s\n", morador->nome);
    printf("///            Data de Nascimento: %s\n", morador->dat_nasc);
    printf("///            E-mail: %s\n", morador->email);
    printf("///            Telefone: %s\n", morador->tel);
    printf("///            CPF: %s\n", morador->cpf);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void atualizar_morador(void) {
    FILE* fp;
    Moradores* morador;
    char cpf_informado[13];
    int encontrado = 0;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Morador = = = = = = = = = = = = =        ///\n");
    printf("///                                                                         ///\n");

    do {
        printf("/// Informe o CPF do morador para atualizar: ");
        fgets(cpf_informado, sizeof(cpf_informado), stdin);
        remove_enter(cpf_informado);
        if (valida_cpf(cpf_informado)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um CPF válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido

    morador = (Moradores*) malloc(sizeof(Moradores)); // Aloca memória dinâmica
    if (morador == NULL) {
        printf("Erro ao alocar memória para o morador.\n");
        exit(1);
    }

    fp = fopen("moradores.dat", "r+b"); // Abre arquivo no modo de leitura
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        free(morador);
        exit(1);
    }

    while (fread(morador, sizeof(Moradores), 1, fp)) {
        if ((strcmp(morador->cpf, cpf_informado) == 0) && (morador->status != 'i')) {  // Compara strings e verifica o status
            encontrado = 1;
            exibir_morador(morador);
            // Laço que garante um nome válido
            printf("/// Atualize os dados do morador:\n");
            printf("///\n");
            
            insira_nome(morador->nome, sizeof(morador->nome));

            insira_data(morador->dat_nasc, sizeof(morador->dat_nasc));

            insira_email(morador->email, sizeof(morador->email));

            insira_telefone(morador->tel, sizeof(morador->tel));

            fseek(fp, -sizeof(Moradores), SEEK_CUR);
            fwrite(morador, sizeof(Moradores), 1, fp);

            printf("///            Dados atualizados com sucesso!\n");
            break;

        }
    }

    if (!encontrado) {
        printf("///            CPF não encontrado!\n");
    }

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Pausa antes de voltar ao menu

    fclose(fp);
    free(morador);
}


void excluir_morador(void) {
    FILE* fp;
    Moradores* morador;
    char cpf_informado[13];
    int encontrado = 0;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Morador = = = = = = = = = = = = =          ///\n");
    printf("///                                                                         ///\n");

    do {
        printf("/// Informe o CPF do morador para atualizar: ");
        fgets(cpf_informado, sizeof(cpf_informado), stdin);
        remove_enter(cpf_informado);
        if (valida_cpf(cpf_informado)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um CPF válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido

    morador = (Moradores*) malloc(sizeof(Moradores)); // Aloca memória dinâmica
    if (morador == NULL) {
        printf("Erro ao alocar memória para o morador.\n");
        exit(1);
    }

    fp = fopen("moradores.dat", "r+b"); // Abre arquivo no modo de leitura
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        free(morador);
        exit(1);
    }

    while (fread(morador, sizeof(Moradores), 1, fp)) {
        if ((strcmp(morador->cpf, cpf_informado) == 0) && (morador->status != 'i')) {  // Compara strings e verifica o status
            encontrado = 1;
            exibir_morador(morador);

            morador->status = 'i';
            fseek(fp, -sizeof(Moradores), SEEK_CUR);
            fwrite(morador, sizeof(Moradores), 1, fp);

            printf("///            Morador removido com sucesso!\n");
            break;

        }
    }

    if (!encontrado) {
        printf("///            CPF não encontrado!\n");
    }
    
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Pausa antes de voltar ao menu

    fclose(fp);
    free(morador);
}

// Função que Salva os dados em arquivo binário
// Adaptado do Professor Flavius Gorgonio
void salva_morador(Moradores* morador) {
    FILE* fp;
    fp = fopen("moradores.dat", "ab");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }
    fwrite(morador, sizeof(Moradores), 1, fp);
    fclose(fp);
}

void insira_nome(char* nome, size_t tamanho) {
    do {
        printf("///            Nome: ");
        fgets(nome, tamanho, stdin);
        remove_enter(nome);
        if (valida_nome(nome)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um NOME válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido
}

void insira_data(char* data, size_t tamanho) {
    do {
        printf("///            Data de Nascimento (DD/MM/AAAA): ");
        fgets(data, tamanho, stdin);
        remove_enter(data);
        if (valida_data(data)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma DATA válida!\n");
        }
    } while (1); // Mantém o laço até que seja valido
}

void insira_email(char* email, size_t tamanho) {
    do {
        printf("///            E-mail: ");
        fgets(email, tamanho, stdin);
        remove_enter(email);
        if (valida_email(email)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um E-MAIL válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido
}

void insira_telefone(char* tel, size_t tamanho) {
    do {
        printf("///            Telefone: ");
        fgets(tel, tamanho, stdin);
        remove_enter(tel);
        if (valida_tel(tel)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um TELEFONE válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido

}