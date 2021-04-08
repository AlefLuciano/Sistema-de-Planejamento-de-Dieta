///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema de Gestão Escolar                      ///
///                Developed by  @lefLuciano - Jan, 2021                    ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cliente.h"
#include "dieta.h"
#include "nutricionista.h"
#include "util.h"


void menuSobre(void);
char menuPrincipal(void);


void moduloRelatorio(void);
char menuRelatorio(void);
void verEvolucao (void);
void telaVerEvolucao (void);
float melhorPeso(float*);


void telaSobre(void) {
    system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|               Universidade Federal do Rio Grande do Norte                   |\n");
  printf("|                   Centro de Ensino Superior do Seridó                       |\n");
  printf("|                 Departamento de Computação e Tecnologia                     |\n");
  printf("|                    Disciplina DCT1106 -- Programação                        |\n");
  printf("|                    Projeto Sistema de Planejamento de Dieta                 |\n");
  printf("|                  Developed by  @lefLuciano - Jan, 2021                      |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|            = = = = = Sistema de Planejamento de Dieta = = = = =             |\n");
  printf("|                                                                             |\n");
  printf("|  Programa utilizado para a disciplina DCT1106 - Programação, consite em     |\n");
  printf("|  em um projeto que propõe um sistema capaz de auxiliar o(a) nutricionista   |\n");
  printf("|  na sugestão de cardápios, alternando os tipos de alimentos a serem         |\n");
  printf("|  consumidos, de forma que os cardápios da dieta não se tornem repetitivos   |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
}

void delay(int segundos) {
  int tempo = 500000 * segundos;
  clock_t inicio = clock();
  while (clock() < inicio + tempo) {
    // não faz nada, apenas gasta tempo
  }
}



/// INICIO DO PROGRAMA PRINCIPAL 

int main(void) {
	char opcao;
	do {
		opcao = menuPrincipal();
		switch(opcao) {
			case '1': 	moduloCliente();
						break;
			case '2': 	moduloNutricionista();
						break;
			case '3': 	moduloDieta();
						break;
      case '4': 	moduloRelatorio();
						break;
		} 		
	} while (opcao != '0');
	return 0;    
}

char menuPrincipal(void) {
	char op;
    system("clear");
	printf("\n");
   printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============       SISTEMA DE PLANO DE DIETA       ==============     |\n");
  printf("|     ==============             MENU PRINCIPAL            ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|      1. Módulo cliente/paciente                                             |\n");
  printf("|      2. Módulo nutricionista                                                |\n");
  printf("|      3. Módulo de dietas                                                    |\n");
  printf("|      4. Módulo relatorio                                                    |\n");
  printf("|                                                                             |\n");
  printf("|      Escolha uma opção:                                                     |\n");
  scanf("%c", &op);
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
	return op;
}


///// MENU RELATORIO\\\\

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
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
	return op;
}

void telaVerEvolucao (void) {
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
  melhorPeso(vetPeso);
}


float melhorPeso(float* vetPeso) {
float menorPeso = 200 ;
for (int i = 0; i < 4; i++) {
  if (vetPeso[i] < menorPeso) {
    menorPeso = vetPeso[i];
  }
}
printf("|      O seu menor peso foi %.2fKg\n", menorPeso);
}




