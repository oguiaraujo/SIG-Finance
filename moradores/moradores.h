
typedef struct moradores Moradores;

struct moradores {
    char nome[50];
    char dat_nasc[20];
    char email[50];
    char tel[17];
    char cpf[13];
};

void menu_moradores(void);
void cadastrar_morador(Moradores *morador);
void pesquisar_morador(Moradores *morador);
void atualizar_morador(Moradores *morador);
void excluir_morador(Moradores *morador);
