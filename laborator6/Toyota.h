//
// Created by Miruna Savin on 3/28/2022.
//

#ifndef LABORATO6_TOYOTA_H
#define LABORATO6_TOYOTA_H
#include "Car.h"
#include "Weather.h"
class Toyota : public Car{
    float Toyota_fuel_capacity, Toyota_fuel_consumption, Toyota_avg_speed;
public:
    Toyota();
    const char* GetName() override;

    float GetFuelCapacity() override;

    float GetFuelConsumption() override;

    float GetAverageSpeed() override;

    void adaptCharacteristics(Weather vreme) override;
};


#endif //LABORATO6_TOYOTA_H
