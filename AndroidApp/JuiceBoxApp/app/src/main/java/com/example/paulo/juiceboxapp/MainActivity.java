package com.example.paulo.juiceboxapp;

        import android.Manifest;
        import android.content.BroadcastReceiver;
        import android.content.ComponentName;
        import android.content.Context;
        import android.content.DialogInterface;
        import android.content.Intent;
        import android.content.IntentFilter;
        import android.content.pm.PackageManager;
        import android.graphics.Color;
        import android.os.Environment;
        import android.provider.Settings;
        import android.support.v4.app.ActivityCompat;
        import android.support.v4.content.ContextCompat;
        import android.support.v7.app.AlertDialog;
        import android.support.v7.app.AppCompatActivity;
        import android.os.Bundle;
        import android.text.TextUtils;
        import android.util.Log;
        import android.view.View;
        import android.widget.Button;
        import android.widget.EditText;
        import android.widget.TextView;

        import org.eclipse.paho.client.mqttv3.IMqttActionListener;
        import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
        import org.eclipse.paho.client.mqttv3.IMqttToken;
        import org.eclipse.paho.client.mqttv3.MqttCallback;
        import org.eclipse.paho.client.mqttv3.MqttMessage;

        import java.io.File;
        import java.io.IOException;
        import java.util.Properties;

        import io.moquette.BrokerConstants;
        import io.moquette.server.Server;
        import io.moquette.server.config.MemoryConfig;

public class MainActivity extends AppCompatActivity implements MqttCallback,IMqttActionListener {

    private static final String TAG = "mainactivity";
    private static final String MESSAGE_GENERIC_APP = "#0*";
    private static final String MESSAGE_FACEBOOK = "#1*";
    private static final String MESSAGE_WHATSAPP = "#2*";
    private static final String MESSAGE_INSTAGRAM = "#3*";
    private static final String MESSAGE_EMAIL = "#4*";
    private static final String TOPIC = "box";
    private Button btnConect;
    private EditText editServerAdress;
    private TextView statusTextView;
    private Button btnFacebook;
    private Button btn_whatsapp;
    private Button btn_instagram;

    public static MQTTconect mqtTconect;
    private Checkstatus checkStatus;
    private final int  MY_PERMISSIONS_REQUEST_ACESS_NETWORK_STATE = 100;
    private final int MY_PERMISSIONS_REQUEST_INTERNET = 101;
    private final int MY_PERMISSIONS_EXTERNAL_STORAGE = 102;
    private final int MY_PERMISSIONS_READ_EXTERNAL_STORAGE = 103;

    private Server moquetteServer;
    private Button btn_email;
    private Button btn_generic_app;
    private EditText editTopic;

