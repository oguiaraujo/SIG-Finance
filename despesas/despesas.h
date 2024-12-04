typedef struct despesas Despesas;

struct despesas {
    char descricao[200];
    char valor[10];
    char data[12];
    char id[5];

};

void menu_despesas(void);
void cadastrar_despesa(Despesas *despesa);
void pesquisar_despesa(Despesas *despesa);
void atualizar_despesa(Despesas *despesa);
void excluir_despesa(Despesas *despesa);
