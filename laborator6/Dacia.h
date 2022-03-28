//
// Created by Miruna Savin on 3/28/2022.
//

#ifndef LABORATO6_DACIA_H
#define LABORATO6_DACIA_H
#include "Car.h"
#include "Weather.h"

class Dacia : public Car{
    float Dacia_fuel_capacity, Dacia_fuel_consumption, Dacia_avg_speed;
public:
    Dacia();
    const char* GetName() override;

    float GetFuelCapacity() override;

    float GetFuelConsumption() override;

    float GetAverageSpeed() override;

    void adaptCharacteristics(Weather vreme) override;
};


#endif //LABORATO6_DACIA_H
