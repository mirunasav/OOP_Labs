//
// Created by Miruna Savin on 3/20/2022.
//

#include "Number.h"
#include<cstring>
#include <iostream>
using namespace std;

void reverse( char *str)//reverse string
{
    int l=strlen(str);
    int i;
    for(i=0;i<l/2; i++)
    {
        char temp=str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=temp;
    }

}
char chVal(int num)//converteste un nr la echivalentul sau in ascii
{
    if(num>=0&&num<=9)
        return (char)(num+'0');
    else
        return (char)(num - 10 + 'A');
}

int val( char c)
{
    if(c>='0' && c<='9')
        return (int)c-'0';
    else
        return (int) c -'A'+10; //daca nr e intr-o baza mai mare decat 10;

}


void TransformToBaseB(int n, int b, char *nr) //transforma un int in char intr-o anumita baza
{
    int i=0;
    while(n>0)
    {
        nr[i++]=chVal(n%b);
        n/=b;
    }
    nr[i]='\0';
    reverse(nr);
}
int TransformToBaseTen(const char *c, int b)//transforma un char in baza 10
{
    int l=strlen(c);
    int nr=0, p=1;
    for (int i=l-1; i>=0; i--)
    {
        nr=nr+=val(c[i])*p;
        p=p*b;
    }
    return nr;

}

//CONSTRUCTORII

Number::Number(const char * value, int base) {
    this->base = base;
    number = new char[strlen(value) + 1];
    memcpy(number, value, strlen(value));
    number[strlen(value)] = '\0';
}
Number::Number (int val)
{
    char *rez;
    //trebuie sa pun valoarea in this->base, apoi sa o aloc lui this->number
    //pas 1: tb sa stiu cate cifre are in baza 10
    int cpy=val, nrcif = 0;
    while (cpy)
    {
        cpy/=10;
        nrcif++;
    }
    rez = new char [nrcif+1];
    TransformToBaseB(val, 10, rez);
    this->number = new char [nrcif + 1];
    strcpy(this->number,rez);
    this->base = 10;

}


//DESTRUCTORUL
Number::~Number()
{
    delete number;
    number=nullptr;
    base=0;
}

void Number:: SwitchBase(int newBase)
{
    //mai intai facem conversia in baza 10
    int l=strlen(this->number);
    int nr = 0, p = 1;
    //convertim din this->base in baza 10;
    for(int i= l-1; i>=0; i--)
    {
        nr+=val(number[i])*p;
        p=p*base;
    }

    //convertim din baza 10, in newBase
    int i = 0;
    char * rez;
    int copy=nr, numcif=0;
    //numaram cate cifre are numarul in newBase
    while(copy){
        copy/=newBase;
        numcif++;
    }
    rez = new char [numcif + 1];
    while(nr>0)
    {
        rez[i++]=chVal(nr % newBase);
        nr/=newBase;
    }
    rez[i]='\0';
    //inversam rezultatul
    reverse(rez);

    strcpy(number, rez);

    this->base=newBase;


}
void Number::Print()
{
    cout<<this->number<<'\n';
}
int Number::GetDigitsCount()
{
    return strlen(this->number);

}// returns the number of digits for the
int Number:: GetBase(){
    return this->base;
}//returns the current base

