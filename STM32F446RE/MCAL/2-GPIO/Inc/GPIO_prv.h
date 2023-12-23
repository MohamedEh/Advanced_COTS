#ifndef GPIO_PRV_H
#define GPIO_PRV_H

#define MODER_MASK				0b11U
#define MODER_PIN_ACCESS		2U

#define OSPEEDR_MASK			0b11U
#define OSPEEDR_PIN_ACCESS		2U

#define OTYPER_MASK				0b1U

#define PUPDR_MASK				0b11U
#define PUPDR_PIN_ACCESS		2U

#define AFR_MASK				0b1111U
#define AFR_PIN_ACCESS			4U
#define AFR_PIN_SHIFTING		8U

#define GPIO_PERIPHERAL_NUM		8U

#endif
