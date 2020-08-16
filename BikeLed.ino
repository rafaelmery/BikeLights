#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define RearRightPIN        10
#define RearLeftPIN         11 
#define FrontRightPIN       12
#define FrontLeftPIN        13 

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 12 // Popular NeoPixel ring size

int FIRSTRUN = 1;
int turnSign = 0;
boolean Break = false;

Adafruit_NeoPixel RearRightLed(NUMPIXELS, RearRightPIN , NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel RearLeftLed(NUMPIXELS, RearLeftPIN , NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel FrontRightLed(NUMPIXELS, FrontRightPIN , NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel FrontLeftLed(NUMPIXELS, FrontLeftPIN , NEO_GRB + NEO_KHZ800);

//#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels

void setup() {
  RearRightLed.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  RearLeftLed.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  FrontRightLed.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  FrontLeftLed.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);  
}

void loop() {

  if(FIRSTRUN != 0){
    RearLedStart();
    FrontLightStart();
    FIRSTRUN = 0;
  } else {
    turnSign = Serial.read();
    if(turnSign == '1'){
      Serial.println("Turn Right");
      TurnRightLight();      
    }

    if(turnSign == '2'){      
      Serial.println("Turn Left");
      TurnLeftLight();
    }

    if(turnSign == '3'){      
      Serial.println("Break");
      BreakLight();
    }
    
    RearLightStandBy(); 
    FrontLightStandBy(); 
  }
}

void RearLedStart(){
  RearRightLed.clear();
  RearLeftLed.clear(); 
  for(int i=0; i<NUMPIXELS; i++) { 
    for (int j=0; j < 255; j++){
      RearRightLed.setPixelColor(i, RearRightLed.Color(j, 0, 0));      
      RearLeftLed.setPixelColor(i, RearLeftLed.Color(j, 0, 0));
      RearRightLed.show(); 
      RearLeftLed.show();     
    } 
  }
}

void FrontLightStart(){
  FrontRightLed.clear();
  FrontLeftLed.clear(); 
  for(int i=0; i<NUMPIXELS; i++) { 
    for (int j=0; j < 255; j++){
      FrontRightLed.setPixelColor(i, FrontRightLed.Color(j, j, j)); //initializing Right light      
      FrontLeftLed.setPixelColor(i, FrontLeftLed.Color(j, j, j)); //initializing left light
      FrontRightLed.show();
      FrontLeftLed.show();    
    } 
  }
}

void RearLightStandBy(){
  RearRightLed.clear(); 
  RearLeftLed.clear(); 
  for(int i=0; i<NUMPIXELS; i++) { 
    RearRightLed.setPixelColor(i, RearRightLed.Color(255, 0, 0));  
    RearLeftLed.setPixelColor(i, RearLeftLed.Color(255, 0, 0));        
  }
  RearRightLed.show();   
  RearLeftLed.show(); 
}

void FrontLightStandBy(){
  FrontRightLed.clear(); 
  FrontLeftLed.clear(); 
  for(int i=0; i<NUMPIXELS; i++) { 
    FrontRightLed.setPixelColor(i, FrontRightLed.Color(255, 255, 255));  
    FrontLeftLed.setPixelColor(i, FrontLeftLed.Color(255, 255, 255));        
  }
  //FrontLeftLed.setBrightness(70);
  //FrontRightLed.setBrightness(70);
  FrontRightLed.show();   
  FrontLeftLed.show(); 
}

void TurnLeftLight(){
  for (int k=0; k < 6; k++){
    RearLeftLed.clear(); 
    FrontLeftLed.clear();
    
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
