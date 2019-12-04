#include <Wire.h>
#include "RTClib.h"
#include <Adafruit_SSD1306.h>


#define OLED_RESET 4

#define lamp1_pin1 27
#define lamp1_pin2 29
#define lamp1_input A15

#define lamp2_pin1 41
#define lamp2_pin2 43
#define lamp2_input A14

String lamba1="Off";
String lamba2="Off";

#define electric_input A0
int shortage_timer = 0;
int shortage_timer_minute=0;
int shortage_moment = 0;
int shortage_moment_minute=0;
int shortage_moment_hour=0;
int shortage_moment_day=0;
int shortage_moment_month=0;
bool is_electricity_on=true;

#define water_input A13
#define water_pin 53
String water="MED";

String phone_message=lamba1+" "+lamba2+" "+shortage_moment_month+"."+shortage_moment_day+" "+shortage_moment_hour+":"+shortage_moment_minute+" "+shortage_timer_minute+"m"+shortage_timer+"s";
Adafruit_SSD1306 display(OLED_RESET);


RTC_DS1307 RTC;




void setup () {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  Wire.begin();
  RTC.begin();

  if (! RTC.isrunning()) {
    //Serial.println("RTC is NOT running!");
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
pinMode(water_pin,OUTPUT);
digitalWrite(water_pin,LOW);

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

void loop () {
    DateTime now = RTC.now();
    
    if(analogRead(lamp1_input)>300) {
      lamba1="On";
      }
    else{
      lamba1="Off";
      }

    if(analogRead(lamp2_input)>300) {
      lamba2="On";
      }
    else{
      lamba2="Off";
      }

    int voltage=analogRead(electric_input);

    
    if(voltage>150){

      if(!is_electricity_on){
        shortage_timer=millis()/1000-shortage_moment;
        shortage_timer=shortage_timer%60;

      }
      is_electricity_on=true;
      }
    else if(voltage<50){
      if(is_electricity_on){
        shortage_moment=millis()/1000;  
        shortage_timer_minute=0;

        shortage_moment_minute=now.minute();
        shortage_moment_hour=now.hour();
        shortage_moment_day=now.day();
        shortage_moment_month=now.month();
        
      }

      shortage_timer=millis()/1000-shortage_moment;
      shortage_timer_minute=shortage_timer/60;
      shortage_timer=shortage_timer%60;
      is_electricity_on=false;
      //Serial.println(shortage_timer);
   }
   
   int water_level = analogRead(water_input);
   water=String(water_level);
   if(water_level<200){
    water="LOW";
    digitalWrite(water_pin,HIGH);
    }
    else if(water_level<400){
      water="MED";
      }
      else{
        water="HIGH";
        digitalWrite(water_pin,LOW);
        }
    
    delay(200);

    display.clearDisplay();
                            
    display.setTextSize(1);                            
    display.setTextColor(WHITE,BLACK);
    
    display.setCursor(0,0);
    display.print("Lamp1: ");
    display.print(lamba1);
    display.setCursor(68,0);
    display.print("Lamp2: ");
    display.print(lamba2);

    display.setCursor(0,8);
    display.print("Electrical shortage: ");
    display.setCursor(0,16);
    display.print(shortage_moment_day);
    display.print(".");
    display.print(shortage_moment_month);
    display.print(" ");
    display.print(shortage_moment_hour);
    display.print(":");
    display.print(shortage_moment_minute);
    display.print(" - ");
    //display.print("20.9 14:33 for ");
    display.print(shortage_timer_minute);
    display.print("m ");
    display.print(shortage_timer);
    display.print("s");
    display.setCursor(0,24);
    display.print("Water L: ");
    display.print(water);
    
    display.setCursor(95,24);                           
    display.print(now.hour(), DEC);
    display.print(':');
    display.print(now.minute(), DEC);
    display.display();
    phone_message=lamba1+"/"+lamba2+"/"+shortage_moment_month+"."+shortage_moment_day+" "+shortage_moment_hour+":"+shortage_moment_minute+" for "+shortage_timer_minute+"m"+shortage_timer+"s/"+water+"?";
    
    
    Serial.println(phone_message);
    int state=0;
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
