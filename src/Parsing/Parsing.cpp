#include "Parsing.hh"

Plazza::Parsing::Parsing(const std::string &line)
{
  splitLine(line);
}

void	Plazza::Parsing::splitLine(const std::string &line)
{
  std::istringstream	parse(line);
  std::string		tmp;

  while (getline(parse, tmp, ';'))
    {

      Plazza::Commander command(tmp);

      if (command.getFile().size() > 0)
	_commander.push_back(Commander(tmp));

    }
}

std::vector<Plazza::Commander>	Plazza::Parsing::getCommander(void) const
{
  return _commander;
}
