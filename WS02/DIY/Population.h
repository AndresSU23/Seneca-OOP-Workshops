/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
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
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#define CODE_SIZE 3
namespace sdds {

	class PopulationCode {
	public:
		char *code;
		int population;

		PopulationCode() {
			code = new char[CODE_SIZE + 1];
			population = 0;
		}
   };
   // returns true of the cstring starts with subString
   bool startsWith(const char* cString, const char* subString);

   bool getPostalCode(char* postal_code_prefix);

   bool load(const char* filename, const char* partial_postal_code_prefix);

   void display();

   void deallocateMemory();

   void sort();

}
#endif // SDDS_POPULATION_H_