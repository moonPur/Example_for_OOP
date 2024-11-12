#pragma once
// подключение библиотек, которыми мы будеи пользоваться 
#include <iostream>
#include <string>
#include <fstream> // for file
#include <limits>
#include <Windows.h>

using namespace std;

/* Data is:
1. FIO
2. Date of birth
3. Adress 
*/

struct Initials {
	string surname,
		name,
		patrinymic;
};

struct Date {
	int day,
		month,
		year;
};

struct Address {
	string street; // original was city
	int home;
};


// class prototype 

class Data {
private:
	Initials initials;
	Date date;
	Address address;

public:
	Data(); // default constructor
	Data(Initials initials_, Date date_, Address address_); // constructor with parametrs
	~Data(); 

	void Print();
	void DataEntry(Initials initials_, Date date_, Address address_);

	Initials GetInitials() { return initials; };
	Date GetDate() { return date; };
	Address GetAddress() { return address; };

	//перегрузка оператора "=" равно reload opeator 
	Data& operator = (Data d_o);
};

