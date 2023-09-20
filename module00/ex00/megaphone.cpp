#include <iostream>
// #include <string>

void megaphone(std::string str)
{
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (std::islower(str[i]))
            str[i] = std::toupper(str[i]);
    };

    std::cout << str;
}

int main(int argc, char *argv[])
{
    if (argc > 1) {
        for (int i = 1; i < argc; i++)
            megaphone(argv[i]);
        std::cout << std::endl;
    } else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}