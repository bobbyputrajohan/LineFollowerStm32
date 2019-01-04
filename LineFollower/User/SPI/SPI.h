#include "PeriphInterface.h"
#include "stm32f4xx_spi.h"

class SPICom : public ISpi
{
    public:
        SPICom(){}
        ~SPICom(){}
        void initialize(SPI_TypeDef* SPIx,GPIO_TypeDef* GpioPort,uint8_t Pin);    
        bool transceive(uint8_t* txData,uint32_t txDataLen, uint8_t* rxBuffer, uint32_t rxBufferLen);
        bool acquire();
        void release();
        // in consideration, in transmit receive or not
        uint8_t isError();
    private:
        volatile SPI_TypeDef* m_SPIx;
        GPIO_TypeDef* m_GpioPort;
        uint8_t m_Pin;
};