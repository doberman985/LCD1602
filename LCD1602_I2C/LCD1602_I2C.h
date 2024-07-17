
#ifndef LCD1602_I2C_H_
#define LCD1602_I2C_H_
#include "main.h"


#define CLEAR_DISPLAY				0x01		// ����� �������
#define RETURN_HOME					0x02		// ������� � �������� ���������
#define ENTRY_MODE_SET_RIGHT		0x07		// ����������� �������� ������� ������
#define ENTRY_MODE_SET_LEFT			0x05		// ����������� �������� ������� �����
#define DISPLAY_ON					0x0C		// �������� �������
#define ON_CURSOR					0x0A		// �������� ������
#define ON_BLINK					0x09		// �������� ������� �������
#define CURSOR_SHIFT_RIGHT			0x14		// ����� ������� ������
#define CURSOR_SHIFT_LEFT			0x10		// ����� ������� �����
#define SCROOL_DISPLAY_RIGHT		0x1C		// ����� ������ ������
#define SCROOL_DISPLAY_LEFT			0x18		// ����� ������ �����
#define BITS8_DATA_TRANSMIT			0x30		// 8-� ������ �������� ������
#define BITS4_DATA_TRANSMIT			0x20		// 4-� ������ �������� ������

#define	I2C_DDR						DDRA
#define I2C_PORT					PORTA
#define I2C_PIN						PINA
#define SDA							0
#define SCL							1
#define I2C_STATUS					(1<<0)
#define SCL1						I2C_PORT |=(1<<SCL)
#define SCL0						I2C_PORT &=~(1<<SCL)

void i2c_start_callback(void);
void i2c_stop_callback(void);
void i2c_send(int data);







#endif 