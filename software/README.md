# Software for the Dish Controller

Nothing here yet. This will be the source code of the software that runs on the RaspberryPi Hat. Probably a mixture of C and Python.

# Project Description for Claude

I have created a PCB and want to create a test procedure to make sure all the Communication and I/O is working.

The MCU is the STM32G431KBT6TR.

Attached is the PCB schematic and the STM32Cube IOC file.

The board will have the following external devices connected:
1. An encoder, the E6B2-CWZ6C/2000PPR will connect to CN7
2. A motor controller, the DM556Y, will be connected to CN8
3. 2 limit switches connected to CN7
4. UART-TX/RX on CN4 connected to a raspberry Pi for RS232 communication.
5. The I2C connector, CN3, will have several I2C sensors connected. For this testing the sesors will be the Adafruit SHT45 Pressure and humidity sensor, and the ADXL435 Tripple-Axis Accelerometer.
6. The board will be programmed and debugged using the 2-wire connector.
7. The SW1 switch will set the 3-bit address of the board. The address is used as the address for the MODBUS over RS232.

This test procedure will be comprised of 3 things I want you to create for me.

1. A Python program that runs on the raspberry pi. This communicates with the PCB over RS232 using a ModBus protocol. 

2. Develop a protocol for the Python and PCB to communicate over ModBus.

- rrr



