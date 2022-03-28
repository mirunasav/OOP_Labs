//
// Created by Miruna Savin on 3/28/2022.
//

#include "Mercedes.h"
#include<iostream>
#include<cstring>
using namespace std;

Mercedes::Mercedes(): Mercedes_fuel_capacity(40.0f), Mercedes_fuel_consumption(7.8f),  Mercedes_avg_speed(80.0f)
{


}
const char* Mercedes::GetName()
{
    return "Mercedes";

}
float  Mercedes::GetFuelCapacity()
{
    return Mercedes_fuel_capacity;
}
float  Mercedes::GetFuelConsumption()
{
    return Mercedes_fuel_consumption;

}
float Mercedes::GetAverageSpeed()
{
    return Mercedes_avg_speed;
}
void  Mercedes:: adaptCharacteristics(Weather vreme)
{
    switch(vreme)
    {
        case Weather::Rain:
            this->Mercedes_avg_speed =70.0f;
            this->Mercedes_fuel_consumption=8.2f;
            break;
        case Weather::Sunny:
            this->Mercedes_avg_speed = 85.0f;
            this->Mercedes_fuel_consumption= 7.0f;
            break;
        case Weather::Snow:
            this->Mercedes_avg_speed = 60.0f;
            this->Mercedes_fuel_consumption= 9.5f;
            break;
        default:
            break;

    }
}
