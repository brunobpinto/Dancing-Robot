#ifndef FUNCOES_H
#define FUNCOES_H
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>
#include "Movimentos.h"

//  PWM                           ÂNGULOS
//  11      Cabeca                Padrão:    0°   (Esquerda),     90°   (Meio),         180°  (Direita)
//  1       Torso                 Padrão:    0°   (Esquerda),     90°   (Meio),         180°  (Direita)
//  2       Quadril Esquerdo      Esquerda:  30°  (Para trás),    45°   (Reto),         65°   (Para frente)
//  3       Joelho Esquerdo       Esquerda:  165° (Vertical) até  75°   (Dobrado)
//  4       Ombro Esquerdo        Esquerda:  0°   (Para baixo),   75°   (Para frente),  160°  (Para cima)
//  5       Braco Esquerdo        Esquerda:  75°  (Reto),         140°  (Dobrado)
//  6       Antebraco Esquerdo    Esquerda:  5°   (Reto),         95°   (Dobrado)
//  7       Quadril Direito       Direita:   60°  (Para trás),    50°   (Reto),         25°   (Para frente)
//  8       Joelho Direito        Direita:   70°  (Vertical) até  150°  (Dobrado)
//  9       Ombro Direito         Direita:   165° (Para baixo),   100°  (Para frente),  10°    (Para cima)
//  10      Braco Direito         Direita:   140° (Reto),         75°   (Dobrado)
//  0       Antebraco Direito     Direita:   80°  (Reto),         0°    (Dobrado)

// Declaração das Variáveis
extern Adafruit_PWMServoDriver pwm;

// Declaração das Funções
void moverServo(int numServo, int anguloDesejado, bool suave = true);

void testarServo(int indice, int angulo);

void resetarRobo();

void inicializarDancas(Danca *dancas);

void exibirDancas(Danca *dancas, int totalDancas);

void moverPadrao();

void realizarDanca(Danca *dancas, String nomeDanca, bool bracos);

#endif