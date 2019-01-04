#include "InterfacePwm.h"
class Pwm : public InterfacePwm
{
    public:
        Pwm(){}
        ~Pwm(){}
        void pwmInitPinTim10(uint32_t periodeHz);
        void pwmModeInitTim10();
        uint32_t getPeriodeTim10();
        void setPeriodeTim10(uint32_t setPeriodeHz);
        void setDutyCycleTim10(int8_t setDutyCycle);
            
        void pwmInitPinTim11(uint32_t periodeHz);
        void pwmModeInitTim11();
        uint32_t getPeriodeTim11();
        void setPeriodeTim11(uint32_t setPeriodeHz);
        void setDutyCycleTim11(int8_t setDutyCycle);
     
    private:
        uint32_t m_periodeTim10;
        uint32_t m_pulseTim10;
        uint32_t m_periodeTim11;
        uint32_t m_pulseTim11;
};