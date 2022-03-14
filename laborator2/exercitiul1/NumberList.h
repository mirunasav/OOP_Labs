//
// Created by Miruna Savin on 2/28/2022.
//

#ifndef LAB2EX1_NUMBERLIST_H
#define LAB2EX1_NUMBERLIST_H


class NumberList
{
    int numbers[11];
    int count;
public:
    void Init();
    bool Add(int x) ;//adauga x la lista de numere si creste countul,
                    // daca count>=10, se returneaza false

    void Sort(); //sorteaza vectorul
    void Print(); //printeaza vectorul curent

};


#endif //LAB2EX1_NUMBERLIST_H
