
typedef struct tarefas Tarefas;

struct tarefas{
    char descricao[100];
    char prazo[20];
    char id[5];
    char status;
};


void menu_tarefas(void);
Tarefas* cadastrar_tarefa(void);
Tarefas* pesquisar_tarefa(void);
void exibir_tarefa(const Tarefas* tarefa);
void atualizar_tarefa(void);
void excluir_tarefa(void);

