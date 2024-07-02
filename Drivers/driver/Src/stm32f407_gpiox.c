#include "stm32f407_gpio.h"
#include "stm32f407xx.h"

// Clock Setup
void GPIO_ClockControl(GPIO_REG *pGPIOxReg, uint8_t enOrDis) {
	if (enOrDis == DISABLE) {
		if (pGPIOxReg == GPIOA) {
			RCC_GPIOA_EN();
		} else if (pGPIOxReg == GPIOB) {
			RCC_GPIOB_EN();
		} else if (pGPIOxReg == GPIOC) {
			RCC_GPIOC_EN();
		} else if (pGPIOxReg == GPIOD) {
			RCC_GPIOD_EN();
		} else if (pGPIOxReg == GPIOE) {
			RCC_GPIOE_EN();
		} else if (pGPIOxReg == GPIOF) {
			RCC_GPIOF_EN();
		} else if (pGPIOxReg == GPIOG) {
			RCC_GPIOG_EN();
		} else if (pGPIOxReg == GPIOH) {
			RCC_GPIOH_EN();
		} else if (pGPIOxReg == GPIOI) {
			RCC_GPIOI_EN();
		}
	} else {
		if (pGPIOxReg == GPIOA) {
			RCC_GPIOA_DI();
		} else if (pGPIOxReg == GPIOB) {
			RCC_GPIOB_DI();
		} else if (pGPIOxReg == GPIOC) {
			RCC_GPIOC_DI();
		} else if (pGPIOxReg == GPIOD) {
			RCC_GPIOD_DI();
		} else if (pGPIOxReg == GPIOE) {
			RCC_GPIOE_DI();
		} else if (pGPIOxReg == GPIOF) {
			RCC_GPIOF_DI();
		} else if (pGPIOxReg == GPIOG) {
			RCC_GPIOG_DI();
		} else if (pGPIOxReg == GPIOH) {
			RCC_GPIOH_DI();
		} else if (pGPIOxReg == GPIOI) {
			RCC_GPIOI_DI();
		}
	}

}

// Initialization GPIO
void GPIO_Init(GPIO_handle_t *pGPIOHandle) {
	// 1. Config Mode
	// 2. Config Speed
	// 3. Pull-up, Pull-down
	// 4. Config Output Type
	// 5. Config Alt Functionality


}

// De - Initialization GPIO
void GPIO_DeInit(GPIO_REG *pGPIOxReg) {

}

// Read input GPIO
uint8_t GPIO_ReadInputPin(GPIO_REG *pGPIOxReg, uint8_t pinNumber) {

}

// Read input GPIO
uint16_t GPIO_ReadInputPort(GPIO_REG *pGPIOxReg) {

}

// Write output GPIO
void GPIO_WriteOutputPin(GPIO_REG *pGPIOxReg, uint8_t pinNumber, uint8_t value) {

}

// Write output GPIO
void GPIO_WriteOutputPort(GPIO_REG *pGPIOxReg, uint16_t value) {

}

// Toggle Output Pin
void GPIO_ToggleOutputPin(GPIO_REG *pGPIOxReg, uint8_t pinNumber) {

}

// Setup IRQ
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t enOrDis) {

}

// Handling IRQ
void GPIO_IRQHandling(uint8_t pinNumber) {

}
