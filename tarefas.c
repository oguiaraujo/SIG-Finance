/*BIBLIOTECAS:*/
#include <stdio.h>
#include <stdlib.h>
#include "tarefas.h"

void menu_tarefas(){
    int opcao;
    do{   
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = = Menu Tarefas = = = = = = = = =             ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar uma tarefa                                      ///\n");
        printf("///            2. Pesquisar as tarefas                                      ///\n");
        printf("///            3. Atualizar tarefas                                         ///\n");
        printf("///            4. Excluir uma tarefa                                        ///\n");
        printf("///            0. Voltar ao menu anterior                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            cadastrar_tarefa();
            break;
        case 2:
            pesquisar_tarefa();
            break;
        case 3:
            atualizar_tarefa();
            break;
        case 4:
            excluir_tarefa();
            break;
         case 0:
        
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            printf("\t\t\t>Opção inválida! Tente novamente.\n");
            printf("///                                                                         ///\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            break;
        }
    } while (opcao != 0);
}

void cadastrar_tarefa()
{
    char descricao[100];
    char prazo[20];
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Tarefa = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("/// ID da tarefa:                                                           ///\n");
    fgets(id, sizeof(id), stdin);
    printf("/// Descrição da tarefa:                                                    ///\n");
    fgets(descricao, sizeof(descricao), stdin);
    printf("/// Prazo da tarefa (dd/mm/aaaa):                                           ///\n");
    fgets(prazo, sizeof(prazo), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}

void pesquisar_tarefa()
{
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Tarefa = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID da tarefa:                                                 ///\n");
    fgets(id, sizeof(id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}

void atualizar_tarefa()
{
    char id[5];
    char nova_descricao[100];
    char novo_prazo[20];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Tarefa = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID da tarefa que deseja atualizar:                            ///\n");
    fgets(id, sizeof(id), stdin);
    printf("/// Nova descrição:                                                         ///\n");
    fgets(nova_descricao, sizeof(nova_descricao), stdin);
    printf("/// Novo prazo (dd/mm/aaaa):                                                ///\n");
    fgets(novo_prazo, sizeof(novo_prazo), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}

void excluir_tarefa()
{
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Tarefa = = = = = = = = = = = = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID da tarefa que deseja excluir:                              ///\n");
    fgets(id, sizeof(id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}
