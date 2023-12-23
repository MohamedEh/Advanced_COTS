#ifndef SCB_INTERFACE_H
#define SCB_INTERFACE_H


typedef enum
{
	GROUP4_SUB0=3,					//4 bits for group priority and 0 bits for sub priority
	GROUP3_SUB1,					//3 bits for group priority and 1 bits for sub priority
	GROUP2_SUB2,					//2 bits for group priority and 2 bits for sub priority
	GROUP1_SUB3,					//1 bits for group priority and 3 bits for sub priority
	GROUP0_SUB4						//0 bits for group priority and 4 bits for sub priority

}SCB_PriGroup_t;

uint8_t SCB_u8SetPriorityGroup(SCB_PriGroup_t copy_u8PriGroup);
#endif
