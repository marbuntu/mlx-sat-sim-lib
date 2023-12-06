/**
 * @file    snx-coords.h
 * 
 * @author  Martin Anschuetz
 * 
 * @brief   
 * 
 * @version 0.1
 * @date    2023-11-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#pragma once


#include <math.h>

namespace snx
{

    class SphericalCoordinates
    {
    public:

        SphericalCoordinates();
        ~SphericalCoordinates();

        
        SphericalCoordinates toDegrees() const;

        void fromDegrees(double phi, double theta, double radius);


        double theta_deg() const;
        double theta_rad() const;

        double phi_deg() const;
        double phi_rad() const;

        double radius() const;


    protected:

        double _phi;
        double _the;
        double _rad;

    };  /* class SphericalCoordinates */


}   /* namespace snx */