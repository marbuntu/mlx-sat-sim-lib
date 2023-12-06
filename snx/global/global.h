
#include <cstddef>

#pragma once

namespace snx
{

    typedef enum 
    {
        // UNKNOWN - Should never be used!
        OID_UNKNOWN = 0,
        
        OID_MOBILITY = 1,

        OID_MOBILITY_PROPAGATOR = 2,

    }   ObejctId_t;


    static const size_t EARTH_RADIUS = 6371e3;
    static const double EARTH_MASS = 5.9722e24;
    static const double EARTH_GM = 398600.4418 * 1e9;


}   /* namespace snx */