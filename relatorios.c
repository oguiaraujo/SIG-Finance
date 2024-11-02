/*BIBLIOTECAS:*/
#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"


void menu_relatorios(void){
     int opcao;
     do{
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = = Menu Relatórios = = = = = = = = =          ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Relatórios de moradores                                   ///\n");
        printf("///            2. Relatórios de despesas                                    ///\n");
        printf("///            3. Relatórios de tarefas                                     ///\n");
        printf("///            0. Retornar ao menu principal                                ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            relatorios_morador();
            break;
        case 2:
            relatorios_despesa();
            break;
        case 3:
            relatorios_tarefa();
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

void relatorios_morador(void)
{
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Moradores = = = = = = = = = = = = =   ///\n");
    // Implementar a geração do relatório
    printf("///////////////////////////////////////////////////////////////////////////////\n");
}

void relatorios_despesa(void)
{
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Despesas = = = = = = = = = = = = =    ///\n");
    // Implementar a geração do relatório
    printf("///////////////////////////////////////////////////////////////////////////////\n");
}

void relatorios_tarefa(void)
{
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Tarefas = = = = = = = = = = = = =     ///\n");
    // Implementar a geração do relatório
    printf("///////////////////////////////////////////////////////////////////////////////\n");
}
