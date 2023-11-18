/***********************************************************************
// OOP244 Workshop #8 lab
//
// File  Rectangle.h
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
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds {
	class Rectangle : public LblShape {
		int m_width{0};
		int m_height{0};

	public:
		Rectangle() = default;
		Rectangle(const char* string, int width, int height);
		~Rectangle();
		void getSpecs(std::istream& istr) override;
		void draw(std::ostream& ostr) const override;
	};
}
#endif // !SDDS_RECTANGLE_H
