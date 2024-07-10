#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#include "stm32f407_gpio.h"

#define __vo volatile

#define NVIC_ISER0          ( (__vo uint32_t*)0xE000E100 )
#define NVIC_ISER1          ( (__vo uint32_t*)0xE000E104 )
#define NVIC_ISER2          ( (__vo uint32_t*)0xE000E108 )
#define NVIC_ISER3          ( (__vo uint32_t*)0xE000E10c )

/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */
#define NVIC_ICER0 			((__vo uint32_t*)0XE000E180)
#define NVIC_ICER1			((__vo uint32_t*)0XE000E184)
#define NVIC_ICER2  		((__vo uint32_t*)0XE000E188)
#define NVIC_ICER3			((__vo uint32_t*)0XE000E18C)

/*
 * ARM Cortex Mx Processor Priority Register Address Calculation
 */
#define NVIC_PR_BASE_ADDR 	((__vo uint32_t*)0xE000E400)

/*
 * ARM Cortex Mx Processor number of priority bits implemented in Priority Register
 */
#define NO_PR_BITS_IMPLEMENTED  4

// IRQ Number
#define IRQ_NO_EXTI0 		6
#define IRQ_NO_EXTI1 		7
#define IRQ_NO_EXTI2 		8
#define IRQ_NO_EXTI3 		9
#define IRQ_NO_EXTI4 		10
#define IRQ_NO_EXTI9_5 		23
#define IRQ_NO_EXTI15_10 	40

// Priority Level
#define NVIC_IRQ_PRI0    0
#define NVIC_IRQ_PRI15    15

// BASE ADDRESS FOR BUS
#define APB1_BASEADDR 0x40000000U
#define APB2_BASEADDR 0x40010000U
#define AHB1_BASEADDR 0x40020000U
#define AHB2_BASEADDR 0x50000000U

// BASE ADDRESS FOR GPIO ON AHB1
#define GPIOA_BASEADDR                   (AHB1_BASEADDR + 0x0000)
#define GPIOB_BASEADDR                   (AHB1_BASEADDR + 0x0400)
#define GPIOC_BASEADDR 					 (AHB1_BASEADDR + 0x0800)
#define GPIOD_BASEADDR 					 (AHB1_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR 					 (AHB1_BASEADDR + 0x1000)
#define GPIOF_BASEADDR 					 (AHB1_BASEADDR + 0x1400)
#define GPIOG_BASEADDR 					 (AHB1_BASEADDR + 0x1800)
#define GPIOH_BASEADDR 					 (AHB1_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR 					 (AHB1_BASEADDR + 0x2000)
#define RCC_BASEADRR                     (AHB1_BASEADDR + 0x3800)

// BASE ADDRESS FOR APB1
#define I2C1_BASEADDR 0x40005400
#define I2C2_BASEADDR 0x40005800
#define I2C3_BASEADDR 0x40005C00
#define SPI2_BASEADDR 0x40003800
#define SPI3_BASEADDR 0x40003C00
#define USART2_BASEADDR 0x40004400
#define USART3_BASEADDR 0x40004800
#define UART4_BASEADDR 0x40004C00
#define UART5_BASEADDR 0x40005000

// BASE ADDRESS FOR APB2
#define SPI1_BASEADDR 0x40013000
#define USART1_BASEADDR 0x40011000
#define USART6_BASEADDR 0x40011400
#define EXTI_BASEADDR 0x40013C00
#define SYSCFG_BASEADDR 0x40013800

// Address of GPIOx
#define GPIOA (GPIO_REG*)GPIOA_BASEADDR
#define GPIOB (GPIO_REG*)GPIOB_BASEADDR
#define GPIOC (GPIO_REG*)GPIOC_BASEADDR
#define GPIOD (GPIO_REG*)GPIOD_BASEADDR
#define GPIOE (GPIO_REG*)GPIOD_BASEADDR
#define GPIOF (GPIO_REG*)GPIOF_BASEADDR
#define GPIOG (GPIO_REG*)GPIOG_BASEADDR
#define GPIOH (GPIO_REG*)GPIOH_BASEADDR
#define GPIOI (GPIO_REG*)GPIOI_BASEADDR
#define GPIOJ (GPIO_REG*)GPIOJ_BASEADDR
#define GPIOK (GPIO_REG*)GPIOK_BASEADDR

// Address of RCC
#define RCC_IMPL ((RCC_REG*)RCC_BASEADRR)

// Address of EXTI
#define EXTI ((EXTI_REG_DEF*)EXTI_BASEADDR)

// Address of SYSCONFIG
#define SYSCONFG ((SYSCFG_REG*)SYSCFG_BASEADDR)

// Enable RCC GPIOx Peripheral
#define RCC_GPIOA_EN() (RCC_IMPL->AHB1ENR |= (1 << 0))
#define RCC_GPIOB_EN() (RCC_IMPL->AHB1ENR |= 1 << 1)
#define RCC_GPIOC_EN() (RCC_IMPL->AHB1ENR |= 1 << 2)
#define RCC_GPIOD_EN() (RCC_IMPL->AHB1ENR |= 1 << 3)
#define RCC_GPIOE_EN() (RCC_IMPL->AHB1ENR |= 1 << 4)
#define RCC_GPIOF_EN() (RCC_IMPL->AHB1ENR |= 1 << 5)
#define RCC_GPIOG_EN() (RCC_IMPL->AHB1ENR |= 1 << 6)
#define RCC_GPIOH_EN() (RCC_IMPL->AHB1ENR |= 1 << 7)
#define RCC_GPIOI_EN() (RCC_IMPL->AHB1ENR |= 1 << 8)

