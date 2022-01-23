#include "menu.h"
#include "equipamento.h"
#include <string.h>

caixa_epi *coleta_dados_epi(caixa_epi *lista_epi)
{

  epi informacao;
  printf("*******************************\n");
  printf("*                             *\n");
  printf("*       Cadastro de epi       *\n");
  printf("*                             *\n");
  printf("*******************************\n");
  setbuf(stdin, NULL);
  printf("\nNOME DA epi:\n");
  gets(informacao.nome);

  printf("VALOR UNITARIO: \n");
  scanf("%f", &informacao.valor_unitario);

  printf("QUANTIDADE:\n");
  scanf("%d", &informacao.quant_itens);

  setbuf(stdin, NULL);
  printf("DATA DE VENCIMENTO: \n");
  gets(informacao.data_vencimento);
  setbuf(stdin, NULL);

  printf("DETALHE DO epi:\n");
  gets(informacao.detalhe_epi);

  setbuf(stdin, NULL);
  printf("TIPO DA epi:\n");
  gets(informacao.tipo_de_epi);

  setbuf(stdin, NULL);
  printf("FABRICANTE: \n");
  gets(informacao.nome_fabricante);
  setbuf(stdin, NULL);

  strcpy(informacao.estado, "EMS");

  lista_epi = adicionar_epi(lista_epi, informacao);
  return lista_epi;
}

caixa_epi *adicionar_epi(caixa_epi *lista_epi, epi informacao)
{
  bool dadoIgual = false;
  if (lista_epi != NULL)
  {
    caixa_epi *aux = lista_epi;

    strcpy(aux->info_epi.nome, lista_epi->info_epi.nome);
    while (aux != NULL)
    {
      if(strcmp(aux->info_epi.nome, informacao.nome) == 0)
      {
        aux->info_epi.quant_itens += informacao.quant_itens;
        printf("o nome %s foi encontrado na lista\n", aux->info_epi.nome);
        dadoIgual = true;
        break;
      }
      else
      {
        aux = aux->prox;
      }
    }
  }
  if (lista_epi == NULL || dadoIgual == false)
  {
    caixa_epi *novo = 0;
    novo = (struct caixa_epi *)malloc(sizeof(struct caixa_epi)); //*alocando memoria
    if (novo == 0)
    { //*verificando se a alocacao deu errado
      printf("Erro de alocacao\n");
      return lista_epi;
    }
    novo->info_epi = informacao; //preenchendo com as informacoes

    if (lista_epi == 0)
    { // verificando se h� a primeira atribui��o
      novo->prox = NULL;
      lista_epi = novo;
    }
    else
    {
      caixa_epi *aux = lista_epi; //*auxiliar
      while (aux->prox != 0)
      { //* percorrendo a lista_epi
        aux = aux->prox;
      }
      novo->prox = NULL;
      aux->prox = novo;
    }
    return lista_epi;
  }
  return lista_epi;
}

void listar_epi(caixa_epi *lista_epi, epi_distribuida *lista_epi_distribuida, int opcao)
{
  if (lista_epi == NULL && opcao == 1)
  {
    printf("NAO HA INSUMOS DE VACINA CADASTRADOS \n"); //*verificando se a lista já esta vazia
  }
  else if (lista_epi_distribuida == NULL && opcao == 2)
  {
    printf("NENHUMA VACINA  FOI DISTRIBUIDA");
  }
  else
  {
    if (opcao == 1) //passar so o numero da opcao no if
    {
      caixa_epi *aux = lista_epi; //*auxiliar
      while (aux != 0)
      { //* percorrendo e exibindo conteudo
        if(aux->info_epi.quant_itens > 0){
        printf("\nNOME: %s\n", aux->info_epi.nome);
        printf("VALOR UNITARIO: R$%.2f\n", aux->info_epi.valor_unitario);
        printf("QUANTIDADE DE ITENS: %d\n", aux->info_epi.quant_itens);
        printf("VENCIMENTO: %s\n", aux->info_epi.data_vencimento);
        printf("FABRICANTE: %s\n", aux->info_epi.nome_fabricante);
        printf("TIPO DA epi: %s\n", aux->info_epi.tipo_de_epi);
        printf("DETALHE_epi: %s\n", aux->info_epi.detalhe_epi);
        }

        aux = aux->prox;
      }
    }
    if (opcao == 2)
    {
      epi_distribuida *aux = lista_epi_distribuida;
      while (aux != 0)
      { //* percorrendo e exibindo conteudo
        printf("\nNOME: %s\n", aux->info_epi_dist.nome);
        printf("VALOR UNITARIO: R$%.2f\n", aux->info_epi_dist.valor_unitario);
        printf("QUANTIDADE DE ITENS: %d\n", aux->info_epi_dist.quant_itens);
        printf("VENCIMENTO: %s\n", aux->info_epi_dist.data_vencimento);
        printf("FABRICANTE: %s\n", aux->info_epi_dist.nome_fabricante);
        printf("TIPO DA epi: %s\n", aux->info_epi_dist.tipo_de_epi);
        printf("DETALHE_epi: %s\n", aux->info_epi_dist.detalhe_epi);
        printf("ESTADO: %s\n", aux->info_epi_dist.estado);
        aux = aux->prox;
      }
    }
    printf("\n");
  }
}

void listar_consult_epi(caixa_epi *lista_epi)
{
  if (lista_epi == 0)
  {
    printf("Não tem Vacinas cadastrada \n"); //*verificando se a lista já esta vazia
  }
  else
  {
    caixa_epi *aux = lista_epi;
    while (aux != 0)
    {
      if(aux->info_epi.quant_itens > 0){
        printf("\nNOME: %s\n", aux->info_epi.nome);
        printf("QUANTIDADE DE ITENS: %d\n", aux->info_epi.quant_itens);
      }
      aux = aux->prox;
    }
  }
  printf("\n");
}

