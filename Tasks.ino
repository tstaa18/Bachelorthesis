//-------------------DEFINES---------------------//
int max_inflate_time = 2750;
int max_deflate_time = 3500;

//-------------------HELPER FUNCTION---------------------//
float wait(int ms){
    return (ms / portTICK_PERIOD_MS);
}

int top_chamber_breathing_rate = 5;

   void topChamberBreathing(int param){
      onPump4();
      delay((int)(max_inflate_time * (param*0.1)));
      onValve4();
      delay((int)(max_inflate_time * (param*0.1)+ 500)); // 
    }

    
    void bottomChamperInflate(int param){
      onPump1();
      onPump2();
      onPump3();
      delay((int)(max_inflate_time * (param*0.1)));
      onValve1();
      onValve2();
      onValve3();
      delay((int)(max_inflate_time * (param*0.1) + 500));
      
    }

void emotionTaskNeutral(){
  /*Normal respiration rates for an adult person at rest range from 12 to 16 breaths per minute.
   * run onpump tasks and neutral tasks with a delay of a half second every 5th sec
  */
  
onPump1();

onPump2();

onPump3();

onPump4();

delay(500);

neutralState1();
neutralState2();
neutralState3();
neutralState4();
 
  

  }

void emotionTaskHappy(){
  /*(in addition to the descriptions from the paper you can incorporate a breathing rate in the range Troels and Ulrich found to match pleasure 7-12.5 BPM)
-  Respiratory frequency: Decrease for joy #how fast it breaths
- Respiratory amplitude: increase dramatically #How much air it breathes 
- Pauses: More pauses after expiration in joy 
- Respiration is more regular and present 
- Less thoracic tension
- Regular, moderately deep and slow breathing through the nose and with minimal thoracic tension, tremors and sighs
- Diaphragmatic and thoracic
Breath fullest lower chambers, and then fullest top chamber.
Below code has been provided by Ulrich and Troels from their study: ""
fill bottom chambers, then top chamber. Make it breath so it looks relaxing
  */

  
   // Start 3 bottom chamber pumps
    // RR is Breaths Per Minute: = 60/((max_inflate_time + max_inflate_time*0.5 + max_deflate_time + 500) / 1000)
    // RR =~ 7.3 bpm
    onPump1();
    onPump2();
    onPump3();
    // Let them inflate for max_inflate_time*0.4
    delay((int)max_inflate_time*0.4);
    // After max_inflate_time*0.4 ms turn on top chamber pump
    onPump4();
    // Wait for the 3 bottom chambers to be fully inflated
    delay((int)max_inflate_time*0.6);
    // Lock 3 bottom chambers at max inflated state for max_inflate_time*0.1 ms
    neutralState1();
    neutralState2();
    neutralState3();
    delay((int)max_inflate_time*0.1);
    // Let the 3 bottom chambers deflate
    onValve1();
    onValve2();
    onValve3();
    delay((int)max_inflate_time*0.1); // After this time, the top chamber is max inflated
    neutralState4(); // Wait at this state for max_inflate_time*0.1 ms
    delay((int)max_inflate_time*0.15);
    // Open top chamber valve
    onValve4();
    delay(max_deflate_time + 500); // Make sure all chambers are deflated before beginning again.


  }

  void emotionTaskSad(){
    /*-  Respiratory frequency: Did not change from baseline level
- Respiratory amplitude: remain at baseline level
- Sighing
- Tremors: 
- Some thoraric tension and irregularity
   Tilt it = greeting  - one bottom chamber, deflate the two others and breathe with top chamber
   More variation / randomisation of sighing
    */

  /*Generate a random number between 1 and 10: Make it seem like the robot is sighing but randomized*/
  int random_num = random(500, 3000);
   
    onPump1();
    onPump2();
    delay(max_inflate_time);

/*
    topChamberBreathing(random_num);
    delay(500);
    neutralState4();
    delay(500);
    topChamberBreathing(random_num);
    delay(500);
    neutralState4();
*/
    
    onPump4();
    delay(500);
    neutralState4();
    delay(500);
    onPump4();
    delay(500);
    neutralState4();
    
    delay(random_num);
    onPump4();
    delay(random_num);
    neutralState4();                 
    
              
    
    }

    void emotionTaskAngry(){
      /*
       * … (in addition to the descriptions from the paper here you can incorporate the breathing rate Troels and Ulrich found to match high arousal 40 BPM)
- Respiratory frequency: increase
- Respiratory amplitude: increase to a lesser extent
- More thoracic tension
- Tremors: moderately present
- Diaphragmatic
- Fast, irregular, and deep nose breathing with thoracic tension, minimal sighs and some tremors
- Expiration was diaphragmatic
- Pattern corresponds to the fast and deep breathing associated with excitement
Low chamber fully blown
      */

      unsigned long previousMillis = millis();
          unsigned long now = millis();
          int i = 0;
          onPump1();
          onPump2();
          onPump3();
          delay((int)max_inflate_time*0.9);
            while(millis() - now <= THIRTY_SECONDS)//Runs for 30 seconds
            {
              unsigned long currentMillis = millis();
              unsigned long interval = 1500; 
                if (currentMillis - previousMillis > interval) //Repeat every 1.5th second to be equal to 40 bpm
                    {
                        previousMillis = currentMillis;
                          onPump4();
                          //delay(max_inflate_time);
                          delay((int)max_inflate_time*0.2);
                          neutralState4();
            
                        i++;
                    }
                    
            }
           neutralState1();
           neutralState2();
           neutralState3();
           neutralState4();
      }




      void emotionTaskFear(){
      /*… (in addition to the descriptions from the paper here you can incorporate the breathing rate Troels and Ulrich found to match high arousal 40 BPM)
-  Respiratory frequency increase
- Respiratory amplitude: remain at baseline level
- Pauses: fewer pauses 
- More thoracic tension
- Tremors: moderately present
- Thoracic
- Fast, irregular, rather shallow breathing
- Much thoracic tension, some tremors and minimal sighs
Below code has been provided by Ulrich and Troels from their study: ""
the breathing rate Troels and Ulrich found to match high arousal 40 BPM)

      */
    
    onPump1();
    onPump2();
    onPump3();
   //topChamberBreathing(5);
    unsigned long time_now = millis();
    if(time_now <= 3000){ 
      //bottomChamperInflate(2);
      topChamberBreathing(5);//Fill the top chamber with a lot of air (delay: 3500*5*0.1) = 1750
    //  unsigned long now = millis(); //Setting a timer
   
    }
      
     if((time_now > 3000) && (time_now <= 10000)){
      //bottomChamperInflate(5);
      neutralState1();
      neutralState2();
      neutralState3();
        topChamberBreathing(3.5); //Fill the chamber with less as much air (delay: 3500*3.5*0.1) = 1225
        
     }
      if(time_now > 10000){ // && (time_now <= TEN_SECONDS)){ 
       // bottomChamperInflate(10);
            topChamberBreathing(1);  //Breath the chamber with 20% of air (delay: 3500*2*0.1) = 700
           
        }
       

      

  
     }

     

      
