/***********************************************************************
// OOP244 Workshop #4 DIY (part 2): tester program
//
// File  LabelMaker.cpp
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
//// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include<iostream>
#include<cstring>
#include"LabelMaker.h"

using namespace std;

namespace sdds {
	LabelMaker::~LabelMaker() {
		delete[] m_labels;
	}
	LabelMaker::LabelMaker(int noOfLabels) {
		m_labels = new Label[noOfLabels];
		m_noOfLabels = noOfLabels;
	}
	void LabelMaker::readLabels() {
		int i; 
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		for (i = 0; i < m_noOfLabels; i++) {
			cout << "Enter label number " << i + 1 << endl;
			cout << "> ";
			m_labels[i].readLabel();
		}
	}
	void LabelMaker::printLabels() {
		int i;
		for (i = 0; i < m_noOfLabels; i++) {
			m_labels[i].printLabel();
		}
	}
};