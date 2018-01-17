#include <Adafruit_Sensor.h>
//#include <DS3231.h>
#include <Wire.h>
#include <DHT.h>


//DS3231 rtc;             //Criação do objeto do tipo DS3231
//RTCDateTime dataehora; //Criação do objeto do tipo RTCDateTime

#define PINODHT 7
#define TIPODHT DHT22

//Array simbolo grau
byte grau[8] ={ B00001100, 
                B00010010, 
                B00010010, 
                B00001100, 
                B00000000, 
                B00000000, 
                B00000000, 
                B00000000,}; 

DHT dht (PINODHT, TIPODHT);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Aguardandod dados");

  //Inicialização do DHT
  dht.begin();

  //Inicialização do RTC DS3231
  //rtc.begin();
  //Configurando valores iniciais do RTC DS3231
  //rtc.setDateTime(__DATE__,__TIME__); //Esta linha deve ser excluida após a primeira compilação

}

void loop() {
  // put your main code here, to run repeatedly:
  //RTC
  /*dataehora = rtc.getDateTime();

  Serial.print("Data:");
  Serial.print(" ");
  Serial.print(dataehora.year);
  Serial.print("-");
  Serial.print(dataehora.month);
  Serial.print("-");
  Serial.print(dataehora.day);
  Serial.print(" ");
  Serial.print("Hora:");
  Serial.print(" ");
  Serial.print(dataehora.hour);
  Serial.print(":");
  Serial.print(dataehora.minute);
  Serial.print(":");
  Serial.print(dataehora.second);
  Serial.println("");

  delay(1000); */

  //DHT22
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Falha ao ler");
    return;
  }
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C  ");

  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.println(" %");
  

}
