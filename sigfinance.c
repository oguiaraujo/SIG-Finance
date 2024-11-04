
/*BIBLIOTECAS:*/
#include <stdio.h>
#include <stdlib.h>
#include "moradores/moradores.h"
#include "despesas/despesas.h"
#include "tarefas/tarefas.h"
#include "relatorios/relatorios.h"
#include "informacoes/informacoes.h"

/*ASSINATURA DAS FUNÇÕES/FUNCTION'S SIGNATURE*/
void tela_principal(void); /* void: Significa que a função não retorna nenhum valor e (void): Indica que a função não recebe nenhum parâmetro.*/

/*FUNÇÃO MAIN/MAIN FUNCTION:*/
int main(void)
{
    tela_principal();
    return 0;
}

/*FUNÇÕES/FUNCTIONS*/
void tela_principal(void)
{
    int opcao;
    do
    {
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
        printf("///      Um sistema de Gestão de Despesas de uma República Estudantil        ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///             = = = = Sistema de Gestão De Despesas = = = =               ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Módulo Moradores                                          ///\n");
        printf("///            2. Módulo Despesas                                           ///\n");
        printf("///            3. Módulo Tarefas diárias                                    ///\n");
        printf("///            4. Módulo Relatórios                                         ///\n");
        printf("///            5. Módulo Informações                                        ///\n");
        printf("///            0. Sair                                                      ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            menu_moradores();
            break;
        case 2:
            menu_despesas();
            break;
        case 3:
            menu_tarefas();
            break;
        case 4:
            menu_relatorios();
            break;
        case 5:
            menu_informacoes();
            break;
        case 0:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("\t\t\t>Opção inválida! Tente novamente.\n");
            printf("///                                                                         ///\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("\n");
            printf("\t\t\t>Tecle <ENTER> para continuar...\n");
            getchar();
        }
    } while (opcao != 0);
}
