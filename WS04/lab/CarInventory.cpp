/***********************************************************************
// OOP244 Workshop #4 LAB (part 1): tester program
//
// File  CarInventory.cpp
// Version 1.0
// Author   Fardad Soleimanloo
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

#include "CarInventory.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace sdds {
	void CarInventory::resetInfo(){
		m_type = NULL;
		m_brand = NULL;
		m_model = NULL;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}

	CarInventory::~CarInventory(){
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
	}

	CarInventory::CarInventory(){
		resetInfo();
	}
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
		resetInfo();
		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);
		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);
		m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
	}
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		if (m_type) delete[] m_type;
		if (m_brand) delete[] m_brand;
		if (m_model) delete[] m_model;
		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);
		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);
		m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
		return *this;
	}
	void CarInventory::printInfo() const {
		cout << "| " << left << setw(10) << m_type << " ";
		cout << "| " << left << setw(16) << m_brand << " ";
		cout << "| " << left << setw(16) << m_model << " ";
		cout << "| " << setw(4) << m_year << " ";
		cout << "| " << setw(4) <<  right << m_code << " ";
		cout << "| " << setw(9) << right << fixed << setprecision(2) << m_price << " |" << endl;
	}
	bool CarInventory::isValid() const
	{
		return m_type && 
			   m_brand &&
			   m_model &&
			   m_year >= 1990 && 
			   (m_code > 99 && m_code < 1000) && 
			   m_price > 0;
	}
	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{
		if (!isValid()) return false;
		return !strcmp(m_type, car.m_type) &&
			   !strcmp(m_brand, car.m_brand) &&
			   !strcmp(m_model, car.m_model) &&
			   m_year == car.m_year;
	}
	int find_similar(CarInventory car[], const int num_cars)
	{
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					return i;
				}
			}
		}
		return 0;
	}
}