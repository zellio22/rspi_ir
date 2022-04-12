#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>
#include "WiFi.h"

TFT_eSPI tft = TFT_eSPI(); 

void setup()
{

    tft.init();
    tft.setRotation(2);

    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(65000, TFT_BLACK);
    Serial.println("Setup done");
}

void loop()
{
  Serial.println("scan start");

  int n = WiFi.scanNetworks();
  tft.fillScreen(TFT_BLACK);
  Serial.println("scan done");
  Serial.println("longueur ");
  Serial.print(strlen("gdfh"));

  if (n == 0) {
    Serial.println("no networks found");
    } 

  else {
    Serial.print(n);
    Serial.println(" networks found");
      for (int i = 0; i < n; ++i) {
        // Print SSID and RSSI for each network found
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(WiFi.SSID(i));
        Serial.print(" (");
        Serial.print(WiFi.RSSI(i));
        tft.setTextColor(WiFi.RSSI(i)*-655, TFT_BLACK);
        Serial.print(")");
        Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
        tft.drawString(WiFi.SSID(i),2,16*i , 2);
        //tft.drawFloat(WiFi.RSSI(i),WiFi.SSID(i).length()+4,26*i , 2);
        delay(10);
        }
    }
    Serial.println("");

    // Wait a bit before scanning again



delay(1000);

}