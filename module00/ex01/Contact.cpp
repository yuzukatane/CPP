#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) { }

Contact::~Contact(void) { }

std::string const& Contact::getFirstName(void) const {
   return _firstName;
}
std::string const& Contact::getLastName(void) const {
    return _lastName;
}
std::string const& Contact::getNickName(void) const {
    return _nickname;
}
std::string const& Contact::getPhoneNumber(void) const {
    return _phoneNumber;
}
std::string const& Contact::getSecret(void) const {
    return _secret;
}

void Contact::setFirstName(std::string const& firstName) {
    this->_firstName = firstName;
}
void Contact::setLastName(std::string const& lastName) {
    this->_lastName = lastName;
}
void Contact::setNickName(std::string const& nickname) {
    this->_nickname = nickname;
}
void Contact::setPhoneNumber(std::string const& phoneNumber) {
    this->_phoneNumber = phoneNumber;
}
void Contact::setSecret(std::string const& secret) {
    this->_secret = secret;
}