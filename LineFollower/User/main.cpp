#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "main.h"
#include "Motor.h"


void initGpioC()
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_InitStructure);   
}

int main()
{
    SystemInit();
    initGpioC();
    Pwm Pwm1;
    Motor motor;
    Pwm *p_pwm = &Pwm1;
    Motor *p_motor = &motor;
    p_motor->initPwm(&Pwm1);
    
    p_pwm -> setPeriodeTim10(10000);
    p_pwm -> pwmInitPinTim10 (Pwm1.getPeriodeTim10());
    p_pwm -> pwmModeInitTim10(); 
    p_pwm -> setPeriodeTim11(25000);
    p_pwm -> pwmInitPinTim11(Pwm1.getPeriodeTim11());
    p_pwm -> pwmModeInitTim11();     
    while(1)
    {
        p_motor->motorMove(-75,-70);   
    }
}