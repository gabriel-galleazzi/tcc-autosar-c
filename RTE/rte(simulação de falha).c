/**
 * @file rte.c
 * @brief Runtime Environment (RTE) - Orquestrador da comunicação entre SWCs.
 *
 * Este módulo simula o comportamento do RTE do AUTOSAR,
 * sendo responsável por:
 *  - Intermediar a comunicação entre os componentes (SWCs)
 *  - Controlar o fluxo de execução do sistema
 *  - Simular o envio de mensagens CAN
 *  - Simular falhas de comunicação
 *
 * Fluxo de execução:
 *  SWC_Input -> RTE -> SWC_Control -> SWC_Output
 */

#include "rte.h"
#include <stdio.h>
#include <stdlib.h>   // Funções de geração de números aleatórios (rand, srand)
#include <time.h>     // Obtenção de tempo (seed do random)

#include "../SWC_Input/input.h"
#include "../SWC_Control/control.h"
#include "../SWC_Output/output.h"
#include "../BSW/can.h"

/**
 * @brief Executa um ciclo completo do sistema.
 *
 * Esta função representa um ciclo do RTE, sendo responsável por:
 * 1. Obter dados do SWC_Input
 * 2. Simular possíveis falhas na comunicação
 * 3. Registrar a transmissão (simulação CAN)
 * 4. Encaminhar a mensagem ao SWC_Control
 * 5. Enviar o resultado ao SWC_Output
 */
void RTE_Run(void) {

    /**
     * Controle de inicialização do gerador de números aleatórios.
     * É executado apenas uma vez (primeiro ciclo).
     */
    static int initialized = 0;

    if (!initialized) {
        srand(time(NULL));  // Define seed usando o tempo atual
        initialized = 1;
    }

    CAN_Message msg;

    /**
     * 1. Leitura de dados do componente de entrada (SWC_Input)
     * Simula aquisição de dados (ex: sensores)
     */
    msg = SWC_Input_Read();

    /**
     * 2. Simulação de falha na comunicação (CAN)
     * Aproximadamente 20% das mensagens são descartadas
     * para simular perda de frames no barramento.
     */
    if (rand() % 5 == 0) {
        printf("[RTE] ERRO: mensagem descartada\n");

        /**
         * A mensagem não é propagada para os próximos módulos,
         * simulando perda de comunicação.
         */
        return;
    }

    /**
     * 3. Simulação de envio no barramento CAN
     * Aqui apenas registramos/logamos a mensagem
     */
    printf("[RTE] TX ");
    CAN_Log(&msg);

    /**
     * 4. Processamento no SWC_Control
     * O módulo de controle aplica lógica sobre os dados
     */
    msg = SWC_Control_Process(msg);

    /**
     * 5. Saída do sistema (SWC_Output)
     * Responsável por exibir ou atuar sobre os dados
     */
    SWC_Output_Write(msg);
}