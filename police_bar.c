  /*
    Police Lightbar program. 
    
    -3 Sequences of lights
    
    @author Matthew Routon
    @version: 11-12-18
  */
  
  const int BLUE_PINS[] = { 6, 7, 8 };
  const int RED_PINS[] = { 10, 11, 12 };
  const int PINS_LENGTH = 3; // same for red and blue
  
  
  void setup() {
      
      for (int i = 0; i < PINS_LENGTH; i++) {
        
        pinMode(BLUE_PINS[i], OUTPUT); 
      }
      
      for (int i = 0; i < PINS_LENGTH; i++) {
        pinMode(RED_PINS[i], OUTPUT); 
      }
      
         
  }
  
  void loop() {                           
      
      cleanBar(); 
      
      runIdleSequence();
      
      cleanBar(); 
          
      runFlickerAlternateSequence();
      
      cleanBar(); 
      
      runIdleSequence();
      
      cleanBar();
      
      for (int i = 0; i < 3; i++) {
        doFollowFlash();  
      }     
            
      
  }
  
  void bluesOn() {
    
    for (int i = 0; i < PINS_LENGTH; i++) {
        
        digitalWrite(BLUE_PINS[i], HIGH);      
    }
  }
  
  void bluesOff() {
    
    for (int i = 0; i < PINS_LENGTH; i++) {
        
        digitalWrite(BLUE_PINS[i], LOW);      
    }
  }
  
  void redsOn() {
    
    for (int i = 0; i < PINS_LENGTH; i++) {
      
      digitalWrite(RED_PINS[i], HIGH);
    }
  }
  
  void redsOff() {
    
    for (int i = 0; i < PINS_LENGTH; i++) {
      
      digitalWrite(RED_PINS[i], LOW); 
    }
  }
  
  void runIdleSequence() {
    
      for (int i = 0; i < 5; i++) {     
        doIdleAlternateFlash(500);  
      }  
      for (int i =0; i < 9; i++) {
        doIdleAlternateFlash(100); 
      }
      for (int i = 0; i < 5; i++) {     
        doIdleAlternateFlash(500);  
      }  
  }
  
  void doIdleAlternateFlash(int interval) {    
      
      bluesOn();
      delay(interval);
      bluesOff(); 
      redsOn();
      delay(interval);
      redsOff();
      bluesOn();
  }
  
  void doFollowFlash() {
    
    const int STEP_DELAY = 75;
    
    for (int i = 0; i < PINS_LENGTH; i++) {
      digitalWrite(BLUE_PINS[i], HIGH);
      digitalWrite(RED_PINS[i], HIGH); 
      delay(STEP_DELAY); 
      digitalWrite(BLUE_PINS[i], LOW);
      digitalWrite(RED_PINS[i], LOW);
    }
    
    cleanBar(); 
    
    for (int i = PINS_LENGTH - 1; i >= 0; i--) {
      digitalWrite(BLUE_PINS[i], HIGH);
      digitalWrite(RED_PINS[i], HIGH); 
      delay(STEP_DELAY); 
      digitalWrite(BLUE_PINS[i], LOW);
      digitalWrite(RED_PINS[i], LOW);
    }
  }
  
  void runFlickerAlternateSequence() {
    
    for (int i = 0; i < 5; i++) {
      
      doFlickerAlternateFlash(); 
    }  
  }
  
  void doFlickerAlternateFlash() {  
    
    const int STEP_DELAY = 175; 
    const int FLICKER_COUNT = 7; 
    const int FLICKER_DELAY = 25; 
    
    for (int i = 0; i < FLICKER_COUNT; i++) {
      bluesOn();
      delay(FLICKER_DELAY);
      bluesOff(); 
      delay(FLICKER_DELAY);
    }
    
    bluesOn();
    delay(STEP_DELAY);  
    bluesOff();
    
     for (int i = 0; i < FLICKER_COUNT; i++) {
      redsOn();
      delay(FLICKER_DELAY);
      redsOff(); 
      delay(FLICKER_DELAY);
    }
    
    redsOn();
    delay(STEP_DELAY);
    redsOff(); 
    
  }
  
  void cleanBar() {
    redsOff(); 
    bluesOff(); 
  }
  
  
