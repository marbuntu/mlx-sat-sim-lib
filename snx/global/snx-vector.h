


#pragma once

#include "global.h"
#include <cstddef>
#include <ostream>


namespace snx 
{

    template<class T>
    class Vector3D
    {
    public:
        Vector3D()
        : x(0), y(0), z(0)
        {
        }


        Vector3D(T x, T y, T z)
        : x(x), y(y), z(z)
        {
        }


        ~Vector3D()
        {
        }


        friend std::ostream& operator<< (std::ostream& stream, const Vector3D& vect)
        {
            stream << "(" << std::to_string(vect.x) << ", " << std::to_string(vect.y) << ", " << std::to_string(vect.z) << ")";
            return stream;
        }


        T x;
        T y;
        T z;
    };


    typedef Vector3D<size_t> LongVector3D;

    typedef Vector3D<double> DoubleVector3D;

    
}   /* namespace snx */ 
