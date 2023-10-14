/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//			Name      : David Andres Sanchez Umbarila
//			Student ID: 140273228
//			Email     : dasanchez-umbarila@myseneca.ca
/			Date      : 07/10/2023
//
//			I have done all the coding by myself and only copied the code
//			 that my professor provided to complete my workshops and
//			 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

#define LITER_PER_PERSON 600

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char*() const;
      bool operator ~() const;
      Flight& operator =(Flight& transferFlight);
      Flight& operator =(int passengers);
      Flight& operator =(double fuel);
      Flight& operator +=(double addFuel);
      Flight& operator +=(int addPasssengers);
      Flight& operator -=(double reduceFuel);
      Flight& operator -=(int reducePasssengers);
      Flight& operator <<(Flight& transferFlight);
      Flight& operator >>(Flight& transferFlight);
      int operator +(const Flight& flight) const;
   };

   int operator+=(int& passengers, const Flight& flight);

}
#endif // SDDS_FLIGHT_H