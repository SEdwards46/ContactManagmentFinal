#include "Contact.h"

using namespace std;

class ContactManager{

private:
int choice;
int id1;
string firstName1;
string lastName1;
string address1;
string phoneNumber1;
int id2;
string firstName2;
string lastName2;
string address2;
string phoneNumber2;


public:
void startGame();
vector<Contact> readContactsFromFile(string fileName);
void writeContactsToFile(vector <Contact> contacts, string fileName);
void addContact(vector <Contact>& contacts);
void searchById(vector<Contact> contacts);
void searchByLastName(vector <Contact> contacts);
};