
//------------------------------------------------------
// This code has been written by Thomas Staal
// April 2022
//------------------------------------------------------


// Structure based on the project:
// SONO MIDI program Ver. 1
// By Evgenios Vlachos & Jonas Jørgensen

// Include the FreeRTOS library to be able to run code concurrently.
#include <Arduino_FreeRTOS.h>


//----------------- Definitions ------------------//
#define IDLE_PRIO 0
#define LOW_PRIO  1
#define MED_PRIO  2
#define HIGH_PRIO 3
#define THIRTY_SECONDS 30000 //30S
//--------------------------------------------//

//Initiate pumps and valves to pins
int pumpPin1 = 7; //pump 1 [PD7] pump 7
int valvePin1 = 4; //valve 1 [PD4]
int pumpPin2 = 2; //pump 2 [PD2]
int valvePin2 = 3; //valve 2 [PD3]
int pumpPin3 = 11; //pump 3 [PB3]
int valvePin3 = 8; //valve 3 [PB0]
// Added for pump4 and valve4
int pumpPin4 = 10; //pump 4 [PB2] = 10
int valvePin4 = 6; //valve 4 [PD6] = 6

int serialData = 0;
const unsigned int MAX_MESSAGE_LENGTH = 10;

void setup() {

  Serial.begin(115200);
  Serial.setTimeout(1000); //1000 ms = 1s
  
  pinMode(pumpPin1, OUTPUT);
  pinMode(valvePin1, OUTPUT);
  pinMode(pumpPin2, OUTPUT);
  pinMode(valvePin2, OUTPUT);
  pinMode(pumpPin3, OUTPUT);
  pinMode(valvePin3, OUTPUT);
  pinMode(pumpPin4, OUTPUT);
  pinMode(valvePin4, OUTPUT);
  deflateComplete();

  


}

void loop() {


//Below code works for serial communication between Python and Arduino
while(Serial.available() > 0){
  
  char pythonData = Serial.read();
      char str[2];
      str[0] = pythonData;
      str[1] = '\0';
      int i = 0;

     //If the strongest emotion passed from Python is neutral: 
     if(pythonData == 'n'){
    unsigned long previousMillis = millis();
          unsigned long now = millis();
          int i = 0;
          emotionTaskNeutral();
            while(millis() - now <= THIRTY_SECONDS)//Runs for 10 seconds
            {
              unsigned long currentMillis = millis();
              unsigned long interval = 3750; 
                if (currentMillis - previousMillis > interval) //Repeat every 3,75th second to be equal to 16 bpm
                    {
                        previousMillis = currentMillis;
                        emotionTaskNeutral();
                        i++;
                    }
                    
            }
            deflateComplete();  
     }
    
    else if(pythonData == 'h'){
      unsigned long previousMillis = millis();
          unsigned long now = millis();
          emotionTaskHappy();
          int i = 0;
            while(millis() - now <= THIRTY_SECONDS)//Runs for 10 seconds
            {
              unsigned long currentMillis = millis();
              unsigned long interval = 8571; 
                if (currentMillis - previousMillis > interval) //Repeat every 8,57th second to be equal to 7 bpm
                    {
                        previousMillis = currentMillis;
                        emotionTaskHappy();
                        i++;
                    }
                    
            }
            deflateComplete();  
    }
    else if(pythonData == 's'){
      unsigned long previousMillis = millis();
          unsigned long now = millis();
          int i = 0;
          emotionTaskSad();
            while(millis() - now <= THIRTY_SECONDS)//Runs for 10 seconds
            {
              unsigned long currentMillis = millis();
              unsigned long interval = 3750; 
                if (currentMillis - previousMillis > interval) //Repeat every 3,75th second to be equal to 16 bpm
                    {
                        previousMillis = currentMillis;
                        emotionTaskSad();
                        i++;
                    }
                    
            }
            deflateComplete();  
    }
    else if(pythonData == 'f'){
       
      unsigned long previousMillis = millis();
          unsigned long now = millis();
          //emotionTaskFear();
            while(millis() - now <= THIRTY_SECONDS)//Runs for 30 seconds
            {
             // unsigned long currentMillis = millis();
              //unsigned long interval = 6000; 
               // if (currentMillis - previousMillis > interval) //Repeat every 6th second to be equal to 10 bpm
                 //   {
                   //     previousMillis = currentMillis;
                    emotionTaskFear();
                 
                    }
                    
           // }
            deflateComplete();  
    }
    else if(pythonData == 'a'){
      emotionTaskAngry();
      deflateComplete();  
      
    }
  



} 
}