//OPERATORII
bool Number::operator > (const Number &n)
{
    int nr1=TransformToBaseTen(this->number, this->base);
    int nr2= TransformToBaseTen(n.number, n.base);
    if(nr1>nr2)
        return true;
    else
        return false;


}
bool Number::operator < (const Number &n)
{
    int nr1=TransformToBaseTen(this->number, this->base);
    int nr2= TransformToBaseTen(n.number, n.base);
    if(nr1<nr2)
        return true;
    else
        return false;



}
bool Number::operator >= (const Number &n)
{
    int nr1=TransformToBaseTen(this->number, this->base);
    int nr2= TransformToBaseTen(n.number, n.base);
    if(nr1>=nr2)
        return true;
    else
        return false;

}
bool Number::operator <= (const Number &n)
{
    int nr1=TransformToBaseTen(this->number, this->base);
    int nr2= TransformToBaseTen(n.number, n.base);
    if(nr1<=nr2)
        return true;
    else
        return false;

}
bool Number:: operator == (const Number &n)
{
    int nr1=TransformToBaseTen(this->number, this->base);
    int nr2= TransformToBaseTen(n.number, n.base);
    if(nr1==nr2)
        return true;
    else
        return false;

}
Number& Number:: operator +=(const Number &n)
{
    int maxBase;
    if(this->base > n.base)
        maxBase=this->base;
    else
        maxBase=n.base;
    int nr1= TransformToBaseTen(this->number, this->base);
    int nr2= TransformToBaseTen(n.number, n.base);
    int sum = nr1+nr2;
    //transform sum in this->base;
    int cpy = sum, nrcif=0;
    while(cpy)
    {
       cpy/=this->base;
        nrcif++;
    }
    char *res = new char [nrcif+1];
    TransformToBaseB(sum, this->base, res);
    delete this->number;
    this->number = new char [nrcif + 1];
    strcpy(this->number, res);

}
Number& Number:: operator =(int val)
{
     char *rez;
     //trebuie sa pun valoarea in this->base, apoi sa o aloc lui this->number
     //pas 1: tb sa stiu cate cifre are in baza 10
     int cpy=val, nrcif = 0;
     while (cpy)
     {
         cpy/=10;
         nrcif++;
     }
     rez = new char [nrcif+1];
    TransformToBaseB(val, this->base, rez);
    this->number = new char [nrcif + 1];
    strcpy(this->number,rez);

    return *this;


}
Number& Number:: operator =(const char *str)//assignment
{
    delete this->number;
    strcpy(this->number, str);
    return *this;
}
Number & Number:: operator = (const Number &n)
{
    delete this->number;
    this->number = new char [strlen(n.number)+1];
    strcpy(this->number, n.number);
    this->base=n.base;
    return *this;
}
Number operator + (const Number &n1, const Number &n2) //friend
{
    int maxBase;
    if(n1.base>n2.base)
        maxBase=n1.base;
    else
        maxBase=n2.base;
    int nr1= TransformToBaseTen(n1.number, n1.base);
    int nr2= TransformToBaseTen(n2.number, n2.base);
    int sum = nr1 + nr2;
    //acum transformam suma in baza maxima;
    char *rez;
    int cpy=sum;
    int nr=0;
    while(cpy>0)
    {
        cpy/=maxBase;
        nr++;

    }
    rez = new char [nr+1];
    TransformToBaseB(sum, maxBase, rez);
    Number tempNr(rez, maxBase);
    return tempNr;

}
Number  operator - (const Number &n1, const Number &n2) //friend
{
    int maxBase;
    if(n1.base>n2.base)
        maxBase=n1.base;
    else
        maxBase=n2.base;
    int nr1= TransformToBaseTen(n1.number, n1.base);
    int nr2= TransformToBaseTen(n2.number, n2.base);
    int diff = nr1 - nr2;
    //acum transformam suma in baza maxima;
    char *rez;
    int cpy=diff;
    int nr=0;
    while(cpy>0)
    {
        cpy/=maxBase;
        nr++;

    }
    rez = new char [nr+1];
    TransformToBaseB(diff, maxBase, rez);
    Number tempNr(rez, maxBase);
    return tempNr;

}
void Number::operator -- ()//prefixat, deci stergem prima cifra din nr;
{
    strcpy(number, number +1);

}
void Number:: operator -- (int value)//postfixat, deci stergem ultima cifra
{
 this->number[strlen(number)-1]='\0';
}
void Number::operator ++()//forma prefixata
{
    int l = strlen(this->number);
    //transformam nr in baza 10, adunam 1, in transformam inapoi in this->base;
    int nr = TransformToBaseTen(this->number, this->base);
    nr++;
    char * rez;
    rez = new char [l + 2];
    TransformToBaseB(nr, this->base, rez);
    delete this->number;
    this->number = new char [l+2];
    strcpy(this->number, rez);

}
void Number:: operator ++(int value)
{
    int l = strlen(this->number);
    //transformam nr in baza 10, adunam 1, in transformam inapoi in this->base;
    int nr = TransformToBaseTen(this->number, this->base);
    nr++;
    char * rez;
    rez = new char [l + 2];
    TransformToBaseB(nr, this->base, rez);
    delete this->number;
    this->number = new char [l+2];
    strcpy(this->number, rez);
}
char& Number::operator [] (int index)
{
    return this->number[index];
}
//char &operator new [] (size_t t, const char *str, int base)
//?? slide 57