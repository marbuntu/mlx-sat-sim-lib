



#include "mobility-propagator.h"
#include <math.h>
#include <iostream>

namespace snx
{


    CircularTrajectoryModel::CircularTrajectoryModel(TrajectoryParameterSet  *params)
    {
        //_params = params;
        //_p.z = (EARTH_RADIUS + params.altitude);

        //_epoche = params.epoche;
        //double per = 2 * M_PI * sqrt((_p.z * _p.z * _p.z) / EARTH_GM);

        //_orbitalPeriod.setNanos(per * 1.0e9);


        //std::cout << "period: " << _orbitalPeriod << "\n";
    
        


    }


    CircularTrajectoryModel::~CircularTrajectoryModel()
    {
    }


    bool CircularTrajectoryModel::setPosition(const DoubleVector3D &vect)
    {

        return true;
    }


    bool CircularTrajectoryModel::setVelocity(const DoubleVector3D &vect)
    {

        return true;
    }


    DoubleVector3D CircularTrajectoryModel::predictPositionAt(const TimeValue ts)
    {

        double res = 0;
        double erg = ts / _orbitalPeriod;
        double f = std::modf(erg, &res);
        double p = 2 * M_PI * _p.z;

        double dist = (f * p);

        std::cout << "f: " << f << " (" << res << ")" << " p: " << p << " dist: " << dist << "\n";

        return DoubleVector3D(_p.x + dist, _p.y, _p.z);
    }


    DoubleVector3D CircularTrajectoryModel::predictVelocityAt(const TimeValue ts)
    {
        return _v;
    }


    
} // namespace snx


