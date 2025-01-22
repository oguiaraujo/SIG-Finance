#include "../despesas/despesas.h"

void relatorios_despesa(void);
void exibe_todas_despesas(void);
void exibe_despesa_por_dat(void);
void exibe_despesa_por_valor(void);
void exibe_despesas_ativas(void);
void exibe_despesas_inativas(void);
void exibe_datas_ordenadas(void);
Lista_des* datas_ordenadas(void);
void mostra_datas_ordenadas(Lista_des* primeiro);
void free_datas_ordenadas(Lista_des* primeiro);