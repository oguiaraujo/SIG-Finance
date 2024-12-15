typedef struct despesas Despesas;

struct despesas {
    char descricao[200];
    char valor[10];
    char data[12];
    char id[5];

};

void menu_despesas(void);
Despesas* cadastrar_despesa(void);
Despesas* pesquisar_despesa(void);
void atualizar_despesa(void);
void excluir_despesa(Despesas *despesa);
