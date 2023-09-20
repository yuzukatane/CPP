#include "Harl.hpp"

Harl::Harl() { };

Harl::~Harl() { }

void Harl::debug( void ) const {
    std::cout << "< DEBUG >\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.\nI really do!" << std::endl;
}

void Harl::info( void ) const {
    std::cout << "< INFO >\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) const {
    std::cout << "< WARNING >\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) const {
    std::cout << "< EROOR >\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {

	std::string name[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*func[])() const = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < 4; i++)
	{
		if (level == name[i]) {
			(this->*func[i])();
			return ;
		}
	}
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
