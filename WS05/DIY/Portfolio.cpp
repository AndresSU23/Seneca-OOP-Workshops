/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
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
#include <cstring>

#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const{
        return m_value;
    }

    Portfolio::operator const char* () const{
        return m_stock;
    }

    Portfolio::operator char() const {
        return m_type;
    }

    Portfolio::operator bool() const {
        return m_type == 'G' || m_type == 'V' || m_type == 'I';
    }

    Portfolio& Portfolio::operator+=(const double value) {
        m_value += (*this && value >= 0) ? value : 0;
        return *this;
    }

    Portfolio& Portfolio::operator-=(const double value) {
        m_value -= (*this && value >= 0) ? value : 0;
        return *this;
    }

    bool Portfolio::operator~() const {
        return m_value < 0;
    }

    Portfolio& Portfolio::operator<<(Portfolio& transfer) {
        if (*this && transfer && strcmp((const char*)(*this), (const char*)(transfer))) {
            *this += transfer;
            transfer.emptyPortfolio();
        }
        return *this;
    }

    Portfolio& Portfolio::operator>>(Portfolio& transfer) {
        if (*this && transfer && strcmp((const char*)(*this), (const char*)(transfer))) {
            transfer += *this;
            emptyPortfolio();
        }
        return *this;
    }




    double operator+(const Portfolio& p1, const Portfolio& p2)
    {
        return (p1 && p2) * (double(p1) + double(p2));
    }

    double& operator+=(double& value, const Portfolio& portfolio) {
        value += double(portfolio);
        return value;
    }

}