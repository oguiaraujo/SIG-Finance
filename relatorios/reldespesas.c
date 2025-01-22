#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reldespesas.h"
#include "../moradores/moradores.h"

void relatorios_despesa(void) {
    int op;
    do{
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Moradores = = = = = = = = = = = = =     ///\n");
    printf("///                                                                           ///\n");
    printf("///            1. Todas as Despesas                                           ///\n");
    printf("///            2. Todas as Despesas(ordenados por data)                       ///\n");
    printf("///            3. Todas as Despesas(ordenados por valor)                      ///\n");
    printf("///            4. Despesas por Data                                           ///\n");
    printf("///            5. Despesas por Valor                                          ///\n");
    printf("///            6. Despesas Ativas                                             ///\n");
    printf("///            7. Despesas Inativas                                           ///\n");
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
        exibe_datas_ordenadas();
        break;
    case 3:
        exibe_valor_ordenado();
        break;
    case 4:
        exibe_despesa_por_dat();
        break;
    case 5:
        exibe_despesa_por_valor();
        break;
    case 6:
        exibe_despesas_ativas();
        break;
     case 7:
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
        char* nome = get_nome_morador(despesa.cpf_responsavel);
        printf("///            Responsável: %s\n", nome);
        printf("///            Descrição: %s\n", despesa.descricao);
        printf("///            Valor: %i\n", despesa.valor);
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
            char* nome = get_nome_morador(despesa->cpf_responsavel);
            printf("///            Responsável: %s\n", nome);
            printf("///            Descrição: %s\n", despesa->descricao);
            printf("///            Valor: %i\n", despesa->valor);
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
            char* nome = get_nome_morador(despesa->cpf_responsavel);
            printf("///            Responsável: %s\n", nome);
            printf("///            Descrição: %s\n", despesa->descricao);
            printf("///            Data: %s\n", despesa->data);
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
            char* nome = get_nome_morador(despesa.cpf_responsavel);
            printf("///            Responsável: %s\n", nome);
            printf("///            Descrição: %s\n", despesa.descricao);
            printf("///            Valor: %i\n", despesa.valor);
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
            char* nome = get_nome_morador(despesa.cpf_responsavel);
            printf("///            Responsável: %s\n", nome);
            printf("///            Descrição: %s\n", despesa.descricao);
            printf("///            Valor: %i\n", despesa.valor);
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

void exibe_datas_ordenadas(void) {
    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                Lista de Despesas Por Data Ordenada                        ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    Lista_des* primeiro = datas_ordenadas();
    mostra_datas_ordenadas(primeiro);
    free_datas_ordenadas(primeiro);

    
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exibe_valor_ordenado(void) {
    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                Lista de Despesas Por Valor                               ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    Lista_des* primeiro = valor_ordenado();
    mostra_valor_ordenado(primeiro);
    free_valor_ordenado(primeiro);

    
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}



void mostra_datas_ordenadas(Lista_des* primeiro) {
    if (primeiro == NULL) {
        printf("/// Nenhuma tarefa cadastrada!\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        getchar();
        return;
    }

    while (primeiro != NULL) {
            char* nome = get_nome_morador(primeiro->des->cpf_responsavel);
            printf("///            ID da Tarefa: %s\n", primeiro->des->id);
            printf("///            Responsável: %s\n", nome);
            printf("///            Descrição: %s\n", primeiro->des->descricao);
            printf("///            Data: %s\n", primeiro->des->data);
            printf("///            Valor: %i\n", primeiro->des->valor);
            printf("///            status: %c\n", primeiro->des->status);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        primeiro = primeiro->prox;
    }
}

// Créditos: Flavius Gorgônio @flgorgonio
void free_datas_ordenadas(Lista_des* primeiro) {
    Lista *p = primeiro;
    while (p != NULL){
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}

Lista_des* datas_ordenadas(void) {
    FILE* fp;
    Despesas* des;
    Lista_des* novo;
    Lista_des* primeiro = NULL;

    fp = fopen("despesas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 0;
    }

    do {
        des = (Despesas*) malloc(sizeof(Despesas));
        if (fread(des, sizeof(Despesas), 1, fp) != 1) {
            free(des);
            break;
        }

        novo = (Lista_des*) malloc(sizeof(Lista_des));
        novo->des = des;
        novo->prox = NULL;

        if (primeiro == NULL) {
            primeiro = novo;
        } else if (strcmp(novo->des->data + 6, primeiro->des->data + 6) > 0 || 
                   (strcmp(novo->des->data + 6, primeiro->des->data + 6) == 0 && 
                    strcmp(novo->des->data + 3, primeiro->des->data + 3) > 0) ||
                   (strcmp(novo->des->data + 6, primeiro->des->data + 6) == 0 &&
                    strcmp(novo->des->data + 3, primeiro->des->data + 3) == 0 &&
                    strcmp(novo->des->data, primeiro->des->data) > 0) < 0) {
            novo->prox = primeiro;
            primeiro = novo;
        } else {
            Lista_des* anterior = primeiro;
            Lista_des* atual = primeiro->prox;
            while ((atual != NULL) && (strcmp(novo->des->data + 6, atual->des->data + 6) < 0 ||
                  (strcmp(novo->des->data + 6, atual->des->data + 6) == 0 &&
                   strcmp(novo->des->data + 3, atual->des->data + 3) < 0) ||
                  (strcmp(novo->des->data + 6, atual->des->data + 6) == 0 &&
                   strcmp(novo->des->data + 3, atual->des->data + 3) == 0 &&
                   strcmp(novo->des->data, atual->des->data) < 0))) {
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

Lista_des* valor_ordenado(void) {
    FILE* fp;
    Despesas* des;
    Lista_des* novo;
    Lista_des* primeiro = NULL;

    fp = fopen("despesas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 0;
    }

     do{
        des = (Despesas*) malloc(sizeof(Despesas));
        if (fread(des, sizeof(Despesas), 1, fp) != 1) {
            free(des);
            break;
        }

        novo = (Lista_des*) malloc(sizeof(Lista_des));
        novo->des = des;
        novo->prox = NULL; 

        if (primeiro == NULL) {
            primeiro = novo; 
        } else if (novo->des->valor < primeiro->des->valor) {
            novo->prox = primeiro;
            primeiro = novo; 
        } else {
            Lista_des* anterior = primeiro;
            Lista_des* atual = primeiro->prox;
            while ((atual != NULL) && (novo->des->valor > atual->des->valor)) {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = novo; 
            novo->prox = atual;
        }
    }while(1);
    
    fclose(fp); 
    return primeiro;   
}

void mostra_valor_ordenado(Lista_des* primeiro) {
    if (primeiro == NULL) {
        printf("/// Nenhuma tarefa cadastrada!\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        getchar();
        return;
    }

    while (primeiro != NULL) {
            char* nome = get_nome_morador(primeiro->des->cpf_responsavel);
            printf("///            ID da Tarefa: %s\n", primeiro->des->id);
            printf("///            Responsável: %s\n", nome);
            printf("///            Descrição: %s\n", primeiro->des->descricao);
            printf("///            Data: %s\n", primeiro->des->data);
            printf("///            Valor: %i\n", primeiro->des->valor);
            printf("///            status: %c\n", primeiro->des->status);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        primeiro = primeiro->prox;
    }
}

// Créditos: Flavius Gorgônio @flgorgonio
void free_valor_ordenado(Lista_des* primeiro) {
    Lista *p = primeiro;
    while (p != NULL){
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}


