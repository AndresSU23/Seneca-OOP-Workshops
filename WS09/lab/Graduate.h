/***********************************************************************
// OOP244 Workshop #9 lab
//
// File  Graduate.h
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
#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H

#include "Student.h"

namespace sdds {
	class Graduate : public Student {
		char* m_supvr{};
		char* m_thesis{};

	public:
		Graduate();
		Graduate(const char* stName, const int age, const char* thesis, const char* suprv);
		Graduate(const Graduate& graduate);
		Graduate& operator=(const Graduate& graduate);
		~Graduate();

		void display();
	};
}

#endif // !SDDS_GRADUATE_H
