#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main(void) {
    // Inicializa a comunicação serial
    stdio_init_all();
    
    // Aguarda a conexão serial (para depuração)
    printf("\nMonitor de Temperatura Interna do RP2040\n");
    
    // Habilita o sensor de temperatura interno
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);  // Canal ADC4 é o sensor de temperatura interno
    
    // Fator de conversão de tensão para valor ADC (3.3V / 4096 níveis)
    const float conversion_factor = 3.3f / (1 << 12);
    
    // Coeficientes para cálculo da temperatura (da documentação do RP2040)
    const float temp_sensor_offset = 0.706f;    // Tensão a 27°C
    const float temp_sensor_coeff = 0.001721f;  // Coeficiente térmico (V/°C)
    
    while (true) {
        // Lê o valor bruto do ADC (12 bits, 0-4095)
        uint16_t raw = adc_read();
        
        // Converte para tensão
        float voltage = raw * conversion_factor;
        
        // Calcula a temperatura (fórmula da documentação)
        float temperature = 27.0f - (voltage - temp_sensor_offset) / temp_sensor_coeff;
        
        // Exibe os resultados
        printf("Valor ADC: %4d, Tensão: %.3f V, Temperatura: %.2f °C\n", 
               raw, voltage, temperature);
        
        // Espera 1 segundo antes da próxima leitura
        sleep_ms(1000);
    }
    
    return 0;
}