#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relmoradores.h"
#include "../moradores/moradores.h"

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
        exibe_todos_moradores();
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

void exibe_todos_moradores(void) {
    FILE *fp;
    Moradores morador;
    int encontrou = 0;

    fp = fopen("moradores.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao tentar abrir o arquivo de moradores!\n");
        return;
    }
    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Lista de Todos os Moradores                        ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    while (fread(&morador, sizeof(Moradores), 1, fp)) {
        encontrou = 1;
        printf("///            Nome: %s\n", morador.nome);
        printf("///            Data de Nascimento: %s\n", morador.dat_nasc);
        printf("///            E-mail: %s\n", morador.email);
        printf("///            Telefone: %s\n", morador.tel);
        printf("///            CPF: %s\n", morador.cpf);
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }

    if (!encontrou) {
        printf("/// Nenhum morador cadastrado.\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    fclose(fp);
}