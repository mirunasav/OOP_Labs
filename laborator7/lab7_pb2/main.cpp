#include <iostream>
#include <stdlib.h>
#include "Vector.h"
using namespace std;
int main() {
    Vector <int> v;
    v.push(5);
    v.push(4);
    v.push(7);
    v.push(2);
    v.push(9);
    v.push(3);
    v.Print();

    v.sort(compare);
    v.Print();

    v.remove(2);
    v.Print();

    cout<<v.firstIndexOf(7,compare)<<'\n';
    cout<<v.Pop()<<'\n';


    v.set(4, 5);
    v.get(9);
    v.Print();
    
    return 0;
}
