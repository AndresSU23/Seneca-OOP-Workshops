/***********************************************************************
// OOP244 Workshop #8 lab
//
// File  Rectangle.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <cstring>

#include "Rectangle.h"

namespace sdds {
	Rectangle::Rectangle(const char* string, int width, int height) : LblShape(string) {
		m_height = height;
		m_width = width;
		if (m_height < 3 || m_width < strlen(label()) + 2) {
			m_height = -1;
			m_width = -1;
		}
	}
	Rectangle::~Rectangle() {
	}
	void Rectangle::getSpecs(std::istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.get();
		istr >> m_height;
		istr.get();

	}
	void Rectangle::draw(std::ostream& ostr) const {
		if (m_height != -1) {
	
			ostr << '+';
			for (int i = 0; i < m_width - 2; ++i) {
				std::cout << '-';
			}
			ostr << '+' << std::endl;


			ostr << "|" << std::setw(m_width - 2) << std::left << label() << '|' << std::endl;

			for (int i = 0; i < m_height - 3; ++i) {
				ostr << '|';
				ostr << std::setw(m_width - 2) << ' ';
				ostr << '|' << std::endl;
			}

			ostr << '+';
			for (int i = 0; i < m_width - 2; ++i) {
				ostr << '-';
			}
			ostr << '+';
		}
	}
}