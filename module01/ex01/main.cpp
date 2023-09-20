#include <iostream>
#include "Zombie.hpp"


int main() {
    int n = 10;

    Zombie z1("z1");
    Zombie *horde = zombieHorde(n, "nobody");


    z1.announce();

    for (int i = 0; i < n; i++) {
        horde[i].announce();
    }

    delete [] horde;
    return 0;
}
