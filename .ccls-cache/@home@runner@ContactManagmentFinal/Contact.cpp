#include "Contact.h"


Contact::Contact(){
  
  id = 0;
}

Contact::Contact(int iD, string fN, string lN, string add, string pN){
  
  id = iD;
  firstName = fN;
  lastName = lN;
  address = add;
  phoneNumber = pN;
}

int Contact::getID(){
  
  return id;
}

string Contact::getFirstName(){
  
  return firstName;
}

string Contact::getLastName(){
  
  return lastName;
}

string Contact::getAddress(){
  
  return address;
}

string Contact::getPhoneNumber(){
  
  return phoneNumber;
}

