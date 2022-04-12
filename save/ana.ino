#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>


TFT_eSPI tft = TFT_eSPI(); 
#define ADC_PIN 34
int vref = 1100;
void setup()
{

    tft.init();
    tft.setRotation(2);

    Serial.begin(115200);

    delay(100);
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(65000, TFT_BLACK);
    tft.setTextSize(3);
    


}

void loop()
{
uint16_t v = analogRead(ADC_PIN);
float battery_voltage = ((float)v / 4095.0) * 2.0 * 3.3 * (vref / 1000.0);
tft.setTextColor(65000, TFT_BLACK);
tft.drawString(String(battery_voltage)+" V",0,8);
tft.setTextColor(tft.color565(0xFF,0x0,0x01), TFT_BLACK);
tft.drawString(String(v)+" ",0,32);
//tft.print("juliendqsfqsdfqsdf");
delay(10);
  

}