#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "Gyro.h"
#include "Delay.h" 

const float GyroL3Gxxxx::RADIAN = 0.01745329252;

bool GyroL3Gxxxx::initSPIGyro(SPI *SPIInit,uint8_t frequency,uint8_t scale)
{
    SPIGyro = SPIInit;
    if(SPIGyro == NULL)
    {
        return false;
    }
    
    writeRegister(REG_CTRL1, VAL_C1_ENABLE_Y_AXIS | VAL_C1_ENABLE_X_AXIS | VAL_C1_POWER_MODE_UP | VAL_C1_ENABLE_Z_AXIS | frequency);
    writeRegister(REG_CTRL2, DEFAULT_MODE_CTRL2);
    writeRegister(REG_CTRL3, DEFAULT_MODE_CTRL3);
    writeRegister(REG_CTRL4, DEFAULT_MODE_CTRL4 | scale);
    writeRegister(REG_CTRL5, DEFAULT_MODE_CTRL5);
    setSensitivityGyroDPS(scale);
    return true;
}

float GyroL3Gxxxx::getDataVelGyroXRad()
{
    uint8_t tx[3],rx[3];
    tx[0] = REG_GYROXL | READ_DATA_C;
    tx[1] = 0x00;
    tx[2] = 0x00;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,3,rx);
    SPIGyro->release();
    float dataGyroX = ((((int16_t)(rx[1]|rx[2]<<8)) * getSensitivityGyroDPS()) * RADIAN);
    return dataGyroX;
}

float GyroL3Gxxxx::getDataVelGyroYRad()
{
    uint8_t tx[3],rx[3];
    tx[0] = REG_GYROYL | READ_DATA_C;
    tx[1] = 0x00;
    tx[2] = 0x00;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,3,rx);
    SPIGyro->release();
    float dataGyroY = ((((int16_t)(rx[1]|rx[2]<<8)) * getSensitivityGyroDPS()) * RADIAN);
    return dataGyroY;
}

float GyroL3Gxxxx::getDataVelGyroZRad()
{
    uint8_t tx[3],rx[3];
    tx[0] = REG_GYROZL | READ_DATA_C;
    tx[1] = 0x00;
    tx[2] = 0x00;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,3,rx);
    SPIGyro->release();
    float dataGyroZ = ((((int16_t)(rx[1]|rx[2]<<8)) * getSensitivityGyroDPS()) * RADIAN);
    return dataGyroZ;
}

void GyroL3Gxxxx::writeRegister(uint8_t address, uint8_t data)
{
    uint8_t tx[2], rx[2];
    tx[0] = address & WRITE_DATA;
    tx[1] = data;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,2,rx);
    SPIGyro->release();
}

uint8_t GyroL3Gxxxx::readRegister(uint8_t address)
{
    uint8_t tx[2], rx[2],read;
    tx[0] = address | READ_DATA_NC;
    tx[1] = 0x00;
    SPIGyro->acquire();
    SPIGyro->transceive(tx,2,rx);
    SPIGyro->release();
    return rx[1];
}

float GyroL3Gxxxx::getSensitivityGyroDPS()
{
    return m_Sensitivity;
}

void GyroL3Gxxxx::setSensitivityGyroDPS(uint8_t scale)
{
    switch(scale)
    {
        case VAL_C4_SCALE250DPS:
            m_Sensitivity = 0.00875f;
        break;
        case VAL_C4_SCALE500DPS:
            m_Sensitivity = 0.0175f;
        break;
        case VAL_C4_SCALE2000DPS:
            m_Sensitivity = 0.07f;
        break;
        default :
            getSensitivityGyroDPS();
    }
}

void GyroL3Gxxxx::getDataVelGyroXYZRad(float *dataGyroX,float *dataGyroY,float *dataGyroZ)
{
    volatile int16_t tempX,tempY,tempZ,tempZ1; 
    uint8_t tx[7],rx[7];
    tx[0] = REG_GYROXL | READ_DATA_C;
    tx[1] = 0x00; 
    tx[2] = 0x00; 
    tx[3] = 0x00;
    tx[4] = 0x00; 
    tx[5] = 0x00;
    tx[6] = 0x00; 
    
    SPIGyro->acquire();
    SPIGyro->transceive(tx,7,rx);
    SPIGyro->release();
    
    *dataGyroX = (((int16_t)(rx[1] | rx[2]<<8)) * getSensitivityGyroDPS()) * RADIAN;
    *dataGyroY = (((int16_t)(rx[3] | rx[4]<<8)) * getSensitivityGyroDPS()) * RADIAN;
    *dataGyroZ = (((int16_t)(rx[5] | rx[6]<<8)) * getSensitivityGyroDPS()) * RADIAN;
}