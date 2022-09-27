/*******************************************************************************
*	Codigo de las funciones
*
*	Funciones para guardar y leer datos en I2C
*
*	Autor: Marcelo García
*
*******************************************************************************/
#include "i2c.h"
#include "STR_Chelo.h"
#include "main.h"


void I2C_E2PROM( I2C_HandleTypeDef * i2c, unsigned char *a, int b, unsigned char *c, int d, unsigned char * e, int f)
{
	if (f==1)
	{
			int LGT=0;
			while (HAL_I2C_IsDeviceReady(i2c, 0xA0, 3, 100) != HAL_OK) {}
			LGT=STRNACT_ADV(e, 0, a, 2);					//Se agrega al de envío la direccion
			LGT=STRNACT_ADV(e, 2, c, strlen(c));			//Se agrega al de envío la info a enviar
			HAL_I2C_Master_Transmit(i2c,0xA0,(uint8_t *)e,LGT, 2);	//Se transmite todo
			HAL_Delay(1);

			//Me falta la fabricacion del vector a enviar a la eeprom
	}
	else	//Lectura
	{
			while (HAL_I2C_IsDeviceReady(i2c, 0xA0, 3, 100) != HAL_OK) {}

			HAL_I2C_Master_Transmit(i2c,0xA0,(uint8_t *)a,b, 1);	//Se envia la direccion a partir de la cual se quiere leer
			HAL_Delay(1);
			HAL_I2C_Master_Receive(i2c,0xA1,(uint8_t *)e,d, 4);	//Se recibe ka cab

	}
}
