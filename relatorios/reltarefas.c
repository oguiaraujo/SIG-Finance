#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reltarefas.h"

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
        // Em desenvolvimento
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
