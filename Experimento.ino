#define PIN_RED 12
#define PIN_GREEN 11
#define BUTTON 2

void setup(){
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  if(digitalRead(BUTTON) == LOW){
  	digitalWrite(PIN_GREEN, HIGH);
  	digitalWrite(PIN_RED, LOW);
    
  }else{
  	digitalWrite(PIN_GREEN, LOW);
  	digitalWrite(PIN_RED, HIGH);
    
  }
}