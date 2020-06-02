#include "ScanList.h"
#include "Scan.h"
#include <string>
#include <vector>
#include <iostream>


ScanList::ScanList()
{
	this->head = NULL;
	this->tail = NULL;
}

ScanList::~ScanList()
{
	Scan* current = this->head;
	while (current != 0) {
		Scan* next = current->getNext();
		delete current;
		current = next;
	}
	this->head = NULL;
}

void ScanList::addScan(int serialNumber)
{
	//If head is NULL -> new head (first Scan)
	if (this->head == NULL) {
		Scan* tmp = new Scan(serialNumber, NULL);

		this->head = tmp;
		this->tail = tmp;
		return;
	}

	//If scan exists -> recycle
	Scan* tmpScan = getScan(serialNumber);
	if (tmpScan != NULL)
	{
		tmpScan->recycle();
		return;
	}

	//If head serialNumber is higher than serialNumber -> new head
	if (serialNumber < this->head->getSerialNumber()) {
		tmpScan = new Scan(serialNumber, this->head);
		this->head = tmpScan;

		return;
	}

	//If tail serialNumber is lower than serialNumber -> new tail
	if (serialNumber > tail->getSerialNumber()) {
		tmpScan = new Scan(serialNumber);
		this->tail->setNext(tmpScan);
		this->tail = tmpScan;

		return;
	}
		
	//New Scans in between existing ones
	Scan* current = this->head;
	Scan* tmp = this->head->getNext();
	//If there is no second Scan -> create and set it
	if (tmp == NULL)
	{
		Scan* newScan = new Scan(serialNumber);

		current->setNext(newScan);
		return;
	}
	else {
		while (tmp != NULL)
		{
			if (serialNumber < tmp->getSerialNumber())
			{
				Scan* newScan = new Scan(serialNumber, tmp);

				current->setNext(newScan);
				//newScan->setNext(tmp);

				return;
			}

			current = current->getNext();
			tmp = tmp->getNext();
		}
	}
	
}

bool ScanList::removeScan(int serialNumber)
{
	Scan* scanToRemove = getScan(serialNumber);

	//If scan is NULL return false
	if (scanToRemove == NULL)
	{
		return false;
	}
	
	//If scan is head then change head to head->getNext() and return true;
	if (scanToRemove->getSerialNumber() == this->head->getSerialNumber())
	{
		this->head = this->head->getNext();
		delete scanToRemove;

		return true;
	}

	//Removes if after head
	Scan* scanBeforeScanToRemove = this->head;
	while (scanToRemove != NULL)
	{
		if (scanBeforeScanToRemove->getNext()->getSerialNumber() == scanToRemove->getSerialNumber())
		{
			if (scanToRemove->getSerialNumber() == this->tail->getSerialNumber())
			{ 
				scanBeforeScanToRemove->setNext(NULL);
				this->tail = scanBeforeScanToRemove;
			}
			else
				scanBeforeScanToRemove->setNext(scanToRemove->getNext());
			
			delete scanToRemove;
			return true;
		}

		scanBeforeScanToRemove = scanBeforeScanToRemove->getNext();
	}


	return false;
}

int ScanList::getTimesRecycled(int serialNumber)
{
	Scan* searchedScan = getScan(serialNumber);
	if (searchedScan != NULL)
	{
		return searchedScan->getTimesRecycled();
	}
	return 0;
}

Scan* ScanList::getHead()
{
	return head;
}

Scan* ScanList::getScan(int serialNumber)
{
	Scan* searchedScan = this->head;
	while (searchedScan != NULL)
	{
		if (searchedScan->getSerialNumber() == serialNumber)
		{
			return searchedScan;
		}
		searchedScan = searchedScan->getNext();
	}

	return NULL;
}
