/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    Name          David Andres Sanchez Umbarila
//    Student Id    140273228
//    Email         dasanchez-umbarila@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#include <iostream>
#include "Employee.h"
#include "File.h"


using namespace std;
namespace sdds {
   const char fileName[] = "employees.csv";

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   bool load(Employee& entry)
   {
       char*& refName = entry.m_name;
       int& refEmpNo = entry.m_empNo;
       double& refSalary = entry.m_salary;
       return (sdds::read(refEmpNo) && sdds::read(refSalary) && sdds::read(refName));
       // return the combined success result of the three read functions. These read 
       // functions should set the properties of the reference argument of the load function
   }


   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      int i;
      if (!openFile(fileName)) {
          cout << "Could not open data file : " << fileName << endl;
          return 0;
      }
      noOfEmployees = noOfRecords();
      employees = new Employee[noOfEmployees];
      for (i = 0; i < noOfEmployees; i++)
      {
          Employee& entry = employees[i];
          if (!sdds::load(entry)) {
              cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
              return 0;
          }
      }
      closeFile();
      return 1;

   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& emp) {
       cout << emp.m_empNo << ": " << emp.m_name << ", $" << emp.m_salary << endl;
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void display() {
       int i;
       cout << "Employee Salary report, sorted by employee number" << endl << "no - Empno, Name, Salary" << endl << "------------------------------------------------" << endl;
       for (i = 0; i < noOfEmployees; i++){
           cout << (i + 1) << "- " << employees[i].m_empNo << ": " << employees[i].m_name << ", $" << employees[i].m_salary << endl;
       }
   }

   void deallocateMemory() {
       int i;
       for (i = 0; i < noOfEmployees; i++) delete[] employees[i].m_name;
       delete[] employees;
   }



}