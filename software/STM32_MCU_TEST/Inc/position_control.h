/* position_control.h - Position/velocity control */
#ifndef POSITION_CONTROL_H
#define POSITION_CONTROL_H

#include <stdint.h>

void Position_Control_Init(void);
void Position_Control_Update(void);
void Update_Shaft_Position(void);
float Calculate_Shaft_RPM(void);

extern TIM_HandleTypeDef htim2;

#endif /* POSITION_CONTROL_H */
