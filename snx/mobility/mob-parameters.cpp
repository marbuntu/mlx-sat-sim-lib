/**
 * @file    parameters.cpp
 * 
 * @author  Martin Anschuetz
 * 
 * @brief   
 * 
 * @version 0.1
 * @date    2023-11-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "mob-parameters.h"
#include <math.h>


namespace snx
{

    TrajectoryParameterSet::TrajectoryParameterSet(double inclination, double eccentricity, double altitudeOfPerigee, double argOfPerigee, double raan, double meanAnomaly)
    {

        _keplOrbit.a = (altitudeOfPerigee + (double) EARTH_RADIUS) / (1 - eccentricity);
        _keplOrbit.i = inclination;
        _keplOrbit.e = eccentricity;
        _keplOrbit.o = raan;
        _keplOrbit.w = argOfPerigee;
        _keplOrbit.mm = meanAnomaly;

        _keplConst.dEdt = sqrt(EARTH_GM / pow(_keplOrbit.a, 3)) * 1e-9;

    }


    TrajectoryParameterSet::~TrajectoryParameterSet()
    {
    }

    KeplerianOrbitalParameters_t TrajectoryParameterSet::getKeplerian() const
    {
        return _keplOrbit;
    }


    KeplerianConstants_t TrajectoryParameterSet::getKeplerianConstants() const
    {
        return _keplConst;
    }


    mlx::MlxVector<double> TrajectoryParameterSet::getInitialStateVector() const
    {
        mlx::MlxVector<double> vec(4);

        double r = _keplOrbit.a * (1 - (_keplOrbit.e * _keplOrbit.e)) / (1 + _keplOrbit.e * cos(_keplOrbit.mm));
        double Vr = sqrt(EARTH_GM / (_keplOrbit.a * (1 - (_keplOrbit.e * _keplOrbit.e)))) * _keplOrbit.e * sin(_keplOrbit.mm);
        double Vt = sqrt(EARTH_GM / (_keplOrbit.a * (1 - (_keplOrbit.e * _keplOrbit.e)))) * ( 1 + _keplOrbit.e * cos(_keplOrbit.mm));

        vec[0] = r * cos(_keplOrbit.mm);
        vec[1] = r * sin(_keplOrbit.mm);
        vec[2] = -Vr * cos(_keplOrbit.mm) - Vt * sin(_keplOrbit.mm);
        vec[3] = Vr * sin(_keplOrbit.mm) + Vt * cos(_keplOrbit.mm);

        return vec;
    }


    double TrajectoryParameterSet::getIdealOrbitalPeriod() const
    {
        return 2 * M_PI * sqrt(pow(_keplOrbit.a, 3) / EARTH_GM);
    }


}   /* namespace snx */
