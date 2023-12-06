/**
 * @file    node-mobility.cpp
 * 
 * @author  Martin Anschuetz
 * 
 * @brief   
 * 
 * @version 0.1
 * @date 2023-11-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once


#include <cstddef>
#include "global/snx-vector.h"
#include "time/snx-time.h"


namespace snx
{

    // class UnperturbedEarthReference
    // {
    // public:


    // protected:
    // private:


    // };  /* class UnperturbedEarthReference */



    class EarthReference
    {
    public:
        // Mean Earth Radius
        static const size_t MEAN_RADIUS = 6371e3;
        
        // Mean Sealevel Radius
        static const size_t MEAN_SEALEVEL_RADIUS = 10;
        
        // Earth's specific Mass
        static const size_t MASS = 5;

        static EarthReference* getInstance();


        DoubleVector3D getReferencePosition(double latitude, double longitude);


        void getRelativePosition();


        void predictRelativePosition();


        bool update(TimeValue delta);


    protected:

        EarthReference();

        static EarthReference* _instance;

        static double _delphi;

        static double _phi;


    };  /* EarthRefence */


}   /* namspace snx */
