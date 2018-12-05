#include <stdlib.h>
#include "stm32f4xx.h"
#include "Pwm.h"
#include "stm32f4xx_gpio.h"

//PWM TIM 10
void Pwm::pwmInitPinTim10(uint32_t periodeHz)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM10);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);    
    TIM_TimeBaseInitTypeDef TIM_BaseStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);
    TIM_BaseStruct.TIM_Prescaler = 0;
    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_BaseStruct.TIM_Period = periodeHz; /* 10kHz PWM */
    TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_BaseStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM10, &TIM_BaseStruct);
    TIM_Cmd(TIM10, ENABLE);
}

void Pwm::pwmModeInitTim10()
{
    TIM_OCInitTypeDef TIM_OCStruct;
	TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCStruct.TIM_Pulse = 0; 
	TIM_OC1Init(TIM10, &TIM_OCStruct);
	TIM_OC1PreloadConfig(TIM10, TIM_OCPreload_Enable);
}
uint32_t Pwm::getPeriodeTim10()
{
    return m_periodeTim10;
}

void Pwm::setPeriodeTim10(uint32_t setPeriodeHz)
{
    m_periodeTim10 = (SystemCoreClock / setPeriodeHz) - 1;
}

void Pwm::setDutyCycleTim10(int8_t setDutyCycle)
{
    if(setDutyCycle > 100)
    {
        setDutyCycle = 100;
    }
    m_pulseTim10 = ((getPeriodeTim10() + 1) * setDutyCycle) / 100 - 1;
    TIM10->CCR1 = m_pulseTim10;
}

//PWM TIM 11
void Pwm::pwmInitPinTim11(uint32_t periodeHz)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM11);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);    
    TIM_TimeBaseInitTypeDef TIM_BaseStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);
    TIM_BaseStruct.TIM_Prescaler = 0;
    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_BaseStruct.TIM_Period = periodeHz; /* 10kHz PWM */
    TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_BaseStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM11, &TIM_BaseStruct);
    TIM_Cmd(TIM11, ENABLE);
}

void Pwm::pwmModeInitTim11()
{
    TIM_OCInitTypeDef TIM_OCStruct;
	TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCStruct.TIM_Pulse = 0; 
	TIM_OC1Init(TIM11, &TIM_OCStruct);
	TIM_OC1PreloadConfig(TIM11, TIM_OCPreload_Enable);
}

uint32_t Pwm::getPeriodeTim11()
{
    return m_periodeTim11;
}

void Pwm::setPeriodeTim11(uint32_t setPeriodeHz)
{
    m_periodeTim11 = (SystemCoreClock/setPeriodeHz) - 1;
}

void Pwm::setDutyCycleTim11(int8_t setDutyCycle)
{
    if(setDutyCycle > 100)
    {
        setDutyCycle = 100;
    }
    m_pulseTim11 = ((getPeriodeTim11() + 1) * setDutyCycle) / 100 - 1;
    TIM11->CCR1 = m_pulseTim11;
}
