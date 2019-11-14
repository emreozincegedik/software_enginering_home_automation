#define lamp1_read A15
#define lamp2_read A14
void setup(){
  Serial.begin(9600);
  pinMode(lamp1_read, INPUT);
  pinMode(lamp2_read, INPUT);
}
void loop(){
  int lamp1_status = analogRead(lamp1_read); //0-1023
  int lamp2_status = analogRead(lamp2_read);
  if (lamp1_status>600)
  {
    Serial.println("Lamp1: On")
  }
  else
  {
    Serial.println("Lamp1: Off")
  }
  if (lamp2_status>600)
  {
    Serial.println("Lamp2: On")
  }
  else
  {
    Serial.println("Lamp2: Off")
  }
}