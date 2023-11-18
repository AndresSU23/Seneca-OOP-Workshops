/***********************************************************************
// OOP244 Workshop #8 lab
//
// File  Line.h
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
#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include <iostream>

#include "LblShape.h"

namespace sdds{
	class Line : public LblShape {
		int m_length{0};

	public:
		Line() = default;
		Line(const char* string, int length);
		~Line();
		void getSpecs(std::istream& istr) override;
		void draw(std::ostream& ostr) const override;
	};
}

#endif // !SDDS_LINE_H
