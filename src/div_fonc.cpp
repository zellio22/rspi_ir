#include "Arduino.h"
#include "TFT_eSPI.h"
#define ADC_BP 36
#define ADC_BAT 34
int vref = 1100;
uint16_t ana_bp;
unsigned long time_reset_bp =0;
extern TFT_eSPI tft;
String last_bp="";

String bp_loop(){


ana_bp = analogRead(ADC_BP);
tft.setTextColor(tft.color565(0xFF,0x0,0x01), TFT_BLACK);
tft.setTextSize(2);

if(ana_bp< 1 && last_bp==""){
    time_reset_bp=millis();
    last_bp="bas";
    return "Bp Bas      ";
    }

if(ana_bp<89 && last_bp==""){
    time_reset_bp=millis();
    last_bp="droit";
    return "Bp Droit         ";
    }

if(ana_bp<355 && last_bp==""){
    time_reset_bp=millis();
    last_bp="haut";
    return "Bp Haut          ";
    }

if(ana_bp<690 && last_bp==""){
    time_reset_bp=millis();
    last_bp="gauche";
    return "Bp Gauche        ";
    }

if(ana_bp<1095 && last_bp==""){
    time_reset_bp=millis();
    last_bp="mid";
    return "Bp Mid           ";
    }

if(ana_bp>4094){
    last_bp="";
    return "none           ";
    }

if(millis()>time_reset_bp+300 && last_bp!=""){
    tft.setTextColor(tft.color565(0x00,0x00,0xFF), TFT_BLACK);
    //tft.drawString("Long",0,170);
    
    return "bp L "+last_bp+"       ";
    }

if (millis()>time_reset_bp+1500 && last_bp==""){
    tft.drawString(String("             "),0,150);
    tft.drawString(String("             "),0,170);
    last_bp="";
    return "             ";
    }


return"";
}


void bat_lvl(){

    //100% 2390
    //0% 1700

    uint16_t v = analogRead(ADC_BAT);
    if(v>2700){
        tft.setTextColor(tft.color565(0x00,0xFF,0x00), TFT_BLACK);
        tft.drawString("USB Full    ",0,220);
    }
    else if(v>2450){
        tft.setTextColor(tft.color565(0xFF,0x0,0x1F), TFT_BLACK);
        tft.drawString("USB Charge    ",0,220);
    }
    else{
    float battery_voltage = ((float)v / 4095.0) * 2.0 * 3.3 * (vref / 1000.0);
    float bettery_percent = ((float)(v-1700)/694*100);
    tft.setTextColor(tft.color565(0xFF,0xFF,0x00), TFT_BLACK);
    tft.drawString(String(battery_voltage)+" V",64,220);
    tft.drawString(String(int(bettery_percent))+" % ",0,220);
    //tft.drawString(String(v)+" %",0,220);
    tft.setTextColor(tft.color565(0xFF,0x0,0x01), TFT_BLACK);

    }
}



