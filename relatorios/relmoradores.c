#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relmoradores.h"

void relatorios_morador(void) {
    int op;
    do{
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Moradores = = = = = = = = = = = = =     ///\n");
    printf("///                                                                           ///\n");
    printf("///            1. Todos os Moradores                                          ///\n");
    printf("///            2. Todos os Moradores (em ordem alfabética)                    ///\n");
    printf("///            3. Moradores por Data de Nascimento                            ///\n");
    printf("///            4. Moradores Ativos                                            ///\n");
    printf("///            5. Moradores Inativos                                          ///\n");
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
        moradores_alfabeticamente();
        break;
    case 3:
        exibe_morador_por_dat_nasc();
        break;
    case 4:
        exibe_moradores_ativos();
        break;
    case 5:
        exibe_moradores_inativos();
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
        printf("///            Status: %c\n", morador.status);
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

void moradores_alfabeticamente(void) {
    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Lista de Todos os Moradores                        ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    Lista* primeiro = lista_alfabetica();
    exibe_lista(primeiro);
    // Função de Exibir Lista em desenvolvimento...

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exibe_morador_por_dat_nasc (void) {
    FILE *fp;
    Moradores *morador;
    char data_informada[20];
    int encontrou = 0;

    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///              Lista de Moradores por Data de Nascimento                  ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");


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

    fp = fopen("moradores.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao tentar abrir o arquivo de moradores!\n");
        return;
    }

    morador = malloc(sizeof(Moradores));
    if (morador == NULL) {
        printf("Erro ao tentar alocar memória");
        fclose(fp);
        return;
    }

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");

    while (fread(morador,sizeof(Moradores), 1, fp) == 1) {
        if (morador->status == 'a' && strcmp(morador->dat_nasc, data_informada) == 0) {
            encontrou = 1;
            printf("///            Nome: %s\n", morador->nome);
            printf("///            E-mail: %s\n", morador->email);
            printf("///            Telefone: %s\n", morador->tel);
            printf("///            CPF: %s\n", morador->cpf);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        }
    }

    if (!encontrou) {
        printf("Nenhum morador encontrado com a data de nascimento %s.\n", data_informada);
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    free(morador);
    fclose(fp);
}

void exibe_moradores_ativos(void) {
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
    printf("///                     Lista de Moradores Ativos                           ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    while (fread(&morador, sizeof(Moradores), 1, fp)) {
        if (morador.status == 'a') {
            encontrou = 1;
            printf("///            Nome: %s\n", morador.nome);
            printf("///            Data de Nascimento: %s\n", morador.dat_nasc);
            printf("///            E-mail: %s\n", morador.email);
            printf("///            Telefone: %s\n", morador.tel);
            printf("///            CPF: %s\n", morador.cpf);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        }
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

void exibe_moradores_inativos(void) {
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
    printf("///                     Lista de Moradores Inativos                           ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    while (fread(&morador, sizeof(Moradores), 1, fp)) {
        if (morador.status == 'i') {
            encontrou = 1;
            printf("///            Nome: %s\n", morador.nome);
            printf("///            Data de Nascimento: %s\n", morador.dat_nasc);
            printf("///            E-mail: %s\n", morador.email);
            printf("///            Telefone: %s\n", morador.tel);
            printf("///            CPF: %s\n", morador.cpf);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        }
    }

    if (!encontrou) {
        printf("/// Nenhum morador inativo.\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    fclose(fp);
}

Lista* lista_alfabetica(void) {
    FILE* fp;
    Moradores* mrd;
    Lista* novo;
    Lista* primeiro = NULL;

    fp = fopen("moradores.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao tentar abrir o arquivo de moradores!\n");
        return 0;
    }

    do {
        mrd = (Moradores*) malloc(sizeof(Moradores));
        if (fread(mrd, sizeof(Moradores), 1, fp) != 1) {
            free(mrd);
            break;
        }

        novo = (Lista*) malloc(sizeof(Lista));
        novo->mrd = mrd;
        novo->prox = NULL;

        if (primeiro == NULL) {
            primeiro = novo;
        } else if (strcmp(novo->mrd->nome, primeiro->mrd->nome) < 0) {
            novo->prox = primeiro;
            primeiro = novo;
        } else {
            Lista* anterior = primeiro;
            Lista* atual = primeiro->prox;
            while ((atual != NULL) && (strcmp(novo->mrd->nome, atual->mrd->nome) > 0)) {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = novo;
            novo->prox = atual;
        }
    } while(1);
    fclose(fp);
    return primeiro;
}

void exibe_lista(Lista* primeiro) {
    if (primeiro == NULL) {
        printf("/// Nenhum morador cadastrado!\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (primeiro != NULL) {
        printf("///            Nome: %s\n", primeiro->mrd->nome);
        printf("///            Data de Nascimento: %s\n", primeiro->mrd->dat_nasc);
        printf("///            E-mail: %s\n", primeiro->mrd->email);
        printf("///            Telefone: %s\n", primeiro->mrd->tel);
        printf("///            CPF: %s\n", primeiro->mrd->cpf);
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        primeiro = primeiro->prox;
    }
}