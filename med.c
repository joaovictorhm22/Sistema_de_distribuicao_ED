#include "med.h"

caixa_medicamento *coleta_de_dados(caixa_medicamento *list)
{

	medicamento date;
	printf("***************************************\n");
	printf("*                                     *\n");
	printf("*       Cadastro de Medicamento       *\n");
	printf("*                                     *\n");
	printf("***************************************\n");
	setbuf(stdin, NULL);
	printf("\nNOME DO MEDICAMENTO:\n");
	gets(date.nome);

	printf("VALOR UNITARIO: \n");
	scanf("%f", &date.valor_unitario);

	printf("QUANTIDADE:\n");
	scanf("%d", &date.quant_itens);

	setbuf(stdin, NULL);
	printf("DATA DE VENCIMENTO: \n");
	gets(date.data_vencimento);
	setbuf(stdin, NULL);

	printf("DOSAGEM (mg):\n");
	scanf("%f", &date.dosagem);

	setbuf(stdin, NULL);
	printf("FORMA DE USO:\n");
	gets(date.forma_de_uso);

	setbuf(stdin, NULL);
	printf("FABRICANTE: \n");
	gets(date.nome_fabricante);
	setbuf(stdin, NULL);
	printf("FORMA DE DISPONIBILIZACAO: \n");
	gets(date.forma_de_disponi);
	setbuf(stdin, NULL);

	strcpy(date.estado, "EMS");

	list = adicionar_med(list, date);
	return list;
}

caixa_medicamento *adicionar_med(caixa_medicamento *list, medicamento date)
{
	bool dadoIgual = false;
	if (list != NULL)
	{
		caixa_medicamento *aux = list;

		strcpy(aux->info_med.nome, list->info_med.nome);
		while (aux != NULL)
		{
      if (strcmp(aux->info_med.nome, date.nome) == 0)
      {
        aux->info_med.quant_itens += date.quant_itens;
        printf("o valor %s foi encontrado na lista\n", aux->info_med.nome);
        dadoIgual = true;
        break;
      }
      else
      {
			  aux = aux->prox;
      }
		}
	}
	if (list == NULL || dadoIgual == false)
	{
		caixa_medicamento *novo = 0;
		novo = (struct caixa_medicamento *)malloc(sizeof(struct caixa_medicamento)); //*alocando memoria
		if (novo == 0)
		{ //*verificando se a alocacao deu errado
			printf("Erro de alocacao\n");
			return list;
		}

		novo->info_med = date; //preenchendo com os dados

		if (list == 0)
		{ // verificando se h� a primeira atribui��o
			novo->prox = NULL;
			list = novo;
		}
		else
		{
			caixa_medicamento *aux = list; //*auxiliar
			while (aux->prox != 0)
			{ //* percorrendo a lista
				aux = aux->prox;
			}
			novo->prox = NULL;
			aux->prox = novo;
		}
		return list;
	}
	return list;
}
void listar_med(caixa_medicamento *list, medicamento_ditribuida *lista_med_distribuida, int opcao)
{
	if (list == NULL && opcao == 1)
	{
		printf("NAO HA INSUMO DE MEDICAMENTO CADASTRADO"); //*verificando se a lista já esta vazia
	}
	else if (lista_med_distribuida == NULL && opcao == 2)
	{
		printf("NENHUM MEDICAMENTO FOI DISTRIBUIDO");
	}
	else
	{
		if (opcao == 1)
		{
			caixa_medicamento *aux = list; //*auxiliar
			while (aux != 0)
			{ //* percorrendo e exibindo conteudo
				if(aux->info_med.quant_itens > 0){
          printf("\nNOME: %s\n", aux->info_med.nome);
          printf("VALOR UNITARIO: %.2f\n", aux->info_med.valor_unitario);
          printf("QUANTIDADE DE ITENS: %d\n", aux->info_med.quant_itens);
          printf("FABRICANTE: %s\n", aux->info_med.nome_fabricante);
          printf("DOSAGEM (mg): %f\n", aux->info_med.dosagem);
          printf("FORMA DE USO: %s\n", aux->info_med.forma_de_uso);
          printf("FORMA DE DISPONIBILIZACAO:: %s\n", aux->info_med.forma_de_disponi);
          printf("VENCIMENTO: %s\n", aux->info_med.data_vencimento);
        }
				aux = aux->prox;
			}
		}
		if (opcao == 2)
		{
			medicamento_ditribuida *aux = lista_med_distribuida; //*auxiliar
			while (aux != 0)
			{ //* percorrendo e exibindo conteudo
				printf("\nNOME: %s\n", aux->info_dist.nome);
				printf("VALOR UNITARIO: %.2f\n", aux->info_dist.valor_unitario);
				printf("QUANTIDADE DE ITENS: %d\n", aux->info_dist.quant_itens);
				printf("FABRICANTE: %s\n", aux->info_dist.nome_fabricante);
				printf("DOSAGEM (mg): %f\n", aux->info_dist.dosagem);
				printf("FORMA DE USO: %s\n", aux->info_dist.forma_de_uso);
				printf("FORMA DE DISPONIBILIZAR: %s\n", aux->info_dist.forma_de_disponi);
				printf("VENCIMENTO: %s\n", aux->info_dist.data_vencimento);
				printf("ESTADO: %s", aux->info_dist.estado);
				aux = aux->prox;
			}
		}
		printf("\n");
	}
}
void listar_consult_med(caixa_medicamento *list)
{
	if (list == 0)
		printf("Não tem Medicamentos cadastrados\n"); //*verificando se a lista já esta vazia
	else
	{
		caixa_medicamento *aux = list; //*auxiliar
		while (aux != 0)
		{
      if(aux->info_med.quant_itens > 0){
			  printf("\nNOME: %s\n", aux->info_med.nome);
			  printf("QUANTIDADE DE ITENS: %d\n", aux->info_med.quant_itens);
      }
			aux = aux->prox;
		}
	}
  printf("\n");
}

