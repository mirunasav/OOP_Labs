#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Students.h"
#include "global.h"
using namespace std;


int main()
{
    Students s1, s2;

    s1.setName((char*)"Ovidiu");
    s1.setEnglishGrade(8);
    s1.setHistoryGrade(9);
    s1.setMathGrade(5);

    s2.setName((char*)"Alina");
    s2.setEnglishGrade(10);
    s2.setHistoryGrade(6);
    s2.setMathGrade(5);


    printf("S1 |nume : %s | nota: %2.2f\n", s1.getName(), s1.AverageGrade());
    //am vrut sa limitez la 2 zecimale media
   printf("S2 |nume : %s | nota: %2.2f\n", s2.getName(), s2.AverageGrade());

   //verificam functiile de comparare nume, note si average
   int c=0;

 c= compare_name(s1.getName(), s2.getName());
 //aici ii voi afisa  alfabetic
    switch (c)
    {
        case 1 : printf("Nume: %s %s \n", s2.getName(), s1.getName()); break;
        case -1: printf("Nume: %s %s \n", s1.getName(), s2.getName());break;
        case 0:  printf("Nume:  %s  \n",  s2.getName());break;
    }


 c= compare_AverageGrade(s1.AverageGrade(), s2.AverageGrade());
//la note, afisam doar persoana cu cea mai mare nota, si o specificam
    switch (c)
    {
        case 1 : printf("MaxAverageGrade: %s %2.2f \n",s1.getName(), s1.AverageGrade()); break;
        case -1:  printf("MaxAverageGrade: %s %2.2f \n", s2.getName(),s2.AverageGrade()); break;
        case 0:  printf("MaxAverageGrade: Cei doi au aceeasi medie: %2.2f \n", s1.AverageGrade()); break;
    }


    c= compare_MathGrade(s1.getMathGrade(), s2.getMathGrade());

//la note, afisam doar persoana cu cea mai mare nota, si o specificam
    switch (c)
    {
        case 1 : printf("MaxMath: %s %d \n",s1.getName(), s1.getMathGrade()); break;
        case -1:  printf("MaxMath: %s %d \n", s2.getName(),s2.getMathGrade()); break;
        case 0:  printf("MaxMath: Cei doi au aceeasi medie: %d \n", s1.getMathGrade()); break;
    }


    c= compare_HistoryGrade(s1.getHistoryGrade(), s2.getHistoryGrade());
//la note, afisam doar persoana cu cea mai mare nota, si o specificam
    switch (c)
    {
        case 1 : printf("MaxHistory: %s %d \n",s1.getName(), s1.getHistoryGrade()); break;
        case -1:  printf("MaxHistory: %s %d \n", s2.getName(),s2.getHistoryGrade()); break;
        case 0:  printf("MaxHistory: Cei doi au aceeasi medie: %d \n", s1.getHistoryGrade()); break;
    }


    c= compare_EnglishGrade(s1.getEnglishGrade(), s2.getEnglishGrade());
//la note, afisam doar persoana cu cea mai mare nota, si o specificam
    switch (c)
    {
        case 1 : printf("MaxEnglish: %s %d \n",s1.getName(), s1.getEnglishGrade()); break;
        case -1:  printf("MaxEnglish: %s %d \n", s2.getName(),s2.getEnglishGrade()); break;
        case 0:  printf("MaxEnglish: Cei doi au aceeasi medie: %d\n", s1.getEnglishGrade()); break;
    }


    system("pause");
    return 0;
}
