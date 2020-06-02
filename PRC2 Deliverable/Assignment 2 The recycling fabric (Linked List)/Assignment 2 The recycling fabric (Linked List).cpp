// Assignment 2 The recycling fabric (Linked List).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Scan.h"
#include "ScanList.h"

using namespace std;

void printList(Scan* head)
{
	for (; head; head = head->getNext())
	{
		cout << "Bottle with Serial Number: " << head->getSerialNumber() << " has been recycled " << head->getTimesRecycled() << " times." << endl;
	}
	cout << "\n";
}

int main()
{
	int input = 1;
	ScanList sl;

	while (input != 0)
	{
		cout << "Enter 0 to exit: \n";
		cout << "Enter 1 to scan a Bottle: \n";
		cout << "Enter 2 to remove a Bottle from the list: \n";
		cout << "Enter 3 to check how many times the Bottle has been recycled before: \n";
		cout << "Enter 4 to clear the list: \n";
		cout << "Enter 5 to print all scanned Bottles: \n";


		cin >> input;


		switch (input)
		{
			case 1:
			{
				cout << "Serial number: ";
				int serialNumber;
				cin >> serialNumber;
				sl.addScan(serialNumber);

				cout << "The bottle was scanned.\n" << endl;
			}
			break;
			case 2:
			{
				cout << "Serial number: ";
				int serialNumber;
				cin >> serialNumber;
				if (sl.removeScan(serialNumber))
					cout << "The bottle was removed.\n" << endl;
				else
					cout << "The bottle was not removed.\n" << endl;
			}
				break;
			case 3:
			{
				cout << "Serial number: ";
				int serialNumber;
				cin >> serialNumber;
				
				cout << "The bottle has been recycled: " << sl.getTimesRecycled(serialNumber) << " times before.\n" << endl;
			}
			break;
			case 4:
				sl.~ScanList();
				cout << "List has been cleared.\n" << endl;
			break;
			case 5:
				printList(sl.getHead());
				
				break;
		}
	}
}


