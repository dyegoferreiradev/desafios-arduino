#define PIN_RED 11
#define PIN_GREEN 10

void setup(){
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
}

void loop()
{
  	int x = 0;
	int serial = Serial.available(); 
  	if(serial > 0){
		x = Serial.read(); 
    	}
    
   	if(x == '0'){
      		digitalWrite(PIN_RED, HIGH);
    		digitalWrite(PIN_GREEN, LOW);
    	}
    
    	if(x == '1'){
      		digitalWrite(PIN_RED, LOW);
    		digitalWrite(PIN_GREEN, HIGH);
    	} 
  
 	if(x == '2'){
      
  	for(int brightness = 0; brightness <= 255; brightness++){
  		analogWrite(PIN_RED, brightness);
      		delay(10);
  	}
  
    	for(int brightness = 255; brightness >= 0; brightness--){
  		analogWrite(PIN_RED, brightness);
      		delay(10);
  	}
  
  	for(int brightness = 0; brightness <= 255; brightness++){
  		analogWrite(PIN_GREEN, brightness);
     		delay(10);
  	}

  	for(int brightness = 255; brightness >= 0; brightness--){
  		analogWrite(PIN_GREEN, brightness);
      		delay(10);
  	}
  
    }
  
}