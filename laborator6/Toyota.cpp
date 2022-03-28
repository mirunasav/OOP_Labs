//
// Created by Miruna Savin on 3/28/2022.
//

#include "Toyota.h"
#include<iostream>
#include<cstring>
using namespace std;

Toyota::Toyota(): Toyota_fuel_capacity(25.0f), Toyota_fuel_consumption(4.8f),  Toyota_avg_speed(65.0f)
{


}
const char* Toyota::GetName()
{
    return "Toyota";

}
float Toyota::GetFuelCapacity()
{
    return Toyota_fuel_capacity;
}
float Toyota::GetFuelConsumption()\
{
    return Toyota_fuel_consumption;

}
float Toyota::GetAverageSpeed()
{
    return Toyota_avg_speed;
}
void Toyota::adaptCharacteristics(Weather vreme)
{
    switch(vreme)
    {
        case Weather::Rain:
            this->Toyota_avg_speed = 60.0f;
            this->Toyota_fuel_consumption= 5.5f;
            break;
        case Weather::Sunny:
            this->Toyota_avg_speed = 70.0f;
            this->Toyota_fuel_consumption= 4.0f;
            break;
        case Weather::Snow:
            this->Toyota_avg_speed = 40.0f;
            this->Toyota_fuel_consumption= 6.0f;
            break;
        default:
            break;

    }
}