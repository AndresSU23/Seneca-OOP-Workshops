/***********************************************************************
// OOP244 Workshop #7 lab 
//
// File  Pack.h
// Version 1.0
// Author David Andres Sanchez Umbarila
// Description
//			Name      : David Andres Sanchez Umbarila
//			Student ID: 140273228
//			Email     : dasanchez-umbarila@myseneca.ca
/			Date      :
//
//			I have done all the coding by myself and only copied the code
//			 that my professor provided to complete my workshops and
//			 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#pragma once
#ifndef SDDS_PACK_H
#define SDDS_PACK_H

#include <iostream>

#include "Container.h"

namespace sdds {
	class Pack :public Container{
		int m_unitSize{330};

	public:
		Pack(const char* content, int size, int unitSize = 330, int noUnits = 0);
		
		int operator +=(int add);
		int operator -=(int remove);

		int unit() const;
		int noOfUnits() const;
		int size() const;

		using Container::clear; 
		void clear(int size, int unitSize, const char* content);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};

	std::ostream& operator <<(std::ostream& ostr, Pack& pack);
	std::istream& operator >>(std::istream& istr, Pack& pack);
}
#endif // !SDDS_PACK_H
