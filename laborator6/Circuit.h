//
// Created by Miruna Savin on 3/28/2022.
//

#ifndef LABORATO6_CIRCUIT_H
#define LABORATO6_CIRCUIT_H
#include <iostream>
#include "Car.h"
#include "Weather.h"
#include "Dacia.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Mazda.h"

class Circuit {
    Car ** cars;
    float length;
    int nr_cars;
    float *ranks;
    Weather vreme;
    int max_index;
public:
    Circuit(); //constructor
    Circuit (const Circuit& c);
    void SetLength(float length_value);
    void SetWeather(Weather vreme);
    void AddCar(Car *c);
    void Race();
    void ShowFinalRanks();
    void ShowWhodidNotFinish();
};


#endif //LABORATO6_CIRCUIT_H
