#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Phone.h"
#include "cStrTools.h"

using namespace std;
namespace sdds {
    
    void phoneDir(const char* programTitle, const char* fileName){
        int i;
        cout << programTitle << " phone direcotry search" << endl << "-------------------------------------------------------" << endl;
        struct PhoneEntry directory[40] = {{"\0","\0","\0","\0"}};
        if(importPhones(fileName, directory, 40)){
            char searched[MAX_NAME_LENGTH + 1] = {"\0"};
            do
            {
                cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl << "> ";
                cin >> searched;
                for (i = 0; i < 40; i++)
                {
                    searchPhone(searched, &directory[i]);
                }
                

            } while (strCmp(searched, "!"));
        }
        cout << "Thank you for using Star Wars directory.";
        
    }

    void searchPhone(char *searched, struct PhoneEntry *entry){
        char tempName[MAX_NAME_LENGTH + 1];
        char tempName2[MAX_NAME_LENGTH + 1];
        toLowerCaseAndCopy(tempName, searched);
        toLowerCaseAndCopy(tempName2, entry->name);
        const char *ptr = strStr(tempName2, tempName);
        if (ptr != NULL){
            cout << entry->name << ": (" << entry->n1 << ") " << entry->n2 << "-" << entry->n3 << endl;
        }
    }

    int importPhones(const char *datafile, struct PhoneEntry directory[], int max)
    {
        FILE *phonesFile;
        int i=0, flag = 1;
        
        phonesFile = fopen(datafile, "r");
        if (phonesFile == NULL) {
            cout << datafile << " file not found!" << endl;
            return 0;
        }

        while (i < max && fscanf(phonesFile, "%[^\t]\t%s\t%s\t%s\n" , directory[i].name,
                                directory[i].n1,
                                directory[i].n2,
                                directory[i].n3) != EOF)
        {
            flag = 0;
            i++;

        }
        fclose(phonesFile);

        if (flag)
        {
            cout << datafile << " file not found!" << endl;
            return 0;
        }
        else
        {
            return i;
        }
    }

}