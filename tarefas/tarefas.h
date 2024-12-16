
typedef struct tarefas Tarefas;

struct tarefas{
    char descricao[100];
    char prazo[20];
    char id[5];
    char status;
};

void menu_tarefas(void);
Tarefas* cadastrar_tarefa(void);
void pesquisar_tarefa(Tarefas *tarefa);
void atualizar_tarefa(Tarefas *tarefa);
void excluir_tarefa(Tarefas *tarefa);
