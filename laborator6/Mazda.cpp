//
// Created by Miruna Savin on 3/28/2022.
//

#include "Mazda.h"
#include<iostream>
#include<cstring>
using namespace std;

Mazda::Mazda(): Mazda_fuel_capacity(35.0), Mazda_fuel_consumption(5.0),  Mazda_avg_speed(62.0f)
{


}
const char* Mazda::GetName()
{
    return "Mazda";

}
float Mazda::GetFuelCapacity()
{
    return Mazda_fuel_capacity;
}
float Mazda::GetFuelConsumption()
{
    return Mazda_fuel_consumption;

}
float Mazda::GetAverageSpeed()
{
    return Mazda_avg_speed;
}
void  Mazda:: adaptCharacteristics(Weather vreme)
{
    switch(vreme)
    {
        case Weather::Rain:
            this->Mazda_avg_speed =55.0f;
            this->Mazda_fuel_consumption=5.5f;
            break;
        case Weather::Sunny:
            this->Mazda_avg_speed = 70.0f;
            this->Mazda_fuel_consumption= 4.5f;
            break;
        case Weather::Snow:
            this->Mazda_avg_speed = 50.0f;
            this->Mazda_fuel_consumption=6.3f;
            break;
        default:
            break;

    }
}