epi_distribuida *adicionar_epi_distribuida(epi_distribuida *lista, epi epi_dist)
{
  bool dadoIgual = false;
  if (lista != NULL)
  {
    epi_distribuida *aux = lista;
    strcpy(aux->info_epi_dist.nome, lista->info_epi_dist.nome);
    while (aux != NULL)
    {
      if(strcmp(aux->info_epi_dist.nome, epi_dist.nome))
      {
        if (strcmp(aux->info_epi_dist.estado, epi_dist.estado) == 0)
        {
          aux->info_epi_dist.quant_itens += epi_dist.quant_itens;
          dadoIgual = true;
          break;
        }
        else{
          aux = aux->prox;
        }
      }
      else{
        aux = aux->prox;
      }
    }
  }
  if (lista == NULL || dadoIgual == false)
  {
    epi_distribuida *novo = 0;
    novo = (struct epi_distribuida *)malloc(sizeof(struct epi_distribuida)); //*alocando memoria
    if (novo == 0)
    { //*verificando se a alocacao deu errado
      printf("Erro de alocacao\n");
      return lista;
    }
    novo->info_epi_dist = epi_dist; //preenchendo com os dados

    if (lista == 0)
    { // verificando se h� a primeira atribui��o
      novo->prox = NULL;
      lista = novo;
    }
    else
    {
      epi_distribuida *aux = lista; //*auxiliar
      while (aux->prox != 0)
      { //* percorrendo a lista
        aux = aux->prox;
      }
      novo->prox = NULL;
      aux->prox = novo;
    }
    return lista;
  }
  return lista;
}
epi_distribuida *distribui_epi(char lugar[4], int quantidade, char nome_epi_dist[20], caixa_epi *lista, epi_distribuida *lista_epi_distribuida)
{
  if (lista == NULL)
  {
    printf("Nao tem vacina cadastrada. ");
    system("pause");
    return lista_epi_distribuida;
  }
  else
  {
    caixa_epi *aux = lista;
    strcpy(aux->info_epi.nome, lista->info_epi.nome);
    while (aux != NULL)
    {
      if(strcmp(aux->info_epi.nome, nome_epi_dist) == 0)
      {
        if(quantidade > aux->info_epi.quant_itens){
          printf("Quantidade insuficiente no estoque. ");
          system("pause");
          return lista_epi_distribuida;
        }
        break;
      }
      else
      {
        aux = aux->prox;
      }
    }
    if(aux == NULL) {
      printf("Vacina **%s** nao disponivel no estoque\n", nome_epi_dist);
      system("pause");
      return lista_epi_distribuida;
    }
    if (strcmp(aux->info_epi.nome, nome_epi_dist) == 0)
    {
      epi epi_distr;
      aux->info_epi.quant_itens -= quantidade;
      strcpy(epi_distr.nome, aux->info_epi.nome);
      epi_distr.valor_unitario = aux->info_epi.valor_unitario;
      epi_distr.quant_itens = quantidade;
      strcpy(epi_distr.data_vencimento, aux->info_epi.data_vencimento);
      strcpy(epi_distr.nome_fabricante, aux->info_epi.nome_fabricante);
      strcpy(epi_distr.detalhe_epi, aux->info_epi.detalhe_epi);
      strcpy(epi_distr.tipo_de_epi, aux->info_epi.tipo_de_epi);
      strcpy(epi_distr.estado, lugar);
      lista_epi_distribuida = adicionar_epi_distribuida(lista_epi_distribuida, epi_distr);
      printf("Distribuicao concluida, ");
      system("pause");
      return lista_epi_distribuida;
    }
  }
  return lista_epi_distribuida;
}

void listar_epi_estado(epi_distribuida *lista, char lugar[4], int opcao)
{

	if (lista == NULL)
	{
		printf("NAO HA INSUMOS DE EPI DISTRIBUIDOS \n"); //*verificando se a lista já esta vazia
	}
	else if (lista != NULL && opcao == 1)
	{

		epi_distribuida *aux = lista;
		strcpy(aux->info_epi_dist.estado, lista->info_epi_dist.estado);
		while (aux != 0)
		{ //* percorrendo e exibindo conteudo

			if (strcmp(aux->info_epi_dist.estado, lugar) == 0)
			{
				printf("\nNOME: %s\n", aux->info_epi_dist.nome);
        printf("VALOR UNITARIO: R$%.2f\n", aux->info_epi_dist.valor_unitario);
        printf("QUANTIDADE DE ITENS: %d\n", aux->info_epi_dist.quant_itens);
        printf("VENCIMENTO: %s\n", aux->info_epi_dist.data_vencimento);
        printf("FABRICANTE: %s\n", aux->info_epi_dist.nome_fabricante);
        printf("TIPO DA epi: %s\n", aux->info_epi_dist.tipo_de_epi);
        printf("DETALHE_epi: %s\n", aux->info_epi_dist.detalhe_epi);
        printf("ESTADO: %s\n", aux->info_epi_dist.estado);
			}
      
			aux = aux->prox;
		}
	}
	else if (lista != NULL && opcao == 2)
	{
		epi_distribuida *aux = lista;
		while (aux != 0)
		{ //* percorrendo e exibindo conteudo
			if (strcmp(aux->info_epi_dist.estado, lugar) == 0)
			{
				printf("\nNOME: %s\n", aux->info_epi_dist.nome);
				printf("QUANTIDADE DE ITENS: %d\n", aux->info_epi_dist.quant_itens);
			}
			aux = aux->prox;
		}
	}
}