#include "part.h"
#include "Operation.h"
#include "setupSheet.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sqlite3.h>
using namespace std;

void partLog(Part&, SetupSheet&); //creates part object
void opLog(Operation&, SetupSheet&); //creates operation object
string whiteSpace(string&); //asks user to renter string if string is empty
//bool createDatabase();

int main()
{
	Part part;
	Operation op;
	SetupSheet sheet;
	int choice = 0;
	ofstream sheetOut("setupSheet.txt", ios::out | ios::trunc);

	do
	{
		cout << string(50, '*') << endl;
		cout << "1. enter a part" << endl;
		cout << "2. enter an operation" << endl;
		cout << "3. display the set up sheet" << endl;
		cout << "4. end the program" << endl;
		cout << "Please enter a choice: ";
		cin >> choice;

		switch (choice)
		{
			case 1:  
				partLog(part, sheet);
				break;

			case 2:
				opLog(op, sheet);
				break;

			case 3:
				sheet.display();
				break;

			default:
				cout << "Enter a valid choice" << endl;
		}

	} while (choice!=4);

	if (sheetOut.is_open())
	{
		sheet.ExporttoFile(sheetOut);
	}
	else
	{
		cerr << "Unable to open file for writing." << endl;
	}

	return 0;
}

void partLog(Part& p, SetupSheet& s)
{
	int partNum = 0;
	string material,
		   machine;

	cout << "Enter part number: ";
	cin >> partNum;
	p.setPartNum(partNum);

	cout << "Enter material: ";
	cin.ignore();
	getline(cin, material);
	material = whiteSpace(material);
	p.setMaterial(material);

	cout << "Enter machine name: ";
	getline(cin, machine);
	machine = whiteSpace(machine);
	p.setMachine(machine);

	s.setPartInfo(p);
}

void opLog(Operation& o, SetupSheet& s)
{
	int opNum = 0;
	string description,
		   toolID;

	cout << "Enter Operation Number: ";
	cin >> opNum;
	o.setOpNum(opNum);

	cout << "Enter Description: ";
	cin.ignore();
	getline(cin, description);
	description = whiteSpace(description);
	o.setDescription(description);

	cout << "Enter Tool ID: ";
	getline(cin, toolID);
	toolID = whiteSpace(toolID);
	o.setToolID(toolID);

	s.addOp(o);
}

string whiteSpace(string& s)
{
	while (s == " ")
	{
		cout << "There is no data here. Enter a proper string." << endl;
		getline(cin, s);
	}

	return s;
}

/*bool createDatabase()
{
	sqlite3* db;
	bool data;

	int result = sqlite3_open("cnc_setup.db", &db);

	if (result != SQLITE_OK)
	{
		cout << "Unable to open database" << endl;
		sqlite3_close(db);
		data = false;
	}

	cout << "Database opened successfully" << endl;
}*/