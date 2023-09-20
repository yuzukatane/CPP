#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;

    while (1)
    {
        std::string cmd;
        if (std::getline(std::cin, cmd)) {
            if (cmd == "ADD") {
                phonebook.add();
            }
            else if (cmd == "SEARCH") {
                phonebook.search();
            }
            else if (cmd == "EXIT")
                break ;
        } else {
            break ;
        } 
    }
    return 0;
}
