#include "hal_led.h"
#include "led_embutido.h"
#include "pico/stdlib.h"

void hal_led_init(void) {
    led_driver_init();
}

void hal_led_toggle(void) {
    static bool estado = false;
    led_driver_set(estado);
    estado = !estado;
    sleep_ms(500);
}
