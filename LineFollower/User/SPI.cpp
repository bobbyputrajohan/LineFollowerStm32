#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f4xx_spi.h"
#include "SPI.h"


void SPI::SPISendWrite(uint16_t address) 
{
	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	while(((SPI1)->SR & (SPI_SR_TXE | SPI_SR_RXNE)) == 0 || ((SPI1)->SR & SPI_SR_BSY));
	
	/* Fill output buffer with data */
	SPI1->DR = address & 0x7fff;
	
	/* Wait for transmission to complete */
	while(((SPI1)->SR & (SPI_SR_TXE | SPI_SR_RXNE)) == 0 || ((SPI1)->SR & SPI_SR_BSY));
	
    /* Return data from buffer */
}

uint8_t SPI::SPISendReadAdd(uint16_t data) 
{
    
	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	while(((SPI1)->SR & (SPI_SR_TXE | SPI_SR_RXNE)) == 0 || ((SPI1)->SR & SPI_SR_BSY));
	
	/* Fill output buffer with data */
	SPI1->DR = data | 0x8000;
	
	/* Wait for transmission to complete */
	while(((SPI1)->SR & (SPI_SR_TXE | SPI_SR_RXNE)) == 0 || ((SPI1)->SR & SPI_SR_BSY));
	
    /* Return data from buffer */
	return SPI1->DR;
 
}

void SPI::initGpioASpi1()
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
    spi.SPI_DataSize = SPI_DataSize_16b;
    spi.SPI_FirstBit = SPI_FirstBit_MSB;
	spi.SPI_Mode = SPI_Mode_Master;
	spi.SPI_NSS = SPI_NSS_Soft|SPI_NSSInternalSoft_Set;
    spi.SPI_CPOL = SPI_CPOL_High;
    spi.SPI_CPHA =  SPI_CPHA_2Edge;
    spi.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
    //SPI1->CR1 &= ~SPI_CR1_SPE;
	/* Init SPI */
	SPI_Init(SPI1, &spi);
	/* Enable SPI */
	//SPI1->CR1 |= SPI_CR1_SPE;
    SPI_Cmd(SPI1, ENABLE);
}

void SPI::initGpioASpi2()
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
	spi.SPI_NSS = SPI_NSS_Soft|SPI_NSSInternalSoft_Set;
    spi.SPI_CPOL = SPI_CPOL_High;
    spi.SPI_CPHA =  SPI_CPHA_2Edge;
    spi.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
    //SPI1->CR1 &= ~SPI_CR1_SPE;
	/* Init SPI */
	SPI_Init(SPI1, &spi);
	/* Enable SPI */
	//SPI1->CR1 |= SPI_CR1_SPE;
    SPI_Cmd(SPI1, ENABLE);
}