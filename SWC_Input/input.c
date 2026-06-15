/**
 * @file input.c
 * @brief SWC_Input - Componente responsável pela geração de dados de entrada.
 *
 * Este módulo simula o comportamento de um componente de entrada (sensor),
 * sendo responsável por:
 *  - Gerar mensagens CAN com os dados do sistema
 *  - Controlar o estado do farol (entrada do usuário)
 *  - Incrementar um contador para simulação de tempo/ciclos
 *
 * Este componente representa um SWC da camada de aplicação.
 */

#include "input.h"

// Índices dos sinais dentro da mensagem CAN
#define SIGNAL_COUNTER 0   // Byte 0 → contador de ciclos
#define SIGNAL_FAROL   1   // Byte 1 → estado do farol

// Estado atual do farol (0 = desligado, 1 = ligado)
static uint8_t farol_estado = 0;

// Contador de ciclos (simula passagem do tempo)
static uint8_t counter = 0;

/**
 * @brief Define o estado do farol.
 *
 * Esta função é chamada pelo módulo principal (main.c) quando o usuário
 * interage com o sistema (pressionando 'f' ou 'd').
 *
 * @param estado 0 = farol desligado, 1 = farol ligado
 */
void SWC_Input_SetFarol(uint8_t estado) {
    farol_estado = estado;
}

/**
 * @brief Gera uma nova mensagem CAN com os dados de entrada.
 *
 * Esta função simula a leitura de sensores, criando uma mensagem CAN
 * contendo:
 *  - contador de ciclos (posição 0)
 *  - estado do farol (posição 1)
 *
 * @return Mensagem CAN preenchida
 */
CAN_Message SWC_Input_Read(void) {

    // Inicializa a estrutura da mensagem com valor zero
    CAN_Message msg = {0};

    // Define o identificador da mensagem (ID CAN)
    msg.id = 0x100;

    // Define o tamanho dos dados (DLC - Data Length Code)
    msg.dlc = 2;

    /**
     * Byte 0 → contador incremental
     * Simula o tempo de execução ou número de ciclos do sistema
     */
    msg.data[SIGNAL_COUNTER] = counter++;

    /**
     * Byte 1 → estado do farol
     * Representa o valor recebido do usuário (entrada)
     */
    msg.data[SIGNAL_FAROL] = farol_estado;

    return msg;
}