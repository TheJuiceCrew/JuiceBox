//Incluir as bibliotecas do DHT22
#include <DHT.h>

//Definir um pino para a comunicação:
#define DHTPIN 7

//Definir tipo do DHT
#define DHTTYPE DHT22

//
DHT dht(DHTPIN, DHTTYPE);

byte grau[8]={ B00001100, 
                B00010010, 
                B00010010, 
                B00001100, 
                B00000000, 
                B00000000, 
                B00000000, 
                B00000000,}; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Inicia o serial
  Serial.println("Aguardando dados...");
  dht.begin(); //Inicializa o DHT

}

void loop() {
  // put your main code here, to run repeatedly:

}

void DHTFuncao(){
  delay(2000);

  //Ler a temperatura e a umidade pode levar de 250 milisegundos ou até 2 segundos, é ums ensor muito lento
  float h = dht.readHumidity(); //Ler a umidade

  float t = dht.readTemperature(); //Ler a temperatura como Celsius (padrão)

  //Checar se qualquer lida sofreu alguma falha
  if (isnan(h)||isnan(t)){
    Serial.println("Falha ao ler o sensor!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C  ");

  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.println(" %/t");
}

void RetornarVariavel4Digits () {
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  int variavel = (h*1000) + t;

  if (scanf("variavel")) {
    Serial.print(variavel);
  }
}
  

