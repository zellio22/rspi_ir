#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

#define BUTTON_1    35
#define BUTTON_2    0
#define rebond  50

unsigned long time_bp1 = 0;
int i =0;
bool last_bp1=true;


TFT_eSPI tft = TFT_eSPI(); 

void bouton(){
    if (digitalRead(BUTTON_1)==false && time_bp1+rebond<millis() && last_bp1 == true){
        i=i+1;
        time_bp1=millis();
        last_bp1=false;
    }

    else if (digitalRead(BUTTON_1)==true && time_bp1+rebond<millis() && last_bp1 == false){
        last_bp1=true;
    }

}

void setup()
{

    pinMode(BUTTON_1,INPUT);
    pinMode(BUTTON_2,INPUT);
    tft.init();
    tft.setRotation(2);
    Serial.begin(115200);
    delay(100);
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE,TFT_BLACK);
    tft.setTextSize(2);
    


}

void loop()
{
    tft.drawFloat(i,0,10,10);

    if (digitalRead(BUTTON_2)==false){
        tft.fillScreen(TFT_BLACK);
        tft.setCursor(0,0);
        i=0;
    }
bouton();
delay(10);
  

}