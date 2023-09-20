#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void){
}

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie(void){
    std::cout << this->_name << ": destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->_name = name;
}

