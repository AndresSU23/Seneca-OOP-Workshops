/***********************************************************************
// OOP244 Workshop #3 DIY (part 2): tester program
//
// File  Train.h
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

#pragma once
#ifndef TRAIN_H_
#define TRAIN_H_

#include <iostream>

#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGERS 1000

namespace sdds {
	class Train
	{
		char* trainName;
		int noPeople;
		int departureTime;
	public:
		void initialize();
		bool validTime(int value)const;
		bool validNoOfPassengers(int value)const;
		void set(const char* name);
		void set(int noOfPassengers, int departure);
		void set(const char* name, int noOfPassengers, int departure);
		void finalize();
		bool isInvalid() const;
		const char* getName() const;
		int getDepartureTime() const;
		int noOfPassengers() const;
		void display() const;
		bool noPromptLoad(int& passengers);
		bool load(int& passengers);
		bool updateDepartureTime();
		bool transfer(const Train& tranferTrain);
	};

}
#endif