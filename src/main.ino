#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>
TFT_eSPI tft = TFT_eSPI(); 
#include <div_fonc.h>

int count = 0;
unsigned long loop_time = 0;
String tab[8][3]={
    {" menu1","1"},
    {" menu2","2"},
    {" menu3","3"},
    {" menu4","4"},
    {" menu5","5"},
    {" menu6","6"},
    {" menu7","7"},
    {" menu8","8"}
    };

void aff(){
    
    //delay(100);
    tft.setTextColor(TFT_WHITE,TFT_BLACK);
    tft.setCursor(0,35);
    for (int x=0;x<8;x++){
        if (count==x){
            tft.setTextColor(TFT_WHITE,TFT_BLUE);
        }
        tft.println(tab[x][0]+" "+tab[x][1]);
        tft.setTextColor(TFT_WHITE,TFT_BLACK);
    }
    
}

void setup()
{
    tft.init();
    tft.setRotation(2);
    Serial.begin(115200);
    delay(100);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(2);
}

void loop(){

tft.setTextColor(tft.color565(0xFA,0x80,0x72), TFT_BLACK);
tft.drawString(String(millis()-loop_time)+"    ",40,200);
loop_time=millis();



String lec_bp=bp_loop();

tft.drawString(lec_bp,10,5);
tft.setTextColor(tft.color565(0xFF,0x0,0x01), TFT_BLACK);
bat_lvl();

if(lec_bp=="Bp Haut          "){
    count--;
}
if(lec_bp=="Bp Bas      "){
    count++;
}
if(lec_bp=="bp L haut       "){
    count--;
    delay(100);
}
if(lec_bp=="bp L bas       "){
    count++;
    delay(100);
}

if(count==8){count=0;}
if(count==-1){count=7;}

aff();

tft.setTextColor(tft.color565(0x31,0x8D,0x1A), TFT_BLACK);
tft.drawString(String(count)+"      ",5,200);
tft.setTextColor(tft.color565(0xFF,0x0,0x01), TFT_BLACK);
}

