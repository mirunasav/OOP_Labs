//
// Created by Miruna Savin on 3/28/2022.
//

#ifndef LABORATO6_FORD_H
#define LABORATO6_FORD_H
#include "Weather.h"
#include "Car.h"
class Ford: public Car{
    float Ford_fuel_capacity, Ford_fuel_consumption, Ford_avg_speed;
public:
    Ford();
    const char* GetName() override;

    float GetFuelCapacity() override;

    float GetFuelConsumption() override;

    float GetAverageSpeed() override;

    void adaptCharacteristics(Weather vreme) override;
};


#endif //LABORATO6_FORD_H
