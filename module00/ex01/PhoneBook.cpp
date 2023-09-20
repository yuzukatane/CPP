#include <iostream>
#include <string>
#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    this->index = 0;
    this->max = 0;
}

PhoneBook::~PhoneBook(void) { }

std::string modifyString(const std::string input) {
    std::string modifiedString;

    if (input.length() <= 10) {
        modifiedString = std::string(10 - input.length(), ' ') + input;
    } else {
        modifiedString = input.substr(0, 10);
        modifiedString[9] = '.';
    }

    return modifiedString;
}

std::string intToString(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

int stringToInt(const std::string str) {
    std::istringstream iss(str);
    int number;
    iss >> number;
    return number;
}

bool isDigit(const std::string str) {
    if (str.length() != 1) {
        return false;
    }

    char c = str[0];
    return (c >= '0' && c <= '9');
}

void showDetails(Contact contacts) {
    std::cout << "First name : " + contacts.getFirstName() << std::endl;
    std::cout << "Last name : " + contacts.getLastName() << std::endl;
    std::cout << "Nickname : " + contacts.getNickName() << std::endl;
    std::cout << "Phone number : " + contacts.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret : " + contacts.getSecret() << std::endl;
}

void PhoneBook::add(void) {
    std::string str;
    int i = this->index % 8;

    do {
        std::cout << "First name : ";
        if (!std::getline(std::cin, str))
            return ;
        this->contacts[i].setFirstName(str);
    } while (str.empty());

    do {
        std::cout << "Last name : ";
        if (!std::getline(std::cin, str)) 
            return ;
        this->contacts[i].setLastName(str);
    } while (str.empty());

    do {
        std::cout << "Nickname : ";
        if (!std::getline(std::cin, str)) 
            return ;
        this->contacts[i].setNickName(str);
    } while (str.empty());

    do {
        std::cout << "Phone number : ";
        if (!std::getline(std::cin, str)) 
            return ;
        this->contacts[i].setPhoneNumber(str);
    } while (str.empty());

    do {
        std::cout << "Darkest secret : ";
        if (!std::getline(std::cin, str)) 
            return ;
        this->contacts[i].setSecret(str);
    } while (str.empty());

    this->index++;
    if (this->max < 8) {
            this->max++;
    };
    if (this->index == 8) {
        this->index = 0;
    }
}

void PhoneBook::search(void) {
    std::string input;
    int inputIndex;

    if (this->max == 0) {
        std::cout << "There is no saved data available." << std::endl;
        return ;
    }
    std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
    for (int i = 0; i < this->max; i++) {
        std::cout << "|" + modifyString(intToString(i)) + "|";
        std::cout << modifyString(this->contacts[i].getFirstName()) + "|";
        std::cout << modifyString(this->contacts[i].getLastName()) + "|";
        std::cout << modifyString(this->contacts[i].getNickName()) + "|";
        std::cout << std::endl;
    };
    do {
        std::cout << "Enter a index number to see details. Or press Enter to get back to menu" << std::endl;
        if (std::getline(std::cin, input)) {
            if (input == "")
                break ;
            else if (isDigit(input) == false)
                continue ;
            inputIndex = stringToInt(input);

            if (inputIndex >= this->max) {
                std::cout << "The entered index is invalid." << std::endl;
            } else {
                showDetails(this->contacts[inputIndex]);
            }
        }
    } while (1);
}

