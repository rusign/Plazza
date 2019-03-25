#include <cstdint>
#include "Regex.hh"
#include "Exceptions.hh"

Plazza::Regex::Regex(const std::string &regex)
{

    if (regcomp(&_regex, regex.c_str(), REG_EXTENDED) != 0)
    {
      throw exception::RegexError("Regex Error");
    }
}

Plazza::Regex::~Regex(void)
{

}

bool		Plazza::Regex::add_to_result(std::vector<std::string> &result)
{
  for (int i = 0; i < result.size(); i++)
    _regexResult.push_back(result[i]);
  return (true);
}

bool            Plazza::Regex::check_duplicate(std::vector<std::string> &result)
{
    std::vector<std::string>    tmp = result;

    std::sort(tmp.begin(), tmp.end());
    auto last = std::unique(tmp.begin(), tmp.end());
    tmp.erase(last, tmp.end());
    if (tmp.size() == result.size())
        return (true);
    result.clear();
    return (false);
}

bool            Plazza::Regex::decipher_caesar(const std::string &file)
{
  std::vector<std::string>	result;
    std::string decipher;
    int         i;

    result.clear();
    for (unsigned char j = 1; j != 0; j++) {
        i = 0;
        decipher.clear();
        while (file[i])
            decipher += ((file[i++] + j) % 256);
        if (checkRegex(decipher, result) && check_duplicate(result))
	  {
	    add_to_result(result);
            return (true);
	  }
    }
    return (false);
}

void		Plazza::Regex::get_information(const std::string &name)
{
  bool			ret = false;
  std::ifstream		file(name);
  std::stringstream	buffer;
  std::string		content;
  std::vector<std::string> result;

  if (file.is_open())
    {
      buffer << file.rdbuf();
      content = buffer.str();
      result.clear();
      if (checkRegex(content, result) && check_duplicate(result))
	ret = add_to_result(result);
      if (ret == false)
	ret = decipher_caesar(content);
      if (ret == false)
	decipher_xor(content);
      file.close();
    }
}

bool		Plazza::Regex::decipher_xor(const std::string &file)
{
  std::vector<std::string>	result;
  std::string	decipher;
  int		i;

  result.clear();
  for (unsigned char j = 1; j != 0; j++)
    {
        i = 0;
        decipher.clear();
        while (file[i])
	  decipher += file[i++] ^ j;
	if (checkRegex(decipher, result) && check_duplicate(result))
	  {
	    add_to_result(result);
	    return (true);
	  }
    }
  for (uint16_t c = 1; c != 0; c++)
    {
      i = 0;
      decipher.clear();
      while (file[i])
	{
	  if (i % 2 == 0)
	    decipher += (file[i] ^ (reinterpret_cast<char *>(&c))[0]);
	  else
	    decipher += (file[i] ^ (reinterpret_cast<char *>(&c))[1]);
	  i++;
	}
      if (checkRegex(decipher, result) && check_duplicate(result))
	{
	  add_to_result(result);
	  return (true);
	}
    }
  return (true);
}

bool    Plazza::Regex::checkRegex(const std::string &file, std::vector<std::string> &result) {

    bool        ret = false;
    std::string tmp_file(file);
    std::string tmp;
    regmatch_t   pmatch[1];

    while (regexec(&_regex, tmp_file.c_str(), 1, pmatch, 0) == 0)
    {
        tmp = &tmp_file.c_str()[pmatch[0].rm_so];
        tmp.resize(pmatch[0].rm_eo - pmatch[0].rm_so);
        result.push_back(tmp);
        tmp.clear();
        tmp_file = &(tmp_file[pmatch[0].rm_eo]);
        ret = true;
    }
    return (ret);
}

std::vector<std::string>    Plazza::Regex::getRegex(void) const {

    return (_regexResult);
}

