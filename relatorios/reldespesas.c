#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reldespesas.h"
#include "../despesas/despesas.h"

void relatorios_despesa(void) {
    int op;
    do{
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Moradores = = = = = = = = = = = = =     ///\n");
    printf("///                                                                           ///\n");
    printf("///            1. Todas as Despesas                                           ///\n");
    printf("///            2. Despesas por Data                                           ///\n");
    printf("///            3. Despesas por Valor                                          ///\n");
    printf("///            4. Despesas Ativas                                             ///\n");
    printf("///            5. Despesas Inativas                                           ///\n");
    printf("///            0. Voltar                                                      ///\n");
    printf("///                                                                           ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%d", &op);
    getchar();
    switch (op)
    {
    case 1:
        exibe_todas_despesas();
        break;
    case 2:
        exibe_despesa_por_dat();
        break;
    case 3:
        exibe_despesa_por_valor();
        break;
    case 4:
        exibe_despesas_ativas();
        break;
    case 5:
        exibe_despesas_inativas();
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
void exibe_todas_despesas(void) {
    FILE *fp;
    Despesas despesa;
    int encontrou = 0;

    fp = fopen("despesas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao tentar abrir o arquivo de despesas!\n");
        return;
    }
    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Lista de Todas as Despesas                            ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////\n");

    while (fread(&despesa, sizeof(Despesas), 1, fp)) {
        encontrou = 1;
        printf("///            Descrição: %s\n", despesa.descricao);
        printf("///            Valor: %s\n", despesa.valor);
        printf("///            Data: %s\n", despesa.data);
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }

    if (!encontrou) {
        printf("/// Nenhuma despesa cadastrada.\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    fclose(fp);
}

void exibe_despesa_por_dat (void) {
    FILE *fp;
    Despesas *despesa;
    char data_informada[20];
    int encontrou = 0;

    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///              Lista de Despesas por Data                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////\n");


    do {
        printf("///            Data de Nascimento (DD/MM/AAAA): ");
        fgets(data_informada, sizeof(data_informada), stdin);
        remove_enter(data_informada);
        if (valida_data(data_informada)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma DATA válida!\n");
        }
    } while (1); // Mantém o laço até que seja valido

    fp = fopen("despesas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao tentar abrir o arquivo de despesas!\n");
        return;
    }

    despesa = malloc(sizeof(Despesas));
    if (despesa == NULL) {
        printf("Erro ao tentar alocar memória");
        fclose(fp);
        return;
    }

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");

    while (fread(despesa,sizeof(Despesas), 1, fp) == 1) {
        if (despesa->status == 'a' && strcmp(despesa->data, data_informada) == 0) {
            encontrou = 1;
            printf("///            Descrição: %s\n", despesa->descricao);
            printf("///            Valor: %s\n", despesa->valor);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        }
    }

    if (!encontrou) {
        printf("Nenhum despesa encontrada com a data %s.\n", data_informada);
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    free(despesa);
    fclose(fp);
}

void exibe_despesa_por_valor (void) {
    FILE *fp;
    Despesas *despesa;
    char valor_informada[20];
    int encontrou = 0;

    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///              Lista de Despesas por Valor                                  ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////\n");


    do {
        printf("///            Valor: ");
        fgets(valor_informada, sizeof(valor_informada), stdin);
        remove_enter(valor_informada);
        if (valida_preco(valor_informada)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma VALOR válido!\n");
        }
    } while (1); // Mantém o laço até que seja valido

    fp = fopen("despesas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao tentar abrir o arquivo de despesas!\n");
        return;
    }

    despesa = malloc(sizeof(Despesas));
    if (despesa == NULL) {
        printf("Erro ao tentar alocar memória");
        fclose(fp);
        return;
    }

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");

    while (fread(despesa,sizeof(Despesas), 1, fp) == 1) {
        if (despesa->status == 'a' && strcmp(despesa->valor, valor_informada) == 0) {
            encontrou = 1;
            printf("///            Descrição: %s\n", despesa->descricao);
            printf("///            Valor: %s\n", despesa->valor);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        }
    }

    if (!encontrou) {
        printf("Nenhum despesa encontrada com o valor informado %s.\n", valor_informada);
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }
    
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    free(despesa);
    fclose(fp);
}

void exibe_despesas_ativas(void) {
    FILE *fp;
    Despesas despesa;
    int encontrou = 0;

    fp = fopen("despesas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao tentar abrir o arquivo de moradores!\n");
        return;
    }
    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Lista de Despesas Ativas                              ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////\n");

    while (fread(&despesa, sizeof(Despesas), 1, fp)) {
        if (despesa.status == 'a') {
            encontrou = 1;
            printf("///            Descrição: %s\n", despesa.descricao);
            printf("///            Valor: %s\n", despesa.valor);
            printf("///            Data: %s\n", despesa.data);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        }
    }

    if (!encontrou) {
        printf("/// Nenhum despesa cadastrada.\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    fclose(fp);
}

void exibe_despesas_inativas(void) {
    FILE *fp;
    Despesas despesa;
    int encontrou = 0;

    fp = fopen("despesas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao tentar abrir o arquivo de despesas!\n");
        return;
    }
    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Lista de Depesas Inativss                             ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////\n");

    while (fread(&despesa, sizeof(Despesas), 1, fp)) {
        if (despesa.status == 'i') {
            encontrou = 1;
            printf("///            Descrição: %s\n", despesa.descricao);
            printf("///            Valor: %s\n", despesa.valor);
            printf("///            Data: %s\n", despesa.data);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        }
    }

    if (!encontrou) {
        printf("/// Nenhum despesa inativa.\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    fclose(fp);
}

