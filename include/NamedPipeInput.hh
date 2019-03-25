#ifndef CPP_PLAZZA_NAMEDPIPEINPUT_HH
# define CPP_PLAZZA_NAMEDPIPEINPUT_HH

# include <string>
# include <fstream>
# include "Commander.hh"
# include <stdio.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <fcntl.h>
#include  <sys/stat.h>
#include "NamedPipeObjet.hh"
class NamedPipeInput {
    public:
        NamedPipeInput(const std::string &path);
        virtual ~NamedPipeInput();

        bool openPipe();
        void closePipe();
        std::string readPipe();
        std::string readPipeState();
        Plazza::Commander *readOrder();
        std::ifstream &getStream();
        int getFd() const;

    private:
        int           _fd;
        std::string   _name;
        std::ifstream _stream;
};

#endif //CPP_PLAZZA_NAMEDPIPEINPUT_HH
