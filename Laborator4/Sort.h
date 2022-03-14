//
// Created by Miruna Savin on 3/14/2022.
//

#ifndef LABORATOR4_SORT_H
#define LABORATOR4_SORT_H

using namespace std;
class Sort {
private:
    int count; //nr elemente
    int *v; //the array

public:

    Sort(int nr,int min, int max);
   Sort( initializer_list <int> l);
    Sort(int a[], int nr);
    Sort(int nr,...);
    Sort(char *str);


    void InsertSort(bool ascendent);

    void QuickSort(int low, int high, bool ascendent);

    void BubbleSort(bool ascendent);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};


#endif //LABORATOR4_SORT_H
