

#include "snx-time.h"


namespace snx
{

    TimeValue::TimeValue() 
    : __value(0)
    {
    }


    TimeValue::~TimeValue()
    {
    }


    TimeValue& TimeValue::setMinutes(uint64_t minutes)
    {
        __value = (minutes * 60) * 1e9;
        return *this;
    }


    uint64_t TimeValue::Minutes() const
    {
        return (__value / (60 * 1e9));
    }


    TimeValue& TimeValue::setSeconds(uint64_t seconds)
    {
        __value = seconds * 1e9;
        return *this;
    }


    uint64_t TimeValue::Seconds() const
    {
        return __value * 1e-9;
    }


    TimeValue& TimeValue::setMillis(uint64_t millis) 
    {
        __value = millis * 1e6;
        return *this;
    }


    uint64_t TimeValue::Millis() const
    {
        return __value * 1e-6;
    }


    TimeValue& TimeValue::setMicros(uint64_t micros)
    {
        __value = micros * 1e3;
        return *this;
    }


    uint64_t TimeValue::Micros() const
    {
        return __value * 1e-3;
    }


    TimeValue& TimeValue::setNanos(uint64_t nanos)
    {
        __value = nanos;
        return *this;
    }


    uint64_t TimeValue::Nanos() const
    {
        return __value;
    }


    std::ostream& operator<< (std::ostream& stream, const TimeValue& tval)
    {
        stream << std::to_string(tval.__value);
        return stream;
    }


    double operator/(const TimeValue& tval, const TimeValue& other)
    {
        return ((double) tval.__value) / ((double) other.__value);
    }


}   /* namespace snx */