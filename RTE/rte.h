/**
 * @file rte.h
 * @brief Interface do Runtime Environment (RTE).
 *
 * Este módulo define a interface do RTE, responsável por
 * orquestrar a comunicação entre os componentes (SWCs) da aplicação.
 *
 * O RTE atua como intermediador, garantindo o desacoplamento
 * entre os módulos, conforme proposto na arquitetura AUTOSAR.
 */

#ifndef RTE_H
#define RTE_H

/**
 * @brief Executa um ciclo completo do sistema.
 *
 * Esta função:
 *  - Realiza a leitura dos dados do SWC_Input
 *  - Gerencia o fluxo de comunicação entre os componentes
 *  - Encaminha a mensagem para o SWC_Control
 *  - Envia o resultado ao SWC_Output
 *  - Simula a comunicação via barramento CAN
 *
 * Esta função é chamada ciclicamente pelo módulo principal (main.c),
 * representando o comportamento de execução periódica de uma ECU.
 */
void RTE_Run(void);

#endif
