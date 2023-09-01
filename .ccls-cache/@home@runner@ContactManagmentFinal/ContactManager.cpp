#include "ContactManager.h"

//Initiates program(Welcome Menu)
void ContactManager::startGame(){


    string fileName = "contacts.in";
  //Read Contacts from file store in vector
    vector <Contact> contacts = readContactsFromFile(fileName);

 //Infinite loop that displays as long as program is running and working.
    while (true) {
        cout << endl;
        cout << "Contact Management System" << endl;
        cout << "1. Add contact" << endl;
        cout << "2. Search by ID" << endl;
        cout << "3. Search by last name" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";

      //User decision
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

//Opens file/reads it
vector <Contact> ContactManager::readContactsFromFile(string fileName){

  //Create vector to store contacts and open file for reading
  vector <Contact> contacts;
    ifstream file(fileName);

  //If opened read each line and create a contact object from data, then add to the vector
    if (file.is_open()) {

        while (file >> id2 >> firstName2 >> lastName2 >> address2 >> phoneNumber2) {
           
            Contact contact(id2, firstName2, lastName2, address2, phoneNumber2);
            contacts.push_back(contact);
        }

        file.close();
    }

    return contacts;
}

//Writes on file
void ContactManager::writeContactsToFile(vector <Contact> contacts, string fileName){
   
  fstream file(fileName);

  //If opened iterate over the contacts in vector and write to file.
    if (file.is_open()) {
        for (Contact contact : contacts) {
          
    file << contact.getID() << " " << contact.getFirstName()<< " " << 
    contact.getLastName() << " " << contact.getAddress() << " " << contact.getPhoneNumber()<< 
    endl;
        }

        file.close();
    }
}

//Adds new contact
void ContactManager::addContact(vector <Contact>& contacts){

//Prompt user action/input
    cout << "Enter the first name: ";
    cin >> firstName1;

    cout << "Enter the last name: ";
    cin >> lastName1;

    cout << "Enter the address: ";
    cin.ignore();
    getline(cin, address1);

    cout << "Enter the phone number: ";
    cin >> phoneNumber1;

  //Generate new ID number based off of the last one, will increase by one each time and starts at 1.
    if (!contacts.empty()) {
        id1 = contacts.back().getID() + 1;
    } else {
        id1 = 1;
    }

  //Adding input from user to vector.
   Contact contact(id1, firstName1, lastName1, address1, phoneNumber1);
    contacts.push_back(contact);
    cout << "Contact added successfully!" << endl;
}

//Looks for equal ID to input
void ContactManager::searchById(vector<Contact> contacts){
  
   int id;

    cout << "Enter the contact id: ";
    cin >> id;

  // Use the find_if function from the <algorithm> library to search for a contact with the given ID.
    auto it = find_if(contacts.begin(), contacts.end(), [id](Contact contact) { return contact.getID() == id; });

  //If contact is found, print out associated data 
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

//Looks for equal lastname to input
void ContactManager::searchByLastName(vector <Contact> contacts){
   
  string lastName;

    cout << "Enter the last name: ";
    cin >> lastName;

  //vector for matching contacts 
    vector<Contact> matchingContacts;


  //Iterate over each contact in the vector contacts
    for (Contact contact : contacts) {
        if (contact.getLastName() == lastName) {
          //If match then add contact data to new vector
            matchingContacts.push_back(contact);
        }
    }

    if (matchingContacts.empty()) {
        cout << "No contacts found with the last name: " << lastName << endl;
    } else {
        cout << "Matching contacts:" << endl;

      //Print out data placed into matching contacts vector
        for (Contact contact : matchingContacts) {
            cout << "ID: " << contact.getID() << endl;
            cout << "Name: " << contact.getFirstName() << " " << contact.getLastName() << endl;
            cout << "Address: " << contact.getAddress() << endl;
            cout << "Phone number: " << contact.getPhoneNumber() << endl;
        }
    }
}



