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

  objetivo = (char*) malloc(13*sizeof(char));

  system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============          DIETAS POR OBJETIVO          ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     informe o objetivo da dieta (perder peso/ganhar peso):");
	scanf("%[a-záéíóúâêôçàãõ  ]", objetivo);
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
  printf("|     =========================================     |\n");
  printf("|     ||  Cod Dieta  ||Objetivo da Dieta     ||     \n");
  printf("|     =========================================     |\n");
  listaDietasPorObjetivo(objetivo);


}




void listaDietasPorObjetivo(char* objetivo) {
    FILE* fp;
    Dieta* diet;

    diet = (Dieta*) malloc(sizeof(Dieta));
    fp = fopen("dietas.dat", "rb");
    while (fread(diet, sizeof(Dieta), 1, fp)) {
      if (strcmp(diet->objetivo, objetivo) == 0) {
        printf("     ||  %-3s  || %s          ||\n", diet->codDieta, diet->objetivo);
      }
    
    }
    printf("\n\nTecle ENTER para continuar!\n\n");
    getchar();
    fclose(fp);
    free(diet);
}




