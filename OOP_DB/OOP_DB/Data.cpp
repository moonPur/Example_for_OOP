#include "Data.h"

// тут реализуютс€ методы дл€ класса Data, объ€вленные в Data.h

Data::Data() // data for default constructor 
{
	initials.surname = "";
	initials.name = "";
	initials.patrinymic = "";

	date.day = 0;
	date.month = 0;
	date.year = 0;

	address.street = "";
	address.home = 0;

} //end Data default constructor 

Data::Data(Initials initials_, Date date_, Address address_) // data for constructor with variables 
{
	initials.surname = initials_.surname;
	initials.name = initials_.name;
	initials.patrinymic = initials_.patrinymic;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	address.street = address_.street;
	address.home = address_.home;
}

Data::~Data() { // не задавали ни какого поведени€ дл€ деструктора 

}

void Data::Print() {
	cout << "FIO: " << initials.surname << " " << initials.name << " " << initials.patrinymic << endl;
	cout << "Date of Birth: " << date.day << "." << date.month << "." << date.year << endl;
	cout << "Address: " << address.street << " st. " << address.home << endl;
}

void Data::DataEntry(Initials initials_, Date date_, Address address_) {
	initials.surname = initials_.surname;
	initials.name = initials_.name;
	initials.patrinymic = initials_.patrinymic;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	address.street = address_.street;
	address.home = address_.home;
}

Data& Data::operator = (Data d_o) {  // d_o old data 
	this->initials.surname = d_o.initials.surname;
	this->initials.name = d_o.initials.name;
	this->initials.patrinymic = d_o.initials.patrinymic;

	this->date.day = d_o.date.day;
	this->date.month = d_o.date.month;
	this->date.year = d_o.date.year;

	this->address.street = d_o.address.street;
	this->address.home = d_o.address.home;
	
	return * this;

	//d_n = d_o; data new = data old 
	//присваиваем новому экземпл€ру класса только что чсчитанные данные 
	// нам это нужно 
}