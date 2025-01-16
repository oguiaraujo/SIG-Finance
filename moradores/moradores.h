
typedef struct moradores Moradores;

struct moradores {
    char nome[50];
    char dat_nasc[12];
    char email[50];
    char tel[17];
    char cpf[13];
    char status;
};

void menu_moradores(void);
void cadastrar_morador(void);
void pesquisar_morador(void);
void exibir_morador(const Moradores* morador);
void atualizar_morador(void);
void excluir_morador(void);
void salva_morador(Moradores* morador);
void insira_nome(char* nome, size_t tamanho);
void insira_data(char* data, size_t tamanho);
void insira_email(char* email, size_t tamanho);
void insira_telefone(char* tel, size_t tamanho);
void insira_cpf(char* cpf, size_t tamanho);
char* get_cpf_morador(char* cpf_procurado);
char* get_nome_morador(char* cpf_procurado);