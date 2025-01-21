#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reltarefas.h"
#include "../moradores/moradores.h"

void relatorios_tarefas(void) {
    int op;
    do{
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Tarefas = = = = = = = = = = = = =       ///\n");
    printf("///                                                                           ///\n");
    printf("///            1. Todos as Tarefas                                            ///\n");
    printf("///            2. Todas as Tarefas (ordenadas por prazo)                      ///\n");
    printf("///            3. Tarefas por Prazo                                           ///\n");
    printf("///            4. Terefas Ativas                                              ///\n");
    printf("///            5. Tarefas Inativas                                            ///\n");
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
        exibe_prazos_ordenados();
        break;
    case 3:
        exibe_tarefas_por_prazo();
        break;
    case 4:
        exibe_tarefas_ativas();
        break;
    case 5:
        exibe_tarefas_inativas();
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
        char* nome = get_nome_morador(tarefa.cpf_responsavel);
        printf("///            ID da Tarefa: %s\n", tarefa.id);
        printf("///            Responsável: %s\n", nome);
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
            char* nome = get_nome_morador(tarefa->cpf_responsavel);
            printf("///            ID da Tarefa: %s\n", tarefa->id);
            printf("///            Responsável: %s\n", nome);
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

void exibe_prazos_ordenados(void) {
    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                Lista de Tarefas com prazos ordenados                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    
    Lista_tar* primeiro = prazos_ordenados();
    mostra_prazos_ordenados(primeiro);
    // Funções em desenvolvimento

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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
            char* nome = get_nome_morador(tarefa.cpf_responsavel);
            printf("///            ID da Tarefa: %s\n", tarefa.id);
            printf("///            Responsável: %s\n", nome);
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

void exibe_tarefas_inativas(void) {
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
    printf("///                     Lista de Todas as Tarefas Inativas                  ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    while (fread(&tarefa, sizeof(Tarefas), 1, fp)) {
        if (tarefa.status == 'i') {
            encontrado = 1;
            char* nome = get_nome_morador(tarefa.cpf_responsavel);
            printf("///            ID da Tarefa: %s\n", tarefa.id);
            printf("///            Responsável: %s\n", nome);
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

// Adaptado do SIG-DietPlan (https://github.com/Diego-Axel/SIG-DietPlan.git) com ajuda do ChatGPT
Lista_tar* prazos_ordenados(void) {
    FILE* fp;
    Tarefas* tar;
    Lista_tar* novo;
    Lista_tar* primeiro = NULL;

    fp = fopen("tarefas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 0;
    }

    do {
        tar = (Tarefas*) malloc(sizeof(Tarefas));
        if (fread(tar, sizeof(Tarefas), 1, fp) != 1) {
            free(tar);
            break;
        }

        novo = (Lista_tar*) malloc(sizeof(Lista_tar));
        novo->tar = tar;
        novo->prox = NULL;

        if (primeiro == NULL) {
            primeiro = novo;
        } else if (strcmp(novo->tar->prazo + 6, primeiro->tar->prazo + 6) > 0 || 
                   (strcmp(novo->tar->prazo + 6, primeiro->tar->prazo + 6) == 0 && 
                    strcmp(novo->tar->prazo + 3, primeiro->tar->prazo + 3) > 0) ||
                   (strcmp(novo->tar->prazo + 6, primeiro->tar->prazo + 6) == 0 &&
                    strcmp(novo->tar->prazo + 3, primeiro->tar->prazo + 3) == 0 &&
                    strcmp(novo->tar->prazo, primeiro->tar->prazo) > 0) < 0) {
            novo->prox = primeiro;
            primeiro = novo;
        } else {
            Lista_tar* anterior = primeiro;
            Lista_tar* atual = primeiro->prox;
            while ((atual != NULL) && (strcmp(novo->tar->prazo + 6, atual->tar->prazo + 6) < 0 ||
                  (strcmp(novo->tar->prazo + 6, atual->tar->prazo + 6) == 0 &&
                   strcmp(novo->tar->prazo + 3, atual->tar->prazo + 3) < 0) ||
                  (strcmp(novo->tar->prazo + 6, atual->tar->prazo + 6) == 0 &&
                   strcmp(novo->tar->prazo + 3, atual->tar->prazo + 3) == 0 &&
                   strcmp(novo->tar->prazo, atual->tar->prazo) < 0))) {
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


void mostra_prazos_ordenados(Lista_tar* primeiro) {
    if (primeiro == NULL) {
        printf("/// Nenhuma tarefa cadastrada!\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (primeiro != NULL) {
            char* nome = get_nome_morador(primeiro->tar->cpf_responsavel);
            printf("///            ID da Tarefa: %s\n", primeiro->tar->id);
            printf("///            Responsável: %s\n", nome);
            printf("///            Descrição: %s\n", primeiro->tar->descricao);
            printf("///            Prazo: %s\n", primeiro->tar->prazo);
            printf("///            status: %c\n", primeiro->tar->status);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        primeiro = primeiro->prox;
    }
}
