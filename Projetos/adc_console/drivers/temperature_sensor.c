#include "hardware/adc.h"
#include "temperature_sensor.h"

#define TEMP_ADC_CHANNEL 4
#define ADC_CONVERSION_FACTOR (3.3f / 4096.0f)

void temperature_sensor_init(void) {
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(TEMP_ADC_CHANNEL);
}

float temperature_sensor_read_voltage(void) {
    uint16_t adc_raw = adc_read();
    return adc_raw * ADC_CONVERSION_FACTOR;
}
