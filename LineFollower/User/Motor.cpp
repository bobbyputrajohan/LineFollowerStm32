#include <stdio.h>
#include <stdlib.h> 
#include "Motor.h"
#include "stm32f4xx_gpio.h" 

static Pwm *p_pwm = NULL;
void Motor::initPwm(Pwm *p_pwmMotor)
{
    p_pwm = p_pwmMotor;
    hasInit = true;
} 
     
void Motor::dirMotorForward()
{
    GPIOC->BSRRH = GPIO_Pin_7; 
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;
    
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;
        
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9;
        
    GPIOC->BSRRH = GPIO_Pin_7;  
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRL = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRL = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9;
        
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRL = GPIO_Pin_6; 
    GPIOC->BSRRH = GPIO_Pin_6; 
}

void Motor::dirMotorBackward()
{
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9;
    
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;
        
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9; 
    
    GPIOC->BSRRL = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRL = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9;
        
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRL = GPIO_Pin_6; 
    GPIOC->BSRRH = GPIO_Pin_6; 
}

// Right Backward Left Forward
void Motor::dirMotorRBLF()
{
    GPIOC->BSRRH = GPIO_Pin_7; 
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;
    
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;
        
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9;
        
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRL = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRL = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9;
        
    GPIOC->BSRRH = GPIO_Pin_7; 
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRL = GPIO_Pin_6; 
    GPIOC->BSRRH = GPIO_Pin_6; 
}

void Motor::dirMotorRFLB()
{
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9;
    
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9;
        
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9;
        
    GPIOC->BSRRL = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRL = GPIO_Pin_7;  
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9;
    GPIOC->BSRRH = GPIO_Pin_9;
        
    GPIOC->BSRRH = GPIO_Pin_7;
    GPIOC->BSRRL = GPIO_Pin_9; 
    GPIOC->BSRRH = GPIO_Pin_9;

    GPIOC->BSRRL = GPIO_Pin_6; 
    GPIOC->BSRRH = GPIO_Pin_6; 
    
}

void Motor::motorMove(int8_t motorRight, int8_t motorLeft)
{
  /* if(motorRight && motorLeft > -1)
    {
       dirMotorForward();
    }
    
    else if(motorRight && motorLeft < 0)
    {
        dirMotorBackward();
    }
    
    else if(motorRight > -1 && motorLeft < 0)
    {
       dirMotorRFLB(); 
    }
    
    else if(motorRight < 0 && motorLeft > -1)
    {
        dirMotorRBLF();
    }
    
*/
    p_pwm->setDutyCycleTim10(abs(motorRight));
    p_pwm->setDutyCycleTim11(abs(motorLeft));
}