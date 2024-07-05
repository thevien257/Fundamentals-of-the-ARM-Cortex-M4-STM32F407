#include "stm32f407xx.h"
#include "stm32f407_gpio.h"

void delay() {
	for (uint32_t i = 0; i < 500000; i++) {
	}
}

int main() {
	GPIO_handle_t gpioLED;
	gpioLED.pGPIOx = GPIOD;
	RCC_GPIOD_EN();
	gpioLED.pGPIO_Confg.GPIO_pinNumber = GPIO_PIN_NB_12;
	gpioLED.pGPIO_Confg.GPIO_pinMode = GPIO_MODE_OUTPUT;
	gpioLED.pGPIO_Confg.GPIO_pinSpeed = GPIO_SPEED_FAST;
	gpioLED.pGPIO_Confg.GPIO_pinOPType = GPIO_MODE_OUTPUTTYPE_PUSHPULL;
	gpioLED.pGPIO_Confg.GPIO_pinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&gpioLED);
	while (1) {
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NB_12);
		delay();
	}
}

