


#include "snx-coords.h"


namespace snx
{

    SphericalCoordinates::SphericalCoordinates()
    {
    }


    SphericalCoordinates::~SphericalCoordinates()
    {
    }


    void SphericalCoordinates::fromDegrees(double phi, double theta, double radius) const
    {
        _phi = phi;
        _the = theta;
        _rad = radius;
    }


}   /* namespace snx */