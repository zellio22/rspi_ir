#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>


TFT_eSPI tft = TFT_eSPI(); 
#define ADC_BP 36
#define ADC_BAT 34
int vref = 1100;
unsigned long time_reset_bp = 0;
uint16_t ana_bp = 0;

String bp_loop(){
if(ana_bp<1){
    
    time_reset_bp=millis();
    return "Bp Bas      ";
    }

if(ana_bp<89){
    time_reset_bp=millis();
    return "Bp Droit      ";
    }

if(ana_bp<355){
    time_reset_bp=millis();
    return "Bp Haut      ";
    }

if(ana_bp<690){
    time_reset_bp=millis();
    return "Bp Gauche    ";
    }

if(ana_bp<1095){
    tft.drawString(String("Bp Mid")+"     ",0,150);
    time_reset_bp=millis();
    return "Bp Mid";
    }

else if (millis()>time_reset_bp+1500){
    tft.drawString(String("             "),0,150);
    return "       ";
    }
return "       ";
}

void bat_lvl(){

    //100% 2390
    //0% 1700
    uint16_t v = analogRead(ADC_BAT);
    float battery_voltage = ((float)v / 4095.0) * 2.0 * 3.3 * (vref / 1000.0);
    float bettery_percent = ((float)(v-1700)/694*100);
    tft.setTextColor(65000, TFT_BLACK);
    tft.drawString(String(battery_voltage)+" V",64,220);
    tft.drawString(String(int(bettery_percent))+" % ",0,220);
    //tft.drawString(String(v)+" %",0,220);
    tft.setTextColor(tft.color565(0xFF,0x0,0x01), TFT_BLACK);
    tft.setTextSize(3);
}
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
ana_bp = analogRead(ADC_BP);
tft.setTextColor(65000, TFT_BLACK);
tft.setTextColor(tft.color565(0xFF,0x0,0x01), TFT_BLACK);
tft.drawString(String(ana_bp)+"     ",0,32);

delay(50);
tft.setTextSize(2);
tft.drawString(bp_loop(),0,150);
bat_lvl();
tft.setTextSize(3);

}

