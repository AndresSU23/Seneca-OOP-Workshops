/***********************************************************************
// OOP244 Workshop #3 lab (part 1): tester program
//
// File  Train.cpp
// Version 1.0
// Author   Cornel Barna, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Train.h"
namespace sdds {
	void Train::initialize()
	{
		trainName = NULL;
		noPeople = -1;
		departureTime = -1;
	}
	bool Train::validTime(int value) const {
		return (value >= MIN_TIME) &&
			   (value <= MAX_TIME) &&
			   ((value % 100)) <= 59;
	}
	bool Train::validNoOfPassengers(int value) const {
		return (value > 0) &&
			   (value < MAX_NO_OF_PASSENGERS);
	}
	void Train::set(const char* name) {
		if (trainName) finalize();
		trainName = NULL;
		if (name && strlen(name)) {
			trainName = new char[strlen(name) + 1];
			strcpy(trainName, name);
		}
	}
	void Train::set(int noOfPassengers, int departure) {
		departureTime = validTime(departure) ? departure : -1;
		noPeople = validNoOfPassengers(noOfPassengers) ? noOfPassengers : -1;
	}
	void Train::set(const char* name, int noOfPassengers, int departure) {
		set(name);
		set(noOfPassengers, departure);
	}
	void Train::finalize() {
		delete[] trainName;
	}
	bool Train::isInvalid() const {
		return !trainName			|| 
			   (noPeople == -1)		|| 
			   (departureTime == -1);
	}
	const char* Train::getName() const {
		return trainName;
	}
	int Train::getDepartureTime() const {
		return departureTime;
	}
	int Train::noOfPassengers() const {
		return noPeople;
	}
	ostream& Train::display(ostream& cout)
	{
		if (isInvalid()) {
			cout << "Train in an invalid State!" << endl;
		}
		else{
			cout << "NAME OF THE TRAIN:     " << getName()			<< endl
				 << "NUMBER OF PASSENGERS:  " << noOfPassengers()   << endl
				 << "DEPARTURE TIME:        " << getDepartureTime() << endl;
		}
		return cout;
	}
}