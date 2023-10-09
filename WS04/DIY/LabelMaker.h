/***********************************************************************
// OOP244 Workshop #4 DIY (part 2): tester program
//
// File  LabelMaker.h
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
#ifndef LABELMAKER_H_
#define LABELMAKER_H_

#include "Label.h"

namespace sdds {
	class LabelMaker {
		Label* m_labels;
		int m_noOfLabels;

	public:
		~LabelMaker();
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
	};
}
#endif