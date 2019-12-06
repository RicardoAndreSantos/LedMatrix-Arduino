#include <SoftwareSerial.h>
#include <FastLED.h>

#define NUM_LEDS 100
#define DATA_PIN 6

// Array of leds
CRGB leds[NUM_LEDS];

char c;


String pos ="" ;
String color = "" ;

SoftwareSerial bluetooth(10,11);
// 10 - RX
// 11 - TX

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

  Serial.setTimeout(100);

}

void loop() {
  if(bluetooth.available()){
    delay(20);
    //Serial.write(bluetooth.read());
    while(bluetooth.available()){
      c = bluetooth.read();
      if(c >= '0' && c <= '9'){
        pos.concat(c);
      }
      else if(c != '-'){
        color.concat(c);
      }
      else{
        continue;
      }
    }
    Serial.print("LED   -> ");
    Serial.println(pos);
    Serial.print("COLOR -> ");
    Serial.println(color);
    Serial.println("-------------");

    if(color == "green"){
      ledGreen(pos.toInt());
      Serial.println("LIGAR VERDE");
    }

    if(color == "linghtGreen"){
      ledLightGreen(pos.toInt());
      Serial.println("LIGAR Verde Claro");
    }
    
    if(color == "red"){
      ledRed(pos.toInt());
      Serial.println("LIGAR VERMELHO");
    }
    
    if(color == "blue"){
      ledBlue(pos.toInt());
      Serial.println("LIGAR Azul");
    }

    if(color == "lightBlue"){
      ledLightBlue(pos.toInt());
      Serial.println("LIGAR Azul Claro");
    }

    if(color == "yellow"){
      ledYellow(pos.toInt());
      Serial.println("LIGAR Amarelo");
    }

    if(color == "orange"){
      ledOrange(pos.toInt());
      Serial.println("LIGAR Laranja");
    }

    if(color == "purple"){
      ledPurple(pos.toInt());
      Serial.println("LIGAR Roxo");      
    }

    if(color == "white"){
      ledWhite(pos.toInt());
      Serial.println("LIGAR Branco");       
    }

    if(color == "pink"){
      ledPink(pos.toInt());
      Serial.println("LIGAR Rosa");        
    }
    
    if(color == "clear"){
      Serial.println("DESLIGAR LED");
      ledClear(pos.toInt());
    }

    if(color == "clearAll"){
      Serial.println("APAGAR");

      for(int i=0 ; i<NUM_LEDS ; i++){
        leds[i] = CRGB::Black;
      }
      FastLED.show();
      /*
      bluetooth.println("{");
      bluetooth.println("APAGOU");
      bluetooth.println("}");
      */
    }
  }
    
  else{
    pos = "" ;
    color= "" ;
  }
   
  /*
  if(Serial.available()){
    //bluetooth.write(Serial.read());
    String aux = Serial.readString();
    Serial.println(aux);
  }
  */
}

//-----------------------------------
void ledGreen(int i){
  leds[i-1] = CRGB::Green;  
  FastLED.show();
}

void ledLightGreen(int i){
  leds[i-1].setRGB( 128, 255, 0);
  FastLED.show();
}

void ledRed(int i){
  leds[i-1] = CRGB::Red;  
  FastLED.show();
}

void ledBlue(int i){
  leds[i-1] = CRGB::Blue;  
  FastLED.show();  
}

void ledLightBlue(int i){
  leds[i-1].setRGB( 0, 255, 255);
  FastLED.show(); 
}

void ledYellow(int i){
  leds[i-1].setRGB( 255, 255, 0);
  FastLED.show(); 
}

void ledOrange(int i){
  leds[i-1].setRGB( 255, 90, 0);
  FastLED.show(); 
}

void ledPurple(int i){
  leds[i-1].setRGB( 128,0,128);
  FastLED.show();
}

void ledWhite(int i){
  leds[i-1].setRGB( 255,255,255);
  FastLED.show();
}


void ledPink(int i){
  leds[i-1].setRGB( 255,20,147);
  FastLED.show();  
}

//-------------------------------------------------------------------
//linghtGreen
//leds[0].setRGB( 128, 255, 0);

//lightBlue
//leds[0].setRGB( 0, 255, 255);

//amarelo
//leds[0].setRGB( 255, 255, 0);

//laranja
//leds[0].setRGB( 255, 90, 0);

//ROXO
//leds[0].setRGB( 128,0,128);

//Branco
//leds[0].setRGB( 255,255,255);



void ledClear(int i){
  leds[i-1] = CRGB::Black;  
  FastLED.show();
}



