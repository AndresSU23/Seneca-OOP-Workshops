/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Population.h"
#include "File.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds {

    PopulationCode *codesArr;
    int totalCodes = 0, searchCodes = 0;
   bool startsWith(const char* cstring, const char* subString) {
      return std::strstr(cstring, subString) == cstring;
   }

   bool getPostalCode(char* postal_code_prefix)
   {    
       cout << "Population Report" << endl << "-----------------" << endl << "Enter postal code:" << endl << "> ";
       cin >> postal_code_prefix;
       if (!strcmp(postal_code_prefix, "!")) return false;
       return true;
   }

   bool load(const char* filename, const char* partial_postal_code_prefix)
   {
       if (!openFile(filename)) return false;
       totalCodes = noOfRecords();
       codesArr = new PopulationCode[totalCodes]{};
       PopulationCode tempCode{};
       int i;
       searchCodes = 0;
       for (i = 0; i < totalCodes; i++)
       { 
           if (!(read(tempCode.code) && read(tempCode.population))) { 
               delete[] tempCode.code;
               return false; 
           }
 
           if (!strcmp(partial_postal_code_prefix, "all") || 
               startsWith(tempCode.code, partial_postal_code_prefix)) {

               strcpy(codesArr[searchCodes].code, tempCode.code);
               codesArr[searchCodes].population = tempCode.population;
               searchCodes++;
           }
	   
       }
       closeFile();
       delete[] tempCode.code;
       return true;
   }

   void display()
   {
       cout << "Postal Code: population" << endl << "-------------------------" << endl;
       int i = 0, totalPopulation = 0;
       sort();
       for (i = 0; i < searchCodes; i++)
       {
           cout << (i + 1) << "- " << codesArr[i].code << ":  " << codesArr[i].population << endl;
           totalPopulation += codesArr[i].population;
       }
       cout << "-------------------------" << endl << "Population of the listed areas: " << totalPopulation << endl << endl;
   }

   void deallocateMemory()
   {
       int i;
       for (i = 0; i < totalCodes; i++) delete[] codesArr[i].code;
       delete[] codesArr;
   }

   void sort() {
       int i, j;
       PopulationCode tempCode{};
       for (i = searchCodes - 1; i > 0; i--) {
           for (j = 0; j < i; j++) {
               if (codesArr[j].population > codesArr[j + 1].population) {
                   strcpy(tempCode.code,codesArr[j].code);
		   tempCode.population = codesArr[j].population;
		   
		   strcpy(codesArr[j].code, codesArr[j+1].code);
		   codesArr[j].population = codesArr[j+1].population;
		  
		   strcpy(codesArr[j+1].code,tempCode.code);
                   codesArr[j+1].population = tempCode.population;
               }
           }
       }
       delete[] tempCode.code;
   }

   


}
