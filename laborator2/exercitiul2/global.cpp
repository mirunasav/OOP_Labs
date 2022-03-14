//
// Created by Miruna Savin on 3/1/2022.
//
#include <iostream>
#include "global.h"
#include <cstring>

int compare_name(char name1[20], char name2[20])
{
   int c= strcmp(name1, name2);
   if (c==0) return 0;
   if(c>0) return 1; //daca studentul 2 are un numar "mai mare alfabetic" decat primul;
   return -1;

}
int compare_EnglishGrade(int nota1, int nota2)
{
if(nota1==nota2) return 0;
if(nota1>nota2) return 1;
return -1;
}
int compare_HistoryGrade(int nota1, int nota2)
{
    if(nota1==nota2) return 0;
    if(nota1>nota2) return 1;
    return -1;

}
int compare_MathGrade(int nota1, int nota2)
{
    if(nota1==nota2) return 0;
    if(nota1>nota2) return 1;
    return -1;
}
int compare_AverageGrade(float nota1, float nota2)
{
    if(nota1==nota2) return 0;
    if(nota1>nota2) return 1;
    return -1;

}

