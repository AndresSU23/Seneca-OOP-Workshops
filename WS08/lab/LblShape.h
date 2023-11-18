/***********************************************************************
// OOP244 Workshop #8 lab
//
// File  LblShape.h
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
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include <iostream>

#include "Shape.h"

namespace sdds {
	class LblShape: public Shape {
		char* m_label{ nullptr };

	protected:
		const char* label() const;

	public:
		LblShape() = default;
		LblShape(const char* label);
		~LblShape();
		void getSpecs(std::istream& istr) override;
	};
}
#endif // !SDDS_LBLSHAPE_H
