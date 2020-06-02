#pragma once
#include <string>
using namespace std;

class PiggyBank
{
private:
	string owner;
	int balance;
	bool broken;
	static int id;

public:
	PiggyBank();

	PiggyBank(string name);

	PiggyBank(string name, int startBalance);

	string getOwnerName();

	void setOwnerName(string name);

	bool isBroken();

	int getBalance();

	void depositMoney(int amount);

	int smash();

	static int getId();

	friend ostream& operator << (ostream& output, PiggyBank& piggyBank);
	friend istream& operator >> (istream& input, PiggyBank& piggyBank);

};

