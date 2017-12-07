#include "iot_configs.h"
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <WiFiUdp.h>

#include <AzureIoTHub.h>
#if defined(IOT_CONFIG_MQTT)
    #include <AzureIoTProtocol_MQTT.h>
#elif defined(IOT_CONFIG_HTTP)
    #include <AzureIoTProtocol_HTTP.h>
#endif

#include "remote_monitoring.h"

static char ssid[] = IOT_CONFIG_WIFI_SSID;
static char pass[] = IOT_CONFIG_WIFI_PASSWORD;

void setup() {
    initSerial();
    initWifi();
    initTime();
}

void loop() {
    remote_monitoring_run();
}

void initSerial() {
    Serial.begin(115200);
    //Serial.setDebugOutput(true);
}

void initWifi() {
    Serial.print("\r\n\r\nAttempting to connect to SSID: ");
    Serial.println(ssid);

    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

    Serial.println("\r\nConnected to wifi");
}

void initTime() {  
   time_t epochTime;

   configTime(0, 0, "pool.ntp.org", "time.nist.gov");

   while (true) {
       epochTime = time(NULL);

       if (epochTime == 0) {
           Serial.println("Fetching NTP epoch time failed! Waiting 2 seconds to retry.");
           delay(2000);
       } else {
           Serial.print("Fetched NTP epoch time is: ");
           Serial.println(epochTime);
           break;
       }
   }
}
