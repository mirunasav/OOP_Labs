//
// Created by Miruna Savin on 3/20/2022.
//

#ifndef LAB5_NUMBER_H
#define LAB5_NUMBER_H
#include<cstring>

class Number {
private:
    char *number;
    int base;

public:
    Number(const char *value, int base);// where base is between 2 and 16
    Number (int val);
    ~Number();

    Number(const Number &n) {
        base = n.base;
        number = new char[strlen(n.number) + 1];
        strcpy(number, n.number); //trebuie sa punem this?

    }

    Number(Number &&n) noexcept //&& pt ca e un obiect temporar
    {
        strcpy(number, n.number);
        base = n.base;
        n.number = nullptr;
    }

    // add operators and copy/move constructor
    bool operator>(const Number &n);

    bool operator<(const Number &n);

    bool operator>=(const Number &n);

    bool operator<=(const Number &n);

    bool operator==(const Number &n);

    Number& operator+=(const Number &n);

    Number& operator=(int val);// de ce punem aici &?  slide 55
    Number& operator=(const char *str);
    Number&  operator = (const Number &n);

    Number friend operator+(const Number &n1, const Number &n2);

    Number friend operator-(const Number &n1, const Number &n2);
    void friend TransformToBaseB(int n, int b, char *nr);
    void operator--();

    void operator--(int value);

    void operator++();

    void operator++(int value);
    char& operator [] (int index);
  //  char &operator new[](size_t t, const char *str, int base);//?? slide 57



    void SwitchBase(int newBase);

    void Print();

    int GetDigitsCount(); // returns the number of digits for the
    int GetBase();//returns the current base
};
#endif //LAB5_NUMBER_H
