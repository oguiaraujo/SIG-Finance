
typedef struct moradores Moradores;

struct moradores {
    char nome[50];
    char dat_nasc[20];
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
