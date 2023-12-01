/***********************************************************************
// OOP244 Workshop # 10
// Module: selection
// File: selection.h
// Version 1.0
// Author
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
#ifndef SDDS_SELECTION_H
#define SDDS_SELECTION_H

#include <iostream>

namespace sdds {
	template <typename arrayType, typename keyType> 
	int* select(arrayType arr[], keyType key, size_t size) {
		int* indices = new int[size + 1];
		int counter{ 0 };
		for (size_t i = 0; i < size; i++) {
			if (arr[i] == key) {
				indices[counter++] = static_cast<int>(i);
			}
		}
		indices[counter] = -1;  
		return indices;
	}

	template <typename arrayType>
	void csvDisplaySelection(const char* title, const arrayType array[], const int* indices) {
		std::cout << title << std::endl;

		if (indices != nullptr && indices[0] != -1) {
			for (int i = 0; indices[i] != -1; ++i) {
				std::cout << array[indices[i]];
				if (indices[i + 1] != -1) std::cout << ", ";
			}
		}
		else std::cout << "Empty Selection";
		std::cout << std::endl;
	}
}

#endif // !SDDS_SELECTION_H
