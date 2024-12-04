
typedef struct tarefas Tarefas;

struct tarefas{
    char descricao[100];
    char prazo[20];
    char id[5];
};


void menu_tarefas(void);
void cadastrar_tarefa(void);
void pesquisar_tarefa(void);
void atualizar_tarefa(void);
void excluir_tarefa(void);
