
//----------------- Global Definitions------------------//
int LOWVOLTAGE = 0;
int HIGHVOLTAGE = 6; //5 VOLTAGE TO SEE THE ROBOT GROW GROW

void onPump1(){
  digitalWrite(valvePin1,LOW);
  digitalWrite(pumpPin1,HIGH);
}

void onPump2(){
  digitalWrite(valvePin2,LOW);
  digitalWrite(pumpPin2,HIGH);
}

void onPump3(){
  digitalWrite(valvePin3,LOW);
  digitalWrite(pumpPin3,HIGH);
}

void onPump4(){
  digitalWrite(valvePin4,LOW);
  digitalWrite(pumpPin4,HIGH);
}

void onValve1(){
  digitalWrite(valvePin1,HIGH);
  digitalWrite(pumpPin1,LOW);
}

void onValve2(){
  digitalWrite(valvePin2,HIGH);
  digitalWrite(pumpPin2,LOW);
}

void onValve3(){
  digitalWrite(valvePin3,HIGH);
  digitalWrite(pumpPin3,LOW);
}

void onValve4(){
  digitalWrite(valvePin4,HIGH);
  digitalWrite(pumpPin4,LOW);
}

void neutralState1(){
  digitalWrite(valvePin1,LOW);
  digitalWrite(pumpPin1,LOW);
}

void neutralState2(){
  digitalWrite(valvePin2,LOW);
  digitalWrite(pumpPin2,LOW);
}

void neutralState3(){
  digitalWrite(valvePin3,LOW);
  digitalWrite(pumpPin3,LOW);
}

void neutralState4(){
  digitalWrite(valvePin4,LOW);
  digitalWrite(pumpPin4,LOW);
}

void deflateComplete() { //Change every 1st sec

  onValve1();
  onValve2();
  onValve3();
  onValve4();
  //delay(1000);

}
