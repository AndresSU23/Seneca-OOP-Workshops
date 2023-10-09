/***********************************************************************
// OOP244 Workshop #4 DIY (part 2): tester program
//
// File  Label.h
// Version 1.0
// Author  David Andres Sanchez Umbarila
// Description
//			Name      : David Andres Sanchez Umbarila
//			Student ID: 140273228
//			Email     : dasanchez-umbarila@myseneca.ca
/			Date      : 07/10/2023
//
//			I have done all the coding by myself and only copied the code
//			 that my professor provided to complete my workshops and
//			 assignments.
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#pragma once
#ifndef LABEL_H_
#define LABEL_H_

#include <iostream>

#define DEFAULT_FRAME "+-+|+-+|"
#define CONTENT_SIZE 70
 
using namespace std;

namespace sdds {
	class Label {
		char* m_frameArg;
		char* m_content;

	public:
		~Label();
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		void setFrame(const char* frameArg);
		void setcontent(const char* content);
		istream& readLabel();
		ostream& printLabel() const;
		Label& text(const char* content);
	};
}

#endif