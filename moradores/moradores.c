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
    char nome[50];
    char dat_nasc[5];
    char email[50];
    char tel[17];
    char cpf[13];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Novo Morador = = = = = = = = = = = = =   ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados do morador:                                            ///\n");
    // do While que garante um nome
    do {
        printf("///            Nome: ");
        fgets(nome, sizeof(nome), stdin);
        remove_enter(nome);
        if (valida_nome(nome)){
            break; // Sai do laço apenas se o nome for válido
        } else{
            printf("///            Insira um NOME válido!\n");
        }
    } while (1); // Mantém o laço até que o nome seja valido

    printf("///            Data de Nascimento: ");
    fgets(dat_nasc, sizeof(dat_nasc), stdin);
    printf("///            E-mail: ");
    fgets(email, sizeof(email), stdin);
    printf("///            Telefone: ");
    fgets(tel, sizeof(tel), stdin);
    printf("///            CPF: ");
    fgets(cpf, sizeof(cpf), stdin);

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Morador cadastrado com sucesso!                              ///\n");
    printf("///            Nome: %s", nome);
    printf("///            Data de Nascimento: %s", dat_nasc);
    printf("///            E-mail: %s", email);
    printf("///            Tel: %s", tel);
    printf("///            CPF: %s", cpf);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Aguarda o usuário pressionar ENTER antes de voltar ao menu
}

void pesquisar_morador(void) {
    char cpf[13];
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Morador = = = = = = = = = = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o CPF do morador para pesquisa: ");
    fgets(cpf, sizeof(cpf), stdin);
    // Código para pesquisar o morador
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Pausa antes de voltar ao menu
}


void atualizar_morador(void) {
    char cpf[13];
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Morador = = = = = = = = = = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o CPF do morador que deseja atualizar: ");
    fgets(cpf, sizeof(cpf), stdin);
    // Código para atualizar o morador
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Pausa antes de voltar ao menu
}


void excluir_morador(void) {
    char cpf[13];
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Morador = = = = = = = = = = = = =          ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o CPF do morador que deseja excluir: ");
    fgets(cpf, sizeof(cpf), stdin);
    // Código para excluir o morador
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Pausa antes de voltar ao menu
}
