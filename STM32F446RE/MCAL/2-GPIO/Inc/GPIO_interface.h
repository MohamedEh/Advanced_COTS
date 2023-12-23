#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
/*
*@Port_t
*/
typedef enum
{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH
}Port_t;
/*
*@Pin_t
*/
typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
	
}Pin_t;

typedef enum
{
	INPUT=0,
	OUTPUT,
	ALTERNATE_FUNCTION,
	ANALOG
}Mode_t;

typedef enum
{
	LOW=0,
	MEDIUM,
	FAST,
	HIGH
}OutputSpeed_t;

typedef enum
{
	PUSH_PULL=0,
	OPEN_DRAIN
}OutputType_t;

typedef enum
{
	NO_PULL=0,
	PULL_UP,
	PULL_DOWN
}PullType_t;

typedef enum
{
	AF0=0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15,
}AltFunc_t;

/*
*@PinVal_t
*/
typedef enum 
{
	PIN_LOW=0,
	PIN_HIGH
}PinVal_t;

typedef struct
{
	Port_t Port;
	Pin_t PinNum;
	Mode_t Mode;
	OutputSpeed_t Speed;
	OutputType_t OutputType;
	PullType_t PullType;
	AltFunc_t AltFunc;
}GPIO_PinConfig_t;


uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t* copy_pPinConfig);

uint8_t GPIO_u8SetPinValue(Port_t copy_u8Port, Pin_t copy_u8PinNum, PinVal_t copy_u8PinVal);

uint8_t GPIO_u8TogglePinValue(Port_t copy_u8Port, Pin_t copy_u8PinNum);

uint8_t GPIO_u8ReadPinValue(Port_t copy_u8Port, Pin_t copy_u8PinNum, PinVal_t* copy_pPinVal);


#endif
