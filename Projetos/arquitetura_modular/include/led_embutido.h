#ifndef LED_EMBUTIDO_H
#define LED_EMBUTIDO_H

#include <stdbool.h>

void led_driver_init(void);
void led_driver_set(bool on);

#endif
