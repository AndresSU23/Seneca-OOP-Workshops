/***********************************************************************
// OOP244 Workshop #9 lab
//
// File  Student.spp
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

#include "Student.h"

namespace sdds {
	Student::Student(): m_name{nullptr}, m_age(0){}
	Student::Student(const char* name, const int age) {
		if (name) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		m_age = age;
	}
	Student::Student(const Student& student) {
		*this = student;
	}
	Student& Student::operator=(const Student& student) {
		if (student.m_name) {
			delete[] m_name;
			m_name = nullptr;
			m_name = new char[strlen(student.m_name) + 1];
			strcpy(m_name, student.m_name);
		}
		m_age = student.m_age;
		return *this;
	}
	Student::~Student() {
		delete[] m_name;
		m_name = nullptr;
	}
	void Student::display() {
		std::cout << "Name: " << m_name << std::endl;
		std::cout << "Age: " << m_age << std::endl;
	}
}