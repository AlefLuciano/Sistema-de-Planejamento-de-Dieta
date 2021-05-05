#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "relatorio.h"
#include "util.h"
#include "dieta.h"
#include "cliente.h"

/// MENU RELATORIO //////

void moduloRelatorio(void) {
	char opcao;
	do {
		  opcao = menuRelatorio();
		  switch(opcao) {
			  case '1': 	verDietasPorObjetivo();
          break;
        case '2': 	verRelatorioDoCliente();
          break;
      }
    } while (opcao != '0');
}



void verDietasPorObjetivo(void) {
  char* objetivo; 

  objetivo = telaDietasPorObjetivo();
	relataDietaPorObjetivo(objetivo);
  free(objetivo);
}

void verRelatorioDoCliente(void) {
  char* matr;

  matr = telaRelatorioCliente();
  relatorioDoCliente(matr);
  free(matr);
}



char menuRelatorio(void) {
	char op;
  system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============       SISTEMA DE PLANO DE DIETA       ==============     |\n");
  printf("|     ==============            MÓDULO RELATORIO           ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     1. Listar dietas por objetivo                                           |\n");
  printf("|     2. Ver relatorio de avaliação do cliente                                |\n");
  printf("|     0. voltar ao menu anterior                                              |\n");
  printf("|                                                                             |\n");
  printf("|      Escolha uma opção:                                                     |\n");
  scanf("%c", &op);
  getchar();
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
	return op;
}

char* telaDietasPorObjetivo(void) {
	char* objetivo;

  objetivo = (char*) malloc(13*sizeof(char));

  system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============          DIETAS POR OBJETIVO          ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     informe o objetivo da dieta (perder peso/ganhar peso): ");
	scanf("%[a-záéíóúâêôçàãõ  ]", objetivo);
	getchar(); 
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
  delay(1);
  return objetivo;
}

char* telaRelatorioCliente(void) {
	char* matr;

  matr = (char*) malloc(7*sizeof(char));

  system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============          RELATORIO DO CLIENTE         ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|      Informe a matrícula do cliente (apenas 6 digitos): ");
	scanf("%[0-9]",matr);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
  return matr;
}




void relataDietaPorObjetivo(char* objetivo) {
  system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============    OBJETIVO: %-12s          ==============     |\n",objetivo);
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|      =====================================     |\n");
  printf("|      ||  Cod Dieta  ||Objetivo da Dieta ||     \n");
  printf("|      =====================================     |\n");
  listaDietasPorObjetivo(objetivo);

}

void relatorioDoCliente(char* matr) {
  system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============          RELATORIO DO CLIENTE         ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  avaliacaoDoCliente(matr);
}




void listaDietasPorObjetivo(char* objetivo) {
    FILE* fp;
    Dieta* diet;

    diet = (Dieta*) malloc(sizeof(Dieta));
    fp = fopen("dietas.dat", "rb");
    while (fread(diet, sizeof(Dieta), 1, fp)) {
      if (strcmp(diet->objetivo, objetivo) == 0) {
        printf("       ||      %s    ||   %s    ||\n", diet->codDieta, diet->objetivo);
      }
    
    }
    printf("\n\nTecle ENTER para continuar!\n\n");
    getchar();
    fclose(fp);
    free(diet);
}

void avaliacaoDoCliente(char* matr) {
  FILE* fp;
  Cliente* cli;

  cli = (Cliente*) malloc(sizeof(Cliente));
  fp = fopen("clientes.dat", "rb");
  while (fread(cli, sizeof(Cliente), 1, fp)) {
  if ((strcmp(cli->matr, matr) == 0) && (cli->status == 1)) {
    printf("\n - - - Cliente Cadastrado - - -\n");
    printf("Matrícula: %s\n", cli->matr);
    printf("Nome do cliente: %s\n", cli->nome);
    printf("O peso do cliente é: %.2fKg\n", cli->peso);
    printf("A altura do cliente é: %.2fm\n", cli->altura);
    printf("o IMC do cliente é %.1f\n", cli->imc);
    if (cli->imc < 18.5){
    printf("\nO IMC esta 'abaixo do normal'\n");
  } else if ((cli->imc >= 18.5) && (cli->imc <= 24.9)) {
    printf("\nO seu IMC esta no 'peso ideal'(parabéns)\n");
  } else if ((cli->imc >= 25.0) && (cli->imc <= 29.9)) {
    printf("\nO seu IMC esta 'levemente acima do peso'\n");
  } else if ((cli->imc >= 30.0) && (cli->imc <= 34.9)) {
    printf("\nO seu IMC esta no 'grau de obsidade I'\n");
  } else if ((cli->imc >= 35.0) && (cli->imc <= 39.9)) {
    printf("\nO seu IMC esta no 'grau de obsidade II(severa)'\n");
  } 
  else {
    printf("\nO seu IMC esta no 'grau de obsidade III'(mórbida)\n");
  }
  }
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
  fclose(fp);
  free(cli);
}




