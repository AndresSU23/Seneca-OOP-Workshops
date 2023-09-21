/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.h
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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char*& name);
   bool read(int& number);
   bool read(double& salary);
 

}

#endif // !SDDS_FILE_H_