# ⚡ Projetos e Desafios de Eletrônica com Arduino

## 📖 Sobre o Repositório
Este repositório contém uma coleção de implementações práticas e experimentos desenvolvidos na plataforma Arduino (com simulações feitas no Tinkercad). O objetivo destes projetos é explorar conceitos essenciais de sistemas embarcados, desde o acionamento básico de portas digitais até o uso de PWM, conversores analógico-digitais, comunicação serial e controle de tempo dinâmico.

---

## 🛠️ Projetos e Implementações

### 1. Experimento Básico: Controle com Botão (Digital I/O)
Um circuito introdutório para testar leituras digitais de estado (HIGH/LOW) usando um botão (push-button).
* **Funcionamento:** O sistema monitora constantemente o estado do botão no pino 2. Em seu estado de repouso (não pressionado), o LED Verde permanece aceso e o Vermelho apagado. Quando o botão é pressionado, a lógica se inverte: o LED Verde apaga e o LED Vermelho acende.
* **Conceitos aplicados:** `pinMode`, `digitalRead`, `digitalWrite`, lógica condicional básica (`if/else`).

### 2. Experimento 2: Comunicação Serial e Efeito Fade (PWM)
Este projeto avança para a comunicação entre o computador e o Arduino através do Monitor Serial, além de introduzir sinais PWM.
* **Funcionamento:** O programa aguarda um comando enviado pelo usuário no terminal serial:
  * Enviar **`0`**: Acende o LED Vermelho e apaga o Verde.
  * Enviar **`1`**: Acende o LED Verde e apaga o Vermelho.
  * Enviar **`2`**: Aciona uma rotina especial de *fading* (respiração). O LED Vermelho aumenta e diminui seu brilho gradualmente, seguido pelo LED Verde fazendo o mesmo efeito de forma sequencial.
* **Conceitos aplicados:** `Serial.begin()`, `Serial.read()`, laços de repetição (`for`), `analogWrite()` para modulação de largura de pulso (PWM).

### 3. Desafio 1: Semáforo Interativo com Botão de Pedestre
Uma simulação de um cruzamento de trânsito onde um pedestre pode solicitar a parada dos carros.
* **Funcionamento:** O semáforo segue um ciclo normal: vermelho por 10 segundos, verde por um tempo máximo de 14 segundos e amarelo por 4 segundos. Durante o sinal verde, o sistema usa a função `millis()` para contar o tempo de forma não-bloqueante e escuta o botão de pedestre. 
* **A Interação:** Se o botão for pressionado durante o sinal verde, o sistema calcula o tempo restante do ciclo e o divide pela metade (`REMAINING_TIME / 2`). Isso faz com que o semáforo feche mais rápido para os carros, garantindo a travessia segura do pedestre sem interromper o fluxo bruscamente.
* **Conceitos aplicados:** Lógica de temporização avançada com `millis()`, interrupção de ciclos baseados em variáveis de estado.

### 4. Desafio 2: Divisor de Controle com Potenciômetro
Uso de um sinal analógico (0 a 1023) lido de um potenciômetro para controlar, de forma proporcional, o brilho de dois LEDs.
* **Funcionamento:** O código lê a posição do potenciômetro e divide o comportamento na metade:
  * **Abaixo de 512:** O LED Verde é acionado. Quanto mais o potenciômetro gira (de 0 a 511), mais forte o LED Verde brilha (convertido para PWM de 0 a 255 através da função `map`).
  * **Acima de 512:** O LED Verde apaga. O sistema converte a faixa superior (512 a
