/**
 * @file    keplerian-propagator.cpp
 * @brief   Keplerian Propagator
 * 
 * @version 1.0
 * @date    2023-12-05
 * 
 * @author  M. Anschuetz (marbuntu)
 * 
 *
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include "keplerian-propagator.h"


namespace snx
{

    UnperturbedKeplerianPropagator::UnperturbedKeplerianPropagator(TrajectoryParameterSet *params)
    : TrajectoryPropagatorModel(params)
    , _rki(4)
    , _state(4)
    {
        //_rki.setStepFunction(&UnperturbedKeplerianPropagator::_rk4_stepCbck);
    }


    UnperturbedKeplerianPropagator::~UnperturbedKeplerianPropagator()
    {
    }


    void UnperturbedKeplerianPropagator::_calc_staring_conditions()
    {

        


    }


    void UnperturbedKeplerianPropagator::plotOrbit(std::ofstream *out)
    {
        mlx::MlxVector<double> u(_params->getInitialStateVector());
        mlx::MlxVector<double> y(4);

        double T = 0;
        double dt = 1;
        double T_end = _params->getIdealOrbitalPeriod();

        auto fp = std::bind(&UnperturbedKeplerianPropagator::_rk4_stepCbck, *this, std::placeholders::_1);

        std::cout << "Orb Period: " << T_end << "\n";
        std::cout << "Initial: " << u.at(0) << "\t" << u.at(1) << "\t" << u.at(2) << "\t" << u.at(3) << "\n";

        while ((T += dt) < T_end)
        {
            _rki.step(u, dt, &y, fp);

            *out << y.at(0) << "\t" << y.at(1) << "\t" << y.at(2) << "\t" << y.at(3) << "\n";
            u = y;
        }

    }


    mlx::MlxVector<double> UnperturbedKeplerianPropagator::_rk4_stepCbck(const mlx::MlxVector<double>& u)
    {
        mlx::MlxVector<double> du(4);

        du[0] = u.at(2);
        du[1] = u.at(3);

        double r = sqrt(u.at(0) * u.at(0) + u.at(1) * u.at(1));
        double f = snx::EARTH_GM / pow(r, 3);

        du[2] = -f * u.at(0);
        du[3] = -f * u.at(1);

        return du;
    }


}   /* namespace snx */