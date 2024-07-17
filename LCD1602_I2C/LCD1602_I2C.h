
#ifndef LCD1602_I2C_H_
#define LCD1602_I2C_H_
#include "main.h"


#define CLEAR_DISPLAY				0x01		// Сброс дисплея
#define RETURN_HOME					0x02		// Вернуть в домашнее положение
#define ENTRY_MODE_SET_RIGHT		0x07		// Направление движения курсора вправо
#define ENTRY_MODE_SET_LEFT			0x05		// Направление движения курсора влево
#define DISPLAY_ON					0x0C		// Включить дисплей
#define ON_CURSOR					0x0A		// Включить курсор
#define ON_BLINK					0x09		// Включить мигание курсора
#define CURSOR_SHIFT_RIGHT			0x14		// Сдвиг курсора вправо
#define CURSOR_SHIFT_LEFT			0x10		// Сдвиг курсора влево
#define SCROOL_DISPLAY_RIGHT		0x1C		// Сдвиг экрана вправо
#define SCROOL_DISPLAY_LEFT			0x18		// Сдвиг экрана влево
#define BITS8_DATA_TRANSMIT			0x30		// 8-и битная передача данных
#define BITS4_DATA_TRANSMIT			0x20		// 4-х битная передача данных

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