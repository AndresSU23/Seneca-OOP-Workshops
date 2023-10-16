/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_

#include <iostream>

using namespace std;
namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
       Portfolio();
       Portfolio(double value, const char* stock, char type);
       void emptyPortfolio();
       void dispPortfolio() const;
       ostream& display() const;
       operator double() const;
       operator const char* () const;
       operator char() const;
       operator bool() const;
       Portfolio& operator +=(const double value);
       Portfolio& operator -=(const double value);
       bool operator ~() const;
       Portfolio& operator <<(Portfolio& transfer);
       Portfolio& operator >>(Portfolio& transfer);
   };

   double operator +(const Portfolio& p1, const Portfolio& p2);
   double& operator +=(double& value, const Portfolio& portfolio);
}
#endif // SDDS_Portfolio_H_