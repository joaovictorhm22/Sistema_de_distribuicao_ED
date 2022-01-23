#ifndef VAC_H_INCLUDED
#define VAC_H_INCLUDED
#include "menu.h"
typedef struct vacina vacina;

struct vacina{
	char nome[20];
	float valor_unitario;
	int quant_itens;
	char data_vencimento[10]; 
	int quant_doses; 
	char nome_fabricante[12];
	int intervalo_de_dias;
	char tipo[20];
	char estado[4];
};
typedef struct caixa_vacina caixa_vacina;

struct caixa_vacina{
	struct vacina info_vac;   //info
	struct caixa_vacina *prox;
};

typedef struct vacina_ditribuida vacina_ditribuida;

struct vacina_ditribuida{
	struct vacina info_vac_dist;  //info_dist
	struct vacina_ditribuida *prox;
};

caixa_vacina *coleta_dados(caixa_vacina*lista_vac);
caixa_vacina *adicionar_vac(caixa_vacina *lista_vac, vacina dados);
void listar_vac(caixa_vacina *lista_vac, vacina_ditribuida *lista_vac_distribuida,int opcao);
void listar_consult_vac(caixa_vacina *lista_vac);
vacina_ditribuida *adicionar_vac_distribuida(vacina_ditribuida *lista_vac,vacina vac_distribuida);
vacina_ditribuida *distribui_vac(char lugar[4], int quantidade, char nome_vac_dist[20], caixa_vacina *lista_vac, vacina_ditribuida *lista_vac_distribuida);
void listar_vac_estado(vacina_ditribuida *lista_vac, char lugar[4], int opcao);

#endif
