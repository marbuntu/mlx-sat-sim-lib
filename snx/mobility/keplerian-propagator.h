/**
 * @file    keplerian-propagator.h
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

#pragma once

#include <fstream>
#include "mob-propagator.h"
#include <mlx-analytics.h>
#include <mlx-runge-kutta.h>

namespace snx
{


class UnperturbedKeplerianPropagator final : public virtual TrajectoryPropagatorModel
{
public:
    /**
     * @brief 
     * 
     */
    UnperturbedKeplerianPropagator(TrajectoryParameterSet *params);


    /**
     * @brief 
     * 
     */
    ~UnperturbedKeplerianPropagator();



    void plotOrbit(std::ofstream* out);



protected:

    void _calc_staring_conditions();

    mlx::MlxVector<double> _rk4_stepCbck(const mlx::MlxVector<double>& u); 

    mlx::MlxVector<double> _state;
    mlx::MlxRungeKuttaIntegration _rki;


}; /* UnperturbedKeplerianPropagator */



}   /* namespace snx */