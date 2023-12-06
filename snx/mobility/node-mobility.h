/**
 * @file mob.h
 * 
 * @author Martin Anschuetz (marbuntu)
 * 
 * @brief 
 * 
 * @version 0.1
 * @date 2023-11-09
 * 
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#pragma once



#include "global/global.h"
#include "time/snx-time.h"
#include "mobility/mob-propagator.h"


namespace snx
{


    template<class T>
    class SatelliteMobility
    {
    static_assert(std::is_base_of<TrajectoryPropagatorModel, T>::value);
    
    public:

        SatelliteMobility(TrajectoryParameterSet &params)
        {
            _params = new TrajectoryParameterSet(params);
            _model = new T(_params);
        }


        ~SatelliteMobility()
        {
            delete(_model);
            delete(_params);
        }


        bool setPropagationModel(T *model)
        {
            if (model == nullptr) return false;

            _model = model;

            return true;
        }


        DoubleVector3D predictPosition(TimeValue ts) 
        {
            return _model->predictPositionAt(ts);
        }


        DoubleVector3D getVelocityAt(TimeValue ts)
        {
            return _model->predictVelocityAt(ts);
        }


        void propagate(size_t ts);


    protected:
        T *_model;
        TrajectoryParameterSet *_params;

    private:
        ObejctId_t __id = OID_MOBILITY;



    }; /* Mobility Vector */



}   /* namespace snx */