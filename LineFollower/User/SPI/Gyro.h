#include "SPI.h"
#include "stdint.h"

enum address
{
    CTRL1 = 0x20,
    CTRL2 = 0x21,
    CTRL3 = 0x22,
    CTRL4 = 0x23,
    CTRL5 = 0x24,
    REFERENCE = 0x25,
    OUTTEMP = 0x26,
    STATUS = 0x27,
    GYROXL = 0x28,
    GYROXH = 0x29,
    GYROYL = 0x2A,
    GYROYH = 0x2B,
    GYROZL = 0x2C,
    GYROZH = 0x2D,
    FIFOCTRL = 0x2E,
    FIFOSRC = 0x2F,
    IGCFG = 0x30,
    IGSRC = 0x31,
    IGTHSXH, 
    IGTHSXL, 
    IGTHSYH,  
    IGTHSYL,
    IGTHSZH,
    IGTHSZL, 
    IGDURATION,
    LOWODR
};

enum CTRL1
{
    POWERMODEDOWN = 0xF7,
    POWERMODEUP = 0x08,        
    ENABLEXAXIS = 0x02,
    ENABLEYAXIS = 0x01,
    ENABLEZAXIS = 0x04,
    CLOCK100HZ = 0x30,
    CLOCK200HZ = 0x70,
    CLOCK400HZ = 0xB0,
    CLOCK800HZ = 0xF0
};

enum CTRL2
{
    EXTREN = 0x80,
    LVLEN = 0x40,
    NORMALMODE = 0x00,
    REFSIGFIL = 0x10,
    NORMALMODE1 = 0x20,
    AUTORESTINT = 0x30,
    HIGHPASSMODE1 = 0x00,
    HIGHPASSMODE2 = 0x01,
    HIGHPASSMODE3 = 0x02,
    HIGHPASSMODE4 = 0x03,
    HIGHPASSMODE5 = 0x04,
    HIGHPASSMODE6 = 0x05,
    HIGHPASSMODE7 = 0x06,
    HIGHPASSMODE8 = 0x07,
    HIGHPASSMODE9 = 0x08,
    HIGHPASSMODE10 = 0x09
};

enum CTRL3
{
    INT1ENA = 0x80,
    INT1STATS = 0x40,
    INTACTLOW = 0x20,
    OPENDRAIN = 0x10,
    INT2DRDY = 0x08,
    INT2FTH = 0x04,
    INT2ORUN = 0x02,
    INT2EMPTY = 0x01
}; 

enum CTRL4
{
    BDU = 0x80,
    BLE = 0x40,
    SCALE2000DPS = 0x30,
    SCALE500DPS = 0x10,
    SCALE250DPS = 0x00,
    IMPEN = 0x08,
    SELFTEST0 = 0x02,
    UNUSED = 0x04,
    SELFTEST1 = 0x06,
    THREEWIRE = 0x01  
};

enum CTRL5
{
    REBOOTMEMORY = 0x80,
    FIFOENA = 0x40,
    STOPONFTH = 0x20,
    HIGHPASSFILENA = 0x10,
    //INTGENERATOR
    //OUTSELECT
 };

 enum FIFOCTRL
 {
    BYPASSMODE = 0x00,
    FIFOMODE = 0x20,
    STREAMMODE = 0x40,
    STREAMTOFIFOMODE = 0x60,
    STREAMTOBYPASSMODE = 0x80,
    DYNAMICSTREAMMODE = 0xC0,
    BYPASSTOFIFOMODE = 0xE0
 };
 
 enum IGCFG 
 {
     ANDOR = 0x80,
     LIR = 0x40,
     ZHIE = 0x20,
     ZLIE = 0x10,
     YHIE = 0x08,
     YLIE = 0x04,
     XHIE = 0x02,
     XLIE = 0x01
 };
 
 enum IGSRC
 {
     IA = 0x40,
     ZH = 0x20,
     ZL = 0x10,
     YH = 0x08,
     YL = 0x04,
     XH = 0x02,
     XL = 0x01
 };

 enum IGTHSXH
 {
     DCRM = 0x80
 };
 
 enum IGDURATION 
 {
     WAITENA = 0x80
 };     
 
 enum LOWODR
 {
     DRDYHL = 0x40,
     I2CDIS = 0x08,
     SWRES = 0x04,
     LOWODR1 = 0x01
 };


class Gyro
{
    public:
        bool initSPIGyro(SPICom *SPIInit,uint8_t frequency,uint8_t scale);
        void transmitDataGyro(uint8_t data);
        float receiveDataGyroX();
        float receiveDataGyroY();
        float receiveDataGyroZ();
        void writeRegister(uint8_t address, uint8_t data);
        uint8_t readRegister(uint8_t address);
        void getDataGyroXYZ(float *dataGyroX,float *dataGyroY,float *dataGyroZ);
        void getAlldataGyro1(int16_t *dataGyroX,int16_t *dataGyroY,int16_t *dataGyroZ);
        static const float RADIAN;
        static const uint16_t READDATANC = 0x80;
        static const uint16_t READDATAC = 0xC0;
        static const uint8_t WRITEDATA = 0x7F;
        float getSensitivity();
        void setSensitivity(float sensitivityDps);
        
    private:
        float m_Sensitivity;
};
