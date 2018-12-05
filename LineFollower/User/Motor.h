#include <stdint.h>
#include "Pwm.h"
class Motor
{
    public:
        Motor(){}
        ~Motor(){}
        void dirMotorForward();
        void dirMotorBackward();
        void dirMotorRBLF();
        void dirMotorRFLB();
        void initPwm(Pwm *p_pwm);
        void motorMove(int8_t motorRight, int8_t motorLeft);
    private:
        bool hasInit;
                
};