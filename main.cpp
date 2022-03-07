#include <iostream>
#include "Canvas.h"
#include <cstring>
using namespace std;
int main()
{

    Canvas c(30,30);
    c.Clear();
    /*c.DrawLine(1, 1, 9, 9, '$');
    c.Print();
    c.Clear();*/
    c.DrawCircle(12, 12, 2, '%');
    c.Print();
    c.Clear();
    c.FillCircle(12, 12, 2, '^');
    c.Print();
    c.Clear();
    c.SetPoint(20, 15, '%');
    c.Print();
    c.Clear();
    c.DrawRect(12, 12, 28, 28, '#' );
    c.Print();
    c.Clear();
    c.FillRect(12, 12, 28, 28, '@');
    c.Print();
    c.Clear();


    system("pause");
    return 0;
}
