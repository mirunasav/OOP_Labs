//
// Created by Miruna Savin on 3/7/2022.
//

#ifndef RPROBLEMA2LAB3_CANVAS_H
#define RPROBLEMA2LAB3_CANVAS_H
#include<iostream>
#include<cstring>
class Canvas

{

private:
    const int n, m; //dimensiunile
    char **matrix; //(char**)(malloc ( n*sizeof(char *))); //n=randuri

public:

    Canvas(int width,int height);

    void DrawCircle(int x, int y, int ray, char ch);

    void FillCircle(int x, int y, int ray, char ch);

    void DrawRect(int left, int top, int right, int bottom, char ch);

    void FillRect(int left, int top, int right, int bottom, char ch);

    void SetPoint(int x, int y, char ch);

    void DrawLine(int x1, int y1, int x2, int y2, char ch);

    void Print(); // shows what was printed

    void Clear(); // clears the canvas

};



#endif //RPROBLEMA2LAB3_CANVAS_H
