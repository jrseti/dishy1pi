/* pid_controller.h - PID algorithm */
#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <stdint.h>

typedef struct {
    float kp, ki, kd;
    float setpoint;
    float error_sum;
    float last_error;
    float out_min, out_max;
    uint32_t last_time_ms;
} PID_t;

void PID_Init(PID_t *pid, float kp, float ki, float kd, float out_min, float out_max);
float PID_Update(PID_t *pid, float measured_value);
void PID_Reset(PID_t *pid);
void PID_SetGains(PID_t *pid, float kp, float ki, float kd);

#endif /* PID_CONTROLLER_H */