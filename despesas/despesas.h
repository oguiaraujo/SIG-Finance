typedef struct despesas Despesas;

struct despesas {
    char descricao[200];
    char valor[10];
    char data[12];
    char id[5];
    char status;
};

void menu_despesas(void);
Despesas* cadastrar_despesa(void);
Despesas* pesquisar_despesa(void);
void atualizar_despesa(void);
void excluir_despesa(void);
