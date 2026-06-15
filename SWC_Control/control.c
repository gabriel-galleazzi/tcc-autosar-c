/**
 * @file control.c
 * @brief SWC_Control - Componente responsável pela lógica de controle.
 *
 * Este módulo simula um Software Component (SWC) da camada de aplicação,
 * sendo responsável pelo processamento das mensagens recebidas e pela 
 * detecção de eventos de mudança de estado.
 *
 * Funções principais:
 *  - Processar dados recebidos via mensagem CAN
 *  - Detectar mudanças no estado do farol
 *  - Gerar eventos (logs) com base nas transições
 */

#include <stdio.h>
#include "control.h"

/**
 * @brief Processa uma mensagem CAN e aplica lógica de controle.
 *
 * Esta função:
 *  - Recebe a mensagem gerada pelo SWC_Input via RTE
 *  - Detecta mudança de estado do farol
 *  - Gera eventos apenas em transições (evitando redundância)
 *
 * @param msg Mensagem CAN recebida
 * @return Mensagem CAN (não modificada neste caso)
 */
CAN_Message SWC_Control_Process(CAN_Message msg) {

    /**
     * Estado anterior do farol.
     * Usado para detectar mudanças de estado.
     * static → mantém valor entre execuções (memória do componente)
     */
    static uint8_t farol_ant = 0;

    /**
     * Obtém estado atual do farol a partir da mensagem CAN.
     * Byte 1 → sinal de farol
     */
    uint8_t farol_atual = msg.data[1];

    /**
     * Verifica se houve mudança de estado (borda)
     * Isso evita geração de eventos redundantes.
     */
    if (farol_atual != farol_ant) {

        /**
         * Geração de evento com base no novo estado
         */
        if (farol_atual)
            printf("[EVENTO] Farol LIGADO\n");
        else
            printf("[EVENTO] Farol DESLIGADO\n");

        /**
         * Atualiza estado anterior após processamento
         */
        farol_ant = farol_atual;
    }

    /**
     * Retorna mensagem sem modificação
     * (Neste caso o SWC apenas monitora, não altera dados)
     */
    return msg;
}
