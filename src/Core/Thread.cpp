#include "Thread.hh"

Plazza::Thread::Thread(int maxThread, int port)
{
  this->_port = port;
  this->_maxThreads = maxThread;
}

void	Plazza::Thread::run(void)
{
  while (true)
    {

    }
}
