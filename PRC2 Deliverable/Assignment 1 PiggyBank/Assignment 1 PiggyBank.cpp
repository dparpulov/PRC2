// Assignment 1 Piggy Bank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "PiggyBank.h"


int main()
{
	int input = 1;
	PiggyBank piggyBank;

	while (input != 0)
	{
		cout << endl << "Enter 0 to exit: \n";
		cout << "Enter 1 to get PiggyBank owner's name: \n";
		cout << "Enter 2 to set a new name for PiggyBank owner: \n";
		cout << "Enter 3 to Check if PiggyBank is broken: \n";
		cout << "Enter 4 to get the balance from the PiggyBank: \n";
		cout << "Enter 5 to deposit money: \n";
		cout << "Enter 6 to smash the PiggyBank: \n";
		cout << "Enter 7 to find out how many PiggyBanks you owned: \n";
		cout << "Enter 8 to create a new PiggyBank: \n";
		cout << "Enter 9 to write the PiggyBank data to a file: \n";
		cout << "Enter 10 to read the PiggyBank data from a file: \n";


		cin >> input;


		switch (input)
		{
		case 1:
			cout << "The owner of this Piggy Bank is: " << piggyBank.getOwnerName() << endl;
			break;
		case 2:
		{
			cout << "What is the new owners name?" << endl << "Owner Name is: ";
			string ownerName;
			cin >> ownerName;
			piggyBank.setOwnerName(ownerName);
		}
		break;
		case 3:
			//{
				/*string broken = "";
				if (piggyBank.isBroken())
					broken = "broken";
				else
					broken = "not broken";*/
			cout << "Is the PiggyBank broken now: " << boolalpha << piggyBank.isBroken() << endl;
			//}
			break;
		case 4:
		{
			int balance = piggyBank.getBalance();
			cout << "The balance from the PiggyBank is: " << balance << endl;
		}
		break;
		case 5:
		{
			cout << "How much would you like to deposit?" << endl << "Amount to deposit: ";
			int amount;
			cin >> amount;
			piggyBank.depositMoney(amount);
		}
		break;
		case 6:
			if (!piggyBank.isBroken())
				cout << "You smash the PiggyBank and you find: " << piggyBank.smash() << " euros inside" << endl;
			else
				cout << "The PiggyBank was already broken" << endl;
			//cout << "Smash the PiggyBank: \n";
			//piggyBank.smash();
			//cout << "Is the PiggyBank broken now: " << boolalpha << piggyBank.isBroken() << endl;

			break;
		case 7:
			cout << "This is your " << piggyBank.getId() << " PiggyBank" << endl;
			break;
		case 8:
		{
			piggyBank = PiggyBank("PapaPig", 100);
			cout << "This is your " << piggyBank.getId() << " PiggyBank" << endl;
		}
		break;
		case 9:
		{
			ofstream writeFile;
			writeFile.open("PiggyBank.txt");
			writeFile << piggyBank;
			writeFile.close();
			cout << "The data of your current PiggyBank is in a text file now.\n";
		}
		break;
		case 10:
		{
			cout << "This data is read from a text file\n";
			ifstream readFile;
			readFile.open("PiggyBank.txt");
			readFile >> piggyBank;

			readFile.close();
			cout << piggyBank.getId() << endl << piggyBank.getOwnerName() << endl <<
				piggyBank.getBalance() << endl << boolalpha << piggyBank.isBroken() << endl;
		}
		break;
		}
	}



}