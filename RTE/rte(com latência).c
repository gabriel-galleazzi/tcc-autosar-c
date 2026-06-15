/**
 * @file rte.c
 * @brief Runtime Environment (RTE) - Versão com medição de latência.
 *
 * Esta versão do RTE adiciona a medição do tempo de execução
 * de cada ciclo do sistema, permitindo avaliar o desempenho
 * da arquitetura proposta.
 *
 * Funções principais:
 *  - Orquestrar a comunicação entre os SWCs
 *  - Simular envio de mensagens CAN
 *  - Medir o tempo de execução (latência do ciclo)
 *
 * Fluxo:
 *  SWC_Input → RTE → SWC_Control → SWC_Output
 */

#include "rte.h"
#include <stdio.h>
#include <time.h>

#include "../SWC_Input/input.h"
#include "../SWC_Control/control.h"
#include "../SWC_Output/output.h"
#include "../BSW/can.h"

/**
 * @brief Executa um ciclo completo do sistema com medição de latência.
 *
 * Esta função realiza:
 * 1. Início da medição de tempo
 * 2. Leitura dos dados de entrada
 * 3. Log da mensagem CAN
 * 4. Processamento da mensagem
 * 5. Saída dos dados
 * 6. Cálculo da latência total do ciclo
 */
void RTE_Run(void) {

    CAN_Message msg;

    /**
     * 1. Início da medição de tempo
     * clock() retorna o tempo de CPU utilizado
     */
    clock_t start = clock();

    /**
     * 2. Leitura do SWC_Input
     * Simula aquisição de dados do sistema
     */
    msg = SWC_Input_Read();

    /**
     * 3. Simulação de envio via barramento CAN
     */
    printf("[RTE] TX ");
    CAN_Log(&msg);

    /**
     * 4. Processamento no SWC_Control
     */
    msg = SWC_Control_Process(msg);

    /**
     * 5. Saída via SWC_Output
     */
    SWC_Output_Write(msg);

    /**
     * 6. Fim da medição de tempo
     */
    clock_t end = clock();

    /**
     * Conversão para milissegundos
     */
    double tempo_ms = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    /**
     * Exibição da latência do ciclo
     */
    printf("[LATENCIA] Tempo ciclo: %.3f ms\n", tempo_ms);
}