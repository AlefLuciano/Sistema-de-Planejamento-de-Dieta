#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "relatorio.h"
#include "util.h"


///// MENU RELATORIO //////

void moduloRelatorio(void) {
	char opcao;
	do {
		  opcao = menuRelatorio();
		  switch(opcao) {
			  case '1': 	verEvolucao();
          
						break;
      }
    } while (opcao != '0');
}

void verEvolucao(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaVerEvolucao();
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
  printf("|     1. Ver evolução do cliente                                              |\n");
  printf("|                                                                             |\n");
  printf("|      Escolha uma opção:                                                     |\n");
  scanf("%c", &op);
  getchar();
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
	return op;
}

void telaVerEvolucao (void) {
float menorPeso;
char matr[12];
float vetPeso[] = {88.0, 82.5, 79.5, 81.8}; 
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============       SISTEMA DE PLANO DE DIETA       ==============     |\n");
  printf("|     ==============             VER EVOLUÇÃO              ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Matrícula (apenas números): ");
  scanf("%[0-9]", matr);
  getchar();
  menorPeso = melhorPeso(vetPeso);
  printf("|      O seu menor peso foi %.2fKg\n", menorPeso);
  printf("Tecle ENTER para continuar!\n");
  getchar();
}


float melhorPeso(float* vetPeso) {
float menorPeso = 200 ;
for (int i = 0; i < 4; i++) {
  if (vetPeso[i] < menorPeso) {
    menorPeso = vetPeso[i];
  }
}
return menorPeso;
}
