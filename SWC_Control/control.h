/**
 * @file control.h
 * @brief Interface do SWC_Control.
 *
 * Este módulo define a interface do componente de controle (SWC_Control),
 * responsável pelo processamento lógico das mensagens recebidas
 * e pela detecção de eventos no sistema.
 *
 * O SWC_Control atua como um elemento central de decisão na
 * camada de aplicação, analisando os dados e identificando
 * mudanças de estado relevantes.
 */

#ifndef CONTROL_H
#define CONTROL_H

#include "../BSW/can.h"

/**
 * @brief Processa uma mensagem CAN e aplica lógica de controle.
 *
 * Esta função:
 *  - Recebe uma mensagem gerada pelo SWC_Input
 *  - Analisa os sinais contidos na mensagem
 *  - Detecta mudanças de estado (eventos)
 *  - Pode gerar ações ou logs com base nessas mudanças
 *
 * @param msg Mensagem CAN recebida
 * @return Mensagem CAN processada
 */
CAN_Message SWC_Control_Process(CAN_Message msg);

#endif