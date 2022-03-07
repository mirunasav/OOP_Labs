#include <iostream>
#include "Canvas.h"
#include <cstring>
using namespace std;
int main()
{

    Canvas c(20,20);
    c.Clear();
    c.DrawLine(1, 1, 9, 9, '$');
    c.Print();
    c.Clear();
    c.DrawCircle(10,10,3, '%');
    c.Print();
    c.Clear();
    c.FillCircle(12, 12, 2, '^');
    c.Print();
    c.Clear();
    c.SetPoint(19, 15, '%');
    c.Print();
    c.Clear();
    c.DrawRect(12, 12, 19, 19, '#' );
    c.Print();
    c.Clear();
    c.FillRect(12, 12, 19, 19, '@');
    c.Print();
    c.Clear();


    system("pause");
    return 0;
}
