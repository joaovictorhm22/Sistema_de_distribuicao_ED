#ifndef EQUIPAMENTO_H_INCLUDED
#define EQUIPAMENTO_H_INCLUDED
#include"menu.h"
typedef  struct epi epi;
struct epi{
	char nome[20];
	float valor_unitario;
	int quant_itens;
	char data_vencimento[10];
	char nome_fabricante[20];
	
	char detalhe_epi[20];
	char tipo_de_epi[20];
	char estado[4];
	
	

};
typedef struct caixa_epi caixa_epi;
struct caixa_epi{
	struct epi info_epi;
	struct caixa_epi *prox;
};

typedef struct epi_distribuida epi_distribuida;
struct epi_distribuida {
	struct epi info_epi_dist;
	struct epi_distribuida *prox;
};

caixa_epi *coleta_dados_epi(caixa_epi *lista_epi);
caixa_epi *adicionar_epi(caixa_epi *lista_epi,epi informacao);
void listar_epi(caixa_epi *lista_epi, epi_distribuida *lista_epi_distribuida, int opcao);
void listar_consult_epi(caixa_epi *lista_epi);
epi_distribuida *adicionar_epi_distribuida(epi_distribuida *lista, epi epi_dist);
epi_distribuida *distribui_epi(char lugar[4], int quantidade, char nome_epi_dist[20], caixa_epi *lista, epi_distribuida *lista_epi_distribuida);
void listar_epi_estado(epi_distribuida *lista, char lugar[4], int opcao);

#endif
