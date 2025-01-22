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
    system("clear||cls");
    Despesas* despesa;
    char valor_int[10];
    despesa = (Despesas*) malloc(sizeof(Despesas));
    if (despesa == NULL) {
        printf("Erro ao alocar memória para o despesa.\n");
        exit(1);
    }

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Nova Despesa = = = = = = = = = = = = =   ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados da despesa:                                            ///\n");
    
    printf("///            Responsavel: ");
    fgets(despesa->cpf_responsavel, sizeof(despesa->cpf_responsavel), stdin);
    remove_enter(despesa->cpf_responsavel);

    printf("///            Descrição: ");
    fgets(despesa->descricao, sizeof(despesa->descricao), stdin);
    remove_enter(despesa->descricao);

    do {
        printf("///            Valor: ");
        fgets(valor_int, 10, stdin); 
        valor_int[strcspn(valor_int, "\n")] = '\0';
        if (valida_preco(valor_int)){
            break; // Sai do laço apenas se for válido
        } else{
            printf("///            Insira uma VALOR válido!\n");
        }
    } while (1); // Mantém o laço até quw seja valido
    despesa->valor = string_to_int(valor_int);
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

    gera_id_despesas(despesa->id);

    despesa->status = 'a';

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();  // Aguarda o usuário pressionar Enter

    salva_despesa(despesa);
    return despesa;

}

Despesas* pesquisar_despesa(void) {
    system("clear||cls");
    FILE* fp;
    Despesas* despesa;
    char id_informado[11];
    int encontrado = 0;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Despesa      = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");
    
   printf("/// Informe o ID da tarefa (DES-XXXXX): ");
    fgets(id_informado, sizeof(id_informado), stdin);
    remove_enter(id_informado);

    despesa = (Despesas*) malloc(sizeof(Despesas));
    if (despesa == NULL) {
        printf("Erro ao alocar memória para o morador.\n");
        exit(1);
    }

    fp = fopen("despesas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        free(despesa);
        return NULL;

    }

    while (fread(despesa, sizeof(Despesas), 1, fp)) {
        if ((strcmp(despesa->id, id_informado)== 0) && (despesa->status != 'i')) {
            encontrado = 1;
            exibir_despesa(despesa);
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
    system("clear||cls");
    if (despesa == NULL) {
        printf("/// Nenhuma despesa encontrada.\n");
        return;
    }
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          ID: %s\n", despesa->id);
    printf("\n");
    printf("///           Responsavel: %s", despesa->cpf_responsavel);
    printf("\n");
    printf("///            Descrição: %s", despesa->descricao);
    printf("\n");
    printf("///            Valor: %i", despesa->valor);
    printf("\n");
    printf("///            Data: %s", despesa->data);
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Aguarda o usuário pressionar Enter
}


void atualizar_despesa(void) {
    system("clear||cls");
    FILE* fp;
    Despesas* despesa;
    char id_informado[11];
    char valor_int[10];
    int encontrado = 0;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Despesa      = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");

    printf("/// Informe o ID da despesa (DES-XXXXX) que deseja atualizar: ");
    fgets(id_informado, sizeof(id_informado), stdin);
    remove_enter(id_informado);

    despesa = (Despesas*) malloc(sizeof(Despesas));
    if (despesa == NULL) {
        printf("Erro ao alocar memória para o morador.\n");
        exit(1);
    }

    fp = fopen("despesas.dat", "r+b");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        free(despesa);
        return NULL;

    }

    while (fread(despesa, sizeof(Despesas), 1, fp)) {
        if ((strcmp(despesa->id, id_informado)== 0) && (despesa->status != 'i')) {
            encontrado = 1;

            exibir_despesa(despesa);

                printf("///            Descrição: ");
        fgets(despesa->descricao, sizeof(despesa->descricao), stdin);
        remove_enter(despesa->descricao);

        do {
            printf("///            Valor: ");
            fgets(valor_int, 10, stdin); 
            valor_int[strcspn(valor_int, "\n")] = '\0';
            if (valida_preco(valor_int)){
                break; // Sai do laço apenas se for válido
            } else{
                printf("///            Insira uma VALOR válido!\n");
            }
        } while (1); // Mantém o laço até quw seja valido
        despesa->valor = string_to_int(valor_int);
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

        } 
    }
    if (!encontrado) {
        printf("///            Despesa não encontrada!\n");
        printf("///                                                                         ///\n");
    }

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Pausa antes de voltar ao menu

    fclose(fp);
    free(despesa);
}

void excluir_despesa() {
    system("clear||cls");
    FILE* fp;
    Despesas* despesa;
    char id_informado[11];
    int encontrado = 0;
    
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Despesa        = = = = = = = = = = = = = = ///\n");
    printf("///                                                                         ///\n");

     printf("/// Informe o ID da despesa (DES-XXXXX) que deseja excluir: ");
    fgets(id_informado, sizeof(id_informado), stdin);
    remove_enter(id_informado);

    despesa = (Despesas*) malloc(sizeof(Despesas));
    if (despesa == NULL) {
        printf("Erro ao alocar memória para o morador.\n");
        exit(1);
    }

    fp = fopen("despesas.dat", "r+b");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        free(despesa);
        return NULL;

    }

    while (fread(despesa, sizeof(Despesas), 1, fp)) {
        if ((strcmp(despesa->id, id_informado)== 0) && (despesa->status != 'i')) {
            encontrado = 1;
            exibir_despesa(despesa);
            despesa->status = 'i';
            fseek(fp, -sizeof(Despesas), SEEK_CUR);
            fwrite(despesa, sizeof(Despesas), 1, fp);

            printf("///            Dados atualizados com sucesso!\n");
            break;

        } 
    }
     if (!encontrado) {
        printf("///            Despesa não encontrada!\n");
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

void gera_id_despesas(char* id_despesas) {
    FILE *fp;
    int contador = 0;

    fp = fopen("id_despesas.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("id_despesas.dat", "wb");

        if (fp == NULL) {
            printf("Erro ao acessar o arquivo de IDs para tarefas!\n");
            exit(1);
        }
        contador = 1;

    } else {
        fread(&contador, sizeof(int), 1, fp);
        contador++;
    }

    rewind(fp);
    fwrite(&contador, sizeof(int), 1, fp);

    fclose(fp);

    sprintf(id_despesas, "DES-%05d", contador);
}

//Créditos: @fillipemdrs https://github.com/Diego-Axel/SIG-DietPlan.git
int string_to_int(char* str) {
    int result = 0;  // Para armazenar o número convertido
    int i = 0;
    while (str[i] != '\0') {
        if (isdigit(str[i])) {  // Verifica se o caractere é um dígito
            result = result * 10 + (str[i] - '0');  // Converte caractere em número
        } else {
            break;  // Para no primeiro caractere não numérico
        }
        i++;
    }
    return result;
}