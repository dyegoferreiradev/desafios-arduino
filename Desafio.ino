// Define os pinos utilizados para os LEDs do semáforo e o botão de pedestre
#define PIN_RED 13
#define PIN_GREEN 12
#define PIN_YELLOW 11
#define BUTTON 2

// Tempo total do ciclo do semáforo em milissegundos (14 segundos)
unsigned long SEMAPHORE_TIME = 14000;

void setup(){
  // Configura os pinos como saídas (para os LEDs) ou entradas (para o botão)
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop(){
  // Lê o estado do botão (pressionado ou não)
  int BUTTON_SITUATION = digitalRead(BUTTON);

  // Liga o LED vermelho
  digitalWrite(PIN_RED, HIGH);
  // Aguarda 10 segundos
  delay(10000);
  // Desliga o LED vermelho
  digitalWrite(PIN_RED, LOW);
  // Liga o LED verde
  digitalWrite(PIN_GREEN, HIGH);
  
  // Obtém o tempo atual em milissegundos
  unsigned long REAL_TIME = millis();
  
  // Enquanto o tempo decorrido for menor que o tempo total do semáforo
  // e o botão não estiver pressionado, continua verificando o estado do botão
  while((millis() - REAL_TIME < SEMAPHORE_TIME) && (BUTTON_SITUATION != HIGH)){
    BUTTON_SITUATION = digitalRead(BUTTON);
    delay(50);
  }
  
  // Se o botão for pressionado durante o ciclo do semáforo
  if(BUTTON_SITUATION == HIGH){
    // Calcula o tempo restante do ciclo do semáforo para ajustar o tempo de espera
    unsigned long REMAINING_TIME = (SEMAPHORE_TIME - (millis() - REAL_TIME)) / 2;
    // Aguarda o tempo restante
    delay(REMAINING_TIME);
  }
  
  // Desliga o LED verde
  digitalWrite(PIN_GREEN, LOW);
  // Liga o LED amarelo
  digitalWrite(PIN_YELLOW, HIGH);
  // Aguarda 4 segundos
  delay(4000);
  // Desliga o LED amarelo
  digitalWrite(PIN_YELLOW, LOW);
}