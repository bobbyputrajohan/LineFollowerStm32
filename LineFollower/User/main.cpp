#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "main.h"
#include "Motor.h"
#include "stm32f4xx_adc.h"
#include "Delay.h"
#include "Gyro.h" 
using namespace STM32F407;

void initGpioASpi1()
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);   
    
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
    
    SPI_I2S_DeInit(SPI1);
    SPI_InitTypeDef spi;
    spi.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    spi.SPI_DataSize = SPI_DataSize_8b;
    spi.SPI_FirstBit = SPI_FirstBit_MSB;
	spi.SPI_Mode = SPI_Mode_Master;
	spi.SPI_NSS = SPI_NSS_Soft | SPI_NSSInternalSoft_Set;
    spi.SPI_CPOL = SPI_CPOL_High;
    spi.SPI_CPHA =  SPI_CPHA_2Edge;
    spi.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
    //SPI1->CR1 &= ~SPI_CR1_SPE;
	/* Init SPI */
	SPI_Init(SPI1, &spi);
	/* Enable SPI */
	//SPI1->CR1 |= SPI_CR1_SPE;
    SPI_Cmd(SPI1, ENABLE);
}

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
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);   
}

void initGpioB()
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);       
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
    
    initGpioASpi1();
    initGpioA();
    initGpioB();
    //SPICom SPII;
    //SPII.initialize(SPI1,GPIOA,GPIO_Pin_4);
    //ISpi *farisjelek = new SPICom();
    //SPII.initGpioASpi1();
   // SPII.initGpioASpi2();
   
    InterfacePwm *test = new Pwm();
    test -> setPeriodeTim10(10000);
    p_pwm -> setPeriodeTim10(10000);
    p_pwm -> pwmInitPinTim10 (Pwm1.getPeriodeTim10());
    p_pwm -> pwmModeInitTim10(); 
    p_pwm -> setPeriodeTim11(10000);
    p_pwm -> pwmInitPinTim11(Pwm1.getPeriodeTim11());
    p_pwm -> pwmModeInitTim11();     
    
    //Gyro gyro;
    //Gyro *pGyro = &gyro;
    //pGyro->initSPIGyro(&SPII,CLOCK100HZ,SCALE500DPS);
    SPI coba1;
    SPI coba2;
    coba1.initialize(SPI1,GPIOA,4);
    coba2.initialize(SPI1,GPIOA,4);
    ISpi *coba = new SPI();
    GyroL3Gxxxx coba4;
    GyroL3Gxxxx coba3;
    
    coba4.initSPIGyro(&coba1,GyroL3Gxxxx::VAL_C1_CLOCK_100_HZ,GyroL3Gxxxx::VAL_C4_SCALE500DPS);
    coba3.initSPIGyro(&coba2,GyroL3Gxxxx::VAL_C1_CLOCK_100_HZ,GyroL3Gxxxx::VAL_C4_SCALE500DPS);
    float readGyro,readGyro1,result;
    volatile float data;
    volatile float readGyroX,readGyroY,readGyroZ;
 
    while(1)
    {
     readGyro = coba4.getDataVelGyroXRad();
     readGyro1 = coba3.getDataVelGyroXRad();
    }
}