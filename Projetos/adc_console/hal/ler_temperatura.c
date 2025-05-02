#include "ler_temperatura.h"

#define TEMP_SENSOR_OFFSET 0.706f     // Tensão em 27°C
#define TEMP_SENSOR_COEFF  0.001721f  // Variação por °C

float adc_to_celsius(float tensao) {
    return 27.0f - ((tensao - TEMP_SENSOR_OFFSET) / TEMP_SENSOR_COEFF);
}
