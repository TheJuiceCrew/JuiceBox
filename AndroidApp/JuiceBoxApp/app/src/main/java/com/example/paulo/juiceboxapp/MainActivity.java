package com.example.paulo.juiceboxapp;

        import android.Manifest;
        import android.content.pm.PackageManager;
        import android.graphics.Color;
        import android.support.v4.app.ActivityCompat;
        import android.support.v4.content.ContextCompat;
        import android.support.v7.app.AppCompatActivity;
        import android.os.Bundle;
        import android.view.View;
        import android.widget.Button;
        import android.widget.EditText;
        import android.widget.TextView;

        import org.eclipse.paho.client.mqttv3.IMqttActionListener;
        import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
        import org.eclipse.paho.client.mqttv3.IMqttToken;
        import org.eclipse.paho.client.mqttv3.MqttCallback;
        import org.eclipse.paho.client.mqttv3.MqttMessage;

public class MainActivity extends AppCompatActivity implements MqttCallback,IMqttActionListener {

    private static final String TAG = "mainactivity";
    private static final String MESSAGE_FACEBOOK = "#1*";
    private static final String MESSAGE_WHATSAPP = "#2*";
    private static final String MESSAGE_INSTAGRAM = "#3*";
    private static final String TOPIC = "thejuicecrew/juicebox/notification";
    private io.moquette.server.Server server;
    private Button btnConect;
    private EditText editServerAdress;
    private TextView statusTextView;
    private Button btnFacebook;
    private Button btn_whatsapp;
    private Button btn_instagram;

    private MQTTconect mqtTconect;
    private Checkstatus checkStatus;
    private final int  MY_PERMISSIONS_REQUEST_ACESS_NETWORK_STATE = 100;
    private final int MY_PERMISSIONS_REQUEST_INTERNET = 101;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnConect = findViewById(R.id.btn_conect);
        editServerAdress = findViewById(R.id.edit_server_adress);
        statusTextView = findViewById(R.id.status_conection);
        btnFacebook = findViewById(R.id.btn_facebook);
        btn_whatsapp = findViewById(R.id.btn_whatsapp);
        btn_instagram = findViewById(R.id.btn_instagram);

        mqtTconect = new MQTTconect(this,this);

        editServerAdress.setText(mqtTconect.getServerAndress());

        btnConect.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mqtTconect.setServerAndress(editServerAdress.getText().toString());
                mqtTconect.doConnect(MainActivity.this);
            }
        });

        btnFacebook.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if (mqtTconect.isconnected()) {
                    mqtTconect.sendMessage(TOPIC,MESSAGE_FACEBOOK);
                }
            }
        });

        btn_instagram.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mqtTconect.isconnected()) {
                    mqtTconect.sendMessage(TOPIC,MESSAGE_INSTAGRAM);
                }
            }
        });

        btn_whatsapp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mqtTconect.isconnected()) {
                    mqtTconect.sendMessage(TOPIC,MESSAGE_WHATSAPP);
                }
            }
        });

        checkStatus = new Checkstatus();
        Thread thread = new Thread(checkStatus);
        thread.start();

        getPermissions();
    }


    public void getPermissions () {
        // Here, thisActivity is the current activity
        if (ContextCompat.checkSelfPermission(this,
                Manifest.permission.ACCESS_NETWORK_STATE)
                != PackageManager.PERMISSION_GRANTED) {

            // Should we show an explanation?


                // No explanation needed, we can request the permission.

                ActivityCompat.requestPermissions(this,
                        new String[]{Manifest.permission.ACCESS_NETWORK_STATE},
                        MY_PERMISSIONS_REQUEST_ACESS_NETWORK_STATE);

                // MY_PERMISSIONS_REQUEST_READ_CONTACTS is an
                // app-defined int constant. The callback method gets the
                // result of the request.

        }

        if (ContextCompat.checkSelfPermission(this,
                Manifest.permission.INTERNET)
                != PackageManager.PERMISSION_GRANTED) {

            // Should we show an explanation?


            // No explanation needed, we can request the permission.

            ActivityCompat.requestPermissions(this,
                    new String[]{Manifest.permission.INTERNET},
                    MY_PERMISSIONS_REQUEST_INTERNET);

            // MY_PERMISSIONS_REQUEST_READ_CONTACTS is an
            // app-defined int constant. The callback method gets the
            // result of the request.

        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           String permissions[], int[] grantResults) {
        switch (requestCode) {
            case MY_PERMISSIONS_REQUEST_ACESS_NETWORK_STATE: {
                // If request is cancelled, the result arrays are empty.
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {

                    // permission was granted, yay! Do the
                    // contacts-related task you need to do.

                } else {
                     finish();
                    // permission denied, boo! Disable the
                    // functionality that depends on this permission.
                }
                return;
            }

            case MY_PERMISSIONS_REQUEST_INTERNET: {
                // If request is cancelled, the result arrays are empty.
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {

                    // permission was granted, yay! Do the
                    // contacts-related task you need to do.

                } else {
                    finish();
                    // permission denied, boo! Disable the
                    // functionality that depends on this permission.
                }
                return;
            }




            // other 'case' lines to check for other
            // permissions this app might request
        }
    }



    @Override
    protected void onDestroy() {
        super.onDestroy();
        checkStatus.off();
        mqtTconect.Disconnect();
    }

    @Override
    public void connectionLost(Throwable cause) {

    }

    @Override
    public void messageArrived(String topic, MqttMessage message) throws Exception {

    }

    @Override
    public void deliveryComplete(IMqttDeliveryToken token) {

    }

    @Override
    public void onSuccess(IMqttToken asyncActionToken) {
        mqtTconect.subscribeToTopic();
    }

    @Override
    public void onFailure(IMqttToken asyncActionToken, Throwable exception) {

    }


    private class Checkstatus implements Runnable {

        boolean on = false;

        public void off() {
            on = false;
        }

        @Override
        public void run() {
            on = true;
           while (on) {
            try {
                Thread.sleep(5000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            MainActivity.this.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    if (mqtTconect.isconnected()) {
                        statusTextView.setTextColor(Color.GREEN);
                        statusTextView.setText("conectado");
                    } else {
                        statusTextView.setTextColor(Color.RED);
                        statusTextView.setText("Desconectado");
                    }
                }
            });


        }
        }
    }
}

