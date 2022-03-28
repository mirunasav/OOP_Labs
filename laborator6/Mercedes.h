//
// Created by Miruna Savin on 3/28/2022.
//

#ifndef LABORATO6_MERCEDES_H
#define LABORATO6_MERCEDES_H
#include "Weather.h"
#include "Car.h"

class Mercedes : public Car{
    float Mercedes_fuel_capacity, Mercedes_fuel_consumption, Mercedes_avg_speed;
public:
    Mercedes();
    const char* GetName() override;

    float GetFuelCapacity() override;

    float GetFuelConsumption() override;

    float GetAverageSpeed() override;

    void adaptCharacteristics(Weather vreme) override;
};



#endif //LABORATO6_MERCEDES_H
