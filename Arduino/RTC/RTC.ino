// Carrega a Biblioteca do RTC DS3231
#include <DS3231.h>

//Modulo RTC ligado as portas analógicas A4 e A5 -> SDA e SCL, respesctivamente
DS3231 rtc;
//Criação do objeto do tipo DateTime
RTCDateTime dataehora;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Inicia o Serial
  Serial.print("Aguardando dados..."); //Printa no serial: Aguardando dados...
  rtc.begin(); //Inicializa o RTC
  //Configurando os valores iniciais do RTC DS3231 (data e tempo)
  rtc.setDateTime(__DATE__,__TIME__); //>>>>>Observação, essa linha deve ser excluída ou comentada após a primeira compilação!<<<<<<<

}

void loop() {
  // put your main code here, to run repeatedly:
  RTCFuncao();

}

void RTCFuncao(){

  dataehora = rtc.getDateTime(); //Obtém as datas e horas sincronizadas com o sistema
  

  //Operações de print na porta serial a sua escolha
  Serial.print("Data ");
  Serial.print(": ");
  Serial.print (dataehora.year);
  Serial.print("-");
  Serial.print(dataehora.month);
  Serial.print("-");
  Serial.print(dataehora.day);
  Serial.print(" ");
  Serial.print("Hora ");
  Serial.print(": ");
  Serial.print(dataehora.hour);
  Serial.print(":");
  Serial.print(dataehora.minute);
  Serial.print(":");
  Serial.print(dataehora.second);
  Serial.println(" ");

  delay(1000);
}

