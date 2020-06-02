#pragma once
using namespace std;

class Scan
{
private:
	int serialNumber;
	int timesRecycled;
	Scan* next;


public:
	Scan(int number);

	Scan(int number, Scan* next);

	virtual ~Scan();

	int getSerialNumber();

	Scan* getNext();

	void setNext(Scan* nextScan);

	void recycle();

	int getTimesRecycled();


};

