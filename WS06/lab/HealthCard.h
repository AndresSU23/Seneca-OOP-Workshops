/***********************************************************************
// OOP244 Workshop #6 lab : tester program
//
// File  HealthCard.h
// Version 1.0
// Author
// Description
//			Name      : David Andres Sanchez Umbarila
//			Student ID: 140273228
//			Email     : dasanchez-umbarila@myseneca.ca
/			Date      : 03/11/2023
//
//			I have done all the coding by myself and only copied the code
//			 that my professor provided to complete my workshops and
//			 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

namespace sdds {
   const int MaxNameLength = 55;
   class HealthCard {
       char* m_name{};
       long long m_number;
       char m_vCode[3];
       char m_sNumber[10];
   public:
       HealthCard(const char* name = nullptr, long long number = 0, const char vCode[] = {}, const char sNumber[] = {});
       HealthCard(const HealthCard& hc);
       HealthCard& operator=(const HealthCard& hc);
       ~HealthCard();
       operator bool() const;
       bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
       void setEmpty();
       void allocateAndCopy(const char* name);
       void extractChar(std::istream& istr, char ch) const;
       std::ostream& printIDInfo(std::ostream& ostr)const;
       void set(const char* name, long long number, const char vCode[], const char sNumber[]);
       std::ostream& print(std::ostream& ostr, bool toFile = true) const;
       std::istream& read(std::istream& istr);
   };
   std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);
   std::istream& operator>>(std::istream& istr, HealthCard& hc);

}
#endif // !SDDS_HealthCard_H


