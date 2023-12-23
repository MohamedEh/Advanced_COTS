#ifndef GPIO_PRV_H
#define GPIO_PRV_H

#define CRL_MASK				0b1111U
#define CRL_PIN_ACCESS			4U

#define CRH_MASK				0b1111U
#define CRH_PIN_ACCESS			4U
#define CNF_ACCESS				2U

#define EVCR_MASK				0b11111111
#define EVCR_PORT_ACCESS		4U
#define EVCR_EVOE_ACCESS		7U
#define EVCR_EVOE_SET_VALUE		1U


#define MAPR_MASK_1				0b1
#define MAPR_MASK_2				0b11
#define MAPR_MASK_SWJ			0b111



#define OSPEEDR_MASK			0b11U
#define OSPEEDR_PIN_ACCESS		2U

#define OTYPER_MASK				0b1U

#define PUPDR_MASK				0b11U
#define PUPDR_PIN_ACCESS		2U

#define AFR_MASK				0b1111U
#define AFR_PIN_ACCESS			4U
#define AFR_PIN_SHIFTING		8U

#define GPIO_PERIPHERAL_NUM		7U

#endif
