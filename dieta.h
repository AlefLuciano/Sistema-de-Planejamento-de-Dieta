typedef struct dieta Dieta;
struct dieta {
  char codDieta[4];
  char objetivo[2];
  char obj;
  char cafeDaManha[7];
  char lanche1[7];
  char almoco[7];
  char lanche2[7];
  char jantar[7];
  char ceia[7];
  int status;
};

void moduloDieta(void);
char menuDieta(void);

char objDieta(char);

void cadastrarDieta(void);
void pesquisarDieta(void);
void atualizarDieta(void);
void excluirDieta(void);

Dieta* telaCadastrarDieta(void);
char* telaPesquisarDieta(void);
char* telaAtualizarDieta(void);
char* telaExcluirDieta(void);

void gravarDieta(Dieta*);
Dieta* buscarDieta(char*);
void exibirDieta(Dieta*);
void regravarDieta(Dieta*);

