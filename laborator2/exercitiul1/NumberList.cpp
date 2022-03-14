//
// Created by Miruna Savin on 2/28/2022.
//

#include "NumberList.h"
#include <string.h>
#include <stdio.h>
#include<iostream>
using namespace std;

void NumberList::Init()
{
this->count=0;

}
bool NumberList:: Add(int x)
{
    if(this->count>=10)
        return false;
    printf("count: %d\n", this->count);
    numbers[this->count]=x;
    this->count++;
printf("count: %d", this->count);
    return true;
}
void  NumberList:: Sort()
{
    for(int i=0; i<9; i++)
    {
        for(int j=i+1; j<=9; j++)
        {
            if(this->numbers[i]>this->numbers[j])
                swap(this->numbers[i], this->numbers[j]);
        }
    }

}

void NumberList::  Print()
{
    printf("Numerele sunt:\n");
for(int i=0; i<=9; i++)
    printf(" %d ", this->numbers[i]);
}