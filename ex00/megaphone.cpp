/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:53:30 by mdahani           #+#    #+#             */
/*   Updated: 2025/09/13 18:14:08 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av){

    if (ac == 1){
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return(1);
    }
    for (int i = 1; av[i]; i++)
    {
        for (int j = 0; av[i][j]; j++)
        {
            std::cout << (char)toupper(av[i][j]);
        }
    }
    std::cout << std::endl;
    return (0);
}
