#include <stdint.h>

class InterfacePwm
{
    public:
        InterfacePwm(){}
        virtual ~InterfacePwm(){}
        virtual void pwmInitPinTim10(uint32_t periodeHz) = 0;
        virtual void pwmInitPinTim11(uint32_t periodeHz) = 0;
        virtual void setPeriodeTim10(uint32_t setPeriodeHz) = 0;
        virtual void setPeriodeTim11(uint32_t setPeriodeHz) = 0;
};