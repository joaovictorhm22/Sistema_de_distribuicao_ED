#include "vac.h"

caixa_vacina *coleta_dados(caixa_vacina *lista_vac)
{

  vacina dados;
  printf("**********************************\n");
  printf("*                                *\n");
  printf("*       Cadastro de Vacina       *\n");
  printf("*                                *\n");
  printf("**********************************\n");
  setbuf(stdin, NULL);
  printf("\nNOME DA VACINA:\n");
  gets(dados.nome);

  printf("VALOR UNITARIO: \n");
  scanf("%f", &dados.valor_unitario);

  printf("QUANTIDADE:\n");
  scanf("%d", &dados.quant_itens);

  setbuf(stdin, NULL);
  printf("DATA DE VENCIMENTO: \n");
  gets(dados.data_vencimento);
  setbuf(stdin, NULL);

  printf("DOSE POR PESSOA:\n");
  scanf("%d", &dados.quant_doses);

  setbuf(stdin, NULL);
  printf("TIPO DA VACINA:\n");
  gets(dados.tipo);

  setbuf(stdin, NULL);
  printf("FABRICANTE: \n");
  gets(dados.nome_fabricante);
  setbuf(stdin, NULL);
  printf("INTERVALO ENTRE AS DOSES (EM DIAS): \n");
  scanf("%d", &dados.intervalo_de_dias);

  strcpy(dados.estado, "EMS");

  lista_vac = adicionar_vac(lista_vac, dados);
  return lista_vac;
}

caixa_vacina *adicionar_vac(caixa_vacina *lista_vac, vacina dados)
{
  bool dadoIgual = false;
  if (lista_vac != NULL)
  {
    caixa_vacina *aux = lista_vac;

    strcpy(aux->info_vac.nome, lista_vac->info_vac.nome);
    while (aux!=NULL)
    {
      if (strcmp(aux->info_vac.nome, dados.nome) == 0)
      {
        aux->info_vac.quant_itens += dados.quant_itens;
        printf("o nome %s foi encontrado na lista\n", aux->info_vac.nome);
        dadoIgual = true;
        break;
      }
      else
      {
        aux = aux->prox;
      }
    }
  }
  if (lista_vac == NULL || dadoIgual == false)
  {
    caixa_vacina *novo = 0;
    novo = (struct caixa_vacina *)malloc(sizeof(struct caixa_vacina)); //*alocando memoria
    if (novo == 0)
    { //*verificando se a alocacao deu errado
      printf("Erro de alocacao\n");
      return lista_vac;
    }
    novo->info_vac = dados; //preenchendo com os dados

    if (lista_vac == 0)
    { // verificando se h� a primeira atribui��o
      novo->prox = NULL;
      lista_vac = novo;
    }
    else
    {
      caixa_vacina *aux = lista_vac; //*auxiliar
      while (aux->prox != 0)
      { //* percorrendo a lista
        aux = aux->prox;
      }
      novo->prox = NULL;
      aux->prox = novo;
    }
    return lista_vac; //warning
  }
  return lista_vac; //warning: control reaches end of non-void function [-Wreturn-type]
}

