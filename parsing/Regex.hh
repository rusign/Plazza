#ifndef REGEX_HH_
# define REGEX_HH_

#include "Regex.hh"

#include <regex.h>
#include <iostream>
#include <string>

class Regex
{
public :
    Regex(void);
    ~Regex(void);
    bool    checkEmail(const std::string &email);
    bool    checkIp(const std::string &);

private :
    regex_t     _regexEmail;
    regex_t     _regexIp;

};

#endif
