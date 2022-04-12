#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

#define BUTTON_1    35
#define BUTTON_2    0
#define rebond  50

unsigned long time_bp1 = 0;
int i = 0;
int last_i = 1;
bool last_bp1=true;

String tab[3][3]={
    {"menu1","1"},
    {"menu2","2"},
    {"menu3","3"}
    };


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
    if(i==4){i=0;}

}

void aff(){
    
    delay(100);
    tft.setCursor(0,25);
    for (int x=0;x<3;x++){
        if (i==x){
            tft.setTextColor(TFT_WHITE,TFT_BLUE);
        }
        tft.println(tab[x][0]+" "+tab[x][1]);
        tft.setTextColor(TFT_WHITE,TFT_BLACK);
    }
    
}

void setup()
{

    pinMode(BUTTON_1,INPUT);
    pinMode(BUTTON_2,INPUT);
    tft.init();
    tft.setRotation(2);
    Serial.begin(115200);
    tft.fillScreen(TFT_RED);
    delay(100);
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE,TFT_BLACK);
    tft.setTextSize(2);

}

void loop(){

    if (digitalRead(BUTTON_2)==false){
        tft.fillScreen(TFT_BLACK);
        i=0;
    }

    tft.drawFloat(i,0,110,220);
    aff();
    bouton();
    delay(10);
  

}