#include "Students.h"
#include <string.h>
#include <stdio.h>

void Students::setName(char *nume)
{
    strcpy_s(this->name, 20, nume);
}
void Students::setEnglishGrade(int nota)
{
    this->english=nota;
}

void Students::setMathGrade(int nota)
{
    this->math=nota;
}

void Students::setHistoryGrade(int nota)
{
    this->history=nota;
}
int Students::getMathGrade()
{
    return this->math;

}

int Students::getEnglishGrade()
{
    return this->english;
}

int Students::getHistoryGrade()
{
  return this->history;
}
float Students::AverageGrade()
{ float f=0;
    f= this->math+this->english+this->history;
    f/=3;
    return f;

}
char *Students:: getName()
{
    return this->name;
}