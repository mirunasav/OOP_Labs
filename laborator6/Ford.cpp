//
// Created by Miruna Savin on 3/28/2022.
//

#include "Ford.h"
#include<iostream>
#include<cstring>
using namespace std;

Ford::Ford(): Ford_fuel_capacity(18.0f), Ford_fuel_consumption(3.0),  Ford_avg_speed(40.0f)
{


}
const char* Ford::GetName()
{
    return "Mercedes";

}
float  Ford::GetFuelCapacity()
{
    return Ford_fuel_capacity;
}
float  Ford::GetFuelConsumption()
{
    return Ford_fuel_consumption;

}
float Ford::GetAverageSpeed()
{
    return Ford_avg_speed;
}
void  Ford:: adaptCharacteristics(Weather vreme)
{
    switch(vreme)
    {
        case Weather::Rain:
            this->Ford_avg_speed =35.0f;
            this->Ford_fuel_consumption=3.5f;
            break;
        case Weather::Sunny:
            this->Ford_avg_speed = 50.0f;
            this->Ford_fuel_consumption= 3.0f;
            break;
        case Weather::Snow:
            this->Ford_avg_speed = 35.0f;
            this->Ford_fuel_consumption=5.0f;
            break;
        default:
            break;

    }
}