void listar_vac(caixa_vacina *lista_vac, vacina_ditribuida *lista_vac_distribuida, int opcao)
{
  if (lista_vac == NULL && opcao == 1)
  {
    printf("NAO HA INSUMOS DE VACINA CADASTRADOS \n"); //*verificando se a lista já esta vazia
  }
  else if (lista_vac_distribuida == NULL && opcao == 2)
  {
    printf("NENHUMA VACINA  FOI DISTRIBUIDA");
  }
  else
  {
    if (opcao == 1) //passar so o numero da opcao no if
    {
      caixa_vacina *aux = lista_vac; //*auxiliar
      while (aux != 0)
      { //* percorrendo e exibindo conteudo
        if (aux->info_vac.quant_itens > 0)
        {
          printf("\nNOME: %s\n", aux->info_vac.nome);
          printf("VALOR UNITARIO: R$%.2f\n", aux->info_vac.valor_unitario);
          printf("QUANTIDADE DE ITENS: %d\n", aux->info_vac.quant_itens);
          printf("VENCIMENTO: %s\n", aux->info_vac.data_vencimento);
          printf("TIPO DA VACINA: %s\n", aux->info_vac.tipo);
          printf("FABRICANTE: %s\n", aux->info_vac.nome_fabricante);
          printf("DOSES POR PESSOA: %d\n", aux->info_vac.quant_doses);
          printf("INTERVALO ENTRE AS DOSES (EM DIAS): %d\n", aux->info_vac.intervalo_de_dias);
        }

        aux = aux->prox;
      }
    }
    if (opcao == 2)
    {
      vacina_ditribuida *aux = lista_vac_distribuida;
      while (aux != 0)
      { //* percorrendo e exibindo conteudo
        printf("\nNOME: %s\n", aux->info_vac_dist.nome);
        printf("VALOR UNITARIO: R$%.2f\n", aux->info_vac_dist.valor_unitario);
        printf("QUANTIDADE DE ITENS: %d\n", aux->info_vac_dist.quant_itens);
        printf("VENCIMENTO: %s\n", aux->info_vac_dist.data_vencimento);
        printf("TIPO DA VACINA: %s\n", aux->info_vac_dist.tipo);
        printf("FABRICANTE: %s\n", aux->info_vac_dist.nome_fabricante);
        printf("DOSES POR PESSOA: %d\n", aux->info_vac_dist.quant_doses);
        printf("INTERVALO ENTRE AS DOSES (EM DIAS): %d\n", aux->info_vac_dist.intervalo_de_dias);
        printf("ESTADO: %s\n", aux->info_vac_dist.estado);
        aux = aux->prox;
      }
    }
    printf("\n");
  }
}

void listar_consult_vac(caixa_vacina *lista_vac)
{
  if (lista_vac == 0)
    printf("Não tem Vacinas cadastrada \n"); //*verificando se a lista já esta vazia
  else
  {
    caixa_vacina *aux = lista_vac;
    while (aux != 0)
    {
      if (aux->info_vac.quant_itens > 0)
      {
        printf("\nNOME: %s\n", aux->info_vac.nome);
        printf("QUANTIDADE DE ITENS: %d\n", aux->info_vac.quant_itens);
      }
      aux = aux->prox;
    }
  }
  printf("\n");
}

