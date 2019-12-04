#define lamp1_pin1 27
#define lamp1_pin2 29
#define lamp1_input A15

#define lamp2_pin1 41
#define lamp2_pin2 43
#define lamp2_input A14

String lamba1="Off";
String lamba2="Off";

void setup(){
  pinMode(lamp1_pin1, OUTPUT);
  pinMode(lamp1_pin2, OUTPUT);
  pinMode(lamp2_pin1, OUTPUT);
  pinMode(lamp2_pin2, OUTPUT);
  digitalWrite(lamp1_pin1,HIGH);
  digitalWrite(lamp2_pin1,HIGH);
  digitalWrite(lamp1_pin2,LOW);
  digitalWrite(lamp2_pin2,LOW);

  if(analogRead(lamp1_input)<300){ }
  else
  {
    if(digitalRead(lamp1_pin1)){
      digitalWrite(lamp1_pin1,LOW);
      digitalWrite(lamp1_pin2,HIGH);
      }
      else{
        digitalWrite(lamp1_pin1,HIGH);
        digitalWrite(lamp1_pin2,LOW);
      }              
  }


  if(analogRead(lamp2_input)<300){ }
  else
  {
    if(digitalRead(lamp2_pin1)){
      digitalWrite(lamp2_pin1,LOW);
      digitalWrite(lamp2_pin2,HIGH);
      }
      else{
        digitalWrite(lamp2_pin1,HIGH);
        digitalWrite(lamp2_pin2,LOW);
      }              
  }
}
void loop(){
  if(Serial.available()>0){
        state=Serial.read();
      }
      if(state==49)
      {
        if(analogRead(lamp1_input)>300){ }
        else
        {
          if(digitalRead(lamp1_pin1)){
            digitalWrite(lamp1_pin1,LOW);
            digitalWrite(lamp1_pin2,HIGH);
            }
            else{
              digitalWrite(lamp1_pin1,HIGH);
              digitalWrite(lamp1_pin2,LOW);
            }              
        }
       }
       if(state==50)
      {
        if(analogRead(lamp1_input)<300){ }
        else
        {
          if(digitalRead(lamp1_pin1)){
            digitalWrite(lamp1_pin1,LOW);
            digitalWrite(lamp1_pin2,HIGH);
            }
            else{
              digitalWrite(lamp1_pin1,HIGH);
              digitalWrite(lamp1_pin2,LOW);
            }              
        }
       }

      if(state==51)
      {
        if(analogRead(lamp2_input)>300){ }
        else
        {
          if(digitalRead(lamp2_pin1)){
            digitalWrite(lamp2_pin1,LOW);
            digitalWrite(lamp2_pin2,HIGH);
            }
            else{
              digitalWrite(lamp2_pin1,HIGH);
              digitalWrite(lamp2_pin2,LOW);
            }              
        }
      }
      if(state==52)
      {
        if(analogRead(lamp2_input)<300){ }
        else
        {
          if(digitalRead(lamp2_pin1)){
            digitalWrite(lamp2_pin1,LOW);
            digitalWrite(lamp2_pin2,HIGH);
            }
            else{
              digitalWrite(lamp2_pin1,HIGH);
              digitalWrite(lamp2_pin2,LOW);
            }              
        }
      }
}