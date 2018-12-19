#include <stdint.h>
#include <stdio.h>
#include "SPI.h"

SPI *SPI1 = NULL;
void initSPIGyro(SPI *SPIGyro)
{
    SPI1=SPIGyro;
}
void transmitDataGyro(uint8_t data)
{
   SPI1->SPISendWrite(data);
}

uint8_t receiveDataGyro(uint16_t data)
{
    SPI1->SPISendReadAdd(data);
}

