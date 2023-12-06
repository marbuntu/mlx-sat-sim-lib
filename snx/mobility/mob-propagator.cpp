/**
 * @file    mob-propagator.cc
 * 
 * @author  Martin Anschuetz
 * 
 * @brief   
 * 
 * @version 0.1
 * @date    2023-11-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <math.h>
#include "mobility/mob-propagator.h"


namespace snx
{

    EllipticalKeplerianTrajectory::EllipticalKeplerianTrajectory(TrajectoryParameterSet *params)
    : TrajectoryPropagatorModel(params)
    {
    }


    EllipticalKeplerianTrajectory::~EllipticalKeplerianTrajectory()
    {
    }


    DoubleVector3D EllipticalKeplerianTrajectory::initialPosition() const
    {
        return predictPositionAt(0.0);
    }


    DoubleVector3D EllipticalKeplerianTrajectory::predictPositionAt(const TimeValue ts) const
    {
        KeplerianConstants_t kc = _params->getKeplerianConstants();
        double theta_E = kc.dEdt * ts.Nanos();

        std::cout << "theta_E: " << kc.dEdt << "\n";

        return predictPositionAt(theta_E);
    }

    DoubleVector3D EllipticalKeplerianTrajectory::predictPositionAt(const double theta_E) const
    {
        KeplerianOrbitalParameters_t kep = _params->getKeplerian();

        double x = kep.a * (cos(theta_E) - kep.e);
        double y = kep.a * sqrt(1 - (kep.e * kep.e)) * sin(theta_E);

        return DoubleVector3D(x, y, 0.0);
    }


    DoubleVector3D EllipticalKeplerianTrajectory::predictVelocityAt(const TimeValue ts) const
    {

        return _v;
    }


    
} // namespace snx
