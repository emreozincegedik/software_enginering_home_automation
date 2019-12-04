#define electric_input A0
int shortage_timer = 0;
int shortage_timer_minute=0;
int shortage_moment = 0;
int shortage_moment_minute=0;
int shortage_moment_hour=0;
int shortage_moment_day=0;
int shortage_moment_month=0;
bool is_electricity_on=true;
void setup(){

}

void loop(){
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
}