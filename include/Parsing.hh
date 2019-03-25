#ifndef PARSING_HH_
# define PARSING_HH_

#include <string>
#include "Commander.hh"

namespace	Plazza
{
  class		Parsing
  {

  public :
    Parsing(const std::string &);
    ~Parsing(void) {}
    std::vector<Plazza::Commander>	getCommander(void) const;

  private :
    void				splitLine(const std::string &);
    std::vector<Plazza::Commander>	_commander;

  };
}


#endif
