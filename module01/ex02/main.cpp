#include <iostream>

int main() {

    std::string str = "HI THIS IS BRAIN";
    std::string *strptr = &str;
    std::string &strref = str;

    std::cout << &str << std::endl;
    std::cout << strptr << std::endl;
    std::cout << &strref << std::endl;

    std::cout << str << std::endl;
    std::cout << *strptr << std::endl;
    std::cout << strref << std::endl;

}
