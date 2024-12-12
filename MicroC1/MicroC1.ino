#include <Adafruit_PWMServoDriver.h>
#include <stdio.h>
#include "Funcoes.h"
#include "Movimentos.h"

#define NUM_DANCAS 3

// Instancia o driver com o endereço padrão (0x40)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Cria uuma Lista de Structs do tipo Danca
Danca dancas[NUM_DANCAS];   // Inicializando um array de n danças

void setup() {
  // Inicializa a Comunicação Serial
  Serial.begin(9600);
  Serial.println("=======>>> Mr.Adam foi inicializado <<<=======\n");

  // Inicializa o Shield de Servos(PWM)
  pwm.begin();
  pwm.setPWMFreq(50); // Frequência de 50 Hz para servos

  // Inicializa os Structs com os dados dos movimentos
  inicializarDancas(dancas);  // Funcao para preencher o array dancas

  // Exibir todas as danças na Serial
  exibirDancas(dancas, NUM_DANCAS); 

  // Ângulos Iniciais do Robô
  resetarRobo();
}

void loop() {
  // Verificação de Comandos na Serial
  if (Serial.available() > 0) {   
    String texto = Serial.readStringUntil('\n');    
    texto.trim();
    
    Serial.println(texto);

    if (texto == "Resetar") {         
      resetarRobo(); // Resetar robô para Ângulos Iniciais
    }

    if (texto == "Batida") {  
      moverPadrao(); // Função para mexer a cabeca sempre no ritmo da Batida
    }

    if (texto.startsWith("Teste")) {             // Exemplo: Teste 1 180 -> Faz o servoCabeça ir para o ângulo 180°  
      String indiceStr = texto.substring(6, 8);  // Pega o índice do Servo Motor desejado
      String anguloStr = texto.substring(8);     // Define o ângulo desejado
      int indice = indiceStr.toInt();
      int angulo = anguloStr.toInt();
      testarServo(indice, angulo);  
    }

    if (texto.startsWith("Movimento")) {            // Exemplo: Movimento leg01 arm01
      String dancaLeg = texto.substring(10, 15);
      String dancaArm = texto.substring(16, 21);  
      realizarDanca(dancas, dancaArm, true);        // Movimento do Braco
      realizarDanca(dancas, dancaLeg, false);       // Movimento da Perna
    }
    
  }

}
