#include "Parsing.hh"

Parsing::Parsing(const std::string & email)
{
    this->_regex = new Regex;

    if (this->_regex->checkEmail(email) == true)
        std::cout << "oui email" << std::endl;
        else if (this->_regex->checkIp(email))
        std::cout << "oui Ip " << std::endl;
    else
        std::cout << "non" << std::endl;


}

Parsing::~Parsing(void)
{

}
