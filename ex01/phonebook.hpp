#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// includes
#include <iostream>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>

// classes
class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        // setters
        void setFirstName(std::string value){
            firstName = value;
        }
        void setLastName(std::string value){
            lastName = value;
        }
        void setNickName(std::string value){
            nickName = value;
        }
        void setPhoneNumber(std::string value){
            phoneNumber = value;
        }
        void setDarkestSecret(std::string value){
            darkestSecret = value;
        }

        // getters
        std::string getFirstName(){
            return firstName;
        }
        std::string getLastName(){
            return lastName;
        }
        std::string getNickName(){
            return nickName;
        }
        std::string getPhoneNumber(){
            return phoneNumber;
        }
        std::string getDarkestSecret(){
            return darkestSecret;
        }
};

class PhoneBook {
    private:
        static const int maxContacts = 8;
        Contact contacts[maxContacts];
        int totalContacts;
        std::string formatField(std::string str){
            if (str.length() > 10)
            {
                return str.substr(0, 9) + ".";
            }
            return str;
        }
    public:
        void addContact(Contact contact){
            contacts[totalContacts % maxContacts] = contact;
            totalContacts++;
        }

        // constructor
        PhoneBook(){
            totalContacts = 0;
        }

        void searchContact(int index) {
            if (index < 0 || index >= totalContacts) {
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

        void displayAllContacts() {
            if (totalContacts == 0) {
                std::cout << "There are no contacts to display!" << std::endl;
                return;
            }
            std::cout << "+----------+----------+----------+----------+" << std::endl;
            std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
            std::cout << "+----------+----------+----------+----------+" << std::endl;
            for (int i = 0; i < totalContacts && i < maxContacts; i++) {
                std::cout << "|" << std::setw(10) << i
                        << "|" << std::setw(10) << formatField(contacts[i].getFirstName())
                        << "|" << std::setw(10) << formatField(contacts[i].getLastName())
                        << "|" << std::setw(10) << formatField(contacts[i].getNickName())
                        << "|" << std::endl;
            }
            std::cout << "+----------+----------+----------+----------+" << std::endl;
        }

};


// functions
void addNewContact();
void displayAllContacts();
std::string getLine();

#endif
