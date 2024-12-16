/*BIBLIOTECAS:*/
#include <stdio.h>
#include <stdlib.h>
#include "despesas.h"
#include "../funcoes/funcoes.h"

void menu_despesas(void){
    int opcao;
    do{
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = = Menu Despesas = = = = = = = = =            ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar uma despesa                                     ///\n");
        printf("///            2. Pesquisar as despesas                                     ///\n");
        printf("///            3. Atualizar despesas                                        ///\n");
        printf("///            4. Excluir uma despesa                                       ///\n");
        printf("///            0. Voltar ao menu anterior                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            cadastrar_despesa();
            break;
        case 2:
            pesquisar_despesa();
            break;
        case 3:
            atualizar_despesa();
            break;
        case 4:
            excluir_despesa();
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

Despesas* cadastrar_despesa(void) {

    Despesas* despesa;
    despesa = (Despesas*) malloc(sizeof(Despesas));
    if (despesa == NULL) {
        printf("Erro ao alocar memória para o despesa.\n");
        exit(1);
    }

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Nova Despesa = = = = = = = = = = = = =   ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados da despesa:                                            ///\n");
    
    printf("///            Descrição: ");
    fgets(despesa->descricao, sizeof(despesa->descricao), stdin);
    remove_enter(despesa->descricao);

    do {
        printf("///            Valor: ");
        fgets(despesa->valor, sizeof(despesa->valor), stdin);
        remove_enter(despesa->valor);
        if (valida_preco(despesa->valor)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma VALOR válido!\n");
        }
    } while (1); // Mantém o laço até quw seja valido

    do {
        printf("///            Data (DD/MM/AAAA): ");
        fgets(despesa->data, sizeof(despesa->data), stdin);
        remove_enter(despesa->data);
        if (valida_data(despesa->data)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma DATA válida!\n");
        }
    } while (1); // Mantém o laço até quw seja valido

    printf("///            id : ");
    fgets(despesa->id, sizeof(despesa->id), stdin);
    remove_enter(despesa->id);

    despesa->status = 'a';

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Despesa cadastrada com sucesso!                              ///\n");
    printf("///            Descrição: %s", despesa->descricao);
    printf("\n");
    printf("///            Valor: %s", despesa->valor);
    printf("\n");
    printf("///            Data: %s", despesa->data);
    printf("\n");
    printf("///            Data: %s", despesa->id);
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();  // Aguarda o usuário pressionar Enter

    salva_despesa(despesa);
    return despesa;

}

Despesas* pesquisar_despesa(void) {

    FILE* fp;
    Despesas* despesa;
    char id_informado[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Despesa      = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o id da despesa:                                                ///\n");
    fgets(id_informado, sizeof(id_informado), stdin);
    remove_enter(id_informado);

    despesa = (Despesas*) malloc(sizeof(Despesas)); // Aloca memória dinâmica
    if (despesa == NULL) {
        printf("Erro ao alocar memória para a despesa.\n");
        exit(1);
    }

    fp = fopen("despesas.dat", "rb"); // Abre arquivo no modo de leitura
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        free(despesa);
        return NULL;
    }

    while (fread(despesa, sizeof(Despesas), 1, fp)) {
        if ((strcmp(despesa->id, id_informado) == 0) && (despesa->status != 'i')) {  // Compara strings e verifica o status
            fclose(fp);
            exibir_despesa(despesa);
            return despesa;  // Retorna o despesa encontrado
        } else {
            printf("///            ID não encontrado!\n");
            break;
        }
    }

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Pausa antes de voltar ao menu

    fclose(fp);
    free(despesa);
    return NULL;
}

void exibir_despesa(const Despesas* despesa) {
    if (despesa == NULL) {
        printf("/// Nenhuma despesa encontrada.\n");
        return;
    }
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            Descrição: %s", despesa->descricao);
    printf("\n");
    printf("///            Valor: %s", despesa->valor);
    printf("\n");
    printf("///            Data: %s", despesa->data);
    printf("\n");
    printf("///            Data: %s", despesa->id);
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Aguarda o usuário pressionar Enter
}


void atualizar_despesa(void) {
    FILE* fp;
    Despesas* despesa;
    char id_informado[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Despesa      = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");

    printf("/// Informe o id da despesa:                                                ///\n");
    fgets(id_informado, sizeof(id_informado), stdin);
    remove_enter(id_informado);

    despesa = (Despesas*) malloc(sizeof(Despesas)); // Aloca memória dinâmica
    if (despesa == NULL) {
        printf("Erro ao alocar memória para a despesa.\n");
        exit(1);
    }

    fp = fopen("despesas.dat", "r+b"); // Abre arquivo no modo de leitura
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        free(despesa);
        return NULL;
    }

    while (fread(despesa, sizeof(Despesas), 1, fp)) {
        if ((strcmp(despesa->id, id_informado) == 0) && (despesa->status != 'i')) {  // Compara strings e verifica o status
            exibir_despesa(despesa);

            printf("///            Descrição: ");
            fgets(despesa->descricao, sizeof(despesa->descricao), stdin);
            remove_enter(despesa->descricao);

            do {
                printf("///            Valor: ");
                fgets(despesa->valor, sizeof(despesa->valor), stdin);
                remove_enter(despesa->valor);
                if (valida_preco(despesa->valor)){
                    break; // Sai do laço apenas se for válido
                } else{
                    printf("///            Insira uma VALOR válido!\n");
                }
            } while (1); // Mantém o laço até quw seja valido

            do {
                printf("///            Data (DD/MM/AAAA): ");
                fgets(despesa->data, sizeof(despesa->data), stdin);
                remove_enter(despesa->data);
                if (valida_data(despesa->data)){
                    break; // Sai do laço apenas se for válido
                } else{
                    printf("///            Insira uma DATA válida!\n");
                }
            } while (1); // Mantém o laço até quw seja valido

            fseek(fp, -sizeof(Despesas), SEEK_CUR);
            fwrite(despesa, sizeof(Despesas), 1, fp);

            printf("///            Dados atualizados com sucesso!\n");
            break;

        } else {
            printf("///            id não encontrado!\n");
            break;
        }
    }

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Pausa antes de voltar ao menu

    fclose(fp);
    free(despesa);
}

void excluir_despesa() {
    FILE* fp;
    Despesas* despesa;
    char id_informado[5];
    
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Despesa        = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");

    printf("/// Informe o id da despesa:                                                ///\n");
    fgets(id_informado, sizeof(id_informado), stdin);
    remove_enter(id_informado);

    despesa = (Despesas*) malloc(sizeof(Despesas)); // Aloca memória dinâmica
    if (despesa == NULL) {
        printf("Erro ao alocar memória para a despesa.\n");
        exit(1);
    }

    fp = fopen("despesas.dat", "r+b"); // Abre arquivo no modo de leitura
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        free(despesa);
        return NULL;
    }

    while (fread(despesa, sizeof(Despesas), 1, fp)) {
        if ((strcmp(despesa->id, id_informado) == 0) && (despesa->status != 'i')) {  // Compara strings e verifica o status
            exibir_despesa(despesa);
            despesa->status = 'i';
            fseek(fp, -sizeof(Despesas), SEEK_CUR);
            fwrite(despesa, sizeof(Despesas), 1, fp);

            printf("///            Dados atualizados com sucesso!\n");
            break;

        } else {
            printf("///            id não encontrado!\n");
            break;
        }
    }

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Pausa antes de voltar ao menu

    fclose(fp);
    free(despesa);
}

void salva_despesa(Despesas* despesa) {
    FILE* fp;
    fp = fopen("despesas.dat", "ab");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }
    fwrite(despesa, sizeof(Despesas), 1, fp);
    fclose(fp);
}