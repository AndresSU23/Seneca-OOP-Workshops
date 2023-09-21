/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include <string.h>

#define MAX_NAME_SIZE 127

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
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
   void closeFile() {
      if (fptr) fclose(fptr);
   }
 
   bool read(char*& name) {
       char inFileName[MAX_NAME_SIZE + 1] = "\0";
       if (fscanf(fptr, "%127[^\n]\n", inFileName)) {
           name = new char[strlen(inFileName) + 1];
           strcpy(name, inFileName);
           return 1;
       }
       return 0;
   }

   bool read(int& number) {
       return fscanf(fptr, "%d,", &number);
   }


   bool read(double& salary) {
       return fscanf(fptr, "%lf,", &salary);
   }

}