vacina_ditribuida *adicionar_vac_distribuida(vacina_ditribuida *lista_vac, vacina vac_distribuida)
{
  bool dadoIgual = false;
  if (lista_vac != NULL)
  {
    vacina_ditribuida *aux = lista_vac;
    strcpy(aux->info_vac_dist.nome, lista_vac->info_vac_dist.nome);
    while (aux != NULL)
    {
      if (strcmp(aux->info_vac_dist.nome, vac_distribuida.nome) == 0)
      {
        if (strcmp(aux->info_vac_dist.estado, vac_distribuida.estado) == 0)
        {
          aux->info_vac_dist.quant_itens += vac_distribuida.quant_itens;
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
  if (lista_vac == NULL || dadoIgual == false)
  {
    vacina_ditribuida *novo = 0;
    novo = (struct vacina_ditribuida *)malloc(sizeof(struct vacina_ditribuida)); //*alocando memoria
    if (novo == 0)
    { //*verificando se a alocacao deu errado
      printf("Erro de alocacao\n");
      return lista_vac;
    }
    novo->info_vac_dist = vac_distribuida; //preenchendo com os dados

    if (lista_vac == 0)
    { // verificando se h� a primeira atribui��o
      novo->prox = NULL;
      lista_vac = novo;
    }
    else
    {
      vacina_ditribuida *aux = lista_vac; //*auxiliar
      while (aux->prox != 0)
      { //* percorrendo a lista
        aux = aux->prox;
      }
      novo->prox = NULL;
      aux->prox = novo;
    }
    return lista_vac;
  }
  return lista_vac;
}

vacina_ditribuida *distribui_vac(char lugar[4], int quantidade, char nome_vac_dist[20], caixa_vacina *lista_vac, vacina_ditribuida *lista_vac_distribuida)
{
  if (lista_vac == NULL)
  {
    printf("Nao tem vacina cadastrada. ");
    system("pause");
    return lista_vac_distribuida;
  }
  else
  {
    caixa_vacina *aux = lista_vac;
    strcpy(aux->info_vac.nome, lista_vac->info_vac.nome);
    while (aux != NULL)
    {
      if (strcmp(aux->info_vac.nome, nome_vac_dist) == 0)
      {
        if(quantidade > aux->info_vac.quant_itens){
          printf("Quantidade insuficiente no estoque. ");
          system("pause");
          return lista_vac_distribuida;
        }
        break;
      }
      else
      {
        aux = aux->prox;
      }
    }
    if(aux == NULL) {
      printf("Vacina **%s** nao disponivel no estoque\n", nome_vac_dist);
      system("pause");
      return lista_vac_distribuida;
    }
    if (strcmp(aux->info_vac.nome, nome_vac_dist) == 0)
    {
      vacina vac_distribuida;
      aux->info_vac.quant_itens -= quantidade;
      strcpy(vac_distribuida.nome, aux->info_vac.nome);
      vac_distribuida.valor_unitario = aux->info_vac.valor_unitario;
      vac_distribuida.quant_itens = quantidade;
      strcpy(vac_distribuida.data_vencimento, aux->info_vac.data_vencimento);
      vac_distribuida.quant_doses = aux->info_vac.quant_doses;
      strcpy(vac_distribuida.nome_fabricante, aux->info_vac.nome_fabricante);
      vac_distribuida.intervalo_de_dias = aux->info_vac.intervalo_de_dias;
      strcpy(vac_distribuida.tipo, aux->info_vac.tipo);
      strcpy(vac_distribuida.estado, lugar);
      lista_vac_distribuida = adicionar_vac_distribuida(lista_vac_distribuida, vac_distribuida);
      printf("Distribuicao concluida, ");
      system("pause");
      return lista_vac_distribuida;
    }
  }
  return lista_vac_distribuida;
}

void listar_vac_estado(vacina_ditribuida *lista_vac, char lugar[4], int opcao)
{
 
  if (lista_vac == NULL)
  {
    printf("NAO HA INSUMOS DE VACINA DISTRIBUIDOS \n"); //*verificando se a lista já esta vazia
  }
  else if (lista_vac != NULL && opcao == 1)
  {

    vacina_ditribuida *aux = lista_vac;
    strcpy(aux->info_vac_dist.estado, lista_vac->info_vac_dist.estado);
    while (aux != 0)
    { //* percorrendo e exibindo conteudo

      if (strcmp(aux->info_vac_dist.estado, lugar) == 0)
      {
        if (aux->info_vac_dist.quant_itens > 0)
        {
          printf("\nNOME: %s\n", aux->info_vac_dist.nome);
          printf("VALOR UNITARIO: R$%.2f\n", aux->info_vac_dist.valor_unitario);
          printf("QUANTIDADE DE ITENS: %d\n", aux->info_vac_dist.quant_itens);
          printf("VENCIMENTO: %s\n", aux->info_vac_dist.data_vencimento);
          printf("TIPO DA VACINA: %s\n", aux->info_vac_dist.tipo);
          printf("FABRICANTE: %s\n", aux->info_vac_dist.nome_fabricante);
          printf("DOSES POR PESSOA: %d\n", aux->info_vac_dist.quant_doses);
          printf("INTERVALO ENTRE AS DOSES (EM DIAS): %d\n", aux->info_vac_dist.intervalo_de_dias);
          printf("ESTADO: %s\n", aux->info_vac_dist.estado);
        }
      }
      aux = aux->prox;
    }
  }
  else if (lista_vac != NULL && opcao == 2)
  {
    vacina_ditribuida *aux = lista_vac;
    while (aux != 0)
    { //* percorrendo e exibindo conteudo
      if (strcmp(aux->info_vac_dist.estado, lugar) == 0)
      {
        printf("\nNOME: %s\n", aux->info_vac_dist.nome);
        printf("QUANTIDADE DE ITENS: %d\n", aux->info_vac_dist.quant_itens);
      }
      aux = aux->prox;
    }
  }
}