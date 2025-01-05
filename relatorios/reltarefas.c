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
        // Em desenvolvimento
        break;
    case 3:
        // Em desenvolvimento
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