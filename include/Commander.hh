
#ifndef COMMANDER_HH_
# define COMMANDER_HH_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

namespace	Plazza
{
  class		Commander
  {

  public :
    enum Information
      {
	PHONE_NUMBER,
	EMAIL_ADDRESS,
	IP_ADDRESS,
	NONE
      };

  public :
    Commander();
    Commander(const std::string &);
    ~Commander(void) {}
    std::vector<std::string>				getFile(void) const;
    Plazza::Commander::Information			getInformation(void) const;

  private :

    std::string						deleteTab(const std::string &, const char, const char);
    bool						checkVector(const std::string &);
    bool						badLine(const std::string &);
    std::string						deleteSpace(const std::string &);
    void						getFile(const std::string &);
    Commander::Information				_information;
    std::map<std::string, Commander::Information>	_map;
    std::vector<std::string>				_file;
    bool						checkLine(const std::string &);
    std::string						changeString(const std::string &);
    bool						openFile(const std::string &file);
  };
}


#endif
