/***********************************************************************
// OOP244 Workshop #7 lab
//
// File  Conatainer.cpp
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

#include "Container.h"

using namespace std;

namespace sdds {
	void Container::setEmpty() {
		memset(m_content, 0, 51);
		m_capacity = -1;
		m_volume = 0;
	}
	int Container::capacity() const {
		return m_capacity;
	}
	int Container::volume() const {
		return m_volume;
	}
	Container::Container(const char* content, int capacity, int volume) {
		if (volume > capacity) setEmpty();
		else {
			m_volume = volume;
			clear(capacity, content);
		}
	}
	int Container::operator+=(int fill) {

		if ((volume() + fill) <= capacity()) {
			m_volume += fill;
			return fill;
		}
		else {
			int added = capacity() - volume();
			m_volume = capacity();
			return added;
		}
	}
	int Container::operator-=(int reduce) {
		if (volume() >= reduce) {
			m_volume -= reduce;
			return reduce;
		}
		else {
			int residue = volume();
			m_volume = 0.0;
			return residue;
		}
	}
	Container::operator bool() const {
		return (capacity() == -1);
	}
	void Container::clear(int capacity, const char* content) {
		if (capacity > 0 && content != nullptr) {
			m_capacity = capacity;
			strcpy(m_content, content);
		}
		else setEmpty();
	}
	std::ostream& Container::print(std::ostream& ostr) const {
		if (*this) ostr << "****: (**cc/***)";
		else ostr << m_content << ": (" << volume() << "cc/" << capacity() << ")";
		return ostr;
	}
	std::istream& Container::read(std::istream& istr) {
		if (*this) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.clear();
			istr.ignore();
			istr.get();
		}
		else {
			print(cout) << endl << ">";
			int add{};
			do {
				istr >> add;
				if (istr.fail()) cout << "Invalid Integer, retry: ";
				else if (add < 1 || add > 999) cout << "Value out of range [1<=val<=999]: ";
			} while (istr.fail() || add < 1 || add > 999);
			cout << "Added " << (*this += add) << " CCs";
		}
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, Container& container) {
		return container.print(ostr);
	}
	std::istream& operator>>(std::istream& istr, Container& container) {
		return container.read(istr);
	}
}