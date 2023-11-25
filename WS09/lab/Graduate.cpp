/***********************************************************************
// OOP244 Workshop #9 lab
//
// File  Graduate.cpp
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

#include <iostream>
#include <cstring>

#include "Graduate.h"

namespace sdds {
	Graduate::Graduate() : Student(), m_supvr(nullptr), m_thesis(nullptr) {}

	Graduate::Graduate(const char* stName, const int age, const char* thesis, const char* suprv) : Student(stName, age) {
		if (thesis) {
			m_thesis = new char[strlen(thesis) + 1];
			strcpy(m_thesis, thesis);
		}
		if (suprv) {
			m_supvr = new char[strlen(suprv) + 1];
			strcpy(m_supvr, suprv);
		}
	}
	Graduate::Graduate(const Graduate& graduate) {
		*this = graduate;
	}
	Graduate& Graduate::operator=(const Graduate& graduate) {
		Student::operator = (graduate);
		if (graduate.m_thesis) {
			if (m_thesis) {
				delete[] m_thesis;
				m_thesis = nullptr;
			}
			m_thesis = new char[strlen(graduate.m_thesis) + 1];
			strcpy(m_thesis, graduate.m_thesis);
		}
		if (graduate.m_supvr) {
			if (m_supvr) {
				delete[] m_supvr;
				m_supvr = nullptr;
			}
			m_supvr = new char[strlen(graduate.m_supvr) + 1];
			strcpy(m_supvr, graduate.m_supvr);
		}
		return *this;
	}
	Graduate::~Graduate() {
		delete[] m_supvr;
		m_supvr = nullptr;
		delete[] m_thesis;
		m_thesis = nullptr;
	}
	void Graduate::display() {
		Student::display();
		std::cout << "Thesis Title: " << m_thesis << std::endl;
		std::cout << "Supervisor: " << m_supvr << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}