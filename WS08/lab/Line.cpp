/***********************************************************************
// OOP244 Workshop #8 lab
//
// File  Line.cpp
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
#include "Line.h"

namespace sdds {
	Line::Line(const char* string, int length) : LblShape(string) {
		m_length = length;
	}
	Line::~Line() {
	}
	void Line::getSpecs(std::istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.get();

	}
	void Line::draw(std::ostream& ostr) const {
		if (m_length && label()) {
			ostr << label() << std::endl;
			for (int i = 0; i < m_length; i++) ostr << '=';
		}
	}
}