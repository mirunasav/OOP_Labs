//
// Created by Miruna Savin on 3/7/2022.
//

#include "Math.h"
#include <bits/stdc++.h>

using namespace std;

int Math::Add(int a, int b)
{
    return a+b;
}

int Math::Add(int a, int b, int c)
{
    return a+b+c;
}

int Math::Add(double x,double y)
{
    return x+y;
}

int Math::Add(double x,double y,double z)
{
    return x+y+z;
}

int Math::Mul(int a,int b)
{
    return a*b;
}

int Math::Mul(int a,int b,int c)
{
    return a*b*c;
}

int Math::Mul(double x,double y)
{
    return x*y;
}

int Math::Mul(double x,double y, double z)
{
    return x*y*z;
}

int Math::Add(int count, ... ) // sums up a list of integers
{
    int sum=0;
    va_list v;
    va_start(v,count);
    for (int i=0;i<count;i++)
    {
        int val = va_arg(v,int);
        sum+=val;
    }
    va_end(v);

    return sum;
}

char* Math::Add(const char * a, const char * b)
{
    char *buffer;
    buffer = (char*)malloc (strlen(a)+strlen(b)+1 );
    if(buffer == NULL) return nullptr;
    if( a==NULL ||b==NULL) return nullptr;

    strcpy(buffer, a);
    strcat(buffer, b);
    buffer[strlen(a)+strlen(b)]='\0';
    return buffer;

}