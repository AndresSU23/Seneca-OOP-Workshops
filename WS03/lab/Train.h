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
		ostream& display(ostream& cout = cout);
		
	};

}
#endif