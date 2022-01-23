#include "menu.h"

int opcao() {
  int numero = 0;
  printf("\n");
  printf("***********************************************************\n");
  printf("*                                                         *\n");
  printf("*   Sistemas de gerenciamento e distribuicao de insumos   *\n");
  printf("*                                                         *\n");
  printf("***********************************************************\n");
  printf("\n1 - Cadastro de insumo no estoque MS"); 
  printf("\n2 - Consulta de insumos no estoque MS");
  printf("\n3 - Descricao de insumos no estoque MS");
  printf("\n4 - Consulta de insumos no estoque MS por tipo");
  printf("\n5 - Descricao de insumos distribuidos por estado");
  printf("\n6 - Consulta de insumos distribudos para estados por tipo");
  printf("\n7 - Consulta de insumos distribuidos por estado");
  printf("\n8 - Distribuir insumos para estados");
  printf("\n0 - Sair do programa");
  printf("\nEscolha uma opcao: ");
  scanf("%d", &numero);
  return numero;
}

void limpaTela() {
  system("cls");  
}

int opc_cadastroInsumo() {
  int numero = 0;
  printf("\n");
  printf("**********************************\n");
  printf("*                                *\n");
  printf("*       Cadastro de Insumo       *\n");
  printf("*                                *\n");
  printf("**********************************\n");
  printf("\n1 - Cadastro de Vacinas"); 
  printf("\n2 - Cadastro de Medicamentos");
  printf("\n3 - Cadastro de epi");
  printf("\nEscolha uma opcao: ");
  scanf("%d", &numero);
  return numero;
}

int consulta_por_tipo(){
  int numero = 0;	
  printf("\n");
  printf("**********************************\n");
  printf("*                                *\n");
  printf("*       Consulta de Insumo       *\n");
  printf("*                                *\n");
  printf("**********************************\n");
  printf("\n1 - CONSULTAR VACINA"); 
  printf("\n2 - CONSULTAR MEDICAMENTOS");
  printf("\n3 - CONSULTAR epi");
  printf("\nEscolha uma opcao: ");
  scanf("%d", &numero);
  return numero;
}

void tela2()
{
  printf("*****************************************\n");
  printf("*                                       *\n");
  printf("*   Consulta de insumos no estoque MS   *\n");
  printf("*                                       *\n");
  printf("*****************************************\n");
}

void tela3()
{
  printf("******************************************\n");
  printf("*                                        *\n");
  printf("*   Descricao de insumos no estoque MS   *\n");
  printf("*                                        *\n");
  printf("******************************************\n");
}

void tela4()
{
  printf("**************************************************\n");
  printf("*                                                *\n");
  printf("*   Consulta de insumos no estoque MS por tipo   *\n");
  printf("*                                                *\n");
  printf("**************************************************\n");
}

void tela5() {
  printf("****************************************************\n");
  printf("*                                                  *\n");
  printf("*   Descricao de insumos distribuidos por estado   *\n");
  printf("*                                                  *\n");
  printf("****************************************************\n");
}

void tela6()
{
  printf("*************************************************************\n");
  printf("*                                                           *\n");
  printf("*   Consulta de insumos distribudos para estados por tipo   *\n");
  printf("*                                                           *\n");
  printf("*************************************************************\n");
  printf("\n1 - CONSULTAR VACINA"); 
  printf("\n2 - CONSULTAR MEDICAMENTOS");
  printf("\n3 - CONSULTAR epi");
  printf("\nEscolha uma opcao: ");
}

void tela7() {
  printf("****************************************************\n");
  printf("*                                                  *\n");
  printf("*   Consulta de insumos distribuidos por estado    *\n");
  printf("*                                                  *\n");
  printf("****************************************************\n");
}


void opc_distribuicao()
{
  printf("****************************************\n");
  printf("*                                      *\n");
  printf("*             Distribuicao             *\n");
  printf("*                                      *\n");
  printf("****************************************\n");
}

int escolha_estado() {
  int estado = 0;
  printf(" 0 - AC |  1 - AL |  2 - AP |  3 - AM |  4 - BA |  5 - CE |  6 - DF |  7 - ES |  8 - GO\n");
  printf(" 9 - MA | 10 - MT | 11 - MS | 12 - MG | 13 - PA | 14 - PB | 15 - PR | 16 - PE | 17 - PI\n");
  printf("18 - RJ | 19 - RN | 20 - RS | 21 - RO | 22 - RR | 23 - SC | 24 - SP | 25 - SE | 26 - TO\n");
  printf("Escolha o estado para distribuicao: ");
  scanf("%d",&estado);
  return estado;
}