/*BIBLIOTECAS:*/
#include <stdio.h>
#include <stdlib.h>
#include "moradores.h"
#include "../funcoes/funcoes.h"

void menu_moradores(void){
    Moradores morador;
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
            cadastrar_morador(&morador);
            break; /*Termina o bloco case. Isso impede que os outros casos sejam executados depois de executar este.*/
        case 2:
            pesquisar_morador(&morador);
            break;
        case 3:
            atualizar_morador(&morador);
            break;
        case 4:
            excluir_morador(&morador);
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

void cadastrar_morador(Moradores *morador){

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Novo Morador = = = = = = = = = = = = =   ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados do morador:                                            ///\n");
    // Laço que garante um nome válido
    do {
        printf("///            Nome: ");
        fgets(morador->nome, sizeof(morador->nome), stdin);
        remove_enter(morador->nome);
        if (valida_nome(morador->nome)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um NOME válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido

    // Laço que garante uma data váida
    do {
        printf("///            Data de Nascimento (DD/MM/AAAA): ");
        fgets(morador->dat_nasc, sizeof(morador->dat_nasc), stdin);
        remove_enter(morador->dat_nasc);
        if (valida_data(morador->dat_nasc)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma DATA válida!\n");
        }
    } while (1); // Mantém o laço até que seja valido

    // Laço que garante um email válido
    do {
        printf("///            E-mail: ");
        fgets(morador->email, sizeof(morador->email), stdin);
        remove_enter(morador->email);
        if (valida_email(morador->email)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um E-MAIL válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido

    // Laço que garante um email válido
    do {
        printf("///            Telefone: ");
        fgets(morador->tel, sizeof(morador->tel), stdin);
        remove_enter(morador->tel);
        if (valida_tel(morador->tel)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um TELEFONE válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido

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
}

void pesquisar_morador(Moradores *morador) {
    char cpf[13];
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Morador = = = = = = = = = = = = =        ///\n");
    printf("///                                                                         ///\n");

    do {
        printf("/// Informe o CPF do morador para pesquisa: ");
        fgets(morador->cpf, sizeof(morador->cpf), stdin);
        remove_enter(morador->cpf);
        if (valida_cpf(morador->cpf)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um CPF válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido

    printf("/// O CPF: %s é válido!\n", morador->cpf);

    // Código para pesquisar o morador
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Pausa antes de voltar ao menu
}


void atualizar_morador(Moradores *morador) {
    char cpf[13];
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Morador = = = = = = = = = = = = =        ///\n");
    printf("///                                                                         ///\n");

    do {
        printf("/// Informe o CPF do morador para pesquisa: ");
        fgets(morador->cpf, sizeof(morador->cpf), stdin);
        remove_enter(morador->cpf);
        if (valida_cpf(morador->cpf)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um CPF válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido

    printf("/// O CPF: %s é válido!\n", morador->cpf);

    // Código para atualizar o morador
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Pausa antes de voltar ao menu
}


void excluir_morador(Moradores *morador) {
    char cpf[13];
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Morador = = = = = = = = = = = = =          ///\n");
    printf("///                                                                         ///\n");

    do {
        printf("/// Informe o CPF do morador para pesquisa: ");
        fgets(morador->cpf, sizeof(morador->cpf), stdin);
        remove_enter(morador->cpf);
        if (valida_cpf(morador->cpf)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira um CPF válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido

    printf("/// O CPF: %s é válido!\n", morador->cpf);

    // Código para excluir o morador
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Pausa antes de voltar ao menu
}
