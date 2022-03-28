//
// Created by Miruna Savin on 3/28/2022.
//


#include<iostream>
#include<cstring>
#include "Dacia.h"
using namespace std;

Dacia::Dacia(): Dacia_fuel_capacity(20.0f), Dacia_fuel_consumption(5.0f),  Dacia_avg_speed(60.0f)
{


}
const char* Dacia::GetName()
{
    return "Dacia";

}
float  Dacia::GetFuelCapacity()
{
    return Dacia_fuel_capacity;
}
float  Dacia::GetFuelConsumption()\
{
    return Dacia_fuel_consumption;

}
float  Dacia::GetAverageSpeed()
{
    return Dacia_avg_speed;
}
void  Dacia:: adaptCharacteristics(Weather vreme)
{
    switch(vreme)
    {
        case Weather::Rain:
            this->Dacia_avg_speed = 42.0f;
            this->Dacia_fuel_consumption= 6.0f;
            break;
        case Weather::Sunny:
            this->Dacia_avg_speed = 65.0f;
            this->Dacia_fuel_consumption= 4.2f;
            break;
        case Weather::Snow:
            this->Dacia_avg_speed = 35.0f;
            this->Dacia_fuel_consumption= 7.0f;
            break;
        default:
            break;

    }
}
