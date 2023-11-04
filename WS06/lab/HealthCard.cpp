/***********************************************************************
// OOP244 Workshop #6 lab : tester program
//
// File  HealthCard.cpp
// Version 1.0
// Author   
// Description
//			Name      : David Andres Sanchez Umbarila
//			Student ID: 140273228
//			Email     : dasanchez-umbarila@myseneca.ca
/			Date      : 03/11/2023
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
#include <iomanip> 
#include <cstring>
#include "HealthCard.h"
using namespace std;
namespace sdds {
	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]){
		set(name, number, vCode, sNumber);
	}

	HealthCard::HealthCard(const HealthCard& hc){
		if (validID(hc.m_name,hc.m_number,hc.m_vCode,hc.m_sNumber)) *this = hc;
	}

	HealthCard& HealthCard::operator=(const HealthCard& hc){
		if (&*this != &hc) {
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
		return *this;
	}

	HealthCard::~HealthCard(){
		delete[] m_name;
	}

	HealthCard::operator bool() const{
		return m_name && strlen(m_name);
	}

	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const{
		return (name && strlen(name) && strlen(name) <= MaxNameLength &&
			number >= 1000000000 && number <= 9999999999 &&
			strlen(vCode) == 2 &&
			strlen(sNumber) == 9);
	}

	void HealthCard::setEmpty(){
		if (m_name) delete[] m_name;
		m_name = nullptr;
		m_number = 0;
		memset(m_vCode, 0, 3);
		memset(m_sNumber, 0, 10);
	}

	void HealthCard::allocateAndCopy(const char* name){
		if (m_name) delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	void HealthCard::extractChar(istream& istr, char ch) const{
		if (istr.peek() == ch) istr.ignore();
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	ostream& HealthCard::printIDInfo(ostream& ostr) const{
		ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
		return ostr;
	}

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]){
		if (validID(name, number, vCode, sNumber)) {
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else setEmpty();
		
	}

	ostream& HealthCard::print(ostream& ostr, bool toFile) const{
		if (validID(m_name, m_number, m_vCode, m_sNumber)) {
			if (toFile) {
				ostr << m_name << ",";
				printIDInfo(ostr)  << endl;
			}
			else {
				ostr << left << setw(50) << setfill('.') << m_name << right;
				printIDInfo(ostr);
			}
		}
		return ostr;
	}

	istream& HealthCard::read(istream& istr) {
		char tempName[MaxNameLength]{};
		long long tempNumber;
		char tempCode[3]{};
		char tempSNumber[10]{};

		istr.clear();

		istr.get(tempName, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> tempNumber;
		extractChar(istr, '-');
		istr.get(tempCode, 3, ',');
		extractChar(istr, ',');
		istr.get(tempSNumber, 10, '\n');
		extractChar(istr, '\n');

		if (!istr.fail()) {
			set(tempName, tempNumber, tempCode, tempSNumber);
		}
		else {
			istr.clear();
			extractChar(istr, '\n');
		}
		
	
		return istr;
	}

	ostream& operator<<(ostream& ostr, const HealthCard& hc){
		if (hc) hc.print(ostr, false);
		else ostr << "Invalid Health Card Record";
		return ostr;
	}

	istream& operator>>(istream& istr, HealthCard& hc){
		hc.read(istr);
		return istr;
	}
}
