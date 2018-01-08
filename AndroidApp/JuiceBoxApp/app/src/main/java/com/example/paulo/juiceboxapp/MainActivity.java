package com.example.paulo.juiceboxapp;

        import android.os.Environment;
        import android.support.v7.app.AppCompatActivity;
        import android.os.Bundle;
        import android.util.Log;

        import java.io.File;
        import java.io.IOException;
        import java.util.Properties;

        import io.moquette.BrokerConstants;
        import io.moquette.server.config.MemoryConfig;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "mainactivity";
    private io.moquette.server.Server server;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        try


        {
            MemoryConfig memoryConfig = new MemoryConfig(new Properties());
            memoryConfig.setProperty(BrokerConstants.PERSISTENT_STORE_PROPERTY_NAME, Environment.getExternalStorageDirectory().getAbsolutePath()+ File.separator + BrokerConstants.DEFAULT_MOQUETTE_STORE_MAP_DB_FILENAME);
            server.startServer(memoryConfig);
            // server.startServer();//is not working due to DEFAULT_MOQUETTE_STORE_MAP_DB_FILENAME;
            Log.d(TAG,"Server Started");
        }
        catch (IOException e) { e.printStackTrace(); }
        catch (Exception e){ e.printStackTrace(); }

    }

}

