/***********************************************************************
// OOP244 Workshop #3 DIY (part 2): tester program
//
// File  Train.cpp
// Version 1.0
// Author   Cornel Barna, Fardad Soleimanloo
// Description
//			Name      : David Andres Sanchez Umbarila
//			Student ID: 140273228
//			Email     : dasanchez-umbarila@myseneca.ca
/			Date      : 02/10/2023
//
//			I have done all the coding by myself and only copied the code
//			 that my professor provided to complete my workshops and 
//			 assignments.
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
	void Train::display() const {
		if (isInvalid()) {
			cout << "Train in an invalid State!" << endl;
		}
		else{
			cout << "NAME OF THE TRAIN:    " << getName()			<< endl
				 << "NUMBER OF PASSENGERS: " << noOfPassengers()   << endl
				 << "DEPARTURE TIME:       " << getDepartureTime() << endl;
		}
	}
	bool Train::noPromptLoad(int& passengers)
	{
		passengers = passengers - (MAX_NO_OF_PASSENGERS - noPeople);
		noPeople = MAX_NO_OF_PASSENGERS;
		if (passengers <= 0) {
			noPeople += passengers;
			passengers = 0;
			return true;
		}
		return false;
	}
	bool Train::load(int& passengers)
	{
		cout << "Enter number of passengers boarding:" << endl << "> ";
		cin >> passengers;
		return noPromptLoad(passengers);
		
	}
	bool Train::updateDepartureTime()
	{
		int desiredTime;
		cout << "Enter new departure time:" << endl << "> ";
		cin >> desiredTime;
		departureTime = validTime(desiredTime) ? desiredTime : -1;
		return departureTime > -1;
	}
	bool Train::transfer(const Train& tranferTrain)
	{
		if (isInvalid() || tranferTrain.isInvalid()) return false;
		char* tempName = new char[strlen(getName()) + strlen(tranferTrain.getName()) + 3];
		strcpy(tempName, getName());
		strcat(tempName, ", ");
		strcat(tempName, tranferTrain.getName());
		set(tempName);
		delete[] tempName;
		int transferPassengers = tranferTrain.noOfPassengers();
		if (!noPromptLoad(transferPassengers)) {
			cout << "Train is full; " << transferPassengers << " passengers of " << tranferTrain.getName() << " could not be boarded!" << endl;
		}
		return true;
	}
}