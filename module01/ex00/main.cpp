#include <iostream>
#include "Zombie.hpp"

int main() {
    Zombie z1("z1");
    Zombie *z2 = newZombie("z2");
    randomChump("z3");

    z1.announce();
    z2->announce();
    delete z2;
    return 0;
}
