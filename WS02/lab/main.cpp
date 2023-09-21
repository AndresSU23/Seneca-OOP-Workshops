/***********************************************************************
// OOP244 Workshop #2 lab (part 1): tester program
//
// File  main.cpp
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
#include "Employee.h"
using namespace sdds;
int main() {
   if(load()) {
      display();
   }
   deallocateMemory();
   return 0;
}