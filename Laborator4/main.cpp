
#include <iostream>
#include "Sort.h"
#include<cstring>
#include <initializer_list>
using namespace std;
int main() {

    Sort s1(5, 1, 100); //5 valori random din intervalul 1-100;
   cout<<"s1:"<<'\n';
   s1.Print();
    s1.BubbleSort(true);
    s1.Print();
    Sort s2({12, 28, 4, 29, 19, 3});//lista de initializare

    cout<<"s2:"<<'\n';
    s2.Print();
    s2.InsertSort(false);
    s2.Print();

    cout<<"s3:"<<'\n';
    int *a ;
    a= new int [5]{12, 34, 189, 102, 115};
    Sort s3(a, 5); //se poate implementa o fct pt size of a;
    s3.Print();

    s3.QuickSort(0, s3.GetElementsCount()-1, true);
    s3.Print();

    cout<<"s4:"<<'\n';

    Sort s4 (5, 12, 27, 190, 365, 102);
    s4.Print();
    cout<< s4.GetElementsCount()<<'\n';
    s3.QuickSort(0, s4.GetElementsCount()-1, false);
    s4.Print();

    cout<<"s5:"<<'\n';
    char s[]= "20,10,2,5,40";
    Sort s5(s);
    s5.Print();
   cout<< s5.GetElementFromIndex(3)<<'\n';




    system("pause");
    return 0;
}
