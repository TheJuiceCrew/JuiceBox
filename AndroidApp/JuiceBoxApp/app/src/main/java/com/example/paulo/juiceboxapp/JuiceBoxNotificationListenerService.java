package com.example.paulo.juiceboxapp;

import android.content.Intent;
import android.os.IBinder;
import android.service.notification.NotificationListenerService;
import android.service.notification.StatusBarNotification;

import org.apache.log4j.chainsaw.Main;

/**
 * Created by alberto on 22/01/2018.
 */

public class JuiceBoxNotificationListenerService extends NotificationListenerService {

    private static final class ApplicationPackageNames {
        public static final String FACEBOOK_PACK_NAME = "com.facebook.katana";
        public static final String FACEBOOK_MESSENGER_PACK_NAME = "com.facebook.orca";
        public static final String WHATSAPP_PACK_NAME = "com.whatsapp";
        public static final String INSTAGRAM_PACK_NAME = "com.instagram.android";
        public static final String EMAIL_PACK_NAME = "com.google.android.gm";
    }


    public static final class InterceptedNotificationCode {
        public static final String FACEBOOK_CODE = "#1*";
        public static final String WHATSAPP_CODE = "#2*";
        public static final String INSTAGRAM_CODE = "#3*";
        public static final String EMAIL_CODE = "#4*";
        public static final String OTHER_NOTIFICATIONS_CODE = "#0*";
    }

    @Override
    public IBinder onBind(Intent intent) {
        return super.onBind(intent);
    }

    @Override
    public void onNotificationPosted(StatusBarNotification sbn){
        // Implement what you want here
        String notificationCode = matchNotificationCode(sbn);


            Intent intent = new  Intent("com.example.paulo.juiceboxapp.JuiceBoxNotificationListenerService");
            intent.putExtra("Notification Code", notificationCode);
            sendBroadcast(intent);

    }

    private String matchNotificationCode(StatusBarNotification sbn) {
        String packageName = sbn.getPackageName();

        if(packageName.equals(ApplicationPackageNames.FACEBOOK_PACK_NAME)
                || packageName.equals(ApplicationPackageNames.FACEBOOK_MESSENGER_PACK_NAME)){
            return(InterceptedNotificationCode.FACEBOOK_CODE);
        }
        else if(packageName.equals(ApplicationPackageNames.INSTAGRAM_PACK_NAME)){
            return(InterceptedNotificationCode.INSTAGRAM_CODE);
        }
        else if(packageName.equals(ApplicationPackageNames.WHATSAPP_PACK_NAME)){
            return(InterceptedNotificationCode.WHATSAPP_CODE);
        }
        else if(packageName.equals(ApplicationPackageNames.EMAIL_PACK_NAME)){
            return(InterceptedNotificationCode.EMAIL_CODE);
        }
        else{
            return(InterceptedNotificationCode.OTHER_NOTIFICATIONS_CODE);
        }
    }

    @Override
    public void onNotificationRemoved(StatusBarNotification sbn){
        // Implement what you want here
    }
}