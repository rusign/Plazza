
#include "Exceptions.hh"
#include "Core.hh"
#include "Regex.hh"

int		main(int ac, const char **av)
{
  int arg;
  /*
  Plazza::Regex reg(EMAIL);

  reg.get_information(av[1]);
  for (int i = 0; i < reg.getRegex().size(); i++)
    std::cout << reg.getRegex()[i] << std::endl;

  */
  if (ac < 2)
    return (true);
  if ((arg = atoi(av[1])) < 1)
    return false;
  Plazza::Core	Core(arg);
  try
    {
      Core.run();
    }
  catch(exception::PlazzaError &e)
    {
      std::cerr << "Exception " << e.GetComponent() << " : " << e.what() << std::endl;
    }
  return (false);
}
