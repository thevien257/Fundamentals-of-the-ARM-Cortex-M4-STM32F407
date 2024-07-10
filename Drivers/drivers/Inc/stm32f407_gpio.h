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

// Mode for Interrupt Method
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

// Structure of EXTI
typedef struct {
	volatile uint32_t IMR; /*!< Give a short description,          	  	    Address offset: 0x00 */
	volatile uint32_t EMR; /*!< TODO,                						Address offset: 0x04 */
	volatile uint32_t RTSR; /*!< TODO,  									     Address offset: 0x08 */
	volatile uint32_t FTSR; /*!< TODO, 										Address offset: 0x0C */
	volatile uint32_t SWIER; /*!< TODO,  									   Address offset: 0x10 */
	volatile uint32_t PR; /*!< TODO,                   					   Address offset: 0x14 */
} EXTI_REG_DEF;

typedef struct {
	GPIO_REG *pGPIOx;
	GPIO_configuration_t pGPIO_Confg;
} GPIO_handle_t;

// @PURPOSE OF SYSCOFG: To decide which Port should take over the EXTIx
typedef struct {
	volatile uint32_t MEMRMP; /*!< Give a short description,                    Address offset: 0x00      */
	volatile uint32_t PMC; /*!< TODO,     									  Address offset: 0x04      */
	volatile uint32_t EXTICR[4]; /*!< TODO , 									  Address offset: 0x08-0x14 */
	uint32_t RESERVED1[2]; /*!< TODO          							  Reserved, 0x18-0x1C    	*/
	volatile uint32_t CMPCR; /*!< TODO         								  Address offset: 0x20      */
	uint32_t RESERVED2[2]; /*!<                                             Reserved, 0x24-0x28 	    */
	volatile uint32_t CFGR; /*!< TODO                                         Address offset: 0x2C   	*/
} SYSCFG_REG;

// Set up GPIO Clock
void GPIO_ClockControl(GPIO_REG *pGPIOxReg, uint8_t enOrDis);

// GPIO initialization
void GPIO_Init(GPIO_handle_t *pGPIOHandle);
// GPIO De-initialization
void GPIO_DeInit(GPIO_REG *pGPIOxReg);

// Read-Write Method
uint8_t GPIO_ReadInputPin(GPIO_REG *pGPIOxReg, uint8_t pinNumber);
uint16_t GPIO_ReadInputPort(GPIO_REG *pGPIOxReg);
void GPIO_WriteOutputPin(GPIO_REG *pGPIOxReg, uint8_t pinNumber, uint8_t value);
void GPIO_WriteOutputPort(GPIO_REG *pGPIOxReg, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_REG *pGPIOxReg, uint8_t pinNumber);

// Interrupt
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t enOrDis);
void GPIO_IRQHandling(uint8_t pinNumber);
void GPIO_IRQPriorty(uint8_t IRQNumber, uint8_t priority);

#endif /* INC_STM32F407_GPIO_H_ */
