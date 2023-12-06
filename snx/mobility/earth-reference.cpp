




#include "earth-reference.h"

#include <math.h>
#include <iostream>


namespace snx
{

    EarthReference *EarthReference::_instance = nullptr;
    double EarthReference::_delphi = 0;
    double EarthReference::_phi = 0;


    EarthReference::EarthReference()
    {
        TimeValue tval;
        tval.setMinutes(24 * 60);
        _delphi = (360) / (double) tval.Nanos();

        std::cout << "dephi: " << _delphi << "\n";
    }


    EarthReference* EarthReference::getInstance()
    {
        if (_instance == nullptr)
        {
            _instance = new EarthReference();
        }

        return _instance;
    }


    bool EarthReference::update(TimeValue delta)
    {
        _phi += _delphi * delta.Nanos();

        std::cout << delta << "\n";

        while(_phi > (360)) _phi -= 360;

        return true;
    }


    DoubleVector3D EarthReference::getReferencePosition(double latitude, double longitude)
    {

        double rot = latitude + _phi;
        //while(_phi > (M_PI * 2)) _phi -= (M_PI * 2);

        return DoubleVector3D(rot, longitude, 0);
    }


    void EarthReference::getRelativePosition()
    {

    }


    void EarthReference::predictRelativePosition()
    {

    }



}   /* namespace snx */