/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:48:27 by mdahani           #+#    #+#             */
/*   Updated: 2025/09/14 16:09:48 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(){
    std::string command;
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
        command = getLine();
        if (command == "ADD") {
            addNewContact();
        }
        else if (command == "SEARCH") {
            displayAllContacts();
        }
        else if (command == "EXIT") {
            std::cout << "Exiting program ..." << std::endl;
            break;
        }
        else {
            std::cout << "Invalid command! Please enter ADD, SEARCH, or EXIT" << std::endl;
        }
    }
}
