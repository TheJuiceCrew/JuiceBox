#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspServer.h>
#include <WiFiEspUdp.h>
#include "SoftwareSerial.h"


/************************* Configuração do WIFI *********************************/

#define WLAN_SSID       "AlanTAS"  //SSID da rede
#define WLAN_PASS       "85585885" //Senha
int status = WL_IDLE_STATUS;

/************************* Configuração do MQTT *********************************/

#define AIO_SERVER      "192.168.0.4" //Endereço do Broker      
#define AIO_SERVERPORT  1883         // Porta do broker
#define AIO_USERNAME    ""           // Nome de usuário; Deixar em branco caso não tenha
#define AIO_KEY         ""          // Senha; Deixar em branco caso não tenha

/************ Instancias das classes de rede ******************/

//Instancia da classe WifiESP para conectar na rede
WiFiEspClient client;

// Instancia do cliente MQTT que recebe a instancia do cliente WIFI e as configurações de acesso ao broker
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Tópicos inscritos ***************************************/
//Exemplo de sintaxe
//Adafruit_MQTT_Publish exemplo = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/casa/exemplo");

// Configura um FEED chamado notify para se inscrever no tópico "/cubo"
Adafruit_MQTT_Subscribe notify = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "cubo"); //Subscription

/*************************** Código ************************************/

//Declara a função por motivos de: Não funciona sem isso
void MQTT_connect();
//Instância da classe SoftwareSerial que emula uma comunicação serial
SoftwareSerial soft(2, 3); // RX, TX (Roxo no 2, cinza no 3)
int appCode = 99; // 99 para sem notificação
// 0 para app genérico; 1 para facebook; 2 para whatsapp; 3 para instagram; 4 pra email

int temp = 25;
int umi = 96;
String enviar;
void setup() {
  Serial.begin(115200);
  soft.begin(9600);
  delay(10);
  WiFi.init(&soft);


  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  // WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (status != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    status = WiFi.begin(WLAN_SSID, WLAN_PASS);
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  //Configura a inscrição no tópico
  mqtt.subscribe(&notify);
}

uint32_t x = 0;

void loop() {
  // Conecta e toma conta se a conexão com o broker está viva
  // se a conexão for perdida a reconexão será tentada automaticamente

  MQTT_connect();

  // this is our 'wait for incoming subscription packets' busy subloop
  // try to spend your time here


  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(300))) {
    if (subscription == &notify) {
      //Serial.print(F("Got: "));
      //Serial.println((char *)notify.lastread);
      String payload = (char *)notify.lastread;
      //Serial.println(payload);

      if (payload.startsWith("#") && payload.endsWith("*")) {

        String numero = payload.substring(1, payload.length() - 1);

        long castnumber = numero.toInt();

        if (castnumber >= 0 && castnumber <= 4) {

          appCode = (int) castnumber;

        }
      }
    }
  }

  //Pegar aqui a leitura do DHT e montar os inteiros de umidade e temperatura
  enviar = "";
  enviar += "#";
  enviar += appCode;
  enviar += "/";
  enviar += temp;
  enviar += "/";
  enviar += umi;
  enviar += "*";

  Serial.println(enviar);

  appCode = 99;
}

// Função para conectar e reconectar ao broker quando necessário
// Deve ser chamada no loop, o resto ela faz

void MQTT_connect() {
  int8_t ret;

  // Se a conexão está viva apenas retorna ao loop
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Conectando ao Broker MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // Connect vai retornar 0 para conectado
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Tentando novamente conexão em 5 segundos...");
    mqtt.disconnect();
    delay(5000);  // Aguarda 5 segundos
    retries--;
    if (retries == 0) {
      //Se não conectar em 3 tentativas entra num loop até o módulo resetar automaticamente
      while (1);
    }
  }
  Serial.println("Broker MQTT Conectado!");
}