// Disable RCC GPIOx Peripheral
#define RCC_GPIOA_DI() (RCC_IMPL->AHB1ENR &= ~(1 << 0))
#define RCC_GPIOB_DI() (RCC_IMPL->AHB1ENR &= ~(1 << 1))
#define RCC_GPIOC_DI() (RCC_IMPL->AHB1ENR &= ~(1 << 2))
#define RCC_GPIOD_DI() (RCC_IMPL->AHB1ENR &= ~(1 << 3))
#define RCC_GPIOE_DI() (RCC_IMPL->AHB1ENR &= ~(1 << 4))
#define RCC_GPIOF_DI() (RCC_IMPL->AHB1ENR &= ~(1 << 5))
#define RCC_GPIOG_DI() (RCC_IMPL->AHB1ENR &= ~(1 << 6))
#define RCC_GPIOH_DI() (RCC_IMPL->AHB1ENR &= ~(1 << 7))
#define RCC_GPIOI_DI() (RCC_IMPL->AHB1ENR &= ~(1 << 8))

// Reset RCC GPIOx Peripheral
#define RCC_GPIOA_RESET() do{(RCC_IMPL->AHB1RSTR |= (1<<0)); (RCC_IMPL->AHB1RSTR &= ~(1<<0));}while(0)
#define RCC_GPIOB_RESET() do{(RCC_IMPL->AHB1RSTR |= (1<<1)); (RCC_IMPL->AHB1RSTR &= ~(1<<1));}while(0)
#define RCC_GPIOC_RESET() do{(RCC_IMPL->AHB1RSTR |= (1<<2)); (RCC_IMPL->AHB1RSTR &= ~(1<<2));}while(0)
#define RCC_GPIOE_RESET() do{(RCC_IMPL->AHB1RSTR |= (1<<3)); (RCC_IMPL->AHB1RSTR &= ~(1<<3));}while(0)
#define RCC_GPIOF_RESET() do{(RCC_IMPL->AHB1RSTR |= (1<<5)); (RCC_IMPL->AHB1RSTR &= ~(1<<5));}while(0)
#define RCC_GPIOG_RESET() do{(RCC_IMPL->AHB1RSTR |= (1<<6)); (RCC_IMPL->AHB1RSTR &= ~(1<<6));}while(0)
#define RCC_GPIOH_RESET() do{(RCC_IMPL->AHB1RSTR |= (1<<7)); (RCC_IMPL->AHB1RSTR &= ~(1<<7));}while(0)
#define RCC_GPIOI_RESET() do{(RCC_IMPL->AHB1RSTR |= (1<<8)); (RCC_IMPL->AHB1RSTR &= ~(1<<8));}while(0)

// Enable I2Cx Peripheral
#define RCC_I2C1_EN() (RCC_IMPL->RCC_APB1ENR |= 1 << 21)
#define RCC_I2C2_EN() (RCC_IMPL->RCC_APB1ENR |= 1 << 22)
#define RCC_I2C3_EN() (RCC_IMPL->RCC_APB1ENR |= 1 << 23)

// Enable SPIx Peripheral
#define RCC_SPI1_EN() (RCC_IMPL->RCC_APB2ENR |= 1 << 12)
#define RCC_SPI2_EN() (RCC_IMPL->RCC_APB1ENR |= 1 << 14)
#define RCC_SPI3_EN() (RCC_IMPL->RCC_APB1ENR |= 1 << 15)

// Enable USART Peripheral
#define RCC_USART1_EN() (RCC_IMPL->RCC_APB2ENR |= 1 << 4)
#define RCC_USART2_EN() (RCC_IMPL->RCC_APB1ENR |= 1 << 17)
#define RCC_USART3_EN() (RCC_IMPL->RCC_APB1ENR |= 1 << 18)
#define RCC_UART4_EN() (RCC_IMPL->RCC_APB1ENR |= 1 << 19)
#define RCC_UART5_EN() (RCC_IMPL->RCC_APB1ENR |= 1 << 20)
#define RCC_USART6_EN() (RCC_IMPL->RCC_APB2ENR |= 1 << 5)

// Enable SYSCFG Peripheral
#define RCC_SYSCFG_EN() (RCC_IMPL->APB2ENR |= 1 << 14)

// PortX
#define portXFunc(x) ((x==GPIOA) ? 0:\
					 (x==GPIOB) ? 1:\
					 (x==GPIOC) ? 2:\
				     (x == GPIOD)?3:\
				     (x == GPIOE)?4:\
				     (x == GPIOF)?5:\
					 (x == GPIOG)?6:\
					 (x == GPIOH)?7: \
					 (x == GPIOI)?8:0)

// Some generic macro
#define ENABLE 	1
#define DISABLE 0
#define SET		ENABLE
#define RESET 	DISABLE

#endif /* INC_STM32F407XX_H_ */
