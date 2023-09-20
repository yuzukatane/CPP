#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
    public:
        Contact(void);
        ~Contact(void);

        std::string const& getFirstName(void) const;
        std::string const& getLastName(void) const;
        std::string const& getNickName(void) const;
        std::string const& getPhoneNumber(void) const;
        std::string const& getSecret(void) const;

        void setFirstName(std::string const& firstName);
        void setLastName(std::string const& lastName);
        void setNickName(std::string const& nickName);
        void setPhoneNumber(std::string const& phoneNumber);
        void setSecret(std::string const& secret);

    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _secret;
};
#endif
