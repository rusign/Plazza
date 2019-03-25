#ifndef REGEX_HH_
# define REGEX_HH_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex.h>
#include <algorithm>

#define PHONE	"0 ?([0-9] ?){8} ?[0-9]"
#define IP	"(([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.){3}([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])"
#define EMAIL	"[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+"

namespace	Plazza
{
  class		Regex
  {
    public :

    Regex(const std::string &);
    ~Regex(void);
    std::vector<std::string> getRegex(void) const;
    void	get_information(const std::string &);

    /*
      it has to be private!!!
    */

private :
    bool                        check_duplicate(std::vector<std::string> &);
    bool			add_to_result(std::vector<std::string> &);
    bool                        decipher_caesar(const std::string &);
    bool                        decipher_xor(const std::string &);
    bool                        checkRegex(const std::string &, std::vector<std::string> &);
    regex_t                     _regex;
    std::vector<std::string>    _regexResult;

  };
}

#endif
