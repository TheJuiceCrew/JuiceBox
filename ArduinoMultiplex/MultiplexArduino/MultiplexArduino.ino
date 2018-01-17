const int SCR_WIDTH = 13; //Largura da tela
const int SCR_HEIGHT = 13; //Altura da tela

int colu[SCR_WIDTH] = {46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22}; //Pinos das colunas
int linh[SCR_HEIGHT] = {23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47}; //Pinos das colunas

bool matrizScreen[SCR_HEIGHT][SCR_WIDTH] =
{ {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
  {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
  {0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1},
  {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
  {0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
}; //Matriz que armazena a imagem que vai ser mostrada na tela


//Matrizes números

bool matrizZero[5][3] = {{1, 1, 1}, {1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}};
bool matrizUm[5][3] = {{0, 1, 0}, {1, 1, 0}, {0, 1, 0}, {0, 1, 0}, {1, 1, 1}};
bool matrizDois[5][3] = {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}};
bool matrizTres[5][3] = {{1, 1, 1}, {0, 0, 1}, {0, 1, 1}, {0, 0, 1}, {1, 1, 1}};
bool matrizQuatro[5][3] = {{1, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {0, 0, 1}};
bool matrizCinco[5][3] = {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}};
bool matrizSeis[5][3] = {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
bool matrizSete[5][3] = {{1, 1, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}};
bool matrizOito[5][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
bool matrizNove[5][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}};
bool matrizHoras[5][3] = {{1, 0, 0}, {1, 0, 0}, {1, 1, 1}, {1, 0, 1}, {1, 0, 1}};
bool matrizMinutos[5][3] = {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
bool matrizPorcento[5][3] = {{1, 0, 1}, {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {1, 0, 1}};
bool matrizGrau[5][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 0}, {0, 0, 0}};
bool matrizBarra[5][3] = {{0, 0, 1}, {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {1, 0, 0}};
bool matrizZeros[5][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

// Matrizes ícones de apps

bool matrizWhatsapp[13][13] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
bool matrizFacebook[13][13] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
bool matrizEmail[13][13] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0}, {0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0}, {0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
bool matrizInstagram[13][13] = {{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1}, {1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}};


unsigned long time;
int horas = 13;
int minutos = 56;
int temp = 34;
int umi = 89;
int dia = 16;
int mes = 1;

int telaAtual = 1; // 1 para hora/data, 2 para temp/umi e 3 para dia/mes;
bool noti = false; //Setado para true quando uma notificação chega e volta para false depois que passar 5 seg
int codigoApp = 2; //Codigos pros icones de notificação
// 0 pra app qualquer, 1 para facebook, 2 para whatsapp, 3 para instagram e 4 para email

void setup() {

  // Define os pinos do display como entradas
  for (int i = 0; i < SCR_WIDTH; i++) {
    pinMode(colu[i], OUTPUT);
  }

  for (int j = 0; j < SCR_HEIGHT; j++) {
    pinMode(linh[j], OUTPUT);
  }

  //Inicia a comunicação serial numa taxa de 115200 bauds/s
  Serial.begin(115200);
  Serial1.begin(115200);

  //Armazena o tempo atual em ms desde que o microcontrolador começou a operar
  time = millis();
}

void loop() {

  while ((millis() - time < 5000) && !noti) {

    checaNoti();

    switch (telaAtual) {
      case 1:
        montarHora(horas, minutos, 1);
        draw();
        break;
      case 2:
        montarHora(temp, umi, 2);
        draw();
        break;
      case 3:
        montarHora(dia, mes, 3);
        draw();
        break;
      default:
        montarHora(horas, minutos, 1);
        draw();
    }

  }

  if (!noti) {
    telaAtual++;
  }
  if (telaAtual > 3) {
    telaAtual = 1;
  }

  time = millis();

  while ((millis() - time < 5000) && noti) {

    switch (codigoApp) {
      case 0:
        montaNoti(matrizFacebook);
        draw();
        break;
      case 1:
        montaNoti(matrizFacebook);
        draw();
        break;
      case 2:
        montaNoti(matrizWhatsapp);
        draw();
        break;
      case 3:
        montaNoti(matrizInstagram);
        draw();
        break;
      case 4:
        montaNoti(matrizEmail);
        draw();
        break;
      default:
        montaNoti(matrizFacebook);
        draw();
    }
  }

  noti = false;
  time = millis();


}


//Função que desenha no display a matriz salva em matrizScreen
//Argumentos: Nenhum
//Retorno: Nenhum
void draw() {
  for (int i = 0; i < SCR_HEIGHT; i++) { //Itera entre todas as linhas

    selectRow(i);

    for (int j = 0; j < SCR_WIDTH; j++) {
      digitalWrite(colu[j],  matrizScreen[i][j]);
      delayMicroseconds(90);
      digitalWrite(colu[j], LOW);
    }
  }
}

//Função que liga uma linha e desliga todas as outras no display
//Evita que tenha ghosting na tela
//Argumentos: Nenhum
//Retorno: Nenhum
void selectRow(int rowNow) {
  for (int p = 0; p < SCR_HEIGHT; p++) { //Itera entre todas as linhas
    digitalWrite(linh[p], HIGH); //Apaga todas
  }
  digitalWrite(linh[rowNow], LOW); //Acende só a que queremos
}


//Função que recebe horas e minutos em inteiros no formato "HH" "MM" e monta a tela de hora e minuto
//Modificado parar tambem ser usado para dia e mes e temperatura e umidade
//Flags: 1 = HH MM
//       2 = TT UU
//       3 = DD MM
//Argumentos: int hora
//Retorno: Nenhum
void montarHora(int horas, int minutos, int type) {

  //Variaveis para armazenar os numeros das horas e minutos
  int hora1;
  int hora2;
  int minuto1;
  int minuto2;


  // Código que separa a hora e data em números individuais e adiciona o 0 para horas e minutos < 10
  if (horas < 10) {
    hora1 = 0;
    hora2 = horas;
  }

  else if (horas >= 10) {
    hora1 = (int) horas / 10;
    hora2 = (int) (horas) - (hora1 * 10);
  }

  if (minutos < 10) {
    minuto1 = 0;
    minuto2 = minutos;
  }

  else {
    minuto1 = (int) minutos / 10;
    minuto2 = (int) (int) (minutos) - (minuto1 * 10);
  }

  //Debug
  //  Serial.print(hora1);
  //  Serial.print(hora2);
  //  Serial.print(":");
  //  Serial.print(minuto1);
  //  Serial.println(minuto2);

  if (type == 1) {
    montaMatriz(retornaNumero(hora1), retornaNumero(hora2), matrizHoras, retornaNumero(minuto1), retornaNumero(minuto2), matrizMinutos);
  }

  if (type == 2) {
    montaMatriz(retornaNumero(hora1), retornaNumero(hora2), matrizGrau, retornaNumero(minuto1), retornaNumero(minuto2), matrizPorcento);
  }

  if (type == 3) {
    montaMatriz(retornaNumero(hora1), retornaNumero(hora2), matrizBarra, retornaNumero(minuto1), retornaNumero(minuto2), matrizZeros);
  }
}

//Função que recebe seis matrizes 5x3 e monta uma matriz 13x13
//Argumentos:  matrizes bool 5x3
//Retorno: nenhum, a modificação da matriz principal se dá por acesso direto à matriz
//declarada como variável global

void montaMatriz(bool p1[5][3], bool p2[5][3], bool p3[5][3], bool p4[5][3], bool p5[5][3], bool p6[5][3]) {

  // Declara 6 matrizes 5x3 pra armazenar as recebidas
  bool matriz_P1[5][3];
  bool matriz_P2[5][3];
  bool matriz_P3[5][3];
  bool matriz_P4[5][3];
  bool matriz_P5[5][3];
  bool matriz_P6[5][3];

  //Popula as 6 matrizes locais com as 6 passadas como argumento
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matriz_P1[i][j] = p1[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matriz_P2[i][j] = p2[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matriz_P3[i][j] = p3[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matriz_P4[i][j] = p4[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matriz_P5[i][j] = p5[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matriz_P6[i][j] = p6[i][j];
    }
  }


  // Zera a matriz para garantir que as partes que são 0 continuem 0;
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 13; j++) {
      matrizScreen[i][j] = 0;
    }
  }

  // Coloca cada matriz 5x3 na sua posição na matriz principal
  //Esquerda para a direita, de cima para baixo
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matrizScreen[i + 1][j + 1] = matriz_P1[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matrizScreen[i + 1][j + 5] = matriz_P2[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matrizScreen[i + 1][j + 9] = matriz_P3[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matrizScreen[i + 7][j + 1] = matriz_P4[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matrizScreen[i + 7][j + 5] = matriz_P5[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      matrizScreen[i + 7][j + 9] = matriz_P6[i][j];
    }
  }
}

//Função que recebe um número entre 0 e 9 e retorna a identificação da matriz
//correspondente aquele número
//Argumentos: int número
//Retorno: int retorno com a identificação da matriz

int retornaNumero(int numero) {
  int retorno;
  switch (numero) {
    case 0:
      retorno = matrizZero;
      break;
    case 1:
      retorno = matrizUm;
      break;
    case 2:
      retorno = matrizDois;
      break;
    case 3:
      retorno = matrizTres;
      break;
    case 4:
      retorno = matrizQuatro;
      break;
    case 5:
      retorno = matrizCinco;
      break;
    case 6:
      retorno = matrizSeis;
      break;
    case 7:
      retorno = matrizSete;
      break;
    case 8:
      retorno = matrizOito;
      break;
    case 9:
      retorno = matrizNove;
      break;
    default:
      retorno = matrizZero;
  }

  return retorno;
}

void montaNoti(bool icone[13][13]) {

  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 13; j++) {
      matrizScreen[i][j] = icone[i][j];
    }
  }
}

//Função que monitora a serial e vê se uma mensagem válida é recebida
//Caso uma mensagem válida tenha sido recebida o bool de notificação vai para true
//E o código do app correspondente é setado
//Argumentos: Nenhum
//Retorna: nada
void checaNoti() {
  String texto;
  long recebido;

  if (Serial1.available()) {
    if (Serial1.read() == '#') {
      texto = Serial1.readStringUntil('*');
      int str_len = texto.length() + 1;
      char payload[str_len];
      texto.toCharArray(payload, str_len);
      Serial.println(texto);

      int um = 0;
      int dois = 0;

      for (int i = 0; i < (sizeof(payload)); i++) {

        if (payload[i] == '/') {
          if (um == 0) {

            um = i;
          }

          else if (dois == 0) {
            dois = i;
          }
        }

      }

      Serial.println(um);
      Serial.println(dois);
      String appCode = texto.substring(0, um);
      String strTemp = texto.substring(um + 1, dois);
      String strUmi = texto.substring(dois + 1, texto.length());
      Serial.print("Codigo: ");
      Serial.println(appCode);
      Serial.print("Temperatura: ");
      Serial.println(strTemp);
      Serial.print("Umidade: ");
      Serial.println(strUmi);

      
      codigoApp = appCode.toInt();
      
      if(codigoApp != 99){
        noti = true;
      }
      temp = strTemp.toInt();
      umi = strUmi.toInt();

    }
  }

  //  if (Serial.available()) {
  //    if (Serial.read() == '#') {
  //      texto = Serial.readStringUntil('*');
  //    }
  //
  //    recebido = texto.toInt();
  //    Serial.println(texto);
  //    if (recebido >= 0 && recebido <= 4) {
  //      noti = true;
  //      codigoApp = (int) recebido;
  //      Serial.println(codigoApp);
  //    }
  //
  //  }
}


