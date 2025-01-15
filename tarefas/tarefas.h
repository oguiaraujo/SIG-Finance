
typedef struct tarefas Tarefas;

struct tarefas{
    char cpf_responsavel[16];
    char descricao[102];
    char prazo[12];
    char id[11];
    char status;
};


void menu_tarefas(void);
void cadastrar_tarefa(void);
void pesquisar_tarefa(void);
void exibir_tarefa(const Tarefas* tarefa);
void atualizar_tarefa(void);
void excluir_tarefa(void);
void gera_id_tarefa(char* id_tarefa);