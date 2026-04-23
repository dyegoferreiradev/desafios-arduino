#define PIN_RED 5
#define PIN_GREEN 3
#define ANALOG A0

unsigned long value = 0;

void setup(){
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(ANALOG, INPUT);
}

void loop()
{
  	value = analogRead(ANALOG);
  	if(value < 512){
    		value = map(value, 0, 511, 0, 255);
      		analogWrite(PIN_GREEN, value);
      		analogWrite(PIN_RED, 0);
  	}

  	else{
    		value = map(value, 512, 1023, 0, 255);
      		analogWrite(PIN_RED, value);
      		analogWrite(PIN_GREEN, 0);
  	}
}