//
// Created by Miruna Savin on 3/7/2022.
//

#include "Canvas.h"
#include <iostream>
#include<cstring>
using namespace std;

Canvas::Canvas(int width, int height): m(height), n(width)
{
  this->matrix = (char**)(malloc ( n*sizeof(char *))); //n=randuri
    for(int i=0; i<n; i++)
       this-> matrix[i]=(char*)(malloc (m*sizeof(char*)));
    /*this->matrix = new char* [height];
    for (int i = 0; i < height; i++)
        this->matrix[i] = new char[width];*/


}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            if (( i - x )*(i-x) + ( j - y )*(j-y) >= ray*(ray-1) && ( i - x )*(i-x) + ( j - y )*(j-y) <= ray*(ray+1))

                matrix[i][j]=(int(ch));
            else matrix[i][j]=' ';
        }

}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{   for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if (((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray))
                this->matrix[i][j] = ch;
            else
                this->matrix[i][j] = ' ';
        }

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for(int i=0; i<n; i++)
           for(int j=0; j<m; j++)
           {
               if(j>=left and j<=right and i==top)
                   this->matrix[i][j]=(int (ch));
               if(j>=left and j<=right and i==bottom)
                   this->matrix[i][j]=(int (ch));
               if(i>=top and i<=bottom and j==left)
                   this->matrix[i][j]=(int (ch));
               if(i>=top and i<=bottom and j==right)
                   this->matrix[i][j]=(int (ch));
           }
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(i>= top && i<=bottom && j>=left && j<=right)
                this->matrix[i][j]=ch;
            else
                this->matrix[i][j]=' ';
        }
}
void Canvas::SetPoint(int x, int y, char ch)
{
    this->matrix[x][y]=ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int slope = 2*(y2-y1);
    int slope_error= slope - (x2-x1);
    for(int x=x1, y=y1; x<=x2; x++)
    {
        this->matrix[x][y]=ch;

        //adaugam slope pt a mari unghiul
        slope_error+=slope;

        //cand ajunge la limita, incrementam y-ul si schimbam slope ul
        if(slope_error>=0)
        {
            y++;
            slope_error=2*(x2-x1);
        }
    }
}

void Canvas::Print()
{
    for (int i=0; i<n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << this->matrix[i][j] <<' ';
        cout<<'\n';


    }
}

void Canvas::Clear()
{
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            this->matrix[i][j]=32;
    }
}