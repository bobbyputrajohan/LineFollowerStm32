#include "PeriphInterface.h"
#include "stm32f4xx_spi.h"

namespace STM32F407
{
class SPI final : public ISpi
{
public: 
    SPI(); 
    ~SPI(){}
    void initialize(SPI_TypeDef* SPIx, GPIO_TypeDef* GpioPortCs, uint16_t PinCs);
    virtual bool transceive(uint8_t* txData, uint32_t txDataLen, uint8_t* rxBuffer); 
    virtual bool acquire();
    virtual void release();
    virtual uint8_t isError(); //implementasinya mana, coba cek datasheet errornya apa aja
            
private: 
    SPI_TypeDef* m_SPIx; 
    GPIO_TypeDef* m_gpioPort;
    uint16_t m_pin;
    uint8_t m_flagPort;
    static const uint8_t PORT_COUNT = 6;
    static volatile bool m_portLock[PORT_COUNT];
    
};
}