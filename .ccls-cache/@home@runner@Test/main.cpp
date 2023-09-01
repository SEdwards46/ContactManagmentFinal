#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Contact.h"
using namespace std;


vector <Contact> readContactsFromFile(string fileName){

  vector <Contact> contacts;
    ifstream file(fileName);

    if (file.is_open()) {
        
        int id;
        string firstName;
        string lastName;
        string address;
        string phoneNumber;

        while (file >> id >> firstName >> lastName >> address >> phoneNumber) {
           
            Contact contact(id, firstName, lastName, address, phoneNumber);
            contacts.push_back(contact);
        }

        file.close();
    }

    return contacts;
}

// Function to write the contacts to the file
void writeContactsToFile(vector <Contact> contacts, string fileName) {

    fstream file(fileName);

    if (file.is_open()) {
        for (Contact contact :   contacts) {
          
            file << contact.getID() << " " << contact.getFirstName()<< " " << contact.getLastName() << " " << contact.getAddress() << " " << contact.getPhoneNumber()<< endl;
        }

        file.close();
    }
}

// Function to add a new contact
void addContact(vector <Contact>& contacts) {
    
    int id;
    string firstName;
    string lastName;
    string address;
    string phoneNumber;

    cout << "Enter the first name: ";
    cin >> firstName;

    cout << "Enter the last name: ";
    cin >> lastName;

    cout << "Enter the address: ";
    cin.ignore();
    getline(cin, address);

    cout << "Enter the phone number: ";
    cin >> phoneNumber;

    if (!contacts.empty()) {
        id = contacts.back().getID() + 1;
    } else {
        id = 1;
    }
  
   Contact contact(id, firstName, lastName, address, phoneNumber);
    contacts.push_back(contact);
    cout << "Contact added successfully!" << endl;
}

// Function to search for a contact by id
void searchById(vector<Contact> contacts) {
    int id;

    cout << "Enter the contact id: ";
    cin >> id;

    auto it = find_if(contacts.begin(), contacts.end(), [id](Contact contact) { return contact.getID() == id; });

    if (it != contacts.end()) {
        Contact contact = *it;
        cout << "ID: " << contact.getID() << endl;
        cout << "Name: " << contact.getFirstName() << " " << contact.getLastName() << endl;
        cout << "Address: " << contact.getAddress() << endl;
        cout << "Phone number: " << contact.getPhoneNumber() << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
}
void searchByLastName(vector<Contact> contacts) {
    string lastName;

    cout << "Enter the last name: ";
    cin >> lastName;

    vector<Contact> matchingContacts;

    for (Contact contact : contacts) {
        if (contact.getLastName() == lastName) {
            matchingContacts.push_back(contact);
        }
    }

    if (matchingContacts.empty()) {
        cout << "No contacts found with the last name: " << lastName << endl;
    } else {
        cout << "Matching contacts:" << endl;

        for (Contact contact : matchingContacts) {
            cout << "ID: " << contact.getID() << endl;
            cout << "Name: " << contact.getFirstName() << " " << contact.getLastName() << endl;
            cout << "Address: " << contact.getAddress() << endl;
            cout << "Phone number: " << contact.getPhoneNumber() << endl;
        }
    }
}

int main() {

    string fileName = "contacts.txt";
    vector<Contact> contacts = readContactsFromFile(fileName);

    while (true) {
        cout << endl;
        cout << "Contact Management System" << endl;
        cout << "1. Add contact" << endl;
        cout << "2. Search by ID" << endl;
        cout << "3. Search by last name" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                writeContactsToFile(contacts, fileName);
                break;

            case 2:
                searchById(contacts);
                break;

            case 3:
                searchByLastName(contacts);
                break;

            case 4:
                cout << "Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

