
#include <stdint.h>
#include <ostream>

#pragma once


namespace snx
{
    
    class TimeValue
    {
    public:

        TimeValue();
        
        ~TimeValue();


        TimeValue& setMinutes(uint64_t minutes);

        TimeValue& setSeconds(uint64_t seconds);

        TimeValue& setMillis(uint64_t millis);

        TimeValue& setMicros(uint64_t micros);

        TimeValue& setNanos(uint64_t nanos);


        uint64_t Minutes() const;

        uint64_t Seconds() const;

        uint64_t Millis() const;
        
        uint64_t Micros() const;

        uint64_t Nanos() const;


        friend std::ostream& operator<<(std::ostream& steam, const TimeValue& tval);


        friend double operator/(const TimeValue& tval, const TimeValue& other);


    private:
        
        // Hold the time value in Nano-Seconds
        uint64_t __value;


    };  /* class TimeValue */

} // namespace snx
