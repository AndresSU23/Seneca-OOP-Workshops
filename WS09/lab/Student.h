/***********************************************************************
// OOP244 Workshop #9 lab
//
// File  Student.h
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
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds {
	class Student {
		char* m_name{};
		int m_age{};

	public:
		Student();
		Student(const char* name, const int age);
		Student(const Student& student);
		Student& operator=(const Student& student);
		virtual ~Student();

		void display();
	};
}
#endif // !SDDS_STUDENT_H