medicamento_ditribuida *adicionar_med_distribuida(medicamento_ditribuida *lista, medicamento med_distribuida)
{
	bool dadoIgual = false;
	if (lista != NULL)
	{
		medicamento_ditribuida *aux = lista;
		strcpy(aux->info_dist.nome, lista->info_dist.nome);
		while (aux != NULL)
		{
      if (strcmp(aux->info_dist.nome, med_distribuida.nome) == 0)
      {
        if (strcmp(aux->info_dist.estado, med_distribuida.estado) == 0)
        {
          lista->info_dist.quant_itens += med_distribuida.quant_itens;
          dadoIgual = true;
          break;
        }
        else {
			    aux = aux->prox;
        }
      }
      else {
        aux = aux->prox;
      }
		}
	}
	if (lista == NULL || dadoIgual == false)
	{
		medicamento_ditribuida *novo = 0;
		novo = (struct medicamento_ditribuida *)malloc(sizeof(struct medicamento_ditribuida)); //*alocando memoria
		if (novo == 0)
		{ //*verificando se a alocacao deu errado
			printf("Erro de alocacao\n");
			return lista;
		}
		novo->info_dist = med_distribuida; //preenchendo com os dados

		if (lista == 0)
		{ // verificando se h� a primeira atribui��o
			novo->prox = NULL;
			lista = novo;
		}
		else
		{
			medicamento_ditribuida *aux = lista; //*auxiliar
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

medicamento_ditribuida *distribui_med(char lugar[4], int quantidade, char nome_med_dist[20], caixa_medicamento *lista, medicamento_ditribuida *lista_medicamento_ditribuida)
{
	if (lista == NULL)
	{
		return lista_medicamento_ditribuida;
		printf("Nao tem vacina cadastrada. ");
		system("pause");
	}
	else
	{
		caixa_medicamento *aux = lista;
    strcpy(aux->info_med.nome, lista->info_med.nome);
    while (aux != NULL)
    {
      if(strcmp(aux->info_med.nome, nome_med_dist) == 0)
      {
        if(quantidade > aux->info_med.quant_itens){
          printf("Quantidade insuficiente no estoque. ");
          system("pause");
          return lista_medicamento_ditribuida;
        }
        break;
      }
      else
      {
        aux = aux->prox;
      }
    }
    if(aux == NULL){
      printf("Vacina **%s** nao disponivel no estoque\n", nome_med_dist);
      system("pause");
      return lista_medicamento_ditribuida;
    }
    if (strcmp(aux->info_med.nome, nome_med_dist) == 0)
    {
      medicamento medicamento_ditribuida;
      aux->info_med.quant_itens -= quantidade;
      strcpy(medicamento_ditribuida.nome, aux->info_med.nome);
      medicamento_ditribuida.valor_unitario = aux->info_med.valor_unitario;
      medicamento_ditribuida.quant_itens = quantidade;
      strcpy(medicamento_ditribuida.data_vencimento, aux->info_med.data_vencimento);
      strcpy(medicamento_ditribuida.nome_fabricante, aux->info_med.nome_fabricante);
      medicamento_ditribuida.dosagem = aux->info_med.dosagem;
      strcpy(medicamento_ditribuida.forma_de_uso, aux->info_med.forma_de_uso);
      strcpy(medicamento_ditribuida.forma_de_disponi, aux->info_med.forma_de_disponi);
      strcpy(medicamento_ditribuida.estado, lugar);
      lista_medicamento_ditribuida = adicionar_med_distribuida(lista_medicamento_ditribuida, medicamento_ditribuida);
      printf("Distribuicao concluida, ");
      system("pause");
      return lista_medicamento_ditribuida;
    }
  }
  return lista_medicamento_ditribuida;
}

void listar_med_estado(medicamento_ditribuida *lista, char lugar[4], int opcao)
{

	if (lista == NULL)
	{
		printf("NAO HA INSUMOS DE MEIDCAMENTO DISTRIBUIDOS \n"); //*verificando se a lista já esta vazia
	}
	else if (lista != NULL && opcao == 1)
	{

		medicamento_ditribuida *aux = lista;
		strcpy(aux->info_dist.estado, lista->info_dist.estado);
		while (aux != 0)
		{ //* percorrendo e exibindo conteudo

			if (strcmp(aux->info_dist.estado, lugar) == 0)
			{
        if(aux->info_dist.quant_itens > 0){
          printf("\nNOME: %s\n", aux->info_dist.nome);
          printf("VALOR UNITARIO: %.2f\n", aux->info_dist.valor_unitario);
          printf("QUANTIDADE DE ITENS: %d\n", aux->info_dist.quant_itens);
          printf("FABRICANTE: %s\n", aux->info_dist.nome_fabricante);
          printf("DOSAGEM (mg): %f\n", aux->info_dist.dosagem);
          printf("FORMA DE USO: %s\n", aux->info_dist.forma_de_uso);
          printf("FORMA DE DISPONIBILIZAR: %s\n", aux->info_dist.forma_de_disponi);
          printf("VENCIMENTO: %s\n", aux->info_dist.data_vencimento);
          printf("ESTADO: %s", aux->info_dist.estado);
        }
			}
			aux = aux->prox;
		}
	}
	else if (lista != NULL && opcao == 2)
	{
		medicamento_ditribuida *aux = lista;
		while (aux != 0)
		{ //* percorrendo e exibindo conteudo
			if (strcmp(aux->info_dist.estado, lugar) == 0)
			{
				printf("\nNOME: %s\n", aux->info_dist.nome);
				printf("QUANTIDADE DE ITENS: %d\n", aux->info_dist.quant_itens);
			}
			aux = aux->prox;
		}
	}
}