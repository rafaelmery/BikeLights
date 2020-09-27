#include <Adafruit_NeoPixel.h>

#define RearRightPIN        12
#define RearLeftPIN         13 
#define FrontRightPIN       10
#define FrontLeftPIN        11
#define TurnLeftBtn         2
#define TurnRightBtn        3

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 12 // Popular NeoPixel ring size

int FIRSTRUN = 1;
int serialInput = 0;
boolean LeftSign = false;
boolean RightSign = false;
boolean Break = false;

Adafruit_NeoPixel RearRightLed(NUMPIXELS, RearRightPIN , NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel RearLeftLed(NUMPIXELS, RearLeftPIN , NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel FrontRightLed(NUMPIXELS, FrontRightPIN , NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel FrontLeftLed(NUMPIXELS, FrontLeftPIN , NEO_GRB + NEO_KHZ800);

void setup() {
  RearRightLed.begin(); 
  RearLeftLed.begin(); 
  FrontRightLed.begin(); 
  FrontLeftLed.begin(); 
  Serial.begin(9600);
}

void loop() {

  if(FIRSTRUN != 0){
    LedStart();
    FIRSTRUN = 0;
  } else {
    serialInput = Serial.read();
    Serial.println("Valor inserido:" );
    Serial.println(serialInput);

    switch (serialInput){
      case '1':
        TurnLeftLight();
        break;
      case '2':
        TurnRightLight();
        break;
    }
    
    LightStandBy();    
  }
}

void LedStart(){
  RearRightLed.clear();
  RearLeftLed.clear(); 
  FrontRightLed.clear();
  FrontLeftLed.clear(); 
  
  for(int i=0; i<NUMPIXELS; i++) {    
    for (int j=0; j < 255; j=j+3){
      RearRightLed.setPixelColor(i, RearRightLed.Color(j, 0, 0));      
      RearLeftLed.setPixelColor(i, RearLeftLed.Color(j, 0, 0));
      FrontRightLed.setPixelColor(i, FrontRightLed.Color(j, j, j)); //initializing Right light      
      FrontLeftLed.setPixelColor(i, FrontLeftLed.Color(j, j, j)); //initializing left light
      RearRightLed.show(); 
      RearLeftLed.show(); 
      FrontRightLed.show();
      FrontLeftLed.show();   
    } 
  } 
}


void LightStandBy(){
  RearRightLed.clear();
  RearLeftLed.clear(); 
  FrontRightLed.clear();
  FrontLeftLed.clear(); 

  for(int i=0; i<NUMPIXELS; i++) { 
    FrontRightLed.setPixelColor(i, FrontRightLed.Color(255, 255, 255));      
    FrontLeftLed.setPixelColor(i, FrontLeftLed.Color(255, 255, 255));
    FrontRightLed.show(); 
    FrontLeftLed.show(); 
  }
  
  for(int i=0; i<NUMPIXELS; i++) {    
    for (int j=0; j <= 255; j=j+3){
        RearRightLed.setPixelColor(i, RearRightLed.Color(j, 0, 0));      
        RearLeftLed.setPixelColor(i, RearLeftLed.Color(j, 0, 0));
        RearRightLed.show(); 
        RearLeftLed.show(); 
    } 
  } 
  for(int i=0; i<NUMPIXELS; i++) {    
    for (int j=255; j >= 0; j=j-3){
      RearRightLed.setPixelColor(i, RearRightLed.Color(j, 0, 0));      
      RearLeftLed.setPixelColor(i, RearLeftLed.Color(j, 0, 0));
      RearRightLed.show(); 
      RearLeftLed.show(); 
    }     
  }    
  
}

void TurnLeftLight(){

 
  for (int k=0; k < 6; k++){
    RearLeftLed.clear(); 
    FrontLeftLed.clear();

    for(int i=0; i<NUMPIXELS; i++) {
      RearRightLed.setPixelColor(i, RearRightLed.Color(255, 0, 0));         
      RearRightLed.show(); 
    } 
    
    for(int i=0; i<NUMPIXELS; i++) { 
      RearLeftLed.setPixelColor(i, RearLeftLed.Color(153, 153, 0)); // Yellow light
      FrontLeftLed.setPixelColor(i, FrontLeftLed.Color(153, 153, 0)); // Yellow light      
    }
    RearLeftLed.show();   
    FrontLeftLed.show();
  
    delay(500); 

    for(int i=0; i<NUMPIXELS; i++) { 
      RearLeftLed.setPixelColor(i, RearLeftLed.Color(0, 0, 0)); 
      FrontLeftLed.setPixelColor(i, FrontLeftLed.Color(0, 0, 0));     
    }

    RearLeftLed.show();   
    FrontLeftLed.show();
    delay(500); 
  }  
}


void TurnRightLight(){
  for (int k=0; k < 6; k++){
    RearRightLed.clear(); 
    FrontRightLed.clear();

    for(int i=0; i<NUMPIXELS; i++) {
      RearLeftLed.setPixelColor(i, RearLeftLed.Color(255, 0, 0));         
      RearLeftLed.show(); 
    }
    
    for(int i=0; i<NUMPIXELS; i++) { 
      RearRightLed.setPixelColor(i, RearRightLed.Color(153, 153, 0)); // Yellow light
      FrontRightLed.setPixelColor(i, FrontRightLed.Color(153, 153, 0)); // Yellow light      
    }
    RearRightLed.show();   
    FrontRightLed.show();
  
    delay(500); 

    for(int i=0; i<NUMPIXELS; i++) { 
      RearRightLed.setPixelColor(i, RearRightLed.Color(0, 0, 0)); 
      FrontRightLed.setPixelColor(i, FrontRightLed.Color(0, 0, 0));     
    }

    RearRightLed.show();   
    FrontRightLed.show();
    delay(500); 
  }  
}

void BreakLight(){
  for (int k=0; k < 20; k++){
    RearLeftLed.clear(); 
    RearRightLed.clear();
    
    for(int i=0; i<NUMPIXELS; i++) { 
      RearLeftLed.setPixelColor(i, RearLeftLed.Color(255, 0, 0)); 
      RearRightLed.setPixelColor(i, RearRightLed.Color(255, 0, 0));      
    }
    RearLeftLed.show();   
    RearRightLed.show();
  
    delay(50); 

    for(int i=0; i<NUMPIXELS; i++) { 
      RearLeftLed.setPixelColor(i, RearLeftLed.Color(0, 0, 0)); 
      RearRightLed.setPixelColor(i, RearRightLed.Color(0, 0, 0));      
    }
    RearLeftLed.show();   
    RearRightLed.show();
  
    delay(50); 
  }
}
