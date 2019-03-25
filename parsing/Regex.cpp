#include "Regex.hh"

Regex::Regex(void)
{

    if (regcomp(&_regexEmail, "^[a-zA-Z0-9]+@[a-zA-Z0-9]+.[a-zA-Z]", REG_NOSUB | REG_EXTENDED) != 0)
    {
        std::cout << "pas valid" << std::endl;
        return;
    }
    else if (regcomp(&_regexIp, "[0-255].[0-255].[0-255].[0-255]", REG_NOSUB | REG_EXTENDED) != 0)
    {
        std::cout << "pas valid" << std::endl;
        return;
    }
}

Regex::~Regex(void)
{
}

bool Regex::checkIp(const std::string &ip)
{
    return (regexec(&_regexIp, ip.c_str(), 0, NULL, 0) == 0) ? true : false;
}

bool Regex::checkEmail(const std::string &email)
{
    return (regexec(&_regexEmail, email.c_str(), 0, NULL, 0) == 0) ? true : false;
}
