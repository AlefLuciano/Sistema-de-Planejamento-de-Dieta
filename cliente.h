typedef struct cliente Cliente;

struct cliente {
  char matr[12];
	char nome[51];
	char email[51];
	char celular[12];
  int dia, mes, ano;
  float peso, altura, imc;
  int status;
};


void moduloCliente(void);
char menuCliente(void);

void cadastrarCliente(void);
void pesquisarCliente(void);
void atualizarCliente(void);
void excluirCliente(void);

Cliente* telaCadastrarCliente(void);
char* telaPesquisarCliente(void);
char* telaAtualizarCliente(void);
char* telaExcluirCliente(void);

void gravarCliente (Cliente*);
Cliente* buscarCliente(char*);
void exibirCliente(Cliente*);
void regravarCliente(Cliente*);