typedef struct nutricionista Nutricionista;

struct nutricionista {
  char mtr[12];
	char nome[51];
	char email[51];
	int dia, mes, ano;
  int dataValida;
	char celular[12];
};

void moduloNutricionista(void);
char menuNutricionista(void);

void telaAtualizarNutricionista(void);
void telaExcluirNutricionista(void);
void cadastrarNutricionista(void);
void pesquisarNutricionista(void);
void atualizarNutricionista(void);
void excluirNutricionista(void);
Nutricionista* telaCadastrarNutricionista(void);
Nutricionista* telaPesquisarNutricionista(void);