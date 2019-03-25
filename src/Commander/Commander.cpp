#include <algorithm>
#include "Commander.hh"

Plazza::Commander::Commander() {

}

Plazza::Commander::Commander(const std::string &Commander)
{
  _map["PHONE_NUMBER"] = Plazza::Commander::PHONE_NUMBER;
  _map["EMAIL_ADDRESS"] = Plazza::Commander::EMAIL_ADDRESS;
  _map["IP_ADDRESS"] = Plazza::Commander::IP_ADDRESS;
  _map["NONE"] = Plazza::Commander::NONE;
  getFile(Commander);
}

std::vector<std::string>	Plazza::Commander::getFile(void) const
{
  return (_file);
}

Plazza::Commander::Information	Plazza::Commander::getInformation(void) const
{
  return (_information);
}

std::string	Plazza::Commander::deleteTab(const std::string &Commander, const char tab, const char space)
{
  std::string	tmp(Commander);

  std::replace(tmp.begin(), tmp.end(), tab, space);
  return (tmp);
}

std::string	Plazza::Commander::deleteSpace(const std::string &Commander)
{
  std::string	tmp(deleteTab(Commander, '\t', ' '));

  if (tmp[0] == ' ')
    tmp.erase(tmp.begin());
  for (int j = 0; j <= tmp.size(); ++j)
    {
      for (int i = 0; i <= j; ++i)
  	{
	  if (tmp[i] == ' ' && tmp[i + 1] == ' ')
  	    tmp.erase(tmp.begin() + i);
  	  else if (tmp[i] == '\0' && tmp[i] == '0')
  	    tmp.erase(tmp.end() - 1);
  	}
    }
  return (tmp);
}

bool			Plazza::Commander::badLine(const std::string &Commander)
{
  std::string		tmp_c(deleteSpace(Commander));
  std::istringstream	parser(tmp_c);
  std::string		tmp;
  int			size(0);
  int			file(0);

  while (getline(parser, tmp, ' '))
    {
      if (_map.find(tmp) != _map.end())
	++size;
      else
	++file;
    }
  if (size > 1 || file == 0)
    return (false);
  return (true);
}

bool			Plazza::Commander::checkLine(const std::string &line)
{
  int			error(0);

  for (int i = 0; i < line.size(); ++i)
    {
      if (!isprint(line[i]))
	++error;
    }
  return (error == 0) ? true : false;
}

bool			Plazza::Commander::checkVector(const std::string &cmp)
{
  return (std::find(this->_file.begin(), this->_file.end(), cmp) != this->_file.end()) ? false : true;
}

std::string		Plazza::Commander::changeString(const std::string &l)
{
  std::string		line(l);
  std::string		tmp;

  line = deleteTab(line, '\t', ' ');
  for (int i = 0; i < line.size(); ++i)
    {
      if (isprint(line[i]))
	tmp += line[i];
    }
  return tmp;
}

bool			Plazza::Commander::openFile(const std::string &file)
{
  std::ifstream		_stream(file);

  return (true);
  return (_stream.is_open()) ? _stream.close(), true : false;
}

void			Plazza::Commander::getFile(const std::string &Commander)
{
  std::string		tmp_c(Plazza::Commander::changeString(Commander));
  tmp_c = Plazza::Commander::deleteSpace(tmp_c);
  std::istringstream	parser(tmp_c);
  std::string		tmp;

  _information = Plazza::Commander::NONE;
  if (badLine(Commander) == false)
    return ;
  while (getline(parser, tmp, ' '))
    {
      if (tmp.size() > 0 && _map.find(tmp) != _map.end())
	{
	  _information = _map[tmp];
	  break;
	}
      else if (tmp.size() > 0 && openFile(tmp) == true)
	{
	  _file.push_back(tmp);
	}
    }
  if (_information == Plazza::Commander::NONE && _file.size() > 0)
	_file.clear();
}
