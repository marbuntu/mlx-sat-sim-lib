/**
 * @file    mob-propagator.h
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


#pragma once

#include "global/global.h"
#include "global/snx-vector.h"
#include "time/snx-time.h"
#include "mobility/mob-parameters.h"


namespace snx
{

    class TrajectoryPropagatorModel
    {   

    public:

        TrajectoryPropagatorModel(TrajectoryParameterSet *params)
        : _params(params)
        {
        }

        bool setEpoch(size_t epoch)
        {
            _epoche = epoch;
            return true;
        }


    protected:        

        // Trajectory Model Parameter Set
        TrajectoryParameterSet *_params;

        // Current Epoch Value
        size_t _epoche;

        // Current Velocity Vector
        Vector3D<double>  _v;

        // Current Position Vector
        Vector3D<double>  _p;


        const ObejctId_t __id = OID_MOBILITY_PROPAGATOR;

    };



    class EllipticalKeplerianTrajectory final : public virtual TrajectoryPropagatorModel
    {

    public:
    
        EllipticalKeplerianTrajectory(TrajectoryParameterSet *params);
        ~EllipticalKeplerianTrajectory();


        bool setPosition(const DoubleVector3D &vect);


        bool setVelocity(const DoubleVector3D &vect);


        DoubleVector3D initialPosition() const;

        DoubleVector3D initialVelocity() const;


        DoubleVector3D predictPositionAt(const double theta_E) const;


        DoubleVector3D predictPositionAt(const TimeValue ts) const;

        // @todo: prediction should include both velo and position!
        DoubleVector3D predictVelocityAt(const TimeValue ts) const;



    protected:

    };

}   /* namespace snx */