#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_GPIO 2

static int8_t led_state = 0;

static void configure_led(void) {
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

static void blink_led(void) {
    gpio_set_level(BLINK_GPIO, led_state);
}

void app_main(void) {
    configure_led();

    while (1) {
        blink_led();
        if(led_state) {
            printf("Den sang.\n");
        } else {
            printf("Den tat.\n");
        }

        led_state = !led_state;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}