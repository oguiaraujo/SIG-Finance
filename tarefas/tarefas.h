
typedef struct tarefas Tarefas;

struct tarefas{
    char descricao[100];
    char prazo[20];
    char id[10];
    char status;
};


void menu_tarefas(void);
void cadastrar_tarefa(void);
void pesquisar_tarefa(void);
void exibir_tarefa(const Tarefas* tarefa);
void atualizar_tarefa(void);
void excluir_tarefa(void);
void gera_id_tarefa(char* id_tarefa);