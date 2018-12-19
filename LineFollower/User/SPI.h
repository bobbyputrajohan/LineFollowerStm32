#include <stdint.h>
class SPI
{
    public:
        SPI(){}
        ~SPI(){}
        void initGpioASpi1();
        void initGpioASpi2();
        void SPISendWrite(uint16_t addressData); 
        uint8_t SPISendReadAdd(uint16_t data); 
        
};