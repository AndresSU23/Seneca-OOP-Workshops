/***********************************************************************
// OOP244 Workshop #8 lab
//
// File  LblSHape.cpp
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
#include <cstring>

#include "LblShape.h"

namespace sdds {
	const char* LblShape::label() const {
		return m_label;
	}
	LblShape::LblShape(const char* label) {
		if (label) {
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}
	LblShape::~LblShape(){
		delete[] m_label;
	}

	void LblShape::getSpecs(std::istream& istr) {
		char string[100];
		istr.getline(string, 100, ',');
		if (!istr.fail()) {
			delete[] m_label;
			m_label = nullptr;
			m_label = new char[strlen(string) + 1];
			strcpy(m_label, string);
		}
	}
	
}