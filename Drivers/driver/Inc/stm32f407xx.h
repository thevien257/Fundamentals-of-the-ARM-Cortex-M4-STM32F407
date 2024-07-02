#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

// BASE ADDRESS FOR BUS
#define APB1_BASEADDR 0x40000000U
#define APB2_BASEADDR 0x40010000U
#define AHB1_BASEADDR 0x40020000U
#define AHB2_BASEADDR 0x50000000U

// BASE ADDRESS FOR GPIO ON AHB1
#define GPIOA_BASEADDR APB1_BASEADDR
#define GPIOB_BASEADDR 0x40020400
#define GPIOC_BASEADDR 0x40020800
#define GPIOD_BASEADDR 0x40020C00
#define GPIOE_BASEADDR 0x40021000
#define GPIOF_BASEADDR 0x40021400
#define GPIOG_BASEADDR 0x40021800
#define GPIOH_BASEADDR 0x40021C00
#define GPIOI_BASEADDR 0x40022000
#define GPIOJ_BASEADDR 0x40022400
#define GPIOK_BASEADDR 0x40022800
#define RCC_BASEADRR 0x40023800

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

// GPIO Register
// GPIO Base Address -> GPIO Register -> MODER, OTYPER....
typedef struct {
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
} GPIO_REG;

// RCC REGISTER
typedef struct {
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_PLLCFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_AHB1RSTR;
	volatile uint32_t RCC_AHB2RSTR;
	volatile uint32_t RCC_AHB3RSTR;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RCC_AHB1ENR;
	volatile uint32_t RCC_AHB2ENR;
	volatile uint32_t RCC_AHB3ENR;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RCC_AHB1LPENR;
	volatile uint32_t RCC_AHB2LPENR;
	volatile uint32_t RCC_AHB3LPENR;
	volatile uint32_t RCC_APB1LPENR;
	volatile uint32_t RCC_APB2LPENR;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	volatile uint32_t RCC_SSCGR;
	volatile uint32_t RCC_PLLI2SCFGR;

} RCC_REG;

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

// Enable RCC GPIOx Peripheral
#define RCC_GPIOA_EN() (RCC_IMPL->RCC_AHB1ENR |= (1 << 0))
#define RCC_GPIOB_EN() (RCC_IMPL->RCC_AHB1ENR |= 1 << 1)
#define RCC_GPIOC_EN() (RCC_IMPL->RCC_AHB1ENR |= 1 << 2)
#define RCC_GPIOD_EN() (RCC_IMPL->RCC_AHB1ENR |= 1 << 3)
#define RCC_GPIOE_EN() (RCC_IMPL->RCC_AHB1ENR |= 1 << 4)
#define RCC_GPIOF_EN() (RCC_IMPL->RCC_AHB1ENR |= 1 << 5)
#define RCC_GPIOG_EN() (RCC_IMPL->RCC_AHB1ENR |= 1 << 6)
#define RCC_GPIOH_EN() (RCC_IMPL->RCC_AHB1ENR |= 1 << 7)
#define RCC_GPIOI_EN() (RCC_IMPL->RCC_AHB1ENR |= 1 << 8)

// Disable RCC GPIOx Peripheral
#define RCC_GPIOA_DI() (RCC_IMPL->RCC_AHB1ENR &= ~(1 << 0))
#define RCC_GPIOB_DI() (RCC_IMPL->RCC_AHB1ENR &= ~(1 << 1))
#define RCC_GPIOC_DI() (RCC_IMPL->RCC_AHB1ENR &= ~(1 << 2))
#define RCC_GPIOD_DI() (RCC_IMPL->RCC_AHB1ENR &= ~(1 << 3))
#define RCC_GPIOE_DI() (RCC_IMPL->RCC_AHB1ENR &= ~(1 << 4))
#define RCC_GPIOF_DI() (RCC_IMPL->RCC_AHB1ENR &= ~(1 << 5))
#define RCC_GPIOG_DI() (RCC_IMPL->RCC_AHB1ENR &= ~(1 << 6))
#define RCC_GPIOH_DI() (RCC_IMPL->RCC_AHB1ENR &= ~(1 << 7))
#define RCC_GPIOI_DI() (RCC_IMPL->RCC_AHB1ENR &= ~(1 << 8))

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
#define RCC_SYSCFG_EN() (RCC_IMPL->RCC_APB2ENR |= 1 << 14)

// Some generic macro
#define ENABLE 	1
#define DISABLE 0
#define SET		ENABLE
#define RESET 	DISABLE

#endif /* INC_STM32F407XX_H_ */
