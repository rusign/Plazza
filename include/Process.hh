#ifndef CPP_PLAZZA_PROCESS_HH
#define CPP_PLAZZA_PROCESS_HH

# include <cstring>
# include <cerrno>
# include <cstdlib>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
#include "ManageProcess.hh"
class Process {

    public:
      Process(const std::string &str, int nbThread);
      virtual ~Process();

      void wait();
      bool alive() const;
      pid_t getPid() const;

    private:
      pid_t _pid;
      bool _isAlive;
};

#endif //CPP_PLAZZA_PROCESS_HH
