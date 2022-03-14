#include <bits/stdc++.h>
#include "Math.h"
using namespace std;

int main()
{
    int a=10, b=20, c=30;
    double x=10.5, y=20.5, z=30.6;
    char *p="123", *pp ="475";

    cout<<Math::Add(a, b)<<"\n";
    cout<<Math::Add(a, b,c)<<"\n";
    cout<<Math::Add(x, y)<<"\n";
    cout<<Math::Add(x, y, z)<<"\n";
    cout<<Math::Mul(a, b)<<"\n";
    cout<<Math::Mul(a, b,c)<<"\n";
    cout<<Math::Mul(x, y)<<"\n";
    cout<<Math::Mul(x, y, z)<<"\n";
    cout<<Math::Add(4, a, b, c, 12)<<"\n";
    cout<<Math:: Add(p, pp)<<"\n";

    system("pause");
    return 0;
}