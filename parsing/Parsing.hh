#ifndef PARSING_HH_
# define PARSING_HH_

#include "Regex.hh"

#include <iostream>
#include <string>
#include <regex.h>

class	Parsing
{
public :

    Parsing(const std::string &);
    ~Parsing(void);
private:

    Regex   *_regex;

};

#endif