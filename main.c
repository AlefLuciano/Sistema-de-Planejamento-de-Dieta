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
#include "nutricionista.h"
#include "util.h"


void menuSobre(void);
char menuPrincipal(void);


void moduloDieta(void);
char menuDieta(void);
void telaCadastrarDieta(void);
void telaPesquisarDieta(void);
void telaAtualizarDieta(void);
void telaExcluirDieta(void);
void cadastrarDieta(void);
void pesquisarDieta(void);
void atualizarDieta(void);
void excluirDieta(void);

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





///////////////////////////////////////////////////////////////////////////////
///								Módulo Dieta
///////////////////////////////////////////////////////////////////////////////
void moduloDieta(void) {
	char opcao;
	do {
		opcao = menuDieta();
		switch(opcao) {
			case '1': 	cadastrarDieta();
						break;
			case '2': 	pesquisarDieta();
						break;
			case '3': 	atualizarDieta();
						break;
			case '4': 	excluirDieta();
						break;
		} 		
	} while (opcao != '0');
}

void cadastrarDieta(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaCadastrarDieta();
}

void pesquisarDieta(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaPesquisarDieta();
}


void atualizarDieta(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaAtualizarDieta();
}


void excluirDieta(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	telaExcluirDieta();
}


char menuDieta(void) {
	char op;

    system("clear");
  printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============       SISTEMA DE PLANO DE DIETA       ==============     |\n");
  printf("|     ==============             MENU PRINCIPAL            ==============     |\n");
  printf("|     ==============            MÓDULO DE DIETAS           ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|      1. Cadastrar nova dieta                                                |\n");
  printf("|      2. Pesquisar dieta                                                     |\n");
  printf("|      3. Atualizar dieta                                                     |\n");
  printf("|      4. Excluir dieta                                                       |\n");
  printf("|      0. Voltar ao menu anterior                                             |\n");
  printf("|                                                                             |\n");
  printf("|      Escolha a opção desejada: ");
	scanf("%c", &op);
	getchar();                                                                       
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
    delay(1);
	return op;


}

void telaCadastrarDieta(void) {
	char codDieta[4];
  char focoDaDieta[20];

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============            CADASTRAR DIETA           ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Escreva um codigo para a dieta: ");
	scanf("%[0-9]", codDieta);
	getchar();
  printf("|     Escreva o foco da dieta: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", focoDaDieta);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
}

void telaPesquisarDieta(void) {
  char focoDaDieta[20];

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============            PESQUISAR DIETA            ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Escreva o foco da dieta: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", focoDaDieta);
	getchar();
printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
}

void telaAtualizarDieta(void) {
	char codDieta[4];

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============            ATUALIZAR DIETA            ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Escreva o codigo da dieta: ");
	scanf("%[0-9]", codDieta);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
}


void telaExcluirDieta(void) {
	char codDieta[4];

  system("clear");
	printf("\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("|                                                                             |\n");
  printf("|     ===================================================================     |\n");
  printf("|     ==============             EXCLUIR DIETA             ==============     |\n");
  printf("|     ===================================================================     |\n");
  printf("|                                                                             |\n");
  printf("|     Escreva o codigo da dieta: ");
	scanf("%[0-9]", codDieta);
	getchar();
  printf("|                                                                             |\n");
  printf("|                                                                             |\n");
  printf("-------------------------------------------------------------------------------\n");
  printf("\n");
	delay(1);
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




