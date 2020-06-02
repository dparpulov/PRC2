#include "PiggyBank.h"

#include <iostream>
#include <string>
using namespace std;


int PiggyBank::id = 0;

PiggyBank::PiggyBank() {
	id++;
	owner = "MamaPig";
	balance = 0;
	broken = false;
}

PiggyBank::PiggyBank(string name) {
	id++;
	this->owner = name;
	balance = 0;
	broken = false;

}

PiggyBank::PiggyBank(string name, int startBalance) {
	id++;
	this->owner = name;
	this->balance = startBalance;
	broken = false;

}

string PiggyBank::getOwnerName() {
	return owner;
}

void PiggyBank::setOwnerName(string name) {
	this->owner = name;
}

bool PiggyBank::isBroken() {
	return broken;
}

int PiggyBank::getBalance() {
	if (broken)
		return -1;

	return balance;
}

void PiggyBank::depositMoney(int amount) {
	if (broken == false)
		balance += amount;
}

int PiggyBank::smash() {
	if (broken == false)
	{
		broken = true;
		return balance;
	}

	return -1;
}

int PiggyBank::getId()
{
	return id;
}

ostream& operator<<(ostream& output, PiggyBank& piggyBank)
{
	output << piggyBank.id << endl;
	output << piggyBank.owner << endl;
	output << piggyBank.balance << endl;
	output << boolalpha << piggyBank.broken << endl;

	return output;
}

istream& operator>>(istream& input, PiggyBank& piggyBank)
{
	input >> piggyBank.id;
	input >> piggyBank.owner;
	input >> piggyBank.balance;
	input >> piggyBank.broken;

	return input;
}

