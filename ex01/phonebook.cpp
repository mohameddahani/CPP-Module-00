/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:44:54 by mdahani           #+#    #+#             */
/*   Updated: 2025/09/14 16:57:57 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook myPhoneBook;

std::string getLine(){
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
    input = getLine();
    newContact.setFirstName(input);

    // Last Name
    std::cout << "Last Name: ";
    input = getLine();
    newContact.setLastName(input);

    // Nick Name
    std::cout << "Nick Name: ";
    input = getLine();
    newContact.setNickName(input);

    // Phone Number
    std::cout << "Phone Number: ";
    input = getLine();
    while (!isDigit(input))
    {
        std::cout << "Phone Number must contain only digits. Try again: ";
        input = getLine();
    }
    newContact.setPhoneNumber(input);

    // Darkest Secret
    std::cout << "Darkest Secret: ";
    input = getLine();
    newContact.setDarkestSecret(input);
    
    // Add this contact to my phone book
    myPhoneBook.addContact(newContact);
    std::cout << "Contact added!" << std::endl;
}

void displayAllContacts(){
    myPhoneBook.displayAllContacts();
    std::cout << "Enter index to view details: ";
    std::string input;
    input = getLine();
    while (!isDigit(input))
    {
        std::cout << "index must contain only digits. Try again: ";
        input = getLine();
    }
    // change string to int
    int index = atoi(input.c_str());
    myPhoneBook.searchContact(index);
}
