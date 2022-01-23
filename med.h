#ifndef MED_H_INCLUDED
#define MED_H_INCLUDED
#include"menu.h"

typedef  struct medicamento medicamento;
struct medicamento{
	char nome[15];
	float valor_unitario;	
	int quant_itens;
	char data_vencimento[10];
	float dosagem;
	char nome_fabricante[12];
	  
	char forma_de_uso[20];  //ex: oral, intravenosa etc
	char forma_de_disponi[20]; //(ex: solu��o/l�quido, comprimido, c�psula, etc.);
	char estado[4];
};

typedef struct caixa_medicamento caixa_medicamento;

struct caixa_medicamento{
	struct medicamento info_med;
	struct caixa_medicamento *prox;
};

typedef struct medicamento_ditribuida medicamento_ditribuida;

struct medicamento_ditribuida{
	struct medicamento info_dist;
	struct medicamento_ditribuida *prox;
};


caixa_medicamento *coleta_de_dados(caixa_medicamento *list);
caixa_medicamento *adicionar_med(caixa_medicamento *list,medicamento date);
void listar_med(caixa_medicamento *list,medicamento_ditribuida *lista_med_distribuida, int opcao);
void listar_consult_med(caixa_medicamento *list);
medicamento_ditribuida *adicionar_med_distribuida(medicamento_ditribuida *lista,medicamento vac_distribuida);
medicamento_ditribuida *distribui_med(char lugar[4], int quantidade, char nome_med_dist[20], caixa_medicamento *lista, medicamento_ditribuida *lista_vac_distribuida);
void listar_med_estado(medicamento_ditribuida *lista, char lugar[4], int opcao);
#endif
