/**
 * @file output.c
 * @brief SWC_Output - Componente responsável pela saída de dados do sistema.
 *
 * Este módulo representa um Software Component (SWC) da camada de aplicação,
 * sendo responsável por:
 *  - Receber mensagens processadas pelo SWC_Control via RTE
 *  - Exibir as mensagens no terminal (simulação de saída)
 *
 * Em sistemas embarcados reais, este componente poderia:
 *  - Acionar atuadores
 *  - Atualizar displays
 *  - Enviar dados para outras ECUs
 */

#include <stdio.h>
#include "output.h"
#include "../BSW/can.h"

/**
 * @brief Realiza a saída da mensagem processada.
 *
 * Esta função:
 *  - Recebe a mensagem já processada pelo SWC_Control
 *  - Exibe o conteúdo no terminal (simulação de saída)
 *
 * @param msg Mensagem CAN processada
 */
void SWC_Output_Write(CAN_Message msg) {

    /**
     * Identificador de saída no log
     * Facilita a visualização do fluxo do sistema
     */
    printf("[OUTPUT] ");

    /**
     * Impressão da mensagem no formato CAN
     * Utiliza função do módulo BSW (camada de comunicação)
     */
    CAN_Log(&msg);
}