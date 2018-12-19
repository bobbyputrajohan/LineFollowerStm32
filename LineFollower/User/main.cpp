#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "main.h"
#include "Motor.h"
#include "SPI.h"
#include "stm32f4xx_adc.h"
#include "Delay.h"



void initGpioC()
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_InitStructure);   
}

void initGpioA()
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);   
}

void initAdcPin()
{
    ADC_InitTypeDef ADC_InitStructure;
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
    SPI SPII;
    SPII.initGpioASpi1();
    initGpioA();
    p_pwm -> setPeriodeTim10(10000);
    p_pwm -> pwmInitPinTim10 (Pwm1.getPeriodeTim10());
    p_pwm -> pwmModeInitTim10(); 
    p_pwm -> setPeriodeTim11(10000);
    p_pwm -> pwmInitPinTim11(Pwm1.getPeriodeTim11());
    p_pwm -> pwmModeInitTim11();     
    
    //SPISend(0x80);
    
    GPIOA->BSRRH = GPIO_Pin_3; // mati
    Delay_ms(1);
    volatile uint16_t result;
    volatile uint16_t read1;
    volatile uint16_t read2;
    
    GPIOA->BSRRH = GPIO_Pin_3; // mati
    Delay_ms(1);
    read1 = SPII.SPISendReadAdd(0x0f00); //ctrl 1
    GPIOA->BSRRL = GPIO_Pin_3; // hidup
    Delay_ms(1);    
        
    GPIOA->BSRRH = GPIO_Pin_3; // mati
    Delay_ms(1);
    SPII.SPISendWrite(0x200f); //ctrl 1
    GPIOA->BSRRL = GPIO_Pin_3; // hidup
    Delay_ms(1);
    GPIOA->BSRRH = GPIO_Pin_3; // mati
    Delay_ms(1);
    SPII.SPISendWrite(0x2100); //ctrl 2
    GPIOA->BSRRL = GPIO_Pin_3; // hidup
    Delay_ms(1);
    GPIOA->BSRRH = GPIO_Pin_3; // mati
    Delay_ms(1);
    SPII.SPISendWrite(0x2200);//ctrl 3
    GPIOA->BSRRL = GPIO_Pin_3; // hidup
    Delay_ms(1);
    GPIOA->BSRRH = GPIO_Pin_3; // mati
    Delay_ms(1);
    SPII.SPISendWrite(0x2330);//ctrl 4
    GPIOA->BSRRL = GPIO_Pin_3; // hidup
    Delay_ms(1);
    
    GPIOA->BSRRH = GPIO_Pin_3; // mati
    Delay_ms(1);
    SPII.SPISendWrite(0x2400);//ctrl 5
    GPIOA->BSRRL = GPIO_Pin_3; // hidup
    Delay_ms(1);
    
    while(1)
    {
        GPIOA->BSRRH = GPIO_Pin_3; // mati
        Delay_ms(1);
        read1=SPII.SPISendReadAdd(0x2800);
         //= SPISendReadAdd(0x00);
        
        GPIOA->BSRRL = GPIO_Pin_3; // hidup
        Delay_ms(1);
        
        GPIOA->BSRRH = GPIO_Pin_3; // mati
        Delay_ms(1);
        
        read2=SPII.SPISendReadAdd(0x2900);
        //SPISendReadAdd(0x00);
        GPIOA->BSRRL = GPIO_Pin_3; // hidup
        Delay_ms(1);
        GPIOA->BSRRH = GPIO_Pin_3; // mati
        Delay_ms(1);
        result = SPII.SPISendReadAdd(0x0f00);
        // = SPISendReadAdd(0x00);
        Delay_ms(1);
        GPIOA->BSRRL = GPIO_Pin_3; // hidup
        
        
    }
}