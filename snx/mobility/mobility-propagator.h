

#pragma once


#include "global/global.h"
#include "global/snx-vector.h"
#include "time/snx-time.h"
#include "mobility/mob-parameters.h"

namespace snx
{

/*
    class TrajectoryPropagatorModel
    {   

    public:

        bool setEpoch(size_t epoch)
        {
            _epoche = epoch;
            return true;
        }


    protected:        
        
        
        size_t _epoche;


    private:
        ObejctId_t __id = OID_MOBILITY_PROPAGATOR;

    };
*/


    class CircularTrajectoryModel final
    {

    public:
    
        CircularTrajectoryModel(TrajectoryParameterSet *params);
        ~CircularTrajectoryModel();


        bool setPosition(const DoubleVector3D &vect);


        bool setVelocity(const DoubleVector3D &vect);


        DoubleVector3D predictPositionAt(const TimeValue ts);

        // @todo: prediction should include both velo and position!
        DoubleVector3D predictVelocityAt(const TimeValue ts);



    protected:
        TrajectoryParameterSet *_params;
        //TrajectoryModelParameters_t _params;
        //KeplerianOrbitalParameters_t _keplerian;

        // Current Velocity Vector
        Vector3D<double>  _v;

        // Current Position Vector
        Vector3D<double>  _p;

        // Current Epoche Time
        size_t _epc;

        TimeValue _orbitalPeriod;

    };

}   /* namespace snx */