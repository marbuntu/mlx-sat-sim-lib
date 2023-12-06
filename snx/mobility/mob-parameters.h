/**
 * @file    parameters.h
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

#pragma once


#include <mlx-analytics.h>
#include "global/snx-vector.h"


namespace snx
{

    typedef struct
    {
        double a;            // Semi-Major Axis
        double e;           // Eccentricity
        double i;           // Inclination
        double o;           // Right-Ascencion of Ascending Node
        double w;           // Argument of perigee
        double mm;          // Mean Anomaly

    } KeplerianOrbitalParameters_t;


    typedef struct
    {
        double dEdt;
        double alphaT;

    } KeplerianConstants_t;
    

    typedef struct
    {

    } PerturbationParameters_t;


    typedef struct 
    {
        KeplerianOrbitalParameters_t keplerian;
        PerturbationParameters_t perturbations;
        size_t epoche;              // Initial Timestamp

    } TrajectoryModelParameters_t;
    

    class TrajectoryParameterSet
    {
    public:

        TrajectoryParameterSet(DoubleVector3D position, DoubleVector3D velocity);

        TrajectoryParameterSet(double inclination, double eccentricity, double heightOfPerigee, double argOfPerigee, double raan, double meanAnomaly);

        ~TrajectoryParameterSet();

        KeplerianOrbitalParameters_t getKeplerian() const;

        KeplerianConstants_t getKeplerianConstants() const;


        mlx::MlxVector<double> getInitialStateVector() const;


        double getIdealOrbitalPeriod() const;


    protected:
        
        KeplerianOrbitalParameters_t _keplOrbit;
        
        KeplerianConstants_t _keplConst;

        PerturbationParameters_t _perturbation;

    };  /* TrajectoryElementSet*/


}   /* namespace snx */
