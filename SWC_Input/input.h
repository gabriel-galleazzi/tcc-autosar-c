/**
 * @file input.h
 * @brief Interface do SWC_Input.
 *
 * Este módulo define a interface do componente de entrada (SWC_Input),
 * responsável por simular a geração de dados do sistema, como sinais
 * provenientes do usuário ou sensores.
 *
 * O SWC_Input gera mensagens no formato CAN que são utilizadas pelos
 * demais componentes do sistema.
 */

#ifndef INPUT_H
#define INPUT_H

#include "../BSW/can.h"

/**
 * @brief Gera uma mensagem CAN com os dados de entrada.
 *
 * Esta função simula a leitura de sinais do sistema e retorna uma
 * mensagem CAN contendo:
 *  - contador de ciclos
 *  - estado do farol
 *
 * @return Mensagem CAN gerada
 */
CAN_Message SWC_Input_Read(void);

/**
 * @brief Define o estado do farol.
 *
 * Esta função atualiza o estado interno do farol no componente,
 * simulando a entrada do usuário (evento externo ao sistema).
 *
 * @param estado 0 = desligado, 1 = ligado
 */
void SWC_Input_SetFarol(uint8_t estado);

#endif