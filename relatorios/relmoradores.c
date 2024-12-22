#include <stdio.h>
#include <stdlib.h>

void relatorios_morador(void) {
    int op;
    do{
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Moradores = = = = = = = = = = = = =     ///\n");
    printf("///                                                                           ///\n");
    printf("///            1. Todos os Moradores                                          ///\n");
    printf("///            2. Moradores por Data de Nascimento                            ///\n");
    printf("///            3. Moradores Ativos                                            ///\n");
    printf("///            4. Moradores Inativos                                          ///\n");
    printf("///            0. Voltar                                                      ///\n");
    printf("///                                                                           ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%d", &op);
    getchar();
    switch (op)
    {
    case 1:
        // Função que mostra todos os moradores (em desenvolvimento)
        break;
    case 2:
        // Função que mostra os moradores pela data de nascimento (em desenvolvimento)
        break;
    case 3:
        // Função que mostra os moradores ativos (em desenvolvimento)
        break;
    case 4:
        // Função que mostra os moradores inativos (em desenvolvimento)
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
