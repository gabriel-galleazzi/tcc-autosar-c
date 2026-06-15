/**
 * @file can.h
 * @brief Interface da camada BSW - Simulação do barramento CAN.
 *
 * Este módulo define a estrutura e as funções utilizadas para
 * representar a comunicação CAN no sistema.
 *
 * A camada BSW (Basic Software) abstrai a comunicação entre os
 * componentes da aplicação (SWCs), simulando o envio e recebimento
 * de mensagens no barramento CAN.
 */

#ifndef CAN_H
#define CAN_H

#include <stdint.h>

/**
 * @brief Tamanho máximo de dados de uma mensagem CAN.
 *
 * No padrão CAN clássico, o payload máximo é de 8 bytes.
 */
#define CAN_MAX_DATA 8

/**
 * @brief Estrutura de uma mensagem CAN.
 *
 * Representa um frame CAN contendo:
 *  - Identificador (ID)
 *  - DLC (Data Length Code)
 *  - Dados (payload)
 */
typedef struct {
    uint32_t id;                 // Identificador da mensagem CAN
    uint8_t dlc;                 // Tamanho do payload (0 a 8 bytes)
    uint8_t data[CAN_MAX_DATA];  // Dados da mensagem
} CAN_Message;

/**
 * @brief Realiza o log de uma mensagem CAN.
 *
 * Exibe a mensagem no terminal em formato similar a ferramentas
 * profissionais de análise CAN, incluindo:
 *  - tempo de transmissão
 *  - ID
 *  - DLC
 *  - dados em hexadecimal
 *
 * @param msg Ponteiro para a mensagem CAN
 */
void CAN_Log(const CAN_Message *msg);

#endif
