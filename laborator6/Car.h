//
// Created by Miruna Savin on 3/28/2022.
//

#ifndef LABORATO6_CAR_H
#define LABORATO6_CAR_H
#include "Weather.h"


class Car {
public:
    virtual const char*  GetName() = 0;
    virtual float GetFuelCapacity() = 0;
    virtual float GetFuelConsumption() = 0;
    virtual float GetAverageSpeed() = 0;
    virtual void adaptCharacteristics(Weather vreme) = 0;

};


#endif //LABORATO6_CAR_H
