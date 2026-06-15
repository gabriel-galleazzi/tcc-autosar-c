/**
 * @file rte.c
 * @brief Runtime Environment (RTE) - Orquestrador da comunicação entre SWCs.
 *
 * Esta versão do RTE representa o fluxo normal do sistema,
 * sem simulação de falhas na comunicação.
 *
 * O RTE é responsável por:
 *  - Coordenar a comunicação entre os componentes (SWCs)
 *  - Simular o envio de mensagens no barramento CAN
 *  - Garantir o desacoplamento entre os módulos
 *
 * Fluxo:
 *  SWC_Input → RTE → SWC_Control → SWC_Output
 */

#include "rte.h"
#include <stdio.h>

#include "../SWC_Input/input.h"
#include "../SWC_Control/control.h"
#include "../SWC_Output/output.h"
#include "../BSW/can.h"

/**
 * @brief Executa um ciclo completo do sistema.
 *
 * Esta função realiza:
 * 1. Leitura dos dados de entrada (SWC_Input)
 * 2. Registro da mensagem no barramento CAN (simulação)
 * 3. Processamento da mensagem (SWC_Control)
 * 4. Saída dos dados processados (SWC_Output)
 *
 * Esta função é chamada ciclicamente pelo módulo principal,
 * simulando o comportamento periódico de uma ECU.
 */
void RTE_Run(void) {

    CAN_Message msg;

    /**
     * 1. Leitura do SWC_Input
     * Simula a aquisição de dados do sistema (entrada)
     */
    msg = SWC_Input_Read();

    /**
     * 2. Simulação de envio da mensagem no barramento CAN
     * Apenas exibe/loga a mensagem (não há transmissão real)
     */
    printf("[RTE] TX ");
    CAN_Log(&msg);

    /**
     * 3. Processamento da mensagem pelo SWC_Control
     * Aplica lógica de controle e detecção de eventos
     */
    msg = SWC_Control_Process(msg);

    /**
     * 4. Saída do sistema via SWC_Output
     * Exibe ou atua sobre os dados (simulação)
     */
    SWC_Output_Write(msg);
}