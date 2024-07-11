#include "stm32f407xx.h"
#include "stm32f407_gpio.h"

void delay() {
	for (uint32_t i = 0; i < 250000; i++) {
	}
}

int main() {
	GPIO_handle_t gpioLED, gpioBtn;
	gpioLED.pGPIOx = GPIOD;
	gpioLED.pGPIO_Confg.GPIO_pinNumber = GPIO_PIN_NB_12;
	gpioLED.pGPIO_Confg.GPIO_pinMode = GPIO_MODE_OUTPUT;
	gpioLED.pGPIO_Confg.GPIO_pinSpeed = GPIO_SPEED_FAST;
	gpioLED.pGPIO_Confg.GPIO_pinOPType = GPIO_MODE_OUTPUTTYPE_PUSHPULL;
	gpioLED.pGPIO_Confg.GPIO_pinPuPdControl = GPIO_NO_PUPD;
	GPIO_ClockControl(GPIOD, ENABLE);
	GPIO_Init(&gpioLED);

	gpioBtn.pGPIOx = GPIOA;
	gpioBtn.pGPIO_Confg.GPIO_pinNumber = GPIO_PIN_NB_0;
	gpioBtn.pGPIO_Confg.GPIO_pinMode = GPIO_MODE_INPUT;
	gpioBtn.pGPIO_Confg.GPIO_pinSpeed = GPIO_SPEED_FAST;
	gpioBtn.pGPIO_Confg.GPIO_pinPuPdControl = GPIO_NO_PUPD;
	GPIO_ClockControl(GPIOA, ENABLE);
	GPIO_Init(&gpioBtn);
	while (1) {
		if (GPIO_ReadInputPin(GPIOA, GPIO_PIN_NB_0)) {
			delay();
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NB_12);
		}
	}
}
