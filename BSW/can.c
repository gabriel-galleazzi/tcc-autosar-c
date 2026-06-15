/**
 * @file can.c
 * @brief BSW - Simulação do barramento CAN.
 *
 * Este módulo faz parte da camada Basic Software (BSW),
 * sendo responsável por simular o comportamento do barramento CAN.
 *
 * Funções principais:
 *  - Exibir mensagens no formato CAN
 *  - Simular temporização relativa das mensagens
 *
 * Em sistemas reais, esta camada seria responsável pela interface
 * direta com o hardware (driver CAN).
 */

#include <stdio.h>
#include "can.h"
#include <time.h>

/**
 * @brief Realiza o log de uma mensagem CAN no terminal.
 *
 * Esta função simula o envio de mensagens no barramento CAN,
 * exibindo:
 *  - Tempo relativo desde a primeira mensagem
 *  - ID da mensagem
 *  - DLC (tamanho)
 *  - Conteúdo dos dados (DATA)
 *
 * @param msg Ponteiro para a mensagem CAN
 */
void CAN_Log(const CAN_Message *msg) {

    /**
     * Tempo inicial da execução.
     * static → é definido apenas na primeira execução
     */
    static clock_t start = 0;

    if (start == 0) {
        start = clock();
    }

    /**
     * Cálculo do tempo relativo (em segundos)
     * desde o início da execução
     */
    double tempo = (double)(clock() - start) / CLOCKS_PER_SEC;

    /**
     * Impressão no formato CAN (semelhante a ferramentas reais)
     */
    printf("[%.3f] | ID: 0x%03X | DLC: %d | DATA:",
           tempo, msg->id, msg->dlc);

    /**
     * Impressão de cada byte da mensagem
     * no formato hexadecimal
     */
    for (int i = 0; i < msg->dlc; i++) {
        printf(" %02X", msg->data[i]);
    }

    printf(" |\n");
}
