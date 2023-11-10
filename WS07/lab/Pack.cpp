/***********************************************************************
// OOP244 Workshop #7 lab
//
// File  Pack.h
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

#include "Pack.h"

using namespace std;

namespace sdds {
	Pack::Pack(const char* content, int size, int unitSize, int noUnits) : Container(content, size* unitSize, noUnits* unitSize){
		if (unitSize > 0) m_unitSize = unitSize;
		else Container::setEmpty();
	}
	int Pack::operator+=(int add) {
		return (Container::operator+=(add*m_unitSize))/m_unitSize;
	}
	int Pack::operator-=(int remove) {
		return (Container::operator-=(remove * m_unitSize)) / m_unitSize;
	}
	int Pack::unit() const {
		return m_unitSize;
	}
	int Pack::noOfUnits() const {
		return Container::volume()/m_unitSize;
	}
	int Pack::size() const {
		return Container::capacity()/m_unitSize;
	}
	void Pack::clear(int size, int unitSize, const char* content) {
		if (unitSize > 0) {
			clear(size * unitSize, content);
			m_unitSize = unitSize;
		}
	}
	std::ostream& Pack::print(std::ostream& ostr) const {
		Container::print(ostr);
		if (!Container::operator bool()) ostr << ", " << noOfUnits() << " in a pack of " << size();
		return ostr;
	}
	std::istream& Pack::read(std::istream& istr) {
		if (Container::operator bool()) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.clear();
			istr.get();

		}
		else {
			if (noOfUnits() < size()) {
				cout << "Add to ";
				print(cout) << endl << "> ";
				int add{};
				do {
					istr >> add;
					if (istr.fail()) cout << "Invalid Integer, retry: ";
					else if (add < 1 || add > (size() - noOfUnits())) cout << "Value out of range [1<=val<=" << (size() - noOfUnits()) << "]: ";
				} while (istr.fail() || add < 1 || add > (size()-noOfUnits()));
				cout << "Added " << (*this += add) << endl;
			}
			else {
				cout << "Pack is full!, press <ENTER> to continue...";
				istr.clear();
				istr.ignore();
				istr.get();
			}
			
		}
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, Pack& pack) {
		return pack.print(ostr);
	}
	std::istream& operator>>(std::istream& istr, Pack& pack) {
		return pack.read(istr);
	}
}