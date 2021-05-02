typedef struct nutricionista Nutricionista;

struct nutricionista {
  char matr[12];
	char nome[51];
	char email[51];
	int dia, mes, ano;
  int dataValida;
	char celular[12];
  int status;
};

void moduloNutricionista(void);
char menuNutricionista(void);


void cadastrarNutricionista(void);
void pesquisarNutricionista(void);
void atualizarNutricionista(void);
void excluirNutricionista(void);

Nutricionista* telaCadastrarNutricionista(void);
char* telaPesquisarNutricionista(void);
char* telaAtualizarNutricionista(void);
char*telaExcluirNutricionista(void);


void gravarNutricionista (Nutricionista*);
Nutricionista* buscarNutricionista(char*);
void exibirNutricionista(Nutricionista*);
void regravarNutricionista(Nutricionista*);