    private static final String ENABLED_NOTIFICATION_LISTENERS = "enabled_notification_listeners";
    private static final String ACTION_NOTIFICATION_LISTENER_SETTINGS = "android.settings.ACTION_NOTIFICATION_LISTENER_SETTINGS";
    private AlertDialog enableNotificationListenerAlertDialog;
    private SendNotificationBroadcastReceiver sendNotificationBroadcastReceiver;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);




        btnConect = findViewById(R.id.btn_conect);
        editServerAdress = findViewById(R.id.edit_server_adress);
        editTopic = findViewById(R.id.edit_topic);
        statusTextView = findViewById(R.id.status_conection);
        btnFacebook = findViewById(R.id.btn_facebook);
        btn_whatsapp = findViewById(R.id.btn_whatsapp);
        btn_instagram = findViewById(R.id.btn_instagram);
        btn_email = findViewById(R.id.btn_email);
        btn_generic_app = findViewById(R.id.btn_generic_app);

        mqtTconect = new MQTTconect(this,this);

        editServerAdress.setText(mqtTconect.getServerAndress());
        editTopic.setText(mqtTconect.getPublishTopic());


        btnConect.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if (mqtTconect.isconnected()) {
                    try {
                        mqtTconect.Disconnect();
                        editServerAdress.setEnabled(true);
                        editTopic.setEnabled(true);
                        btnConect.setText("Connect");
                    } catch ( Exception e ) {
                        e.printStackTrace();
                    }

                } else {
                    editServerAdress.setEnabled(false);
                    editTopic.setEnabled(false);
                    btnConect.setText("Disconnect");
                    mqtTconect.setPublishTopic(editTopic.getText().toString());
                    mqtTconect.setServerAndress(editServerAdress.getText().toString());
                    mqtTconect.doConnect(MainActivity.this);
                }
            }
        });

        btn_generic_app.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if (mqtTconect.isconnected()) {
                    mqtTconect.sendMessage(MESSAGE_GENERIC_APP);
                }
            }
        });

        btnFacebook.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if (mqtTconect.isconnected()) {
                    mqtTconect.sendMessage(MESSAGE_FACEBOOK);
                }
            }
        });

        btn_instagram.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mqtTconect.isconnected()) {
                    mqtTconect.sendMessage(MESSAGE_INSTAGRAM);
                }
            }
        });

        btn_whatsapp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mqtTconect.isconnected()) {
                    mqtTconect.sendMessage(MESSAGE_WHATSAPP);
                }
            }
        });

        btn_email.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mqtTconect.isconnected()) {
                    mqtTconect.sendMessage(MESSAGE_EMAIL);
                }
            }
        });

        checkStatus = new Checkstatus();
        Thread thread = new Thread(checkStatus);
        thread.start();

        if (persistentStoragePermissionsGranted()) {
            setupMoquetteServer();
        } else {
            requestExternalStoragePermission();
        }

        // If the user did not turn the notification listener service on we prompt him to do so
        if(!isNotificationServiceEnabled()){
            enableNotificationListenerAlertDialog = buildNotificationServiceAlertDialog();
            enableNotificationListenerAlertDialog.show();
        }

        // Finally we register a receiver to tell the MainActivity when a notification has been received
        sendNotificationBroadcastReceiver = new SendNotificationBroadcastReceiver();
        IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction("com.example.paulo.juiceboxapp.JuiceBoxNotificationListenerService");
        registerReceiver(sendNotificationBroadcastReceiver,intentFilter);

    }

    private boolean isNotificationServiceEnabled(){
        String pkgName = getPackageName();
        final String flat = Settings.Secure.getString(getContentResolver(),
                ENABLED_NOTIFICATION_LISTENERS);
        if (!TextUtils.isEmpty(flat)) {
            final String[] names = flat.split(":");
            for (int i = 0; i < names.length; i++) {
                final ComponentName cn = ComponentName.unflattenFromString(names[i]);
                if (cn != null) {
                    if (TextUtils.equals(pkgName, cn.getPackageName())) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean persistentStoragePermissionsGranted () {

        if (ContextCompat.checkSelfPermission(this,
                Manifest.permission.WRITE_EXTERNAL_STORAGE)
                == PackageManager.PERMISSION_GRANTED) {
            if (ContextCompat.checkSelfPermission(this,
                    Manifest.permission.READ_EXTERNAL_STORAGE)
                    == PackageManager.PERMISSION_GRANTED) {
                return true;
            }
        }

        return false;
    }

    private AlertDialog buildNotificationServiceAlertDialog(){
        AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(this);
        alertDialogBuilder.setTitle("Ativar serviço de notificação?");
        alertDialogBuilder.setMessage("precisamos ativar o serviço de nmotificação para a juicebox funcionar corretamente");
        alertDialogBuilder.setPositiveButton("sim :>",
                new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        startActivity(new Intent(ACTION_NOTIFICATION_LISTENER_SETTINGS));
                    }
                });
        alertDialogBuilder.setNegativeButton("naum >:(",
                new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        // If you choose to not enable the notification listener
                        // the app. will not work as expected
                    }
                });
        return(alertDialogBuilder.create());
    }

    private void setupMoquetteServer() {
        moquetteServer = new Server();
        try {
            MemoryConfig memoryConfig = new MemoryConfig(new Properties());
            memoryConfig.setProperty(BrokerConstants.PERSISTENT_STORE_PROPERTY_NAME, Environment.getExternalStorageDirectory().getAbsolutePath()+ File.separator + BrokerConstants.DEFAULT_MOQUETTE_STORE_MAP_DB_FILENAME);
            moquetteServer.startServer(memoryConfig);
            Log.d(TAG,"Server Started");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void requestExternalStoragePermission () {
        ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE},
                    MY_PERMISSIONS_EXTERNAL_STORAGE);
    }

    public void requestExternalStorageReadPermission () {
        ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.READ_EXTERNAL_STORAGE},
                MY_PERMISSIONS_READ_EXTERNAL_STORAGE);
    }


    public void getPermissions () {

        /*
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
        */
    }


    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           String permissions[], int[] grantResults) {
        switch (requestCode) {
            case MY_PERMISSIONS_EXTERNAL_STORAGE: {
                // If request is cancelled, the result arrays are empty.
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {

                    requestExternalStorageReadPermission();
                    // permission was granted, yay! Do the
                    // contacts-related task you need to do.

                } else {
                     finish();
                    // permission denied, boo! Disable the
                    // functionality that depends on this permission.
                }
                return;
            }

            case MY_PERMISSIONS_READ_EXTERNAL_STORAGE: {
                // If request is cancelled, the result arrays are empty.
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {

                    setupMoquetteServer();
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
        if (mqtTconect.isconnected()) mqtTconect.Disconnect();
        unregisterReceiver(sendNotificationBroadcastReceiver);
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

    /**
     * Change Intercepted Notification Image
     * Changes the MainActivity image based on which notification was intercepted
     * @param notificationCode The intercepted notification code
     */
    private void sendNotification(String notificationCode){
        Log.d(TAG,"Notificação recebida: " + notificationCode);
        if (mqtTconect.isconnected()) {
            mqtTconect.sendMessage(notificationCode);
        }
    }

    /**
     * Image Change Broadcast Receiver.
     * We use this Broadcast Receiver to notify the Main Activity when
     * a new notification has arrived, so it can properly change the
     * notification image
     * */
    public class SendNotificationBroadcastReceiver extends BroadcastReceiver {
        @Override
        public void onReceive(Context context, Intent intent) {
            String receivedNotificationCode = intent.getStringExtra("Notification Code");
            sendNotification(receivedNotificationCode);
        }
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

