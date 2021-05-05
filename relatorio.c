#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "relatorio.h"
#include "util.h"
#include "dieta.h"


///// MENU RELATORIO //////

void moduloRelatorio(void) {
	char opcao;
	do {
		  opcao = menuRelatorio();
		  switch(opcao) {
			  case '1': 	verDietasPorObjetivo();
          
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

  objetivo = (char*) malloc(2*sizeof(char));

  system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============          DIETAS POR OBJETIVO          ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Objetivo da dieta\n");
  printf("|     1-Perder peso\n");
  printf("|     2-Ganhar peso\n");
  printf("|     Escolha o objetivo da dieta");
	scanf("%[1-2]", objetivo);
	getchar(); 
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
  delay(1);
  return objetivo;
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
  printf("|     ==============================================     |\n");
  printf("|     ||  Cod Dieta  ||     Objetivo da Dieta     ||     \n");
  printf("|     ==============================================     |\n");
  listaDietasPorObjetivo(objetivo);


}




void listaDietasPorObjetivo(char* objetivo) {
    FILE* fp;
    Dieta* diet;

    diet = (Dieta*) malloc(sizeof(Dieta));
    fp = fopen("dietas.dat", "rb");
    while (fread(diet, sizeof(Dieta), 1, fp)) {
      if (strcmp(diet->objetivo, objetivo) == 0) {
        printf("||  %-3s  ||     %s     ||\n", diet->codDieta, diet->objetivo);
      }
    printf("\n\nTecle ENTER para continuar!\n\n");
    getchar();
    }

    fclose(fp);
    free(diet);
}




