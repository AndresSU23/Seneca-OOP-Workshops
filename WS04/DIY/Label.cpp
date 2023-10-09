/***********************************************************************
// OOP244 Workshop #4 DIY (part 2): tester program
//
// File  Label.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <istream>
#include <iomanip>
#include <cstring>
#include "Label.h"

using namespace std;

namespace sdds {
	Label::~Label() {
		delete[] m_frameArg;
		delete[] m_content;
	}
	Label::Label() {
		setFrame(NULL);
		setcontent(NULL);
	}
	Label::Label(const char* frameArg) {
		setFrame(frameArg);
		setcontent(NULL);
	}
	Label::Label(const char* frameArg, const char* content) {
		setFrame(frameArg);
		setcontent(content);
	}
	void Label::setFrame(const char* frameArg) {
		if (frameArg) {
			m_frameArg = new char[strlen(frameArg) + 1];
			strcpy(m_frameArg, frameArg);
		}
		else
		{
			m_frameArg = new char[strlen(DEFAULT_FRAME) + 1];
			strcpy(m_frameArg, DEFAULT_FRAME);
		}
	}
	void Label::setcontent(const char* content) {
		if (content) {
			m_content = new char[CONTENT_SIZE + 1];
			strcpy(m_content, content);
		}
		else
		{
			m_content = new char[CONTENT_SIZE + 1];
			strcpy(m_content, "");
		}
	}
	istream& Label::readLabel() {
		char temp[CONTENT_SIZE + 1];
		cin.getline(temp, CONTENT_SIZE + 1);
		strcpy(m_content, temp);
		return cin;
	}
	ostream& Label::printLabel() const {
		if (!strlen(m_content)) return cout;
		cout << right << m_frameArg[0] << setfill(m_frameArg[1]) << setw(strlen(m_content) + 3) << m_frameArg[2] << endl;
		cout << m_frameArg[7] << setfill(' ') << setw(strlen(m_content) + 3) << m_frameArg[3] << endl;
		cout << m_frameArg[7] << " " << m_content << " " << m_frameArg[3] << endl;
		cout << m_frameArg[7] << setfill(' ') << setw(strlen(m_content) + 3) << m_frameArg[3] << endl;
		cout << m_frameArg[6] << setfill(m_frameArg[5]) << setw(strlen(m_content) + 3) << m_frameArg[4];
		return cout;
	}
	Label& Label::text(const char* content) {
		strcpy(m_content, content);
		return *this;
	}
};