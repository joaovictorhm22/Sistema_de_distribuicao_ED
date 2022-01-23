#include "menu.h"

int main()
{
  int expression = 0, opcaoInsumo = 0, opcaoTipo = 0, quantidadeVacina = 0, num_estado = 0, opc_distribuicao_insumo = 0, quantidade_distribuida = 0, opcaoEstado = 0;
  char nome_estado[4], nome_vacina[20], nome_med[20], nome_epi[20];
  bool rodando = true;
  caixa_vacina *lista_vac = 0;
  caixa_medicamento *list = 0; 
  caixa_epi *lista_epi = 0;
  vacina_ditribuida *lista_vac_distribuida = 0;
  medicamento_ditribuida *lista_med_distribuida = 0;
  epi_distribuida *lista_epi_distribuida = 0;

  while (rodando)
  {
    limpaTela();
    expression = opcao();
    switch (expression)
    {
    case 0:
      limpaTela();
      printf("Saindo do programa. ");
      system("pause");
      rodando = false;
      break;
    case 1:
      limpaTela();
      opcaoInsumo = opc_cadastroInsumo();
      switch (opcaoInsumo)
      {
      case 1:
        limpaTela();
        lista_vac = coleta_dados(lista_vac);
        limpaTela();
        printf("Cadastro completo, ");
        system("pause");
        limpaTela();
        break;
      case 2:
        limpaTela();
        list = coleta_de_dados(list);
        limpaTela();
        printf("Cadastro completo, ");
        system("pause");
        limpaTela();
        break;
      case 3:
        limpaTela();
        lista_epi = coleta_dados_epi(lista_epi);
        limpaTela();
        printf("Cadastro completo, ");
        system("pause");
        limpaTela();
        break;
      default:
        limpaTela();
        printf("Voce escolheu uma opcao inexistente,  \n\n\n");
        system("pause");
        limpaTela();
        break;
      }
      break;
    case 2:
      limpaTela();
      tela2();
      if (lista_vac != NULL)
      {
        printf("\n---------- Vacina -----------");
        listar_consult_vac(lista_vac);
      }
      if (list != NULL)
      {
        printf("\n-------- Medicamento --------");
        listar_consult_med(list);
      }
      if (lista_epi != NULL)
      {
        printf("\n------------ epi ------------");
        listar_consult_epi(lista_epi);
        printf("\n-------------------------------------------------\n");
      }
      system("pause");
      break;
    case 3:
      limpaTela();
      tela3();
      if (lista_vac != NULL)
      {
        listar_vac(lista_vac, NULL, 1);
      }
      if (list != NULL)
      {
        listar_med(list, NULL, 1);
      }
      if (lista_epi != NULL)
      {
        listar_epi(lista_epi, NULL, 1);
      }
      printf("-------------------------------------------------\n");
      system("pause");
      break;
    case 4:
      limpaTela();
      tela4();
      opcaoTipo = consulta_por_tipo();
      if (opcaoTipo == 1)
      {
        listar_consult_vac(lista_vac);
        printf("-------------------------------------------------\n");
        system("pause");
      }
      else if (opcaoTipo == 2)
      {
        listar_consult_med(list);
        printf("-------------------------------------------------\n");
        system("pause");
      }
      else if (opcaoTipo == 3)
      {
        listar_consult_epi(lista_epi);
        printf("-------------------------------------------------\n");
        system("pause");
      }
      break;
    case 5:
      limpaTela();
      tela5();
      opcaoEstado = escolha_estado();
      switch (opcaoEstado)
      {
      case 0:
        strcpy(nome_estado, "ACR");
        break;
      case 1:
        strcpy(nome_estado, "ALG");
        break;
      case 2:
        strcpy(nome_estado, "AMP");
        break;
      case 3:
        strcpy(nome_estado, "AMZ");
        break;
      case 4:
        strcpy(nome_estado, "BAH");
        break;
      case 5:
        strcpy(nome_estado, "CEA");
        break;
      case 6:
        strcpy(nome_estado, "DIF");
        break;
      case 7:
        strcpy(nome_estado, "EST");
        break;
      case 8:
        strcpy(nome_estado, "GOI");
        break;
      case 9:
        strcpy(nome_estado, "MAR");
        break;
      case 10:
        strcpy(nome_estado, "MTG");
        break;
      case 11:
        strcpy(nome_estado, "MSL");
        break;
      case 12:
        strcpy(nome_estado, "MGR");
        break;
      case 13:
        strcpy(nome_estado, "PAR");
        break;
      case 14:
        strcpy(nome_estado, "PBA");
        break;
      case 15:
        strcpy(nome_estado, "PRA");
        break;
      case 16:
        strcpy(nome_estado, "PEB");
        break;
      case 17:
        strcpy(nome_estado, "PIA");
        break;
      case 18:
        strcpy(nome_estado, "RJO");
        break;
      case 19:
        strcpy(nome_estado, "RNE");
        break;
      case 20:
        strcpy(nome_estado, "RSL");
        break;
      case 21:
        strcpy(nome_estado, "RON");
        break;
      case 22:
        strcpy(nome_estado, "RRM");
        break;
      case 23:
        strcpy(nome_estado, "SCA");
        break;
      case 24:
        strcpy(nome_estado, "SPO");
        break;
      case 25:
        strcpy(nome_estado, "SER");
        break;
      case 26:
        strcpy(nome_estado, "TOC");
        break;
      default:
        strcpy(nome_estado, "EMS");
        break;
      }
      limpaTela();
      printf("----------------------------- ESTADO %s -----------------------------", nome_estado);
      printf("\n----------- VACINA -----------\n");
      listar_vac_estado(lista_vac_distribuida, nome_estado, 1);
      printf("\n----------- MEDICAMENTO -----------\n");
      listar_med_estado(lista_med_distribuida, nome_estado, 1);
      printf("\n----------- EPI -----------\n");
      listar_epi_estado(lista_epi_distribuida, nome_estado, 1);
      system("pause");
      break;
    case 6:
      limpaTela();
      tela6();
      scanf("%d", &opcaoTipo);
      switch (opcaoTipo)
      {
      case 1:
        limpaTela();
        listar_vac(NULL, lista_vac_distribuida, 2);
        printf("-------------------------------------------------\n");
        system("pause");
        break;
      case 2:
        limpaTela();
        listar_med(NULL, lista_med_distribuida, 2);
        printf("-------------------------------------------------\n");
        system("pause");
        break;
      case 3:
        limpaTela();
        listar_epi(NULL, lista_epi_distribuida, 2);
        printf("-------------------------------------------------\n");
        system("pause");
        break;
      default:
        printf("\nOpcao inexistente, ");
        system("pause");
        break;
      }
      break;
    case 7:
      limpaTela();
      tela7();
      opcaoEstado = escolha_estado();
      switch (opcaoEstado)
      {
      case 0:
        strcpy(nome_estado, "ACR");
        break;
      case 1:
        strcpy(nome_estado, "ALG");
        break;
      case 2:
        strcpy(nome_estado, "AMP");
        break;
      case 3:
        strcpy(nome_estado, "AMZ");
        break;
      case 4:
        strcpy(nome_estado, "BAH");
        break;
      case 5:
        strcpy(nome_estado, "CEA");
        break;
      case 6:
        strcpy(nome_estado, "DIF");
        break;
      case 7:
        strcpy(nome_estado, "EST");
        break;
      case 8:
        strcpy(nome_estado, "GOI");
        break;
      case 9:
        strcpy(nome_estado, "MAR");
        break;
      case 10:
        strcpy(nome_estado, "MTG");
        break;
      case 11:
        strcpy(nome_estado, "MSL");
        break;
      case 12:
        strcpy(nome_estado, "MGR");
        break;
      case 13:
        strcpy(nome_estado, "PAR");
        break;
      case 14:
        strcpy(nome_estado, "PBA");
        break;
      case 15:
        strcpy(nome_estado, "PRA");
        break;
      case 16:
        strcpy(nome_estado, "PEB");
        break;
      case 17:
        strcpy(nome_estado, "PIA");
        break;
      case 18:
        strcpy(nome_estado, "RJO");
        break;
      case 19:
        strcpy(nome_estado, "RNE");
        break;
      case 20:
        strcpy(nome_estado, "RSL");
        break;
      case 21:
        strcpy(nome_estado, "RON");
        break;
      case 22:
        strcpy(nome_estado, "RRM");
        break;
      case 23:
        strcpy(nome_estado, "SCA");
        break;
      case 24:
        strcpy(nome_estado, "SPO");
        break;
      case 25:
        strcpy(nome_estado, "SER");
        break;
      case 26:
        strcpy(nome_estado, "TOC");
        break;
      default:
        strcpy(nome_estado, "EMS");
        break;
      }      
      limpaTela();
      printf("\n----------- VACINA -----------\n");
      listar_vac_estado(lista_vac_distribuida, nome_estado, 2);
      printf("\n----------- MEDICAMENTO -----------\n");
      listar_med_estado(lista_med_distribuida, nome_estado, 2);
      printf("\n----------- EPI -----------\n");
      listar_epi_estado(lista_epi_distribuida, nome_estado, 2);
      system("pause");
      break;
    case 8:
      limpaTela();
      opc_distribuicao();
      opcaoEstado = escolha_estado();
      switch (opcaoEstado)
      {
      case 0:
        strcpy(nome_estado, "ACR");
        break;
      case 1:
        strcpy(nome_estado, "ALG");
        break;
      case 2:
        strcpy(nome_estado, "AMP");
        break;
      case 3:
        strcpy(nome_estado, "AMZ");
        break;
      case 4:
        strcpy(nome_estado, "BAH");
        break;
      case 5:
        strcpy(nome_estado, "CEA");
        break;
      case 6:
        strcpy(nome_estado, "DIF");
        break;
      case 7:
        strcpy(nome_estado, "EST");
        break;
      case 8:
        strcpy(nome_estado, "GOI");
        break;
      case 9:
        strcpy(nome_estado, "MAR");
        break;
      case 10:
        strcpy(nome_estado, "MTG");
        break;
      case 11:
        strcpy(nome_estado, "MSL");
        break;
      case 12:
        strcpy(nome_estado, "MGR");
        break;
      case 13:
        strcpy(nome_estado, "PAR");
        break;
      case 14:
        strcpy(nome_estado, "PBA");
        break;
      case 15:
        strcpy(nome_estado, "PRA");
        break;
      case 16:
        strcpy(nome_estado, "PEB");
        break;
      case 17:
        strcpy(nome_estado, "PIA");
        break;
      case 18:
        strcpy(nome_estado, "RJO");
        break;
      case 19:
        strcpy(nome_estado, "RNE");
        break;
      case 20:
        strcpy(nome_estado, "RSL");
        break;
      case 21:
        strcpy(nome_estado, "RON");
        break;
      case 22:
        strcpy(nome_estado, "RRM");
        break;
      case 23:
        strcpy(nome_estado, "SCA");
        break;
      case 24:
        strcpy(nome_estado, "SPO");
        break;
      case 25:
        strcpy(nome_estado, "SER");
        break;
      case 26:
        strcpy(nome_estado, "TOC");
        break;
      default:
        strcpy(nome_estado, "EMS");
        break;
      }
      printf("1 - Vacina\n2 - Medicamento\n3 - EPI\nDigite uma opcao: ");
      scanf("%d", &opc_distribuicao_insumo);
      switch (opc_distribuicao_insumo)
      {
      case 1:
        printf("Digite o nome da vacina: ");
        scanf("%s", &nome_vacina);
        printf("Digite a quantidade de vacina a ser distribuida: ");
        scanf("%d", &quantidade_distribuida);
        lista_vac_distribuida = distribui_vac(nome_estado, quantidade_distribuida, nome_vacina, lista_vac, lista_vac_distribuida);
        break;
      case 2:
        printf("Digite o nome do medicamento: ");
        scanf("%s", &nome_med);
        printf("Digite a quantidade de medicamento a ser distribuida: ");
        scanf("%d", &quantidade_distribuida);
        lista_med_distribuida = distribui_med(nome_estado, quantidade_distribuida, nome_med, list, lista_med_distribuida);
        break;
      case 3:
        printf("Digite o nome do EPI: ");
        scanf("%s", &nome_epi);
        printf("Digite a quantidade de medicamento a ser distribuida: ");
        scanf("%d", &quantidade_distribuida);
        lista_epi_distribuida = distribui_epi(nome_estado, quantidade_distribuida, nome_epi, lista_epi, lista_epi_distribuida);
        break;
      default:
        printf("Opcao invalida, ");
        system("pause");
        break;
      }
      break;
    default:
      limpaTela();
      printf("Voce escolheu uma opcao inexistente,  \n\n\n");
      system("pause");
      break;
    }
  }
  return 0;
}
