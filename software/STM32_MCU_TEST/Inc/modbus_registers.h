/* modbus_registers.h - Modbus register map definitions */
#ifndef MODBUS_REGISTERS_H
#define MODBUS_REGISTERS_H

#include <stdint.h>

/* Total register count */
#define MODBUS_REG_COUNT 128

/* ============================================================================
   CONFIGURATION REGISTERS (0x0000 - 0x0015)
   ============================================================================ */

#define REG_MOTOR_PPR_HIGH              0x0000
#define REG_MOTOR_PPR_LOW               0x0001
#define REG_MOTOR_TO_SHAFT_RATIO_HIGH   0x0002
#define REG_MOTOR_TO_SHAFT_RATIO_LOW    0x0003
#define REG_SHAFT_MAX_RPM_HIGH          0x0004
#define REG_SHAFT_MAX_RPM_LOW           0x0005
#define REG_MOTOR_MAX_RPM_HIGH          0x0006
#define REG_MOTOR_MAX_RPM_LOW           0x0007
#define REG_ENCODER_PPR_HIGH            0x0008
#define REG_ENCODER_PPR_LOW             0x0009
#define REG_ENCODER_PULLEY_RATIO_HIGH   0x000A
#define REG_ENCODER_PULLEY_RATIO_LOW    0x000B
#define REG_LIMIT_SW1_DEG_HIGH          0x000C
#define REG_LIMIT_SW1_DEG_LOW           0x000D
#define REG_LIMIT_SW2_DEG_HIGH          0x000E
#define REG_LIMIT_SW2_DEG_LOW           0x000F
#define REG_PID_P_HIGH                  0x0010
#define REG_PID_P_LOW                   0x0011
#define REG_PID_I_HIGH                  0x0012
#define REG_PID_I_LOW                   0x0013
#define REG_PID_D_HIGH                  0x0014
#define REG_PID_D_LOW                   0x0015

/* ============================================================================
   OPERATIONAL REGISTERS (0x0020 - 0x002F)
   ============================================================================ */

#define REG_MOTOR_ENABLE                0x0020
#define REG_MOTOR_DIR                   0x0021
#define REG_SHAFT_COMMAND_DEG_HIGH      0x0022
#define REG_SHAFT_COMMAND_DEG_LOW       0x0023
#define REG_SHAFT_COMMAND_RPM_HIGH      0x0024
#define REG_SHAFT_COMMAND_RPM_LOW       0x0025
#define REG_HOMING                      0x0026

/* ============================================================================
   STATUS REGISTERS (0x0030 - 0x003F)
   ============================================================================ */

#define REG_SHAFT_ACTUAL_DEG_HIGH       0x0030
#define REG_SHAFT_ACTUAL_DEG_LOW        0x0031
#define REG_SHAFT_ACTUAL_RPM_HIGH       0x0032
#define REG_SHAFT_ACTUAL_RPM_LOW        0x0033
#define REG_MOTOR_COMMAND_PWM_HIGH      0x0034
#define REG_MOTOR_COMMAND_PWM_LOW       0x0035
#define REG_MOTOR_COMMAND_RPM_HIGH      0x0036
#define REG_MOTOR_COMMAND_RPM_LOW       0x0037
#define REG_ERROR_CODE_HIGH             0x0038
#define REG_ERROR_CODE_LOW              0x0039
#define REG_FIRMWARE_VERSION_HIGH       0x003A
#define REG_FIRMWARE_VERSION_LOW        0x003B
#define REG_SYSTEM_STATUS               0x003C

/* ============================================================================
   TIMESTAMP REGISTERS (0x0050 - 0x0057)
   ============================================================================ */

#define REG_UNIX_TIMESTAMP_US_0         0x0050  // Unix timestamp μs (bits 63:48)
#define REG_UNIX_TIMESTAMP_US_1         0x0051  // Unix timestamp μs (bits 47:32)
#define REG_UNIX_TIMESTAMP_US_2         0x0052  // Unix timestamp μs (bits 31:16)
#define REG_UNIX_TIMESTAMP_US_3         0x0053  // Unix timestamp μs (bits 15:0)
#define REG_TIMESTAMP_SYNC_COUNT        0x0054  // Number of syncs received
#define REG_TIMESTAMP_AGE_MS_HIGH       0x0055  // Age of last sync (high word)
#define REG_TIMESTAMP_AGE_MS_LOW        0x0056  // Age of last sync (low word)
#define REG_TIMESTAMP_STATUS            0x0057  // Status flags

/* ============================================================================
   SYSTEM STATUS BITS (REG_SYSTEM_STATUS 0x003C)
   ============================================================================ */

#define STATUS_MOTOR_ENABLED            (1 << 0)
#define STATUS_MOTOR_MOVING             (1 << 1)
#define STATUS_LIMIT_SW1                (1 << 2)
#define STATUS_LIMIT_SW2                (1 << 3)
#define STATUS_Z_PULSE                  (1 << 4)
#define STATUS_HOMING                   (1 << 5)
#define STATUS_PID_ACTIVE               (1 << 6)
#define STATUS_ERROR                    (1 << 7)
#define STATUS_AT_TARGET                (1 << 8)
#define STATUS_CONSTANT_RPM             (1 << 9)

/* ============================================================================
   TIMESTAMP STATUS BITS (REG_TIMESTAMP_STATUS 0x0057)
   ============================================================================ */

#define TIMESTAMP_STATUS_VALID          (1 << 0)  // Timestamp is valid
#define TIMESTAMP_STATUS_SYNC_NEEDED    (1 << 1)  // Sync needed (>5 min)
#define TIMESTAMP_STATUS_STALE          (1 << 2)  // Timestamp stale (>10 min)

/* ============================================================================
   ERROR CODES
   ============================================================================ */

#define ERROR_NONE                      0x0000
#define ERROR_CONFIG_INVALID            0x0001
#define ERROR_ENCODER_FAULT             0x0002
#define ERROR_MOTOR_FAULT               0x0003
#define ERROR_LIMIT_SWITCH_FAULT        0x0004
#define ERROR_HOMING_FAILED             0x0005
#define ERROR_POSITION_ERROR_LARGE      0x0006
#define ERROR_MODBUS_CRC                0x0007
#define ERROR_MODBUS_TIMEOUT            0x0008

/* ============================================================================
   GLOBAL REGISTER STORAGE
   ============================================================================ */

extern uint16_t modbus_registers[MODBUS_REG_COUNT];

/* ============================================================================
   HELPER FUNCTIONS
   ============================================================================ */

uint32_t Modbus_Read_Uint32(uint16_t reg_high);
void Modbus_Write_Uint32(uint16_t reg_high, uint32_t value);
float Modbus_Read_Float32(uint16_t reg_high);
void Modbus_Write_Float32(uint16_t reg_high, float value);

#endif /* MODBUS_REGISTERS_H */
