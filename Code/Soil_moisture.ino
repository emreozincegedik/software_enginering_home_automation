#define moisture_pin A13
#define water_pump 53
void setup() {
pinMode(moisture_pin, INPUT);
pinMode(water_pump, OUTPUT);
digitalWrite(water_pump, LOW);
Serial.begin(9600);
}
String level;
void loop() {
  int moisture=analogRead(moisture_pin); //moisture is 0-1023

  if (moisture<200){
    pinMode(water_pump, HIGH);
    level="LOW";    
    
    }
    else if(moisture<600){
    level="MED";
    }
   else{
    pinMode(water_pump,LOW);
    level="HIGH";
    }
    Serial.print("Water level: ");
    Serial.println(level);
    //Also OLED screen
}
