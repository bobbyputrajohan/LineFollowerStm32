#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "Gyro.h"
#include "Delay.h" 

SPICom *SPIGyro = NULL;
const float Gyro::RADIAN = 0.01745329252;
bool Gyro::initSPIGyro(SPICom *SPIInit,uint8_t frequency,uint8_t scale)
{
    uint8_t tx[2],rx[2];
    SPIGyro = SPIInit;
    if(SPIGyro == NULL)
    {
        return false;
    }
    
    tx[0] = 0x20 & WRITEDATA; //cntl 1 
    tx[1] = 0x0f | frequency;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,2,rx,2);
    SPIGyro->release();
    
    tx[0] = 0x21 & WRITEDATA; //cntl 2
    tx[1] = 0x00;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,2,rx,2);
    SPIGyro->release();
    
    tx[0] = 0x22 & WRITEDATA; //cntl 3
    tx[1] = 0x00;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,2,rx,2);
    SPIGyro->release();
    
    tx[0] = 0x23 & WRITEDATA; //cntl 4
    tx[1] = 0x00 | scale;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,2,rx,2);
    SPIGyro->release();
    
    tx[0] = 0x24 & WRITEDATA; //cntl 5
    tx[1] = 0x00;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,2,rx,2);
    SPIGyro->release();
    
    switch(scale)
    {
        case 0x00:
            setSensitivity(0.00875f);
        break;
        case 0x10:
            setSensitivity(0.0175f);
        break;
        case 0x30:
            setSensitivity(0.07f);
        break;
        default :
            getSensitivity();
    }
    return true;
}

float Gyro::receiveDataGyroX()
{
    uint8_t tx[3],rx[3];
    tx[0] = 0x28 | READDATAC;
    tx[1] = 0x00;
    tx[2] = 0x00;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,3,rx,3);
    SPIGyro->release();
    int16_t dataX = rx[1] | rx[2]<<8;
    float dataGyroX = ((dataX * getSensitivity()) * RADIAN);
    return dataGyroX;
}

float Gyro::receiveDataGyroY()
{
    uint8_t tx[3],rx[3];
    tx[0] = 0x2A | READDATAC;
    tx[1] = 0x00;
    tx[2] = 0x00;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,3,rx,3);
    SPIGyro->release();
    int16_t dataY = rx[1] | rx[2]<<8;
    float dataGyroY = ((dataY * getSensitivity()) * RADIAN);
    return dataGyroY;
}

float Gyro::receiveDataGyroZ()
{
    uint8_t tx[3],rx[3];
    tx[0] = 0x2C | READDATAC;
    tx[1] = 0x00;
    tx[2] = 0x00;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,3,rx,3);
    SPIGyro->release();
    int16_t dataZ = rx[1] | rx[2]<<8;
    float dataGyroZ = ((dataZ * getSensitivity()) * RADIAN);
    return dataGyroZ;
}

void Gyro::writeRegister(uint8_t address, uint8_t data)
{
    uint8_t tx[2], rx[2];
    tx[0] = address & WRITEDATA;
    tx[1] = data;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,2,rx,2);
    SPIGyro->release();
}

uint8_t Gyro::readRegister(uint8_t address)
{
    uint8_t tx[2], rx[2],read;
    tx[0] = address | READDATANC;
    tx[1] = 0x00;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,2,rx,2);
    SPIGyro->release();
    return rx[1];
}

float Gyro::getSensitivity()
{
    return m_Sensitivity;
}

void Gyro::setSensitivity(float sensitivityDps)
{
    m_Sensitivity = sensitivityDps;
}

void Gyro::getDataGyroXYZ(float *dataGyroX,float *dataGyroY,float *dataGyroZ)
{
    volatile int16_t tempX,tempY,tempZ,tempZ1; 
    uint8_t tx[7],rx[7];
    tx[0] = GYROXL | READDATAC;
    tx[1] = 0x00; 
    tx[2] = 0x00; 
    tx[3] = 0x00;
    tx[4] = 0x00; 
    tx[5] = 0x00;
    tx[6] = 0x00; 
    
    SPIGyro->acquire();
    SPIGyro->transceive(tx,7,rx,7);
    SPIGyro->release();
    
    *dataGyroX = (((int16_t)(rx[1] | rx[2]<<8)) * getSensitivity()) * RADIAN;
    *dataGyroY = (((int16_t)(rx[3] | rx[4]<<8)) * getSensitivity()) * RADIAN;
    *dataGyroZ = (((int16_t)(rx[5] | rx[6]<<8)) * getSensitivity()) * RADIAN;
}