/**
 * @file main.c
 * @brief Módulo principal responsável por simular o comportamento de uma ECU.
 *
 * Este arquivo representa o ponto de entrada do sistema embarcado simulado.
 * Ele controla:
 *  - Inicialização da ECU (Key ON / Key OFF)
 *  - Interação com o usuário (entrada de comandos)
 *  - Execução cíclica do sistema (chamada do RTE)
 *
 * O comportamento implementa um loop infinito típico de sistemas embarcados.
 */

#include <stdio.h>      // Entrada e saída padrão
#include <conio.h>     // Funções de teclado (kbhit, getchar)
#include <windows.h>   // Função Sleep para controle de tempo

#include "RTE/rte.h"             // Interface do Runtime Environment
#include "SWC_Input/input.h"     // Interface do componente de entrada

/**
 * @brief Função principal do sistema.
 *
 * Simula o funcionamento de uma ECU, executando um loop infinito
 * que processa entrada do usuário e executa os ciclos do sistema.
 */
int main() {

    int ecu_on = 0;  // Estado da ECU (0 = OFF, 1 = ON)

    // Mensagens iniciais para o usuário
    printf("ECU OFF - Pressione S(keyOn) para que sua ECU ligue e X(KeyOff) para que ela desligue\n");
    printf("Pression f para ligar o farol e d para desligar\n");

    /**
     * Loop infinito típico de sistemas embarcados
     * Mantém o sistema em execução contínua
     */
    while (1) {

        /**
         * Verifica se o usuário pressionou alguma tecla
         * (entrada não bloqueante)
         */
        if (kbhit()) {

            char c = getchar();  // Captura o caractere digitado

            switch (c) {

                case 's':
                    ecu_on = 1;  // Liga a ECU
                    printf("[ECU] ON\n");
                    break;

                case 'x':
                    ecu_on = 0;  // Desliga a ECU
                    printf("[ECU] OFF\n");
                    break;

                case 'f':
                    /**
                     * Envia sinal para o SWC_Input indicando farol LIGADO
                     */
                    SWC_Input_SetFarol(1);
                    printf("[USER] Farol ON\n");
                    break;

                case 'd':
                    /**
                     * Envia sinal para o SWC_Input indicando farol DESLIGADO
                     */
                    SWC_Input_SetFarol(0);
                    printf("[USER] Farol OFF\n");
                    break;
            }
        }

        /**
         * Execução cíclica do sistema
         * Só ocorre se a ECU estiver ligada
         */
        if (ecu_on) {

            // Chamada do RTE (orquestrador dos componentes)
            RTE_Run();

            /**
             * Delay de 500 ms (0,5s)
             * Simula um ciclo periódico típico de sistemas embarcados
             */
            Sleep(500);
        }
    }

    return 0;
}