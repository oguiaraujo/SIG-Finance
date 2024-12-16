/*BIBLIOTECAS:*/
#include <stdio.h>
#include <stdlib.h>
#include "tarefas.h"
#include "../funcoes/funcoes.h"

void menu_tarefas(){
    Tarefas tarefa;
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
            pesquisar_tarefa(&tarefa);
            break;
        case 3:
            atualizar_tarefa(&tarefa);
            break;
        case 4:
            excluir_tarefa(&tarefa);
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

Tarefas* cadastrar_tarefa(void){
    
    Tarefas* tarefa;
    tarefa = (Tarefas*) malloc(sizeof(Tarefas));
    if (tarefa == NULL) {
        printf("Erro ao alocar memória para a tarefa.\n");
        exit(1);
    }
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Tarefa = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("/// ID da tarefa:                                                           ///\n");
    fgets(tarefa->id, sizeof(tarefa->id), stdin);
    printf("/// Descrição da tarefa:                                                    ///\n");
    fgets(tarefa->descricao, sizeof(tarefa->descricao), stdin);

    do {
        printf("/// Prazo da tarefa (DD/MM/AAAA):                                           ///\n");
        fgets(tarefa->prazo, sizeof(tarefa->prazo), stdin);
        remove_enter(tarefa->prazo);
        if (valida_data(tarefa->prazo)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma DATA válida!\n");
        }
    } while (1); // Mantém o laço até quw seja valido

    tarefa->status ='a';

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///           Tarefa cadastrada com sucesso                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///           ID: %s", tarefa->id);
    printf("\n");
    printf("///           Descrição: %s", tarefa->descricao);
    printf("\n");
    printf("///           Prazo: %s", tarefa->prazo);
    printf("\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); // Aguarda o usuário pressionar ENTER antes de voltar ao menu

    salva_tarefa(tarefa);
    return tarefa; 
}


void pesquisar_tarefa(Tarefas *tarefa)
{
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Tarefa = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID da tarefa:                                                 ///\n");
    fgets(tarefa->id, sizeof(tarefa->id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}

void atualizar_tarefa(Tarefas *tarefa)
{
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Tarefa = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID da tarefa que deseja atualizar:                            ///\n");
    fgets(tarefa->id, sizeof(tarefa->id), stdin);
    printf("/// Nova descrição:                                                         ///\n");
    fgets(tarefa->descricao, sizeof(tarefa->descricao), stdin);

    do {
        printf("/// Novo prazo (DD/MM/AAAA):                                                ///\n");
        fgets(tarefa->prazo, sizeof(tarefa->prazo), stdin);
        remove_enter(tarefa->prazo);
        if (valida_data(tarefa->prazo)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma DATA válida!\n");
        }
    } while (1); // Mantém o laço até quw seja valido
}

void excluir_tarefa(Tarefas *tarefa)
{
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Tarefa = = = = = = = = = = = = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID da tarefa que deseja excluir:                              ///\n");
    fgets(tarefa->id, sizeof(tarefa->id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}
/*BIBLIOTECAS:*/
#include <stdio.h>
#include <stdlib.h>
#include "tarefas.h"
#include "../funcoes/funcoes.h"

void menu_tarefas(){
    Tarefas tarefa;
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
            pesquisar_tarefa(&tarefa);
            break;
        case 3:
            atualizar_tarefa(&tarefa);
            break;
        case 4:
            excluir_tarefa(&tarefa);
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

Tarefas* cadastrar_tarefa(void){
    
    Tarefas* tarefa;
    tarefa = (Tarefas*) malloc(sizeof(Tarefas));
    if (tarefa == NULL) {
        printf("Erro ao alocar memória para a tarefa.\n");
        exit(1);
    }
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Tarefa = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("/// ID da tarefa:                                                           ///\n");
    fgets(tarefa->id, sizeof(tarefa->id), stdin);
    printf("/// Descrição da tarefa:                                                    ///\n");
    fgets(tarefa->descricao, sizeof(tarefa->descricao), stdin);

    do {
        printf("/// Prazo da tarefa (DD/MM/AAAA):                                           ///\n");
        fgets(tarefa->prazo, sizeof(tarefa->prazo), stdin);
        remove_enter(tarefa->prazo);
        if (valida_data(tarefa->prazo)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma DATA válida!\n");
        }
    } while (1); // Mantém o laço até quw seja valido

    tarefa->status ='a';

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///           Tarefa cadastrada com sucesso                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///           ID: %s", tarefa->id);
    printf("\n");
    printf("///           Descrição: %s", tarefa->descricao);
    printf("\n");
    printf("///           Prazo: %s", tarefa->prazo);
    printf("\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); // Aguarda o usuário pressionar ENTER antes de voltar ao menu

    salva_tarefa(tarefa);
    return tarefa; 
}


void pesquisar_tarefa(Tarefas *tarefa)
{
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Tarefa = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID da tarefa:                                                 ///\n");
    fgets(tarefa->id, sizeof(tarefa->id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}

void atualizar_tarefa(Tarefas *tarefa)
{
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Tarefa = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID da tarefa que deseja atualizar:                            ///\n");
    fgets(tarefa->id, sizeof(tarefa->id), stdin);
    printf("/// Nova descrição:                                                         ///\n");
    fgets(tarefa->descricao, sizeof(tarefa->descricao), stdin);

    do {
        printf("/// Novo prazo (DD/MM/AAAA):                                                ///\n");
        fgets(tarefa->prazo, sizeof(tarefa->prazo), stdin);
        remove_enter(tarefa->prazo);
        if (valida_data(tarefa->prazo)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma DATA válida!\n");
        }
    } while (1); // Mantém o laço até quw seja valido
}

void excluir_tarefa(Tarefas *tarefa)
{
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Tarefa = = = = = = = = = = = = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID da tarefa que deseja excluir:                              ///\n");
    fgets(tarefa->id, sizeof(tarefa->id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}


void salva_tarefa(Tarefas* tarefa) {
    FILE* fp;
    fp = fopen("tarefas.dat", "ab");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }
    fwrite(tarefa, sizeof(Tarefas), 1,fp);
    fclose(fp);
}

void salva_tarefa(Tarefas* tarefa) {
    FILE* fp;
    fp = fopen("tarefas.dat", "ab");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }
    fwrite(tarefa, sizeof(Tarefas), 1,fp);
    fclose(fp);
}
