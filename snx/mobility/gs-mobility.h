

#pragma once


namespace snx
{
    class GroundStationPropagator
    {
    public:
        GroundStationPropagator();
        ~GroundStationPropagator();

    protected:

    };  /* class GroundStationPropagator */


    template<class T>
    class GroundStationMobility
    {
    static_assert(std::is_base_of<GroundStationPropagator, T>::value);

    public:

        GroundStationMobility()
        {
            _model = new T();
        }


        ~GroundStationMobility()
        {
            delete(_model);
        }

        bool setPropagatorModel(T *model)
        {
            if (model == nullptr) return false;

            _model = model;

            return true;
        }


        DoubleVector3D predictPosition(TimeValue ts)
        {
            return DoubleVector3D();
        }


    protected:
        T* _model;

    };  /* class GroundStationMobility */


}   /* namespace snx */