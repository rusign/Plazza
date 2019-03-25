#ifndef CORE_HH_
# define CORE_HH_

#include <string>
#include <iostream>
#include <vector>

#include "Parsing.hh"
#include "ManangeOrder.hh"

namespace	Plazza
{
  class		Core
  {

  public:

    Core(int);
    ~Core(void) {}
    void	run(void);

  private :

    void			printTMP(Plazza::Parsing *);

    std::vector<Commander>	_command;
    int				_port;
    int				_nbThreads;

  };
}


#endif
