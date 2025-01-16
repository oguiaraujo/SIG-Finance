
typedef struct tarefas Tarefas;

struct tarefas{
    char cpf_responsavel[13];
    char descricao[101];
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
void insira_descricao(char* descricao, size_t tamanho);
void insira_prazo(char* prazo, size_t tamanho);