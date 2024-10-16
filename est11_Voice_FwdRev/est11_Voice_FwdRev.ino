
// Title: Voice Assisted FWD-REV 3 Phase Induction Motor Controller Using MIT App

#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 12); // RX, TX pins for voice recognition(bluetooth module

//const int placed here any_variable_name = 4; // variable #1 Pin for controlling fwd direction 
const int FWD_VCP = 5; // variable #1 Pin for controlling fwd direction  
const int REV_VCP = 6; // variable #2 Pin for controlling rev 
const int STOP_VCP = 7; // variable #3 Pin for controlling stop
const int LED_FWD = 8; // variable #4 LED for fwd 
const int LED_REV = 9; // variable #5 LED for rev
const int LED_STOP = 10; // variable #6 LED for stop

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  
  pinMode(FWD_VCP, OUTPUT);  // variable #1
  pinMode(REV_VCP, OUTPUT);  // variable #2
  pinMode(STOP_VCP, OUTPUT);  // variable #3
  pinMode(LED_FWD, OUTPUT);  // variable #4 LED1
  pinMode(LED_REV, OUTPUT);  // variable #5 LED2
  pinMode(LED_STOP, OUTPUT);  // variable #6 LED3
  
  
}

void loop() {
  if (mySerial.available()) {
    String voiceCommand = mySerial.readStringUntil('\n');
    voiceCommand.trim(); // Remove leading/trailing spaces

    // Check for specific voice commands
    if (voiceCommand.equalsIgnoreCase("abanti")) { // on the space provided for...place any word u want to activate FWD
      FWD(FWD_VCP);
    } else if (voiceCommand.equalsIgnoreCase("atras")) { // place here any wordings to activate REV directions
      REV(REV_VCP);
    } else if (voiceCommand.equalsIgnoreCase("tigil")) { // ur chosen word to STOP the motor
      STOP(STOP_VCP);
    }
    
    // Add more commands as needed

    delay(1000); // Adjust as needed to prevent false triggers
  }
}

void FWD(int FWD_VCP) { // ur chosen word to activate FWD directions
  // Activate the corresponding Motor directions
  digitalWrite(FWD_VCP, HIGH);
  digitalWrite(LED_FWD, HIGH);
  Serial.println("FORWARD=========>");
  
  delay(1500); // Simulating Motor direction shifting; adjust as needed
  
  // Deactivate FWD operation
  digitalWrite(FWD_VCP, LOW);
  digitalWrite(LED_FWD, LOW);
}

void REV(int REV_VCP) { // ur chosen word to activate REV directions
  // Activate the corresponding Motor directions 
  digitalWrite(REV_VCP, HIGH);
  digitalWrite(LED_REV, HIGH);
  Serial.println("<==========REVERSE");
  
  delay(1500); // Simulating Motor direction shifting; adjust as needed
  
  // Deactivate REV operation
  digitalWrite(REV_VCP, LOW);
  digitalWrite(LED_REV, LOW);
}

void STOP(int STOP_VCP) { // ur chosen word to activate STOP the motor
  // Activate the corresponding Motor directions
  digitalWrite(STOP_VCP, HIGH);
  digitalWrite(LED_STOP, HIGH);
  Serial.println("STOP STOP STOP");
  
  delay(1500); // Simulating Motor direction shifting; adjust as needed
  
  // Deactivate Motor operation
  digitalWrite(STOP_VCP, LOW);
  digitalWrite(LED_STOP, LOW);
} 
