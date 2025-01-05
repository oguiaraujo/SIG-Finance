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

void cadastrar_tarefa(void){
    
    Tarefas* tarefa;
    tarefa = (Tarefas*) malloc(sizeof(Tarefas));
    if (tarefa == NULL) {
        printf("Erro ao alocar memória para a tarefa.\n");
        exit(1);
    }
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Tarefa = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");
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

    gera_id_tarefa(tarefa->id);

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
    free(tarefa);
}


void pesquisar_tarefa(void) {
    FILE *fp;
    Tarefas* tarefa;
    char id_informado[11];
    int encontrado = 0;

    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Tarefa = = = = = = = = = = = = = = = =   ///\n");
    printf("///                                                                         ///\n");

    printf("/// Informe o ID da tarefa (TAR-XXXXX): ");
    fgets(id_informado, sizeof(id_informado), stdin);
    remove_enter(id_informado);

    tarefa = (Tarefas*) malloc(sizeof(Tarefas));
    if (tarefa == NULL) {
        printf("Erro ao alocar memória para o morador.\n");
        exit(1);
    }

    fp = fopen("tarefas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        free(tarefa);
        return NULL;

    }

    while (fread(tarefa, sizeof(Tarefas), 1, fp)) {
        if ((strcmp(tarefa->id, id_informado)== 0) && (tarefa->status != 'i')) {
            encontrado = 1;
            exibir_tarefa(tarefa);
            break;
        }
    }

    if (!encontrado) {
        printf("///            Tarefa não encontrada!\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }

    fclose(fp);
    free(tarefa);
}

void exibir_tarefa(const Tarefas* tarefa) {
    if (tarefa == NULL) {
        printf("/// Nenhuma tarefa encontrada.\n");
        return;
    }

    printf("\n////////////////////////////////////////////////////////////////////////////////\n");
    printf("///          = = = = = Dados da tarefa = = = = = = = = = = = = =               ///\n");
    printf("///                                                                            ///\n");
    printf("///          ID: %s\n", tarefa->id);
    printf("///          Descrição: %s\n", tarefa->descricao);
    printf("///          Prazo: %s\n", tarefa->prazo);
    printf("///                                                                            ///\n");
    printf("\n////////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void atualizar_tarefa(void) {
    FILE* fp;
    Tarefas* tarefa;
    char id_informado[11];
    int encontrado = 0;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Tarefa = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");

    printf("/// Informe o ID da tarefa (TAR-XXXXX) que deseja atualizar: ");
    fgets(id_informado, sizeof(id_informado), stdin);
    remove_enter(id_informado);

    tarefa = (Tarefas*) malloc(sizeof(Tarefas));
    if (tarefa == NULL) {
        printf("Erro ao alocar memória para a tarefa\n");
        exit(1);
    }

    fp = fopen("tarefas.dat", "r+b");
    if (fp == NULL) {
        printf("Erro na gravação do arquivo!\n");
        free(tarefa);
        exit(1);
    }
    
    while (fread(tarefa, sizeof(Tarefas), 1, fp)) {
        if ((strcmp(tarefa->id, id_informado)== 0) && (tarefa->status != 'i')) {
            encontrado = 1;
            exibir_tarefa(tarefa);

            printf("///        Descrição:  ");
            fgets(tarefa->descricao, sizeof(tarefa->descricao), stdin);

            do {
                printf("/// Prazo da tarefa (DD/MM/AAAA): ");
                fgets(tarefa->prazo, sizeof(tarefa->prazo), stdin);
                remove_enter(tarefa->prazo);
                if(valida_data(tarefa->prazo)){
                    break;
                } else{
                    printf("///      Insira uma DATA válida!\n");
                }
            } while(1);

            fseek(fp, -sizeof(Tarefas), SEEK_CUR);
            fwrite(tarefa, sizeof(Tarefas), 1, fp);

            printf("///              Dados atualizados com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("///            Tarefa não encontrada!\n");
    }

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    fclose(fp);
    free(tarefa);
}

void excluir_tarefa(void) {
    FILE* fp;
    Tarefas* tarefa;
    char id_informado[11];
    int encontrado = 0;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Tarefa = = = = = = = = = = = = = = = =     ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID da tarefa (TAR-XXXXX) que deseja excluir: ");
    fgets(id_informado, sizeof(id_informado), stdin);
    remove_enter(id_informado);

    tarefa = (Tarefas*) malloc(sizeof(Tarefas));
    if (tarefa == NULL) {
        printf("Erro ao alocar memória para tarefa.\n");
        exit(1);
    }

    fp = fopen("tarefas.dat", "r+b");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        free(tarefa);
        exit(1);
    }

    while (fread(tarefa, sizeof(Tarefas), 1, fp)) {
        if ((strcmp(tarefa->id, id_informado) == 0) && (tarefa->status != 'i')) {
            encontrado = 1;
            exibir_tarefa(tarefa);
            tarefa->status = 'i';
            fseek(fp, -sizeof(Tarefas), SEEK_CUR);
            fwrite(tarefa, sizeof(Tarefas), 1, fp);

            printf("///         Tarefa removida com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("///            Tarefa não encontrada!\n");
    }
    
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    fclose(fp);
    free(tarefa);
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

// Créditos ChatGPT
void gera_id_tarefa(char* id_tarefa) {
    FILE *fp;
    int contador = 0;

    fp = fopen("id_tarefas.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("id_tarefas.dat", "wb");

        if (fp == NULL) {
            printf("Erro ao acessar o arquivo de IDs para tarefas!\n");
            exit(1);
        }
        contador = 1;

    } else {
        fread(&contador, sizeof(int), 1, fp);
        contador++;
    }

    rewind(fp);
    fwrite(&contador, sizeof(int), 1, fp);

    fclose(fp);

    sprintf(id_tarefa, "TAR-%05d", contador);
}