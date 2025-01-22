typedef struct despesas Despesas;

struct despesas {
    char cpf_responsavel[13];
    char descricao[102];
    int valor;
    char data[12];
    char id[11];
    char status;
};

typedef struct lista_des Lista_des;

struct lista_des {
    Despesas* des;
    Lista_des* prox;
};

void menu_despesas(void);
Despesas* cadastrar_despesa(void);
Despesas* pesquisar_despesa(void);
void atualizar_despesa(void);
void excluir_despesa(void);
void gera_id_despesas(char*);
int string_to_int(char* str);
