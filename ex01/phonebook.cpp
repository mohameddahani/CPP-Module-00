/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:44:54 by mdahani           #+#    #+#             */
/*   Updated: 2025/09/28 19:38:05 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// * Constructor
PhoneBook::PhoneBook(){
    this->totalContacts = 0;
}

// * Setters and Getters Of Contact
// setters
void Contact::setFirstName(std::string value){
    this->firstName = value;
}
void Contact::setLastName(std::string value){
    this->lastName = value;
}
void Contact::setNickName(std::string value){
    this->nickName = value;
}
void Contact::setPhoneNumber(std::string value){
    this->phoneNumber = value;
}
void Contact::setDarkestSecret(std::string value){
   this-> darkestSecret = value;
}

// getters
std::string Contact::getFirstName(){
    return this->firstName;
}
std::string Contact::getLastName(){
    return this->lastName;
}
std::string Contact::getNickName(){
    return this->nickName;
}
std::string Contact::getPhoneNumber(){
    return this->phoneNumber;
}
std::string Contact::getDarkestSecret(){
    return this->darkestSecret;
}

 // * getters and setters of phonebook:
// setters
void PhoneBook::incrementTotalContacts(){
    this->totalContacts++;
}

// gertters
int PhoneBook::getMaxContacts(){
    return this->maxContacts;
}

int PhoneBook::getTotalContacts(){
    return this->totalContacts;
}

// format the text
std::string PhoneBook::formatField(std::string str){
    if (str.length() > 10){
        return str.substr(0, 9) + ".";
    }
    return str;
};

// Add contact
void PhoneBook::addContact(Contact contact){
    contacts[getTotalContacts() % getMaxContacts()] = contact;
    incrementTotalContacts();
}

// search a contact
void PhoneBook::searchContact(int index){
    if (index < 0 || index >= getTotalContacts()) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    std::cout << "\nFull contact information:" << std::endl;
    std::cout << "First Name    : " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name     : " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname      : " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number  : " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

// display all Contacts
bool PhoneBook::displayAllContacts(){
    if (getTotalContacts() == 0) {
        std::cout << "There are no contacts to display!" << std::endl;
        return false;
    }
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    for (int i = 0; i < getTotalContacts() && i < getMaxContacts(); i++) {
        std::cout << "|" << std::setw(10) << i
                << "|" << std::setw(10) << formatField(contacts[i].getFirstName())
                << "|" << std::setw(10) << formatField(contacts[i].getLastName())
                << "|" << std::setw(10) << formatField(contacts[i].getNickName())
                << "|" << std::endl;
    }
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    return true;
}

PhoneBook myPhoneBook;

std::string handleLine(){
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (std::cin.eof()) {
            std::cout << "Reached end of input. Exiting..." << std::endl;
            exit(EXIT_FAILURE);
        }
        if (line.empty()) {
            std::cout << "Empty input, try again: ";
            continue;
        }
        return line;
    }
}

static bool isDigit(std::string value){
    if (value.empty()){
        return false;
    }
    for (size_t i = 0; i < value.length(); i++){
        if (value[i] == '+' && i == 0)
        {
            continue;
        }
        
        if (value[i] == '+' && i != 0)
        {
            return false;
        }
        
        if (!std::isdigit(value[i]))
        {
            return false;
        }
    }
    return true;
}


void addNewContact(){
    Contact newContact;
    std::string input;
    
    // First Name
    std::cout << "First Name: ";
    input = handleLine();
    newContact.setFirstName(input);

    // Last Name
    std::cout << "Last Name: ";
    input = handleLine();
    newContact.setLastName(input);

    // Nick Name
    std::cout << "Nick Name: ";
    input = handleLine();
    newContact.setNickName(input);

    // Phone Number
    std::cout << "Phone Number: ";
    input = handleLine();
    while (!isDigit(input))
    {
        std::cout << "Phone Number must contain only digits. Try again: ";
        input = handleLine();
    }
    newContact.setPhoneNumber(input);

    // Darkest Secret
    std::cout << "Darkest Secret: ";
    input = handleLine();
    newContact.setDarkestSecret(input);
    
    // Add this contact to my phone book
    myPhoneBook.addContact(newContact);
    std::cout << "Contact added!" << std::endl;
}

void showAllContacts(){
    if (!myPhoneBook.displayAllContacts())
    {
        return;
    }
    std::cout << "Enter index to view details: ";
    std::string input;
    input = handleLine();
    while (!isDigit(input))
    {
        std::cout << "index must contain only digits. Try again: ";
        input = handleLine();
    }
    // change string to int
    int index = atoi(input.c_str());
    myPhoneBook.searchContact(index);
}
