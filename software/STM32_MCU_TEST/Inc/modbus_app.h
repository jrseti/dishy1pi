/* modbus_app.h - Modbus RTU protocol handler */
#ifndef MODBUS_APP_H
#define MODBUS_APP_H

#include <stdint.h>
#include <stdbool.h>
#include "main.h"

#define MODBUS_SLAVE_ADDRESS    1
#define MODBUS_BAUDRATE         115200
#define MODBUS_TIMEOUT_MS       1000

#define MODBUS_FC_READ_HOLDING_REGISTERS    0x03
#define MODBUS_FC_WRITE_SINGLE_REGISTER     0x06
#define MODBUS_FC_WRITE_MULTIPLE_REGISTERS  0x10

#define MODBUS_EXCEPTION_ILLEGAL_FUNCTION   0x01
#define MODBUS_EXCEPTION_ILLEGAL_ADDRESS    0x02
#define MODBUS_EXCEPTION_ILLEGAL_VALUE      0x03

void Modbus_Init(void);
void Modbus_Poll(void);
void Modbus_Load_Config_From_Registers(void);
void Modbus_Save_Config_To_Registers(void);
void Modbus_Load_Timestamp_From_Registers(void);
void Modbus_Update_Timestamp_Status(void);

extern UART_HandleTypeDef huart1;

#endif /* MODBUS_APP_H */