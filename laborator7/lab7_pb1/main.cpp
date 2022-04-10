#include <iostream>
using namespace std;
float operator"" _Kelvin(unsigned long long int grade)
{
    return grade - 273.15;
}
float operator"" _Fahrenheit(unsigned long long int grade)
{
    return (grade-32)/1.8;
}
int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    printf("300 de grade Kelvin sunt %f grade Celsius \n", a);
    printf("120 de grade Fahrenheit sunt %f grade Celsius \n", b);
    return 0;
}
