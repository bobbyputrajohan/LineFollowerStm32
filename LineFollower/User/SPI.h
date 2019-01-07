#include "PeriphInterface.h"
#include "stm32f4xx_spi.h"

namespace STM32F407
{
class SPI final : public ISpi
{
public: 
    enum ErrorCodeMask
    {
        ERR_MODE_FAULT = 0x20,
        ERR_MODE_CRC = 0x10,
        ERR_MODE_OVERRUN = 0x40
    };
    
    SPI(); 
    ~SPI(){}
    void initialize(SPI_TypeDef* SPIx, GPIO_TypeDef* GpioPortCs, uint16_t PinCs);
    virtual CmdStatus transceive(uint8_t* txData, uint32_t txDataLen, uint8_t* rxBuffer); 
    virtual CmdStatus acquire();
    virtual void release();
    virtual uint8_t getErrorCode();
            
private: 
    SPI_TypeDef* m_SPIx; 
    GPIO_TypeDef* m_gpioPort;
    uint16_t m_pin;
    uint8_t m_flagPort;
    uint8_t m_errorCode;
    static const uint8_t PORT_COUNT = 6;
    static volatile bool m_portLock[PORT_COUNT];
    
};
}