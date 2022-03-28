//
// Created by Miruna Savin on 3/28/2022.
//

#ifndef LABORATO6_MAZDA_H
#define LABORATO6_MAZDA_H
#include "Car.h"
#include "Weather.h"
class Mazda: public Car{
    float Mazda_fuel_capacity, Mazda_fuel_consumption, Mazda_avg_speed;
public:
    Mazda();
    const char* GetName() override;

    float GetFuelCapacity() override;

    float GetFuelConsumption() override;

    float GetAverageSpeed() override;

    void adaptCharacteristics(Weather vreme) override;
};

#endif //LABORATO6_MAZDA_H
