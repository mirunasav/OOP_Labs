//
// Created by Miruna Savin on 3/1/2022.
//

#ifndef LAB2EX2_STUDENTS_H
#define LAB2EX2_STUDENTS_H


class Students {
    char name[20];
    int math, english, history;
public:
    void setName(char *name);
     char *getName();

    void setMathGrade(int nota);
    void setEnglishGrade(int nota);
    void setHistoryGrade(int nota);

    int getMathGrade();
    int getEnglishGrade();
    int getHistoryGrade();
    float AverageGrade();
};





#endif //LAB2EX2_STUDENTS_H
