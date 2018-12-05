#include <stdint.h>
#include "Pwm.h"
class Motor
{
    public:
        Motor(){}
        ~Motor(){}
        void initPwm(Pwm *p_pwm);
        void motorMove(int8_t motorRight, int8_t motorLeft);
            
};