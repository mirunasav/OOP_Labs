//
// Created by Miruna Savin on 3/14/2022.
//
//#define_CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<initializer_list>
#include "Sort.h"
#include <cstdarg>
#include<cstring>
#include<time.h>

using namespace std;
Sort::Sort( int nr,int min, int max): count(nr)
{
    this->v=new int [nr];
    srand((unsigned)time(0));
    for(int i=0; i<nr; i++)
        v[i]=rand()%(max-min+1)+min;
}
Sort:: Sort( initializer_list <int> l)
{
int j = -1;
count=l.size();
this->v=new int [count];
for(int i:l)
    v[++j]=i;
}

Sort::Sort(int a[], int nr)
{
    this->v=new int [nr];
    for (int i=0; i<nr; i++) {
        v[i] = a[i];
    }
    this->count=nr;
}

Sort::Sort(int nr,...): count(nr)
{
    this->v=new int [nr];
    va_list ptr;

    va_start(ptr, nr);

    for(int i=0; i<nr; i++)
        v[i]=va_arg(ptr, int);
    va_end(ptr);

}
Sort::Sort(char *str)
{   int nr=0, i=0;
    while(str[i]!='\0')
    {
        if(str[i]==',')
            nr++;
        i++;
    }
    nr++;
    this->v=new int [nr];
   this-> count=nr;
    char *p;
    p=strtok(str, ",");
    i=-1;
    while(p!=nullptr)
    {

        int k=0, nr=0;
        while(p[k]!='\0')
        {
            nr=nr*10+(p[k]-'0');
            k++;
        }
        v[++i]=nr;
        p=strtok(NULL, ",");

    }

}

void Sort::InsertSort(bool ascendent)
{
     int i, key, j;
     for(i=1; i<GetElementsCount(); i++) {
         key = v[i];
         j = i - 1;
     if(ascendent) {
         while (j >= 0 && v[j] > key) {
             v[j + 1] = v[j];
             j--;
         }
     }
     else
     {
         while (j >= 0 && v[j] <key) {
             v[j + 1] = v[j];
             j--;
         }
     }
         v[j + 1] = key;
     }
}

void swap(int *a, int *b)//de ce lucram cu pointeri aici? dc folosim *
{
    int aux=*a;
    *a=*b;
    *b=aux;
}

int partition(int *arr, int low, int high, bool ascendent)
{
    int pivot= arr[high];
    int i = (low-1);

    for(int j=low; j<=high-1; j++)
    {
        if(ascendent)
        {
            if(arr[j]<pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        else
        {
            if(arr[j]>pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}
void Sort:: QuickSort(int low, int high, bool ascendent)
{
    if(low < high)
    {
        int pi = partition(v, low, high, ascendent);
        QuickSort(low, pi-1,ascendent);
        QuickSort(pi+1, high, ascendent);
    }
}

void Sort::BubbleSort(bool ascendent)
{
    int i, j;
    for(i=0; i<GetElementsCount()-1; i++)
        for(j=0; j<GetElementsCount()-i-1; j++)
        {
            if(ascendent==true)//sortam crescator
            {
                if(v[j]>v[j+1])
                    swap(&v[j] ,&v[j+1]);
            }
            else //sortam descrescator
                if(v[j]<v[j+1])
                    swap(&v[j], &v[j+1]);

        }


}


void Sort::Print()
{
    for(int i=0; i<GetElementsCount(); i++)
        cout<<v[i]<<' ';
    cout<<'\n';
}

int  Sort::GetElementsCount()
{
    return count;

}

int  Sort::GetElementFromIndex(int index)
{

        if(index<count)
            return this->v[index]; //de ce aici nu mai e nevoie de this si putem
            //scrie doar v[index]?
        return -1;
}

#include "Sort.h"
