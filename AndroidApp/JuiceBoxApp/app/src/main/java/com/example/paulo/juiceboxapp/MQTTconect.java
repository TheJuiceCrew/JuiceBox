package com.example.paulo.juiceboxapp;


import android.content.Context;

import org.eclipse.paho.android.service.MqttAndroidClient;
import org.eclipse.paho.client.mqttv3.IMqttActionListener;
import org.eclipse.paho.client.mqttv3.IMqttToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;

/**
 *
 *    ALPHAMAGE APPS TECHNOLOGY
 *    Desenvolvimento de aplicações com qualidade
 *
 */

public class MQTTconect {


    private MqttAndroidClient mqttAndroidClient;                //objeto Cliente MQTT do Android
    private String serverAndress = "tcp://iot.eclipse.org";     //variavel para armazenar o endereço do servidor
    private String clientID;                                    //armazena o identificador do cliente MQTT
    private String username = "alberto";                        //armazena o nome de usuário
    private String password = "null";                           //armazena a senha de conexão do broker
    private String publishTopic = "thejuicecrew/juicebox/notification";           //Tópico para o cliente subescrever no servidor


    public MQTTconect(Context contexto, MqttCallback mqttcallback) {

        //gera um código randômico que serve como identificação do cliente
        clientID = MqttClient.generateClientId()+"juicebox";
        //cria um objeto MQTTClient android entregando como parametro o endereço o servidor e o id do cliente
        mqttAndroidClient = new MqttAndroidClient(contexto, serverAndress, clientID);
        //configura um objeto CallBack (objeto de chamada caso haja alteração)
        mqttAndroidClient.setCallback(mqttcallback);


    }

    public void sendMessage (String topic,String StringMessage) {
        if (isconnected()) {
            MqttMessage message = new MqttMessage();
            message.setPayload(StringMessage.getBytes());
            try {
                mqttAndroidClient.publish(topic,message);
            } catch (MqttException e) {
                e.printStackTrace();
            }
        }


    }

    public boolean isconnected () {
        boolean retorno;
        try {
            retorno = mqttAndroidClient.isConnected();
        }
        catch (Exception e) {
            e.printStackTrace();
            retorno = false;
        }
        return retorno;
    }

    public void doConnect(IMqttActionListener listener) {

        try {
            //realiza a conexão com o broker
            MqttConnectOptions options = new MqttConnectOptions();
            options.setConnectionTimeout(5);
            IMqttToken token = mqttAndroidClient.connect();
            token.setActionCallback(listener);

        } catch (MqttException e) {

            e.printStackTrace();
        }

    }

    public void subscribeToTopic() {

        if (mqttAndroidClient.isConnected()) {
            try {
                IMqttToken subToken = mqttAndroidClient.subscribe(publishTopic, 1);
                subToken.setActionCallback(new IMqttActionListener() {
                    @Override
                    public void onSuccess(IMqttToken asyncActionToken) {


                    }

                    @Override
                    public void onFailure(IMqttToken asyncActionToken,
                                          Throwable exception) {

                          Disconnect();
                          exception.printStackTrace();
                    }
                });

            } catch (MqttException e) {
                e.printStackTrace();
            }

        } else {

        }
    }


    public void Disconnect() {
        if (isconnected()) {
            try {
                mqttAndroidClient.disconnect();
            } catch (MqttException e) {
                e.printStackTrace();
            }
        }
    }


    //getters and setters methods

    public void setServerAndress(String adress) {
        this.serverAndress = adress;
    }

    public void setUsername (String username) {
        this.username = username;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getServerAndress() {
        return serverAndress;
    }

    public String getClientID() {
        return clientID;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public String getPublishTopic() {
        return publishTopic;
    }

    public void setPublishTopic(String publishTopic) {
        this.publishTopic = publishTopic;
    }


}
