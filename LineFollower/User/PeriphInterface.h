#ifndef PERIPH_INTERFACE_H
#define PERIPH_INTERFACE_H

#include <stdint.h>
#include <string.h>

struct CallbackConf
{
    void (*cb)(void* arg);
    void* cb_arg;
};

class IPwmOutput
{
public:
    virtual void setValue(uint32_t value) = 0;
    virtual uint32_t getValue() = 0;
    virtual uint32_t getMaxValue() = 0;

    virtual uint64_t getPeriodUs() = 0;
    virtual void setPeriod(uint64_t periodUs) = 0;
};

class IGpio
{
public:
    enum EdgeType 
    {
        RISING_EDGE,
        FALLING_EDGE,
        BOTH_EDGE
    };

    virtual void set() = 0;
    virtual void clear() = 0;
    virtual void write(bool active) = 0;
    virtual void toggle() = 0;
    virtual bool get() = 0;

    virtual void enableEdgeCallback(EdgeType edge, CallbackConf* cbConf) = 0;
    virtual void disableEdgeCallback() = 0;
};

class IAdc
{
public:
    virtual uint32_t get() = 0;
    virtual uint32_t maxVal() = 0;
};

class IUart
{
public:
    virtual void transmit(uint8_t* dataOut, uint32_t dataLen) = 0;
    virtual uint32_t receive(uint8_t* dataIn, uint32_t maxDataLen) = 0; //specify the fifo size in init
    virtual bool hasData() = 0;
    virtual uint8_t isError() = 0;

    //in consideration
    virtual void enableReceiveCallback(uint8_t* dataIn, uint8_t dataLen);
    virtual void disableCallback();
};

class ITimer
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual uint64_t getTick() = 0;
    virtual uint64_t getPeriodUs() = 0;

    virtual void enableTimeoutCallback(CallbackConf* cbConf);
    virtual void disableTimeoutCallback();
};

class IWatchdog
{
public:
    virtual void Kick() = 0;
};

class IInputCapture
{
public:
    enum EdgeType 
    {
        RISING_EDGE,
        FALLING_EDGE,
        BOTH_EDGE
    };

    virtual void startCapture(EdgeType edge, CallbackConf* cbConf = NULL) = 0;
    virtual bool isFinished() = 0;
    virtual uint64_t getTimingUs() = 0;
};

class IPwmInput
{
public:
    virtual void startMeasure(CallbackConf* cbConf = NULL) = 0;
    virtual bool isFinished() = 0;
    virtual uint64_t getPulseWidthUs() = 0;
    virtual uint64_t getPulsePeriodUs() = 0;
};

class ISignalCounter
{
public:
    virtual void startCounting() = 0;
    virtual void pauseCounting() = 0;
    virtual void clearCount() = 0;
    virtual uint64_t getCount() = 0;
};

class IDac
{
public:
    virtual void setValue(uint32_t value) = 0;
    virtual uint32_t getValue() = 0;
    virtual uint32_t maxValue() = 0;
};

class ISpi
{
public:
   
    virtual bool transceive(uint8_t* txData,uint32_t txDataLen, uint8_t* rxBuffer) = 0;
    virtual bool acquire() = 0;
    virtual void release() = 0;

    // in consideration, in transmit receive or not
    virtual uint8_t isError() = 0;
};

class II2c
{
public:
    virtual void start() = 0;
    virtual void write(uint16_t devAddr, uint16_t regAddr, uint8_t* dataOut, uint32_t dataLen) = 0;
    virtual uint32_t read(uint8_t* dataIn, uint32_t maxDataLen) = 0;
    virtual void stop() = 0;

    // in consideration, in transmit receive or not
    virtual uint8_t isError() = 0;
};

class IEncoder
{
public:
    virtual uint64_t getCount() = 0;
    virtual void resetCount() = 0;
    virtual uint8_t isError() = 0;
};

#endif