#include "Scan.h"
#include <string>
#include <vector>



Scan::Scan(int number)
{
	this->next = NULL;
	this->serialNumber = number;
	this->timesRecycled = 1;
}

Scan::Scan(int number, Scan* next)
{

	this->next = next;
	this->serialNumber = number;
	this->timesRecycled = 1;
}

Scan::~Scan() {}

int Scan::getSerialNumber()
{
	return this->serialNumber;
}

Scan* Scan::getNext()
{
	return this->next;
}

void Scan::setNext(Scan* nextScan)
{
	if (nextScan != NULL)
		this->next = nextScan;
	else
		this->next = NULL;
}

void Scan::recycle()
{
	this->timesRecycled++;
}

int Scan::getTimesRecycled()
{
	return this->timesRecycled;
}
