int validaAltura (float altura) {
  if (altura < 0.00 || altura > 3.00) {
    return 0; }
  else 
    return 1;
}

int validaPeso (float peso) {
    if (peso < 2.00 || peso > 200.00) {
    return 0; }
  else 
    return 1; 
}

float calcularIMC(float peso, float altura) {
  float a2, imc;
  a2 = altura * altura;
  imc = peso / a2;
  return imc;
}

//// Essa função é um adaptação do "valida datas" apresentada em aula 
int bissexto(int);

int validadeDataDeNascimento(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 1900 || aa > 2021 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (bissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || 
             mm == 9 || mm == 11) {
               maiorDia = 30;
  } else
    maiorDia = 31;

  if (dd < 1 || dd > maiorDia)
    return 0;

  return 1;
}

int bissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return 1;
  } else if (aa % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se o caractere recebido for um dígito (entre 0 e 9)
/// retorna 0 caso contrário
///
/// Função retirada do projeto linguasolta

int ehDigito(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a um número de matrícula válido 
/// (apenas dígitos) ou retorna 0 caso contrário
///


int validarMatr(char* matr) {
  int tam;
  tam = strlen(matr);
  if (tam < 10 || tam > 11) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(matr[i])) {
      return 0;
    }
  }
  return 1;
}