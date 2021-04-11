const int LM1 = 4;     // the number of the pushbutton pin
const int LM2 =  5;      // the number of the LED pin
const int RM1 =  3;
const int RM2 =  2;
char valu;
void setup() {
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
//  runforward();
    while (Serial.available() > 0)
  {
  valu = Serial.read();
  Serial.println(valu);
  delay(500);
  }
   if( valu == "F") // Forward
    {
     runforward();
    }
  else if(valu == "B") // Backward
    {

runbackward();
    }
  
    else if(valu == "L") //Left
    {
  turnleft();
    }
    else if(valu == "R") //Right
    {
turnright();
    }
    
  else if(valu == "S") //Stop
    {
stoprunning();
    }else{
      Serial.print('MisCommand');
      }
//  runforward();
//  delay(1000);
//  stoprunning();
//  delay(500);
//  turnright();
//  delay(500);
//  stoprunning();
//  delay(500);
//  runforward();
//  delay(800);
//  stoprunning();
//  delay(15000); 
  }
  void turnright(){
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,HIGH);
  }
void turnleft(){
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,HIGH);
}
void runforward(){
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
}
void runbackward(){
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,HIGH);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,HIGH);
}
void stoprunning(){
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);
}
