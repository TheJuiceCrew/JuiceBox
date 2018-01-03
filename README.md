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

