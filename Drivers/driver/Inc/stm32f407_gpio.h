#ifndef INC_STM32F407_GPIO_H_
#define INC_STM32F407_GPIO_H_
#include "stm32f407xx.h"

// GPIO_PIN_NUMBERS
#define GPIO_PIN_NB_0 	0
#define GPIO_PIN_NB_1 	1
#define GPIO_PIN_NB_2	2
#define GPIO_PIN_NB_3 	3
#define GPIO_PIN_NB_4 	4
#define GPIO_PIN_NB_5 	5
#define GPIO_PIN_NB_6 	6
#define GPIO_PIN_NB_7 	7
#define GPIO_PIN_NB_8 	8
#define GPIO_PIN_NB_9 	9
#define GPIO_PIN_NB_10 	10
#define GPIO_PIN_NB_11 	11
#define GPIO_PIN_NB_12 	12
#define GPIO_PIN_NB_13 	13
#define GPIO_PIN_NB_14 	14
#define GPIO_PIN_NB_15 	15

// GPIO PIN MODES
#define GPIO_MODE_INPUT 0
#define GPIO_MODE_OUTPUT 1
#define GPIO_MODE_ALT 2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE_FALLING 4
#define GPIO_MODE_RISING 5
#define GPIO_MODE_RISING_FALLING 6

// GPIO_PIN_OUTPUT_TYPE
#define GPIO_MODE_OUTPUTTYPE_PUSHPULL 0
#define GPIO_MODE_OUTPUTTYPE_OPENDRAIN 1

// GPIO_PIN_SPEED
#define GPIO_SPEED_LOW 0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_FAST 2
#define GPIO_SPEED_HIGH 3

// GPIO_PIN_PUPD
#define GPIO_NO_PUPD 0
#define GPIO_PIN_PU 1
#define GPIO_PIN_PD 2

typedef struct {
	uint8_t GPIO_pinNumber; // @GPIO_PIN_NUMBERS
	uint8_t GPIO_pinMode; // @GPIO_PIN_MODES
	uint8_t GPIO_pinSpeed; // @GPIO_PIN_SPEED
	uint8_t GPIO_pinPuPdControl; // @GPIO_PIN_PUPD
	uint8_t GPIO_pinOPType; // @GPIO_PIN_OUTPUT_TYPE
	uint8_t GPIO_pinAltFunMode;
} GPIO_configuration_t;

typedef struct {
	GPIO_REG *pGPIOx;
	GPIO_configuration_t *pGPIO_Confg;
} GPIO_handle_t;

void GPIO_ClockControl(GPIO_REG *pGPIOxReg, uint8_t enOrDis);

void GPIO_Init(GPIO_handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_REG *pGPIOxReg);

uint8_t GPIO_ReadInputPin(GPIO_REG *pGPIOxReg, uint8_t pinNumber);
uint16_t GPIO_ReadInputPort(GPIO_REG *pGPIOxReg);
void GPIO_WriteOutputPin(GPIO_REG *pGPIOxReg, uint8_t pinNumber, uint8_t value);
void GPIO_WriteOutputPort(GPIO_REG *pGPIOxReg, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_REG *pGPIOxReg, uint8_t pinNumber);

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t enOrDis);
void GPIO_IRQHandling(uint8_t pinNumber);

#endif /* INC_STM32F407_GPIO_H_ */
