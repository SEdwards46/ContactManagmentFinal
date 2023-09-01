#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Contact {
private:
    int id;
    string firstName;
    string lastName;
    string address;
    string phoneNumber;

public:
Contact();
Contact(int iD, string fN, string lN, string add, string pN);
int getID();
string getFirstName();
string getLastName();
string getAddress();
string getPhoneNumber();
};