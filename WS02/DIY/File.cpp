/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   bool read(char*& name) {
       char inFileName[3 + 1] = "\0";
       if (fscanf(fptr, "%3[^,],", inFileName)) {
           strcpy(name, inFileName);
           return 1;
       }
       return 0;
   }

   bool read(int& number) {
       return fscanf(fptr, "%d\n", &number);
   }

   int noOfRecords() {
       int noOfRecs = 0;
       char ch;
       while (fscanf(fptr, "%c", &ch) == 1) {
           noOfRecs += (ch == '\n');
       }
       rewind(fptr);
       return noOfRecs;
    }
}