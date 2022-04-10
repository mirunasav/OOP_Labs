//
// Created by Miruna Savin on 4/4/2022.
//

#ifndef LAB7_PB2_VECTOR_H
#define LAB7_PB2_VECTOR_H
#include <stdlib.h>
#include <iostream>
using namespace std;
template <class T>

int compare(T t1, T t2)
{
    if(t1<t2)
        return -1;
    if(t1>t2)
        return 1;
    return 0; //daca sunt egale
}
template <class T>
class Vector {
    T* vector;
    int size;
    int count;
   // int error;
public:
   // typedef int (*CompareCallBack)(const T& t1, const T& t2);

    Vector()
    {
        size = 100;
        count = 0;
        vector = (T*)malloc(100*sizeof(T));
    }
    void push(const T& value)
    {
        if(count < size)
        {
            vector[count++] = value;

        }
        else //dublam dimensiunea vectorului
        {
            size*=2;
            vector = (int*)realloc(vector, size *sizeof(T));
            vector[count++]=value;
        }
    }
    T& Pop()
    {
        return vector[count -1];
    }
    void remove(int index)
    {
        if(index<count) {
            count--;
            for (int j = index; j < count; j++)
                vector[j] = vector[j + 1];


        }

    }
    void insert(int index, T& value)
    {
        if(index<=count)
        {
            for(int i=count; i>=index; i--)
                vector[i]=vector[i-1];
            vector[index] = value;
            count++;
        }
    }
    T& get(const T& value)
    {
        for(int i=0; i< count; i++)
            if(vector[i]==value)
                return (T&) this->vector[i];
    }
    T& set(int index,const T& value)
    {
        if(index<count)
            vector[index] = value;
    }
  int firstIndexOf(const T& value,int (*callback)(T, T) )
    {
        if(callback != nullptr)
        {
            for (int i = 0; i < count; i++) {
                if (callback(vector[i], value) == 0)
                    return i;
            }
        }
        else// altfel vom folosi ==
        {
            for(int i=0; i< count; i++) {
                if (vector[i]==value)
                    return i;
            }

        }


    }
    void sort(int (*callback)(T, T) )
    {
        if(callback != nullptr)

            for(int i=0; i< count -1; i++)
                for(int j = i+1; j < count; j++)
                {
                    if(callback(vector[i],vector[j]) == 1)
                        swap(vector[i], vector[j]);
                }
        else
        {
            for(int i=0; i< count -1; i++)
                for(int j = i+1; j< count; j++)
                {
                    if(vector[i]>vector[j])
                        swap(vector[i], vector[j]);
                }
        }

    }
   int Count()
   {
       return this->count;
   }
   void Print()
   {
       for(int i=0; i< count; i++)
           cout<<vector[i]<<' ';
       cout<<'\n';
   }
};


#endif //LAB7_PB2_VECTOR_H
