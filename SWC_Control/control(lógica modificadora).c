
/**
 * @file control.c
 * @brief SWC_Control - Versão com alteração de dados (transformação de mensagem).
 *
 * Este módulo representa um Software Component (SWC) responsável
 * pelo processamento lógico dos dados recebidos e pela modificação
 * do conteúdo da mensagem CAN.
 *
 * Nesta versão, o componente atua como um transformador de dados,
 * alterando o valor do sinal de saída com base na lógica de controle.
 */

#include <stdio.h>
#include "control.h"

// Índices dos sinais dentro da mensagem CAN
#define SIGNAL_COUNTER 0   // Byte 0 → contador
#define SIGNAL_FAROL   1   // Byte 1 → estado do farol

/**
 * @brief Processa a mensagem CAN e altera os dados com base na lógica de controle.
 *
 * Esta função:
 *  - Recebe a mensagem do SWC_Input via RTE
 *  - Interpreta o estado do farol
 *  - Modifica o valor do sinal na mensagem
 *  - Retorna a mensagem alterada
 *
 * @param msg Mensagem CAN recebida
 * @return Mensagem CAN modificada
 */
CAN_Message SWC_Control_Process(CAN_Message msg) {

    /**
     * Obtém o estado atual do farol da mensagem
     */
    uint8_t farol = msg.data[SIGNAL_FAROL];

    /**
     * Nova lógica de controle:
     * Em vez de apenas observar o dado, o módulo altera o valor
     * com base no estado do sistema.
     *
     * Isso demonstra capacidade de modificar o comportamento
     * sem alterar a estrutura do sistema.
     */
    if (farol == 1) {

        /**
         * Caso farol esteja ligado:
         * altera o valor para um estado diferente (ex: 2)
         */
        msg.data[SIGNAL_FAROL] = 2;

        printf("[CONTROL] MODO ATIVO - DADO MODIFICADO\n");

    } else {

        /**
         * Caso farol esteja desligado:
         * altera o valor para outro estado (ex: 3)
         */
        msg.data[SIGNAL_FAROL] = 3;

        printf("[CONTROL] MODO PASSIVO - DADO MODIFICADO\n");
    }

    /**
     * Retorna a mensagem com os dados modificados
     */
    return msg;
}
