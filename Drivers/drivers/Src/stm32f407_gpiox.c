#include "stm32f407_gpio.h"
#include "stm32f407xx.h"

// Clock Setup
void GPIO_ClockControl(GPIO_REG *pGPIOxReg, uint8_t enOrDis) {
	if (enOrDis == ENABLE) {
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
	// 32-bit Register Moder
	uint32_t temp = 0;
	if (pGPIOHandle->pGPIO_Confg.GPIO_pinMode <= GPIO_MODE_ANALOG) {
		// Non-Interrupt Mode
		temp = (pGPIOHandle->pGPIO_Confg.GPIO_pinMode
				<< (2 * pGPIOHandle->pGPIO_Confg.GPIO_pinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3
				<< pGPIOHandle->pGPIO_Confg.GPIO_pinNumber); // Clearing first
		pGPIOHandle->pGPIOx->MODER |= temp; // Setting

	} else {
		// Interrupt Mode
		if (pGPIOHandle->pGPIO_Confg.GPIO_pinMode == GPIO_MODE_FALLING) {
			EXTI->FTSR |= (1 << pGPIOHandle->pGPIO_Confg.GPIO_pinNumber);
			EXTI->RTSR &= ~(1 << pGPIOHandle->pGPIO_Confg.GPIO_pinNumber);
		} else if (pGPIOHandle->pGPIO_Confg.GPIO_pinMode == GPIO_MODE_RISING) {
			EXTI->RTSR |= (1 << pGPIOHandle->pGPIO_Confg.GPIO_pinNumber);
			EXTI->FTSR &= ~(1 << pGPIOHandle->pGPIO_Confg.GPIO_pinNumber);
		} else if (pGPIOHandle->pGPIO_Confg.GPIO_pinMode
				== GPIO_MODE_RISING_FALLING) {
			EXTI->RTSR |= (1 << pGPIOHandle->pGPIO_Confg.GPIO_pinNumber);
			EXTI->FTSR |= (1 << pGPIOHandle->pGPIO_Confg.GPIO_pinNumber);
		}
		// 2. Find out the PORT for the EXTIx
		RCC_SYSCFG_EN();
		uint8_t extiX = pGPIOHandle->pGPIO_Confg.GPIO_pinNumber / 4;
		uint8_t posRegEXTIx = pGPIOHandle->pGPIO_Confg.GPIO_pinNumber % 4;
		uint8_t portX = portXFunc(pGPIOHandle->pGPIOx);
		SYSCONFG->EXTICR[extiX] = portX << (posRegEXTIx * 4);
		// 3. ENABLE THE INTERRUPT OF GPIO PERIPHERAL
		EXTI->IMR |= (1 << pGPIOHandle->pGPIO_Confg.GPIO_pinNumber);
	}
	// 2. Config Speed
	temp = 0;
	temp = (pGPIOHandle->pGPIO_Confg.GPIO_pinSpeed
			<< (2 * pGPIOHandle->pGPIO_Confg.GPIO_pinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3
			<< pGPIOHandle->pGPIO_Confg.GPIO_pinNumber); // Clearing first
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;
	temp = 0;
	// 3. Pull-up, Pull-down
	temp = (pGPIOHandle->pGPIO_Confg.GPIO_pinPuPdControl
			<< (2 * pGPIOHandle->pGPIO_Confg.GPIO_pinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3
			<< pGPIOHandle->pGPIO_Confg.GPIO_pinNumber); // Clearing first
	pGPIOHandle->pGPIOx->PUPDR |= temp;
	temp = 0;

	// 4. Config Output Type
	temp = (pGPIOHandle->pGPIO_Confg.GPIO_pinOPType
			<< (pGPIOHandle->pGPIO_Confg.GPIO_pinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1
			<< pGPIOHandle->pGPIO_Confg.GPIO_pinNumber); // Clearing first
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp = 0;

	// 5. Config Alt Functionality
	// Alt:
	// Low: pin 0 -> pin 7
	// High: pin 8 - > pin 15
	if (pGPIOHandle->pGPIO_Confg.GPIO_pinMode == GPIO_MODE_ALT) {
		uint8_t temp1 = 0, temp2 = 0;
		temp1 = pGPIOHandle->pGPIO_Confg.GPIO_pinNumber / 8;
		temp2 = pGPIOHandle->pGPIO_Confg.GPIO_pinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2)); // Clearing first
		pGPIOHandle->pGPIOx->AFR[temp1] |=
				pGPIOHandle->pGPIO_Confg.GPIO_pinAltFunMode << (4 * temp2);
	}
}

// De - Initialization GPIO
void GPIO_DeInit(GPIO_REG *pGPIOxReg) {
	if (pGPIOxReg == GPIOA) {
		RCC_GPIOA_RESET();
	} else if (pGPIOxReg == GPIOB) {
		RCC_GPIOA_RESET();
	} else if (pGPIOxReg == GPIOC) {
		RCC_GPIOA_RESET();
	} else if (pGPIOxReg == GPIOD) {
		RCC_GPIOA_RESET();
	} else if (pGPIOxReg == GPIOE) {
		RCC_GPIOA_RESET();
	} else if (pGPIOxReg == GPIOF) {
		RCC_GPIOA_RESET();
	} else if (pGPIOxReg == GPIOG) {
		RCC_GPIOA_RESET();
	} else if (pGPIOxReg == GPIOH) {
		RCC_GPIOA_RESET();
	} else if (pGPIOxReg == GPIOI) {
		RCC_GPIOA_RESET();
	}
}

// Read input GPIO
uint8_t GPIO_ReadInputPin(GPIO_REG *pGPIOxReg, uint8_t pinNumber) {

	uint8_t inputVal = (uint8_t) ((pGPIOxReg->IDR) >> pinNumber) & 0x00000001;
	return inputVal;
}

// Read input GPIO
uint16_t GPIO_ReadInputPort(GPIO_REG *pGPIOxReg) {
	uint16_t inputVal = (uint16_t) pGPIOxReg->IDR;
	return inputVal;
}

// Write output GPIO
void GPIO_WriteOutputPin(GPIO_REG *pGPIOxReg, uint8_t pinNumber, uint8_t value) {
	if (value == SET) {
		pGPIOxReg->ODR |= (1 << pinNumber);
	} else {
		pGPIOxReg->ODR &= ~(1 << pinNumber);
	}
}

// Write output GPIO
void GPIO_WriteOutputPort(GPIO_REG *pGPIOxReg, uint16_t value) {
	pGPIOxReg->ODR = value;
}

// Toggle Output Pin
void GPIO_ToggleOutputPin(GPIO_REG *pGPIOxReg, uint8_t pinNumber) {
	pGPIOxReg->ODR ^= (1 << pinNumber);
}

// Setup IRQ (ENABLE NVIC) (PROCESSOR SIDE)
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t enOrDis) {
	if (enOrDis == ENABLE) {
		if (IRQNumber <= 31) {
			//ISER0
			*NVIC_ISER0 |= (1 << IRQNumber);
		} else if (IRQNumber > 31 && IRQNumber < 64) {
			*NVIC_ISER1 |= (1 << (IRQNumber % 32));
		} else if (IRQNumber >= 64 && IRQNumber < 96) {
			*NVIC_ISER2 |= (1 << (IRQNumber % 64));
		}
	} else {
		if (IRQNumber <= 31) {
			//ISER0
			*NVIC_ICER0 |= (1 << IRQNumber);
		} else if (IRQNumber > 31 && IRQNumber < 64) {
			*NVIC_ICER1 |= (1 << (IRQNumber % 32));
		} else if (IRQNumber >= 64 && IRQNumber < 96) {
			*NVIC_ICER2 |= (1 << (IRQNumber % 64));
		}
	}
}

// Config Priorty
void GPIO_IRQPriorty(uint8_t IRQNumber, uint8_t priority) {
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprxSection = IRQNumber % 4;
	uint8_t shiftAmount = (8 * iprxSection) + (8 - NO_PR_BITS_IMPLEMENTED);
	*( NVIC_PR_BASE_ADDR + iprx) |= (priority << shiftAmount);
}

// Handling IRQ
void GPIO_IRQHandling(uint8_t pinNumber) {
	if (EXTI->PR & (1 << pinNumber)) {
		EXTI->PR |= (1 << pinNumber);
	}
}
