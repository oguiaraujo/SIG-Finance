/*BIBLIOTECAS:*/
#include <stdio.h>
#include <stdlib.h>
#include "despesas.h"
#include "../funcoes/funcoes.h"

void menu_despesas(void){
    Despesas despesa;
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
            cadastrar_despesa(&despesa);
            break;
        case 2:
            pesquisar_despesa(&despesa);
            break;
        case 3:
            atualizar_despesa(&despesa);
            break;
        case 4:
            excluir_despesa(&despesa);
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

void cadastrar_despesa(Despesas *despesa)
{

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Nova Despesa = = = = = = = = = = = = =   ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados da despesa:                                            ///\n");
    printf("///            Descrição: ");
    fgets(despesa->descricao, sizeof(despesa->descricao), stdin);
    printf("///            Valor: ");
    fgets(despesa->valor, sizeof(despesa->valor), stdin);

    do {
        printf("///            Data (DD/MM/AAAA): ");
        fgets(despesa->data, sizeof(despesa->data), stdin);
        remove_enter(despesa->data);
        if (valida_data(despesa->data)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma DATA válida!\n");
        }
    } while (1); // Mantém o laço até quw seja valido

    printf("///            id: ");
    fgets(despesa->id, sizeof(despesa->id), stdin);

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Despesa cadastrada com sucesso!                              ///\n");
    printf("///            Descrição: %s", despesa->data);
    printf("///            Valor: %s", despesa->valor);
    printf("///            Data: %s", despesa->data);
    printf("///            Data: %s", despesa->id);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();  // Aguarda o usuário pressionar Enter
}

void pesquisar_despesa(Despesas *despesa)
{
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Despesa      = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o id da despesa:                                                ///\n");
    fgets(despesa->id, sizeof(despesa->id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}

void atualizar_despesa(Despesas *despesa) {
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Despesa      = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o id da despesa:                                                ///\n");
    fgets(id, sizeof(id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
    printf("/// Informe a descrição da despesa:                                        ///\n");
    fgets(despesa->descricao, sizeof(despesa->descricao), stdin);
    printf("/// Informe o valor da despesa:                                            ///\n");
    fgets(despesa->valor, sizeof(despesa->valor), stdin);

    do {
        printf("/// Informe a data da despesa (DD/MM/AAAA):                               ///\n");
        fgets(despesa->data, sizeof(despesa->data), stdin);
        remove_enter(despesa->data);
        if (valida_data(despesa->data)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma DATA válida!\n");
        }
    } while (1); // Mantém o laço até quw seja valido

    //  adicionar o código para atualizar a despesa com os dados recebidos.
}

void excluir_despesa(Despesas *despesa)
{
    char id[5];
    
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Despesa        = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o id da despesa:                                                ///\n");
    fgets(despesa->id, sizeof(despesa->id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}
