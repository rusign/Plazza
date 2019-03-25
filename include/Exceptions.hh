#ifndef EXCEPTION_HH_
# define EXCEPTION_HH_

#include <string>
#include <exception>

namespace exception
{
  class PlazzaError : public std::exception
  {
  public :
    PlazzaError(const std::string &message, const std::string &component = "Unknown") :
      _message(message), _component(component) {}
    virtual ~PlazzaError() throw () {}

    const std::string &GetComponent() const {return _component;}
    const char *what() const throw() {return _message.c_str();}

  private :
    std::string _message;
    std::string _component;
  };

  class ParsingError : public PlazzaError
  {
  public :
    ParsingError(const std::string &message) : PlazzaError(message, "Parsing Error") {}
  };

  class CoreError : public PlazzaError
  {
  public :
    CoreError(const std::string &message) : PlazzaError(message, "Core Error") {}
  };
  class RegexError : public PlazzaError
  {
  public :
    RegexError(const std::string &message) : PlazzaError(message, "Regex Error") {}
  };
}


#endif
