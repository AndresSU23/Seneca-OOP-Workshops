/***********************************************************************
// OOP244 Workshop #7 lab 
//
// File  Conatainer.h
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
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

#include <iostream>

namespace sdds {
	class Container {
		char m_content[51]{};
		int m_capacity{};
		int m_volume{};

	protected:
		void setEmpty();
		int capacity() const;
		int volume() const;

	public:
		Container(const char* content, int capacity, int volume = 0.0);
		int operator+=(int fill);
		int operator-=(int reduce);
		operator bool() const;

		void clear(int capacity, const char* content);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};

	std::ostream& operator <<(std::ostream& ostr, Container& container);
	std::istream& operator >>(std::istream& ostr, Container& container);
}
#endif // !SDDS_CONTAINER_H
