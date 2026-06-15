# TCC - Simulação AUTOSAR em C

Este projeto implementa uma arquitetura modular de software embarcado inspirada no AUTOSAR, com comunicação baseada em mensagens CAN.

## Compilação

Antes de compilar, mantenha apenas os arquivos principais em cada pasta.

Arquivos de teste extras (como versões com falha, latência ou lógica modificada) devem ser removidos ou movidos para fora das pastas.

Caso queira utilizar as versões modificadas, remova o arquivo original e renomeie o arquivo desejado, pois múltiplas versões podem causar erro de compilação.

Comando:

gcc main.c bsw/*.c rte/*.c swc_input/*.c swc_control/*.c swc_output/*.c -o autosar_sim

## Execução

./autosar_sim
