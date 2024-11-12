
 #include "Function.h"

int _startMenu; // global variable 

void Menu() {
	cout << "Select action: " << endl //cout include in data.h 
		<< "(11) Close program" << endl
		<< "(1) Input data" << endl
		<< "(2) Show data in console" << endl
		<< "(3) Change data" << endl
		<< "(4) Add data if you alredy have data from (1)" << endl
		<< "(5) Delete data" << endl
		<< "(6) Sort data" << endl
		<< "(7) Save data" << endl
		<< "Your choice is: ";
	cin >> _startMenu;
}


void main() {

	
	int _actions;
	string fileName;

	int _size = 0; //количество данных

	Data* d = new Data[_size]; // массив данных

	while (_startMenu != 11) {
		Menu();
		switch (_startMenu) {
		case 1:
			system("cls");

			cout << "Input data from file (1) or manialy (2)?" << endl;
			cout << "Your choise is ";
			cin >> _actions;
			system("cls");

			if (_actions == 2) {
				//данные вводим с клавиатуры 
				DataEntry(d, _size); // this in header or another cpp
			}
			if ( _actions == 1){
				// input from file 
				//cout << "Input file name " << endl;
				//cin >> fileName; // txt file 

				//DataReading(d, _size, fileName);

				DataReading(d, _size, "Input.txt");
			}
			if (_actions != 2 && _actions != 1){
				cout << "Wrong action, please try again from the start" << endl;
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');  // был конфликт с max от Windows.h 
			}
			system("pause");
			system("cls");
			break;

		case 2:
			system("cls");


			if (_size != 0)
				Print(d, _size);
			else
				cout << "There is no data" << endl;
			
			system("pause");
			system("cls");
			break;

		case 3:
			system("cls");
			if (_size != 0)
				DataChange(d, _size);
			else
				cout << "There is no data" << endl;
			
			system("pause");
			system("cls");
			break;

		case 4:
			system("cls");
			if (_size != 0)
				AddData(d, _size);
			else
				cout << "There is no data" << endl;
			
			system("pause");
			system("cls");
			break;

		case 5:
			system("cls");
			if (_size != 0)
				DeleteData(d, _size);
			else
				cout << "There is no data" << endl;

			system("pause");
			system("cls");
			break;

		case 6:
			system("cls");
			if (_size != 0)
				SortingData(d, _size);
			else
				cout << "There is no data" << endl;

			system("pause");
			system("cls");
			break;

		case 7:
			system("cls");
			if (_size != 0) {
				// cout << "Input file name for saving " << endl;
				//cin >> fileName; // txt file 

				//SaveData(d, _size, fileName);

				SaveData(d, _size, fileName);
			}
			else
				cout << "There is no data" << endl;

			system("pause");
			system("cls");
			break;

		default:
			cout << "Wrong action, please try again" << endl;
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');  // был конфликт с max от Windows.h 
			system("cls");
			break;
		} // end switch
	} // end while 
	system("cls");
	cout << "Application is finished" << endl;
	system("pause");
}// end main