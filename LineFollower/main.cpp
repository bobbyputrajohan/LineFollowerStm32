#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "main.h"
//#include "Pwm.h"
#include "Motor.h"

int main()
{
    SystemInit();
    Pwm Pwm1;
    Motor motor;
    Pwm *p_pwm = &Pwm1;
   
    
       
    GPIOC->BSRRH = GPIO_Pin_8;
    GPIOC->BSRRH = GPIO_Pin_7; // 0     00110
        GPIOC->BSRRL = GPIO_Pin_9;
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRL = GPIO_Pin_7;//data 1
        GPIOC->BSRRL = GPIO_Pin_9;//clock
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRL = GPIO_Pin_9;//clock 1
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRH = GPIO_Pin_7;//data 0
        GPIOC->BSRRL = GPIO_Pin_9;//clock
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRH = GPIO_Pin_7;//data 1
        GPIOC->BSRRL = GPIO_Pin_9;//clock
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRL = GPIO_Pin_6;//latch
        GPIOC->BSRRH = GPIO_Pin_6;//latch
    Motor *p_motor = &motor;
    p_motor->initPwm(&Pwm1);
    p_pwm -> setPeriodeTim10(10000);
    p_pwm -> pwmInitPinTim10 (Pwm1.getPeriodeTim10());
    p_pwm -> pwmPulseInitTim10(); 
    p_pwm -> setPeriodeTim11(25000);
    p_pwm -> pwmInitPinTim11(Pwm1.getPeriodeTim11());
    p_pwm -> pwmPulseInitTim11();     
    while(1)
    {
        //p_pwm->setDutyCycleTim10(20);
        //p_pwm->setDutyCycleTim11(50);
        p_motor->motorMove(50,70);
        //Pwm1.pwmMove(50,20);
    }
}