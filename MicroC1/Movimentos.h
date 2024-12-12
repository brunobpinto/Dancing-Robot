#ifndef MOVIMENTOS_H
#define MOVIMENTOS_H
#include <Arduino.h>
#include <stdio.h>
#include <string.h>

// Definição de máximos
#define MAX_ANGULOS 5
#define MAX_NOME 7
#define MAX_SERVOS 6

// Enumerar os nomes dos servos para valores indices
enum Servo {
    ANTEBRACO_DIREITO,   // 0
    TORSO,               // 1
    QUADRIL_ESQUERDO,    // 2
    JOELHO_ESQUERDO,     // 3
    OMBRO_ESQUERDO,      // 4
    BRACO_ESQUERDO,      // 5
    ANTEBRACO_ESQUERDO,  // 6
    QUADRIL_DIREITO,     // 7
    JOELHO_DIREITO,      // 8
    OMBRO_DIREITO,       // 9
    BRACO_DIREITO,       // 10
    CABECA               // 11
};

// Estrutura para armazenar os movimentos de cada servo
typedef struct {
    enum Servo servo;                      // Indice correspondente ao Servo
    unsigned char angulos[MAX_ANGULOS];    // Lista de ângulos para o servo
} ServoMovimento;

// Estrutura para armazenar os dados de cada dança
typedef struct {
    char nome[MAX_NOME];                    // Nome da dança
    ServoMovimento movimentos[MAX_SERVOS];  // Movimentos de cada servo
    unsigned char quantidadeServos;         // Quantidade de servos na dança
    unsigned char quantidadeAngulos;        // Quantidade total de ângulos

} Danca;

#endif