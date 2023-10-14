/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
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
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const {
        return (m_passengers > 0) && (m_fuel >= (m_passengers * LITER_PER_PERSON));
    }

    Flight::operator int() const {
        return m_passengers;
    }

    Flight::operator double() const {
        return m_fuel;
    }

    Flight::operator const char*() const {
        return m_title;
    }

    bool Flight::operator~() const
    {
        return m_passengers == 0;
    }

    Flight& Flight::operator=(Flight& transferFlight) {
        m_fuel = transferFlight.m_fuel;
        m_passengers = transferFlight.m_passengers;
        strcpy(m_title, transferFlight.m_title);
        transferFlight.m_fuel = 0;
        transferFlight.m_passengers = 0;
        strcpy(transferFlight.m_title, "EmptyPlane");
        return *this;
    }

    Flight& Flight::operator=(int passengers)
    {
        m_passengers = (passengers > 0 && m_passengers <= Boen747Capacity) ? passengers : m_passengers;
        return *this;
    }

    Flight& Flight::operator=(double fuel)
    {
        m_fuel = (fuel > 0 && m_fuel <= FuelTankCapacity) ? fuel : m_fuel;
        return *this;
    }

    Flight& Flight::operator+=(double addFuel)
    {
        m_fuel += (addFuel < 0 || ((m_fuel + addFuel) > FuelTankCapacity)) ? 0 : addFuel;
        return *this;
    }

    Flight& Flight::operator+=(int addPasssengers)
    {
        m_passengers += (addPasssengers < 0 || (m_passengers + addPasssengers) > Boen747Capacity) ? 0 : addPasssengers;
        return *this;
    }

    Flight& Flight::operator-=(double reduceFuel)
    {
        m_fuel -= (reduceFuel < 0 || (m_fuel - reduceFuel) < 0) ? 0 : reduceFuel;
        return *this;
    }

    Flight& Flight::operator-=(int reducePasssengers)
    {
        m_passengers -= (reducePasssengers < 0 || (m_passengers - reducePasssengers) < 0) ? 0 : reducePasssengers;
        return *this;
    }

    Flight& Flight::operator<<(Flight& transferFlight)
    {
        int sumPassengers = m_passengers + transferFlight.m_passengers;
        m_passengers = ((Boen747Capacity - sumPassengers) < 0) ? Boen747Capacity : (Boen747Capacity - sumPassengers);
        transferFlight.m_passengers = ((Boen747Capacity - sumPassengers) < 0) ? sumPassengers - Boen747Capacity : 0;
        return *this;
    }

    Flight& Flight::operator>>(Flight& transferFlight)
    {
        int sumPassengers = m_passengers + transferFlight.m_passengers;
        transferFlight.m_passengers = ((Boen747Capacity - sumPassengers) < 0) ? Boen747Capacity : (Boen747Capacity - sumPassengers);
        m_passengers = ((Boen747Capacity - sumPassengers) < 0) ? sumPassengers - Boen747Capacity : 0;
        return *this;
    }


    int Flight::operator+(const Flight& flight) const
    {
        return (*this && flight) ? (m_passengers + flight.m_passengers) : 0;
    }

    int operator+=(int& passengers, const Flight& flight)
    {
        passengers += int(flight);
        return passengers;
    }

}