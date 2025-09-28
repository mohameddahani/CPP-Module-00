#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// includes
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

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
        void setFirstName(std::string value);
        void setLastName(std::string value);
        void setNickName(std::string value);
        void setPhoneNumber(std::string value);
        void setDarkestSecret(std::string value);

        // getters
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
};

class PhoneBook {
    private:
        static const int maxContacts = 8;
        Contact contacts[maxContacts];
        int totalContacts;
        std::string formatField(std::string str);
    public:
    // constructor
    PhoneBook();

        void addContact(Contact contact);
        void searchContact(int index);
        bool displayAllContacts();


        // getters and setters:
        
        // setters
        void incrementTotalContacts();

        // gertters
        int getMaxContacts();

        int getTotalContacts();
    };
    

// functions
void addNewContact();
void showAllContacts();
std::string handleLine();

#endif
