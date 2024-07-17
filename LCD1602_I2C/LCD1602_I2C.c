#include "LCD1602_I2C.h"
uint8_t i2c_state = 0;

void i2c_ini(void)
{
	
}

void i2c_start_callback(void) {
	// Установка флага, что начата передача по I2C
	i2c_state |= I2C_STATUS;

	// Установка линии данных (SDA) в состояние "Низкий"
	I2C_DDR |= (1 << SDA);
	I2C_PORT &= ~(1 << SDA);
	

	// Подождать 4.7 мкс (согласно спецификации I2C)
	_delay_us(4.7);

	// Установка линии тактовой частоты (SCL) в состояние "Низкий"
	I2C_DDR |= (1 << SCL);
	I2C_PORT &= ~(1 << SCL);
	

	// Подождать 4.0 мкс (согласно спецификации I2C)
	_delay_us(4.0);
}

void i2c_stop_callback(void) {
	// Установка флага, что начата передача по I2C
	i2c_state &= ~I2C_STATUS;

	// Установка линии тактовой частоты (SCL) в состояние "Высокий"
	I2C_DDR &=~(1 << SCL);
	I2C_PORT |= (1 << SCL);
	

	// Подождать 4.0 мкс (согласно спецификации I2C)
	_delay_us(4.0);
	
	// Установка линии данных (SDA) в состояние "Высокий"
	I2C_DDR &=~(1 << SDA);
	I2C_PORT |= (1 << SDA);
	

	// Подождать 4.7 мкс (согласно спецификации I2C)
	_delay_us(4.7);
}

void i2c_send_byte(int data)
{
	uint8_t n = 8;
	while(n--)
	{
		if(data & (1<<7))
		{
			SCL1;
			I2C_PORT |=(1<<SDA);
			SCL0;
		}
		else
		{
			SCL1;
			I2C_PORT &=~(1<<SDA);
			SCL0;
		}
		data <<= 1;
	}
}

void i2c_set_adress(void)
{
	i2c_send_byte(0x4E);
}

uint8_t i2c_recive_ack(void)
{
	I2C_DDR &=~(1<<SDA);
	SCL1;
	if(!(I2C_PIN & (1<<SDA)))
	{
		SCL0;
		I2C_DDR |=(1<<SDA);
		return 1;
	}
	else
	{
		SCL0;
		I2C_DDR |=(1<<SDA);
		return 0;
	}
}

void i2c_send_string(char* string)
{
	uint8_t n = 0;
	while(string[n])
	{
		i2c_send_byte(string[n]);
		if(i2c_recive_ack())
		{
			i2c_stop_callback();
		}
		n++;
	}
}

void i2c_send(int data)
{
	i2c_start_callback();
	i2c_set_adress();
	if(i2c_recive_ack())
	{
		i2c_send_byte(data);
	}
	else
	{
		i2c_stop_callback();
	}
}