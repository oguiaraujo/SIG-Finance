typedef struct despesas Despesas;

struct despesas {
    char cpf_responsavel[16];
    char descricao[100];
    char valor[10];
    char data[12];
    char id[11];
    char status;
};

void menu_despesas(void);
Despesas* cadastrar_despesa(void);
Despesas* pesquisar_despesa(void);
void atualizar_despesa(void);
void excluir_despesa(void);
