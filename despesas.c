/*BIBLIOTECAS:*/
#include <stdio.h>
#include <stdlib.h>
#include "despesas.h"

void menu_despesas(void){
    int opcao;
    do{
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = = Menu Despesas = = = = = = = = =            ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar uma despesa                                     ///\n");
        printf("///            2. Pesquisar as despesas                                     ///\n");
        printf("///            3. Atualizar despesas                                        ///\n");
        printf("///            4. Excluir uma despesa                                       ///\n");
        printf("///            0. Voltar ao menu anterior                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            cadastrar_despesa();
            break;
        case 2:
            pesquisar_despesa();
            break;
        case 3:
            atualizar_despesa();
            break;
        case 4:
            excluir_despesa();
            break;
        case 0:
        
            break;
        default:
            printf("\t\t\t>Opção inválida! Tente novamente.\n");
            printf("///                                                                         ///\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            break;
        }
    } while (opcao != 0);
}

void cadastrar_despesa()
{
    char descricao[200];
    char valor[10];
    char data[12];
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Nova Despesa = = = = = = = = = = = = =   ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados da despesa:                                            ///\n");
    printf("///            Descrição: ");
    fgets(descricao, sizeof(descricao), stdin);
    printf("///            Valor: ");
    fgets(valor, sizeof(valor), stdin);
    printf("///            Data (dd/mm/aaaa): ");
    fgets(data, sizeof(data), stdin);
    printf("///            id: ");
    fgets(id, sizeof(id), stdin);

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Despesa cadastrada com sucesso!                              ///\n");
    printf("///            Descrição: %s", descricao);
    printf("///            Valor: %s", valor);
    printf("///            Data: %s", data);
    printf("///            Data: %s", id);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();  // Aguarda o usuário pressionar Enter
}

void pesquisar_despesa()
{
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Despesa      = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o id da despesa:                                                ///\n");
    fgets(id, sizeof(id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}

void atualizar_despesa() {
    char id[5];
    char descricao[200];
    char valor[10];
    char data[12];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Despesa      = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o id da despesa:                                                ///\n");
    fgets(id, sizeof(id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
    printf("/// Informe a descrição da despesa:                                        ///\n");
    fgets(descricao, sizeof(descricao), stdin);
    printf("/// Informe o valor da despesa:                                            ///\n");
    fgets(valor, sizeof(valor), stdin);
    printf("/// Informe a data da despesa (DD/MM/AAAA):                               ///\n");
    fgets(data, sizeof(data), stdin);
    //  adicionar o código para atualizar a despesa com os dados recebidos.
}

void excluir_despesa()
{
    char id[5];
    
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Despesa        = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o id da despesa:                                                ///\n");
    fgets(id, sizeof(id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}
