#pragma once

#include "Scan.h"

using namespace std;


class ScanList
{
private: //when using private variables for readability use this 
	Scan* head;
	Scan* tail;

public:
	ScanList();

	virtual ~ScanList();

	void addScan(int serialNumber);

	bool removeScan(int serialNumber);

	int getTimesRecycled(int serialNumber);

	Scan* getHead();

	Scan* getScan(int serialNumber);
};

