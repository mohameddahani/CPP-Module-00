/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:48:27 by mdahani           #+#    #+#             */
/*   Updated: 2025/09/16 19:22:29 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(int ac, char **av){
    if (ac != 1)
    {
        std::cout << "Please enter only name of programe [phonebook]" << std::endl;
        return 1;
    }
    (void)av;
    std::string command;
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
        command = handleLine();
        if (command == "ADD") {
            addNewContact();
        }
        else if (command == "SEARCH") {
            showAllContacts();
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
