#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "NumberList.h"
using namespace std;

int main()
{
    int x;
    NumberList nr1;
    nr1.Init();
    printf("Scrieti un numar:");
    {
        cin>>x;
        while(nr1.Add(x))
        {
            cin>>x;
        }

    }
    printf("Ati terminat de scris numerele\n");
    nr1.Sort();
    nr1.Print();
}