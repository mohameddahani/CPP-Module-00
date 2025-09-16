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
        std::string formatField(std::string str);
    public:
    // constructor
    PhoneBook(){
        totalContacts = 0;
    }

        void addContact(Contact contact);
        void searchContact(int index);
        bool displayAllContacts();


        // getters and setters:
        
        // setters
        void incrementTotalContacts(){
            totalContacts++;
        }

        // gertters
        int getMaxContacts(){
            return maxContacts;
        }

        int getTotalContacts(){
            return totalContacts;
        }
    };
    

// functions
void addNewContact();
void showAllContacts();
std::string handleLine();

#endif
