#include <stdio.h>
#include <stdlib.h> 
#include "Motor.h"
#include "stm32f4xx_gpio.h" 

Pwm *p_pwm = NULL;
void Motor::initPwm(Pwm *p_pwmMotor)
{
    p_pwm = p_pwmMotor;
} 
void Motor::motorMove(int8_t motorRight, int8_t motorLeft)
{
   if(motorRight && motorLeft > -1)
    {
        //both of motor forward
        //BSRRL high
        //BSRRH low
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
    }
    else if(motorRight && motorLeft < 0)
    {
        //both of motor backward
        //BSRRL high
        //BSRRH low
        GPIOC->BSRRH = GPIO_Pin_7; //11000
        GPIOC->BSRRL = GPIO_Pin_9;
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRH = GPIO_Pin_7;//data 0
        GPIOC->BSRRL = GPIO_Pin_9;//clock
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRH = GPIO_Pin_9;//clock 0
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRL = GPIO_Pin_7;//data 1
        GPIOC->BSRRL = GPIO_Pin_9;//clock
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRL = GPIO_Pin_9;//clock
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRL = GPIO_Pin_6;//latch
        GPIOC->BSRRH = GPIO_Pin_6;//latch
    }
    else if(motorRight > -1 && motorLeft < 0) //motor left 2a motor right 1a
    {
        //BSRRL high
        //BSRRH low
        GPIOC->BSRRH = GPIO_Pin_7; // 0     10100
        GPIOC->BSRRL = GPIO_Pin_9;
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRH = GPIO_Pin_7;//data 0
        GPIOC->BSRRL = GPIO_Pin_9;//clock
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        
        GPIOC->BSRRL = GPIO_Pin_7;//data 1
        GPIOC->BSRRL = GPIO_Pin_9;//clock 1
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        
        GPIOC->BSRRH = GPIO_Pin_7;//data 0
        GPIOC->BSRRL = GPIO_Pin_9;//clock
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        
        
        GPIOC->BSRRL = GPIO_Pin_7;//data 1
        GPIOC->BSRRL = GPIO_Pin_9;//clock
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRL = GPIO_Pin_6;//latch
        GPIOC->BSRRH = GPIO_Pin_6;//latch
    }
    
    else if(motorRight < 0 && motorLeft > -1)
    {
        //BSRRL high
        //BSRRH low
        GPIOC->BSRRH = GPIO_Pin_7; // 0     10100      01010
        GPIOC->BSRRL = GPIO_Pin_9;
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRL = GPIO_Pin_7;//data 0
        GPIOC->BSRRL = GPIO_Pin_9;//clock
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        
        GPIOC->BSRRH = GPIO_Pin_7;//data 1
        GPIOC->BSRRL = GPIO_Pin_9;//clock 1
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        
        GPIOC->BSRRL = GPIO_Pin_7;//data 0
        GPIOC->BSRRL = GPIO_Pin_9;//clock
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        
        
        GPIOC->BSRRH = GPIO_Pin_7;//data 1
        GPIOC->BSRRL = GPIO_Pin_9;//clock
        GPIOC->BSRRH = GPIO_Pin_9;// clock
        GPIOC->BSRRL = GPIO_Pin_6;//latch
        GPIOC->BSRRH = GPIO_Pin_6;//latch
    }
    p_pwm->setDutyCycleTim10(abs(motorRight));
    p_pwm->setDutyCycleTim11(abs(motorLeft));
}