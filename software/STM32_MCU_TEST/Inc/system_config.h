/* system_config.h - Runtime configuration, NO hardcoded values */
#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include <stdint.h>
#include <stdbool.h>

/* ============================================================================
   SYSTEM CONFIGURATION STRUCTURE
   All values loaded via Modbus at startup - NO HARDCODED DEFAULTS
   ============================================================================ */

typedef struct {
    // Motor configuration
    uint32_t motor_ppr;                      // Motor driver pulses per revolution
    uint32_t motor_max_rpm;                  // Maximum motor RPM
    
    // Gearbox (motor to shaft)
    uint32_t motor_to_shaft_gear_ratio;      // Gearbox reduction ratio
    uint32_t shaft_max_rpm;                  // Maximum shaft RPM
    
    // Encoder configuration
    uint32_t encoder_ppr;                    // Encoder pulses per revolution
    uint32_t encoder_to_shaft_pulley_ratio;  // Pulley ratio (encoder:shaft)
    
    // Limit switches (from homing)
    float limit_sw1_deg;                     // Limit switch 1 angle
    float limit_sw2_deg;                     // Limit switch 2 angle
    
    // PID gains
    float pid_p;                             // Proportional gain
    float pid_i;                             // Integral gain
    float pid_d;                             // Derivative gain
    
    // Calculated values (computed from above)
    uint32_t encoder_counts_per_shaft_rev;   // Precomputed for performance
    float deg_per_encoder_count;             // Precomputed for performance
    float counts_per_degree;                 // Precomputed for performance
    
} SystemConfig_t;

/* ============================================================================
   GLOBAL CONFIGURATION INSTANCE
   ============================================================================ */

extern SystemConfig_t g_config;

/* ============================================================================
   CONFIGURATION FUNCTIONS
   ============================================================================ */

void Config_Init(void);
void Config_Update_Calculations(void);
bool Config_Validate(void);

/* ============================================================================
   CONVERSION FUNCTIONS - Use runtime config, not hardcoded values
   ============================================================================ */

/* Encoder Count ↔ Shaft Degrees */
static inline float Encoder_To_Shaft_Degrees(int32_t encoder_count)
{
    return (float)encoder_count * g_config.deg_per_encoder_count;
}

static inline int32_t Shaft_Degrees_To_Encoder(float shaft_degrees)
{
    return (int32_t)(shaft_degrees * g_config.counts_per_degree);
}

/* Shaft RPM ↔ Motor RPM */
static inline float Shaft_RPM_To_Motor_RPM(float shaft_rpm)
{
    return shaft_rpm * (float)g_config.motor_to_shaft_gear_ratio;
}

static inline float Motor_RPM_To_Shaft_RPM(float motor_rpm)
{
    return motor_rpm / (float)g_config.motor_to_shaft_gear_ratio;
}

/* Shaft RPM ↔ Encoder RPM */
static inline float Shaft_RPM_To_Encoder_RPM(float shaft_rpm)
{
    return shaft_rpm * (float)g_config.encoder_to_shaft_pulley_ratio;
}

static inline float Encoder_RPM_To_Shaft_RPM(float encoder_rpm)
{
    return encoder_rpm / (float)g_config.encoder_to_shaft_pulley_ratio;
}

/* Shaft Degrees → Motor Pulses */
static inline uint32_t Shaft_Degrees_To_Motor_Pulses(float shaft_degrees)
{
    float shaft_revolutions = shaft_degrees / 360.0f;
    float motor_revolutions = shaft_revolutions * (float)g_config.motor_to_shaft_gear_ratio;
    return (uint32_t)(motor_revolutions * (float)g_config.motor_ppr);
}

#endif /* SYSTEM_CONFIG_H */
