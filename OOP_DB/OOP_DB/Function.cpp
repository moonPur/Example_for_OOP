#include "Function.h"
// тут задана сама логика, описанных в заголовочном файлк Function.h прототипов функций  


// в этой функции данные передаются по ссылке, точнее массив передается по ссылке, потому что 
void DataEntry(Data* (&d), int& n) // input data manualy 
{
	// временные переменные 
	Initials initials;
	Date date;
	Address address;

	cout << "Input size off array data: ";
	cin >> n;

	// массив у нас динамический выделяем память под него
	d = new Data[n];



	// input data 
	for (int i = 0; i < n; i++) {
		cout << "Enter FIO for " << i + 1 <<  " person: " << endl;
		cin >> initials.surname  >> initials.name >> initials.patrinymic;

		cout << "Enter date of birth for" << i + 1 << " person: " << endl;
		cin >> date.day >> date.month >> date.year;

		cout << "Enter address for " << i + 1 << " person: " << endl;
		cin >>address.street >> address.home;  

		// добавляем данные в наш массив класс Date 
		d[i].DataEntry(initials, date, address);

		cout << "__________________________________________\n";

	}// end for 
}

void DataReading(Data* (&d), int& n, string fileName) // input data from file 
{
	ifstream reading(fileName); // create stream for reading from file 

	if (reading) {
		Initials initials;
		Date date;
		Address address;

		reading >> n;
		d = new Data[n];

		// input data 
		for (int i = 0; i < n; i++) {

			reading >> initials.surname >> initials.name >> initials.patrinymic;
			reading >> date.day >> date.month >> date.year;
			reading >> address.street >> address.home;
			// добавляем данные в наш массив класс Date 
			d[i].DataEntry(initials, date, address);
		}// end for 

		cout << "Data from file is reading" << endl;
	} // end if 
	else
		cout << "Error cann't open file" << endl;

	reading.close(); // закрыли файл

} // end void DataReading

void Print(Data* d, int n) //  n and d without &
{
	for (int i = 0; i < n; i++) {
		cout << "Data No." << i + 1 << endl;
		d[i].Print();
		cout << "__________________________________________\n";
	}// end for 

}

void DataChange(Data* d, int n) //  n and d without &
{
	// временные переменные 
	Initials initials;
	Date date;
	Address address;
	int _n;

	cout << "Input position number of element that you whant to change (from 1 to" << n << "):";
	cin >> _n;
	_n--; // decrease for 1, because arrays start from zero

	if (_n >= 0 && _n < n) {
		cout << "Input new person FIO: ";
		cin >> initials.surname >> initials.name >> initials.patrinymic;

		cout << "Enter new person date of birth " << endl;
		cin >> date.day >> date.month >> date.year;

		cout << "Enter new person address " << endl;
		cin >> address.street >> address.home;

		// добавляем данные в наш массив класс Date 
		d[_n].DataEntry(initials, date, address);
	}//end if 
	else
		cout << "Input data was incorrect!" << endl;
	// after this message we out of DataChange function 
}

void Copy(Data* d_n, Data* d_o, int n) //  n and d without &
{
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void AddData(Data* (&d), int& n) // 
{
	// временные переменные 
	Initials initials;
	Date date;
	Address address;
	Data* buf = new Data[n]; // временный массив для новых данных
	int size = n, new_size = ++n; // сполько было данных и новый размер для выделенных

	Copy(buf, d, size); //function that we have upper
	// here we copy to buff
	d = new Data[new_size]; // here we delete/overwrite previous data, when reinitialize d 

	Copy(d, buf, size); // copy to d from buf

	cout << "Input person FIO that you want to add: ";
	cin >> initials.surname >> initials.name >> initials.patrinymic;

	cout << "Enter person date of birth that you want to add " << endl;
	cin >> date.day >> date.month >> date.year;

	cout << "Enter person address that you want to add " << endl;
	cin >> address.street >> address.home;
	// добавляем данные в наш массив класс Date 
	d[size].DataEntry(initials, date, address); // согласно 123 строке мы добавляем в конец (проверить это)

	cout << "Your data was added!" << endl;

	delete[] buf;
}

void DeleteData(Data* (&d), int& n) // 
{
	int _n;
	Data* buf = new Data[n];

	cout << "Input position number of element that you whant to DELETE (from 1 to" << n << "):";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		Copy(buf, d, n);
		int q = 0;
		_n--;

		d = new Data[n];

		for (int i = 0; i <= n; i++) {
			if (i != _n) {  // если у нас не выбранный носмер 
				d[q] = buf[i]; // то мы его сохраняем 
				q++;
			} //end if (i != _n)
		}// end for 
		cout << "Chosen data was deleted" << endl;  // past from "choose"
	}// end if 
	else
		cout << "Input data was incorrect!" << endl;

	delete[] buf;
}

void SortingData(Data* d, int n) //  n and d without &
{
	Data buf;
	int numOfSorted = 0;

	// bubble sort
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i].GetInitials().surname > d[j].GetInitials().surname) {
				buf = d[i];
				d[i] = d[j];
				d[j] = buf; 
			
				numOfSorted++;
			}// end if 
		} // enf for j
	}// end for i
}

void SaveData (Data* d, int n, string fileName) //  n and d without &
{
	ofstream record(fileName); // поток для записи

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i].GetInitials().surname << " " << d[i].GetInitials().name << " " << d[i].GetInitials().patrinymic << endl;
			record << d[i].GetDate().day << "." << d[i].GetDate().month << "." << d[i].GetDate().year;
			record << d[i].GetAddress().street << " st." << d[i].GetAddress().home;

			if (i < n - 1)
				record << endl; // если у нас не последний элемент списка, то после посделней строчким будет ставится endl
		}// end for
	} // end if record
	else 
		cout << "Error cann't open file" << endl;

	cout << "Your data was sawed to " << fileName << endl;

	record.close();

}