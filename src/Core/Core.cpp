#include "Core.hh"

void	Plazza::Core::printTMP(Plazza::Parsing *parse)
{
  for (int i = 0; i < parse->getCommander().size(); ++i)
      	{
      	  for (int j = 0; j < parse->getCommander()[i].getFile().size(); ++j)
      	    {
	      switch (parse->getCommander()[i].getInformation())
		{
		case 1:
		  std::cout << "The file is : " << parse->getCommander()[i].getFile()[j] << " we have to find EMAIL_ADDRESS" << std::endl;
		  break;
		case 0:
		  std::cout << "The file is : " << parse->getCommander()[i].getFile()[j] << " we have to find PHONE_NUMBER" << std::endl;
		  break;
		case 2:
		  std::cout << "The file is : " << parse->getCommander()[i].getFile()[j] << " we have to find IP_ADDRESS" << std::endl;
		  break;
		case 3:
		  std::cout << "The file is : " << parse->getCommander()[i].getFile()[j] << " we have to find NONE" << std::endl;
		  break;
		}
	    }
      	}
}

Plazza::Core::Core(int threads)
{
  this->_nbThreads = threads;
}

void		Plazza::Core::run(void)
{
  std::string	line;
  bool		free(false);

 Plazza::Parsing *parse;
  // while (std::getline(std::cin, line)) {
  // 	  parse = new Plazza::Parsing(line);
  // 	  printTMP(parse);
  // 	  line.clear();
  // }
  ManangeOrder		manageOrder(_nbThreads);
  manageOrder.run();

}
