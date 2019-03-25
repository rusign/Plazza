#ifndef THREAD_HH_
# define THREAD_HH_

namespace	Plazza
{
  class		Thread
  {
  public :

    Thread(int, int);
    ~Thread(void) {}

    void	run(void);

  private :

    int		_port;
    int		_maxThreads;

  };
}


#endif
