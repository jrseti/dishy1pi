/* motor_control.h - Motor hardware interface */
#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <stdint.h>
#include <stdbool.h>
#include "main.h"

void Motor_Init(void);
void Motor_Set_RPM(float motor_rpm);
void Motor_Set_Direction(uint8_t direction);
void Motor_Set_Enable(bool enable);
void Motor_Stop(void);

extern TIM_HandleTypeDef htim3;

#endif /* MOTOR_CONTROL_H */