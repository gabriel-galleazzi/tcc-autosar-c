/**
 * @file output.h
 * @brief Interface do SWC_Output.
 *
 * Este módulo define a interface do componente de saída (SWC_Output),
 * responsável por receber e apresentar os dados processados pelo sistema.
 *
 * O SWC_Output simula o comportamento de atuadores ou interfaces de saída,
 * exibindo as mensagens CAN no terminal para fins de monitoramento e validação.
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include "../BSW/can.h"

/**
 * @brief Realiza a saída de uma mensagem CAN.
 *
 * Esta função:
 *  - Recebe a mensagem processada pelo SWC_Control
 *  - Simula a saída do sistema (ex: display, atuador)
 *  - Exibe os dados no formato CAN
 *
 * @param msg Mensagem CAN a ser exibida
 */
void SWC_Output_Write(CAN_Message msg);

#endif