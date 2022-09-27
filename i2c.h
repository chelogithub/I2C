/*******************************************************************************
*	Declaraciones de la LibrÍa
*
*	Funciones para utilizar para guardado de datos i2c
*
*	Autor: Marcelo García
*
*******************************************************************************/
#include "main.h"
#define READ 0
#define WRITE 1
struct I2C
{
	char _net[32];					//Nombre de la red WIFI  a conectaraurt
	char _pass[10];					//Password de la red WIFI
	char _TCPServer[16];			//IP del Servidor TCP
	char _TCPPort[5];				//Puerto del Servidor TCP
	char _addr_net[2];				//Dirección de nombre de red
	char _addr_net_pass[2];			//Dirección de password
	char _addr_tcp[2];				//Dirección de servidor TCP
	char _addr_tcp_port[2];			//Dirección de Puerto
	char _send[64];					//Vector utilizado para enviar datos
	char _receive[64];				//Vector utilizado para recibir datos
	char _serial[64];
	int  _rw;						//Comando de lectura, escritura

};
void I2C_E2PROM( I2C_HandleTypeDef *, unsigned char *, int , unsigned char *, int , unsigned char *, int );
/*----------------------------------------------
Realiza, lectura o escritura en le EEPROM de acuerdo a los
datos colocados en la estructura

I2C_HandleTypeDef 	//i2c a utilizar
unsigned char		//Vector de direccion
int					//Cantidad de elementos
unsigned char		//Vector de datos a enviar
int					//Cantidad de elementos
unsigned char		//Vector de datos para enviar o recibir
int 				//Operación rw

rw					0=LEER 1= ESCRIBIR
-----------------------------------------------*/
