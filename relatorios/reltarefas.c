#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reltarefas.h"
#include "../tarefas/tarefas.h"

void relatorios_tarefas(void) {
    int op;
    do{
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Tarefas = = = = = = = = = = = = =       ///\n");
    printf("///                                                                           ///\n");
    printf("///            1. Todos as Tarefas                                            ///\n");
    printf("///            2. Tarefas por Prazo                                           ///\n");
    printf("///            3. Terefas Ativas                                              ///\n");
    printf("///            4. Tarefas Inativas                                            ///\n");
    printf("///            0. Voltar                                                      ///\n");
    printf("///                                                                           ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%d", &op);
    getchar();
    switch (op)
    {
    case 1:
        exibe_todas_tarefas();
        break;
    case 2:
        exibe_tarefas_por_prazo();
        break;
    case 3:
        exibe_tarefas_ativas();
        break;
    case 4:
        // Em desenvolvimento
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

    } while (op != 0);

}

void exibe_todas_tarefas(void) {
    FILE *fp;
    Tarefas tarefa;
    int encontrado = 0;

    fp = fopen("tarefas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }

    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Lista de Todas as Tarefas                           ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    while (fread(&tarefa, sizeof(Tarefas), 1, fp)) {
        encontrado = 1;
        printf("///            ID da Tarefa: %s\n", tarefa.id);
        printf("///            Descrição: %s\n", tarefa.descricao);
        printf("///            Prazo: %s\n", tarefa.prazo);
        printf("///            status: %c\n", tarefa.status);
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }

    if (!encontrado) {
        printf("/// Nenhuma Tarefa Cadastrada.\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    fclose(fp);
}

void exibe_tarefas_por_prazo(void) {
    FILE *fp;
    Tarefas* tarefa;
    char prazo_informado[20];
    int encontrado = 0;

    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Lista de Tarefas por Prazo                           ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    do {
        printf("/// Prazo das Tarefas (DD/MM/AAAA):                                           ///\n");
        fgets(prazo_informado, sizeof(prazo_informado), stdin);
        remove_enter(prazo_informado);
        if (valida_data(prazo_informado)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma DATA válida!\n");
        }
    } while (1); // Mantém o laço até quw seja valido

    fp = fopen("tarefas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }

    tarefa = (Tarefas*) malloc(sizeof(Tarefas));
    if (tarefa == NULL) {
        printf("Erro ao alocar memória para o morador.\n");
        exit(1);
    }

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");

    while (fread(tarefa, sizeof(Tarefas), 1, fp) == 1) {
        if (tarefa->status == 'a' && strcmp(tarefa->prazo, prazo_informado) == 0) {
            encontrado = 1;
            printf("///            ID da Tarefa: %s\n", tarefa->id);
            printf("///            Descrição: %s\n", tarefa->descricao);
            printf("///////////////////////////////////////////////////////////////////////////////\n"); 
        }
    }

    if (!encontrado) {
        printf("/// Nenhuma Tarefa Cadastrada.\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    free(tarefa);
    fclose(fp);
}

void exibe_tarefas_ativas(void) {
    FILE *fp;
    Tarefas tarefa;
    int encontrado = 0;

    fp = fopen("tarefas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }

    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Lista de Todas as Tarefas Ativas                     ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    while (fread(&tarefa, sizeof(Tarefas), 1, fp)) {
        if (tarefa.status == 'a') {
            encontrado = 1;
            printf("///            ID da Tarefa: %s\n", tarefa.id);
            printf("///            Descrição: %s\n", tarefa.descricao);
            printf("///            Prazo: %s\n", tarefa.prazo);
            printf("///            status: %c\n", tarefa.status);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        }
        
    }

    if (!encontrado) {
        printf("/// Nenhuma Tarefa Cadastrada.\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    fclose(fp);
}