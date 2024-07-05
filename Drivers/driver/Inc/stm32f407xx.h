#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

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
	volatile uint32_t AFR[2];
} GPIO_REG;

// RCC REGISTER
typedef struct {
	volatile uint32_t CR; /*!< TODO,     										Address offset: 0x00 */
	volatile uint32_t PLLCFGR; /*!< TODO,     										Address offset: 0x04 */
	volatile uint32_t CFGR; /*!< TODO,     										Address offset: 0x08 */
	volatile uint32_t CIR; /*!< TODO,     										Address offset: 0x0C */
	volatile uint32_t AHB1RSTR; /*!< TODO,     										Address offset: 0x10 */
	volatile uint32_t AHB2RSTR; /*!< TODO,     										Address offset: 0x14 */
	volatile uint32_t AHB3RSTR; /*!< TODO,     										Address offset: 0x18 */
	uint32_t RESERVED0; /*!< Reserved, 0x1C                                                       */
	volatile uint32_t APB1RSTR; /*!< TODO,     										Address offset: 0x20 */
	volatile uint32_t APB2RSTR; /*!< TODO,     										Address offset: 0x24 */
	uint32_t RESERVED1[2]; /*!< Reserved, 0x28-0x2C                                                  */
	volatile uint32_t AHB1ENR; /*!< TODO,     										Address offset: 0x30 */
	volatile uint32_t AHB2ENR; /*!< TODO,     										Address offset: 0x34 */
	volatile uint32_t AHB3ENR; /*!< TODO,     										Address offset: 0x38 */
	uint32_t RESERVED2; /*!< Reserved, 0x3C                                                       */
	volatile uint32_t APB1ENR; /*!< TODO,     										Address offset: 0x40 */
	volatile uint32_t APB2ENR; /*!< TODO,     										Address offset: 0x44 */
	uint32_t RESERVED3[2]; /*!< Reserved, 0x48-0x4C                                                  */
	volatile uint32_t AHB1LPENR; /*!< TODO,     										Address offset: 0x50 */
	volatile uint32_t AHB2LPENR; /*!< TODO,     										Address offset: 0x54 */
	volatile uint32_t AHB3LPENR; /*!< TODO,     										Address offset: 0x58 */
	uint32_t RESERVED4; /*!< Reserved, 0x5C                                                       */
	volatile uint32_t APB1LPENR; /*!< TODO,     										Address offset: 0x60 */
	volatile uint32_t APB2LPENR; /*!< RTODO,     										Address offset: 0x64 */
	uint32_t RESERVED5[2]; /*!< Reserved, 0x68-0x6C                                                  */
	volatile uint32_t BDCR; /*!< TODO,     										Address offset: 0x70 */
	volatile uint32_t CSR; /*!< TODO,     										Address offset: 0x74 */
	uint32_t RESERVED6[2]; /*!< Reserved, 0x78-0x7C                                                  */
	volatile uint32_t SSCGR; /*!< TODO,     										Address offset: 0x80 */
	volatile uint32_t PLLI2SCFGR; /*!< TODO,     										Address offset: 0x84 */
	volatile uint32_t PLLSAICFGR; /*!< TODO,     										Address offset: 0x88 */
	volatile uint32_t DCKCFGR; /*!< TODO,     										Address offset: 0x8C */
	volatile uint32_t CKGATENR; /*!< TODO,     										Address offset: 0x90 */
	volatile uint32_t DCKCFGR2; /*!< TOvolatile */

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
#define RCC_SYSCFG_EN() (RCC_IMPL->RCC_APB2ENR |= 1 << 14)

// Some generic macro
#define ENABLE 	1
#define DISABLE 0
#define SET		ENABLE
#define RESET 	DISABLE

#endif /* INC_STM32F407XX_H_ */
