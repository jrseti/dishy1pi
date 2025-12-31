/* homing.h - Homing procedure */
#ifndef HOMING_H
#define HOMING_H

#include <stdbool.h>

typedef enum {
    HOMING_IDLE,
    HOMING_FAST_TO_SW1,
    HOMING_BACKUP_FROM_SW1,
    HOMING_SLOW_TO_SW1,
    HOMING_FAST_TO_SW2,
    HOMING_DONE
} HomingState_t;

void Homing_Init(void);
void Homing_Start(void);
void Homing_Update(void);
bool Homing_IsComplete(void);

#endif /* HOMING_H */