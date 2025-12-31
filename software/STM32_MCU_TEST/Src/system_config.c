/* system_config.c - Configuration management */

#include "system_config.h"
#include <string.h>

SystemConfig_t g_config;

void Config_Init(void)
{
    memset(&g_config, 0, sizeof(SystemConfig_t));
    g_config.deg_per_encoder_count = 0.0f;
    g_config.counts_per_degree = 0.0f;
    g_config.encoder_counts_per_shaft_rev = 0;
}

void Config_Update_Calculations(void)
{
    if (g_config.encoder_ppr == 0 || g_config.encoder_to_shaft_pulley_ratio == 0) {
        g_config.encoder_counts_per_shaft_rev = 0;
        g_config.deg_per_encoder_count = 0.0f;
        g_config.counts_per_degree = 0.0f;
        return;
    }
    
    g_config.encoder_counts_per_shaft_rev = 
        g_config.encoder_ppr * 4 * g_config.encoder_to_shaft_pulley_ratio;
    
    g_config.deg_per_encoder_count = 
        360.0f / (float)g_config.encoder_counts_per_shaft_rev;
    
    g_config.counts_per_degree = 
        (float)g_config.encoder_counts_per_shaft_rev / 360.0f;
}

bool Config_Validate(void)
{
    if (g_config.motor_ppr == 0) return false;
    if (g_config.motor_to_shaft_gear_ratio == 0) return false;
    if (g_config.encoder_ppr == 0) return false;
    if (g_config.encoder_to_shaft_pulley_ratio == 0) return false;
    
    if (g_config.motor_ppr > 10000) return false;
    if (g_config.encoder_ppr > 10000) return false;
    if (g_config.motor_to_shaft_gear_ratio > 1000) return false;
    if (g_config.encoder_to_shaft_pulley_ratio > 100) return false;
    
    if (g_config.pid_p < 0.0f) return false;
    if (g_config.pid_i < 0.0f) return false;
    if (g_config.pid_d < 0.0f) return false;
    
    return true;
}
