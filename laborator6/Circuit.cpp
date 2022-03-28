//
// Created by Miruna Savin on 3/28/2022.
//

#include "Circuit.h"
#include<iostream>
Circuit::Circuit(): length(0), nr_cars(0),vreme(Weather::Sunny), max_index(5)
{
    cars = new Car * [nr_cars]; //pointer catre Car?

}
Circuit ::Circuit(const Circuit& c)
{
    this->length=c.length;
    this->nr_cars=c.nr_cars;
    this->vreme=c.vreme;
    std:: cout<<"am apelat constructorul Circuit(const)";
}
void Circuit::SetLength(float length_value)
{
    this->length=length_value;
}
void Circuit::SetWeather(Weather vreme)
{
    this->vreme=vreme;
}
void Circuit::AddCar(Car *c)
{
    Car **temp;
    this->nr_cars++;
    temp = new Car * [nr_cars];
    for(int i=0; i<nr_cars; i++)
        temp[i]=cars[i];
    delete[] cars;
    cars=temp;
    cars[nr_cars-1]=c;
    //practic fac un nou vector de pointer, de dimensiunea noului numar de masini;
    //copiez in vectorul temp toate elementele care erau deja in vectorul cars;
    //sterg cars; cars devine temp; pe ultima pozitie adaug elementul c;
    //cum mai puteam proceda?

}
void Circuit::Race()
{
    for(int i=0; i<nr_cars; i++)
        cars[i]->adaptCharacteristics(vreme);
    ranks=new float [nr_cars];
    for(int i=0; i<nr_cars; i++)
        //verificam ce masini nu termina cursa
    {
        if(this->length/100*cars[i]->GetFuelConsumption()>cars[i]->GetFuelCapacity())
            ranks[i]=-1;
    }
    for(int i=0; i<nr_cars; i++)
    {
        if(ranks[i]!=-1) //aflam in cat timp termina cursa masinile
        {
            ranks[i]=this->length/cars[i]->GetAverageSpeed();
        }
    }
    //ordonam
    for(int i=0; i<nr_cars-1; i++)

        for(int j=i+1; j<nr_cars; j++)
        {
            if(ranks[i] > ranks[j])
            {
                //interschimba atat valorile din ranks, cat si ordinea masinilor din cars
                Car* aux;
                aux=cars[i];
                cars[i]=cars[j];
                cars[j]=aux;

                float aux1;
                aux1=ranks[i];
                ranks[i]=ranks[j];
                ranks[j]=aux1;

            }
        }

}
void Circuit::ShowFinalRanks()
{
    int pozitie=0;
    for(int i =0; i<nr_cars; i++)
    {
        if(ranks[i]!=-1)
        {
            pozitie++;
            std:: cout<<cars[i]->GetName()<<" a terminat pe locul "<<pozitie<<" cu timpul "<< ranks[i]<<" h\n";
        }
    }
}
void Circuit::ShowWhodidNotFinish()
{
    for(int i=0; i<nr_cars; i++) {
        if (ranks[i] == -1)
            std::cout<<cars[i]->GetName()<<" nu a terminat cursa\n";
    }
}