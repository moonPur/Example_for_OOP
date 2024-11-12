
#pragma once
// тут созданы прототипы функций, которые мы будем использовать 

#include "Data.h"

void DataEntry(Data* (&d), int& n); // input data manualy 
void DataReading(Data* (&d), int& n, string fileName); // input data from file 
void Print(Data* d, int n); //  n and d without &
void DataChange(Data* d, int n); //  n and d without &
void Copy(Data*d_n, Data* d_o, int n); //  n and d without &
void AddData(Data* (&d), int& n); // 
void DeleteData(Data* (&d), int& n); // 
void SortingData(Data* d, int n); //  n and d without &
void SaveData(Data* d, int n, string fileName); //  n and d without &