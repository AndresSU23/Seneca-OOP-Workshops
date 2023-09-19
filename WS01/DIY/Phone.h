#ifndef SDDS_PHONE_H // replace with relevant names
#define SDDS_PHONE_H
 
#define MAX_NAME_LENGTH 20
#define MAX_PARSE_NUMBER 14
namespace sdds {
    struct PhoneEntry
    {
        char name[MAX_NAME_LENGTH + 1];
        char n1[3 + 1];
        char n2[3 + 1];
        char n3[4 + 1];
    };
    

    void phoneDir(const char* programTitle, const char* fileName);

    void searchPhone(char *searched, struct PhoneEntry *entry);

    int importPhones(const char *datafile, struct PhoneEntry directory[], int max);

}
#endif