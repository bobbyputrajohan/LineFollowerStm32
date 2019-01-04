#include "SPI.h"
#include "stdint.h"
using namespace STM32F407;

enum REGISTER_ADDR 
{
    REG_CTRL1 = 0x20,
    REG_CTRL2 = 0x21,
    REG_CTRL3 = 0x22,
    REG_CTRL4 = 0x23,
    REG_CTRL5 = 0x24,
    REG_REFERENCE = 0x25,
    REG_OUTTEMP = 0x26,
    REG_STATUS = 0x27,
    REG_GYROXL = 0x28,
    REG_GYROXH = 0x29,
    REG_GYROYL = 0x2A,
    REG_GYROYH = 0x2B,
    REG_GYROZL = 0x2C,
    REG_GYROZH = 0x2D,
    REG_FIFOCTRL = 0x2E,
    REG_FIFOSRC = 0x2F,
    REG_IGCFG = 0x30,
    REG_IGSRC = 0x31,
    REG_IGTHSXH, 
    REG_IGTHSXL, 
    REG_IGTHSYH,  
    REG_IGTHSYL,
    REG_IGTHSZH,
    REG_IGTHSZL, 
    REG_IGDURATION,
    REG_LOWODR
};

enum VALUE_REG_CTRL1 
{
    VAL_C1_POWER_MODE_DOWN = 0xF7,
    VAL_C1_POWER_MODE_UP = 0x08,        
    VAL_C1_ENABLE_X_AXIS = 0x02,
    VAL_C1_ENABLE_Y_AXIS = 0x01,
    VAL_C1_ENABLE_Z_AXIS = 0x04,
    VAL_C1_CLOCK_100_HZ = 0x30,
    VAL_C1_CLOCK_200_HZ = 0x70,
    VAL_C1_CLOCK_400_HZ = 0xB0,
    VAL_C1_CLOCK_800_HZ = 0xF0
};

enum VALUE_REG_CTRL2 
{
    //HPM = HighPassMode
    VAL_C2_EXTREN = 0x80,
    VAL_C2_LVLEN = 0x40,
    DEFAULT_MODE_CTRL2 = 0x00,
    VAL_C2_REFSIGFIL = 0x10,
    VAL_C2_NORMALMODE1 = 0x20,
    VAL_C2_AUTORESTINT = 0x30,
    VAL_C2_HPM1 = 0x00,
    VAL_C2_HPM2 = 0x01,
    VAL_C2_HPM3 = 0x02,
    VAL_C2_HPM4 = 0x03,
    VAL_C2_HPM5 = 0x04,
    VAL_C2_HPM6 = 0x05,
    VAL_C2_HPM7 = 0x06,
    VAL_C2_HPM8 = 0x07,
    VAL_C2_HPM9 = 0x08,
    VAL_C2_HPM10 = 0x09
};

enum VALUE_REG_CTRL3
{
    DEFAULT_MODE_CTRL3 =0x00,
    VAL_C3_INT1ENA = 0x80,
    VAL_C3_INT1STATS = 0x40,
    VAL_C3_INTACTLOW = 0x20,
    VAL_C3_OPENDRAIN = 0x10,
    VAL_C3_INT2DRDY = 0x08,
    VAL_C3_INT2FTH = 0x04,
    VAL_C3_INT2ORUN = 0x02,
    VAL_C3_INT2EMPTY = 0x01
}; 

enum VALUE_REG_CTRL4
{
    DEFAULT_MODE_CTRL4 = 0x00,
    VAL_C4_BDU = 0x80,
    VAL_C4_BLE = 0x40,
    VAL_C4_SCALE2000DPS = 0x30,
    VAL_C4_SCALE500DPS = 0x10,
    VAL_C4_SCALE250DPS = 0x00,
    VAL_C4_IMPEN = 0x08,
    VAL_C4_SELFTEST0 = 0x02,
    VAL_C4_UNUSED = 0x04,
    VAL_C4_SELFTEST1 = 0x06,
    VAL_C4_THREEWIRE = 0x01  
};

enum VALUE_REG_CTRL5
{
    DEFAULT_MODE_CTRL5 = 0x00,
    VAL_C5_REBOOTMEMORY = 0x80,
    VAL_C5_FIFOENA = 0x40,
    VAL_C5_STOPONFTH = 0x20,
    VAL_C5_HIGHPASSFILENA = 0x10,
    //INTGENERATOR
    //OUTSELECT
 };

 enum VALUE_REG_FIFOCTRL
 {
    VAL_FIFO_BPM = 0x00, //By Pass Mode
    VAL_FIFO_FM = 0x20, //Fifo Mode
    VAL_FIFO_SM = 0x40, //Stream Mode
    VAL_FIFO_STFM = 0x60, // Stream To Fifo Mode
    VAL_FIFO_STBPM = 0x80, //STREAM TO BY PASS MODE
    VAL_FIFO_DSM = 0xC0,// DYNAMICSTREAMMODE
    VAL_FIFO_BPTFM = 0xE0 //BYPASSTOFIFOMODE
 };
 
 enum VALUE_REG_IGCFG 
 {
     VAL_IGC_ANDOR = 0x80,
     VAL_IGC_LIR = 0x40,
     VAL_IGC_ZHIE = 0x20,
     VAL_IGC_ZLIE = 0x10,
     VAL_IGC_YHIE = 0x08,
     VAL_IGC_YLIE = 0x04,
     VAL_IGC_XHIE = 0x02,
     VAL_IGC_XLIE = 0x01
 };
 
 enum VALUE_REG_IGSRC
 {
     VAL_IGS_IA = 0x40,
     VAL_IGS_ZH = 0x20,
     VAL_IGS_ZL = 0x10,
     VAL_IGS_YH = 0x08,
     VAL_IGS_YL = 0x04,
     VAL_IGS_XH = 0x02,
     VAL_IGS_XL = 0x01
 };

 enum VALUE_REG_IGTHSXH
 {
     VAL_IGT_DCRM = 0x80
 };
 
 enum VALUE_REG_IGDURATION 
 {
     VAL_IGD_WAITENA = 0x80
 };     
 
 enum VALUE_REG_LOWODR
 {
     VAL_LOW_DRDYHL = 0x40,
     VAL_LOW_I2CDIS = 0x08,
     VAL_LOW_SWRES = 0x04,
     VAL_LOW_LOWODR1 = 0x01
 };

 enum READ_WRITE_DATA
 {
     READ_DATA_NC = 0x80, //NC = Not Continue
     READ_DATA_C = 0xC0, //C = Continue
     WRITE_DATA = 0x7F 
 };
 

class GyroL3Gxxxx
{
public:
    GyroL3Gxxxx(){}
    ~GyroL3Gxxxx(){}
    bool initSPIGyro(SPI *SPIInit, uint8_t frequency, uint8_t scale);
    float getDataVelGyroXRad(); 
    float getDataVelGyroYRad();
    float getDataVelGyroZRad();
    void writeRegister(uint8_t address, uint8_t data);
    uint8_t readRegister(uint8_t address);
    void getDataVelGyroXYZRad(float *dataGyroX,float *dataGyroY,float *dataGyroZ);
    float getSensitivityGyroDPS();
    void setSensitivityGyroDPS(uint8_t scale);
    
private:
    float m_Sensitivity;
    SPI *SPIGyro; 
    static const float RADIAN;

};