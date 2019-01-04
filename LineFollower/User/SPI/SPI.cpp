#include "stm32f4xx.h"
#include "SPI.h"


bool SPICom::transceive(uint8_t* txData,uint32_t txDataLen, uint8_t* rxBuffer, uint32_t rxBufferLen)
{ 
    for(int i=0; i<txDataLen; i++)
    {
        while(((m_SPIx)->SR & (SPI_SR_TXE | SPI_SR_RXNE)) == 0 || ((m_SPIx)->SR & SPI_SR_BSY));
        /* Fill output buffer with data */  
        m_SPIx->DR = txData[i];
        /* Wait for transmission to complete */
        while(((m_SPIx)->SR & (SPI_SR_TXE | SPI_SR_RXNE)) == 0 || ((m_SPIx)->SR & SPI_SR_BSY));
        
        /* Return data from buffer */
        rxBuffer[i] = m_SPIx->DR;
    }
    return true;  
}
void SPICom::initialize(SPI_TypeDef* SPIx,GPIO_TypeDef* GpioPort,uint8_t Pin)
{
    m_SPIx = SPIx;
    m_GpioPort = GpioPort;
    m_Pin = Pin;
}

bool SPICom::acquire()
{
    m_GpioPort -> BSRRH |= m_Pin; 
    return true;
}
void SPICom::release()
{
    m_GpioPort -> BSRRL = m_Pin; 
}

 // in consideration, in transmit receive or not
uint8_t SPICom::isError()
{}

