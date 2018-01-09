# JuiceBox (Em construção)

#Tarefas de cada módulo 

MÓDULO 1 - ArduinoMutiplex
* Controle do display conforme descrito no relatório técnico
* Controlar módulo RTC para consulta das hora a ser exibida
* Sensor DHT de umidade e temperatura
* Montar em tempo de execução a tela de hora/minuto a partir de matrizes de números individuais
* Mostrar dia e mês em formato a ser definido
* Mostrar temperatura e umidade conforme lido do sensor DHT
* Mostrar o ícone de notificação do app correspondente ou um ícone genérico para apps não definidos
  por um período a ser definido e então voltar para a execução normal
* Exibir hora/minuto, dia/mês, temp/hum de forma alternada e contínua de modo a ser definido
* Receber por serial do ArduinoMQTT as flags de comunicação (a serem definidas) que indiquem qual app da notificação

MÓDULO 2 - ArduinoMQTT
* Controlar o módulo ESP8266 de forma a controlar a conexão wifi e o protocolo MQTT
* Utilizar em conjunto as bibliotecas WiFiEsp e Adafruit_MQTT para gerenciar a conexão e o protocolo MQTT
* Se conectar por SoftwareSerial ao ArduinoMultiplex para troca de flags de notificações (a serem definidas)
* Usar a maior velocidade possível na conexão serial, de preferência 115200 bauds/segundos 

MÓDULO 3 - AndroidAPP
* Funcionar como cliente e servidor MQTT que irá permitir a comunicação entre o AndroidAPP e o ArduinoMQTT
* Ler as notificações do celular e quando recebidas identificar o app
* Postar nos devidos tópicos (a serem definidos) as mensagens que indiquem o app que a notificação foi recebida


#Apps que irão exibir ícones personalizados
Marcar com um (✓) ao lado dos ícones que já estiverem prontos e upados em forma de matriz
(Cada um em um arquivo separado)
* Facebook
* Whatsapp
* Instagram
* Email (Para os clientes mais comuns, Gmail e Outlook)
* SMS
* Facebook Messenger (Boa sorte pensando em como fazer esse kkkkk)

#Flags para cada App
(Para serem usadas tanto na comunicação serial entre ArduinoMQTT e ArduinoMultiplex
    quanto a serem postados nos tópicos MQTT)
    
* Facebook: "11"
* Whatsapp: "22"
* Instagram "33"
* Email (Para os clientes mais comuns, Gmail e Outlook) "44"
* SMS "55"
* Facebook Messenger (Boa sorte pensando em como fazer esse kkkkk) "66"

#Identificador
Há de ser definido um identificador de mensagem com início e fim com algum símbolo como '#' ou '*'
Tanto para a comunicação serial entre os arduinos quanto para a comunicação MQTT

*ESPECIFICAÇÕES DO DHT22:
Especificações:
– Modelo: AM2302 (datasheet)
– Tensão de operação: 3-5VDC (5,5VDC máximo)
– Faixa de medição de umidade: 0 a 100% UR
– Faixa de medição de temperatura: -40º a +80ºC
– Corrente: 2,5mA max durante uso, em stand by de 100uA a 150 uA
– Precisão de umidade de medição: ± 2,0% UR
– Precisão de medição de temperatura: ± 0,5 ºC
– Resolução: 0,1
– Tempo de resposta: 2s
– Dimensões: 25 x 15 7mm (sem terminais)


*ESPECIFICAÇÕES DO RTC DS3231:
Especificações:

Tensão de operação: 3,3-5V
Chip: DS3231 (datasheet)
Trabalha com segundos, minutos, horas, dias da semana, dias do mês, meses e anos (de 2000 a 2099)
Sensor de temperatura com ± 3 °C de exatidão.
Chip de memória: AT24C32 (capacidade de 32K bytes que podem ser usadas como RAM estendida do microcontrolador)
Interface I2C
Circuito de detecção de falha de energia
Consome menos de 500 nA no modo bateria com oscilador em funcionamento
Faixa de temperatura: 0 a 40°C
Dimensões: 38 x 22 x 14mm
Peso: 8g

Recursos – Principais Funções

rtc.setDOW(MONDAY)  – Escreve o dia da semana em inglês
rtc.setTime(15, 29, 0)      – Escreve as horas no formato 24 horas, hh, mm, ss
rtc.setDate(20, 3, 2017)  – Escreve a data de acordo com o sistema que utilizas DD, MM, AAAA
rtc.getDOWStr()               – Le o dia da semana
rtc.getDateStr()                – Le a data
rtc.getTimeStr()                – Le as horas
rtc.getTemp()                   – Le a temperatura

