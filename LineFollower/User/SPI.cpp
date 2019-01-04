#include "stm32f4xx.h"
#include "SPI.h"
using namespace STM32F407;

uint8_t m_flagPort = 0;

const uint8_t PORT_COUNT = 6;
volatile bool SPI::m_portLock[PORT_COUNT] = {0};

SPI::SPI()
{
    m_SPIx = NULL;            
    m_gpioPort = NULL;
    m_pin = NULL;
}

bool SPI::transceive(uint8_t* txData,uint32_t txDataLen, uint8_t* rxBuffer)
{ 
    for(int i=0; i<txDataLen; i++)
    {
        while(!((m_SPIx)->SR & SPI_SR_TXE));
        m_SPIx->DR = txData[i];
        while(!((m_SPIx)->SR & SPI_SR_RXNE));
        rxBuffer[i] = m_SPIx->DR;
    } 
    while (m_SPIx->SR & SPI_SR_BSY);
    return true; //harusnya ada return false-nya, cek kalau error
}
void SPI::initialize(SPI_TypeDef* SPIx,GPIO_TypeDef* GpioPort,uint16_t Pin)
{
    m_SPIx = SPIx;
    m_gpioPort = GpioPort;
    m_pin = Pin;
    
    if(m_SPIx == SPI1)
    {
        m_flagPort =0;
    }
    else if(m_SPIx == SPI2)
    {
        m_flagPort =1;
    }
    else if(m_SPIx == SPI3)
    {
        m_flagPort =2;
    }
    else if(m_SPIx == SPI4)
    {
        m_flagPort =3;
    }
    else if(m_SPIx == SPI5)
    {
        m_flagPort =4;
    }
    else if(m_SPIx == SPI6)
    {
        m_flagPort =5;
    }
}

bool SPI::acquire()
{
    if(m_portLock[m_flagPort])
    {
        return false;
    }
    m_portLock[m_flagPort] = true;
    m_gpioPort -> BSRRH = 0x01 << m_pin;
    return true;
}
void SPI::release()
{
    m_portLock[m_flagPort] = false;
    m_gpioPort -> BSRRL = 0x01 << m_pin;
}

uint8_t SPI::isError()
{}
