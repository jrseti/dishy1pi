/* modbus_registers.c - Modbus register storage */

#include "modbus_registers.h"
#include <string.h>

uint16_t modbus_registers[MODBUS_REG_COUNT];

uint32_t Modbus_Read_Uint32(uint16_t reg_high)
{
    return ((uint32_t)modbus_registers[reg_high] << 16) | 
            modbus_registers[reg_high + 1];
}

void Modbus_Write_Uint32(uint16_t reg_high, uint32_t value)
{
    modbus_registers[reg_high] = (value >> 16) & 0xFFFF;
    modbus_registers[reg_high + 1] = value & 0xFFFF;
}

float Modbus_Read_Float32(uint16_t reg_high)
{
    union {
        float f;
        uint32_t u;
    } converter;
    
    converter.u = ((uint32_t)modbus_registers[reg_high] << 16) | 
                   modbus_registers[reg_high + 1];
    return converter.f;
}

void Modbus_Write_Float32(uint16_t reg_high, float value)
{
    union {
        float f;
        uint32_t u;
    } converter;
    
    converter.f = value;
    modbus_registers[reg_high] = (converter.u >> 16) & 0xFFFF;
    modbus_registers[reg_high + 1] = converter.u & 0xFFFF;
}
