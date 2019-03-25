#ifndef CPP_PLAZZA_NAMEDPIPEOUTPUT_HH
# define CPP_PLAZZA_NAMEDPIPEOUTPUT_HH

# include <string>
# include <fstream>
# include <fcntl.h>
# include <unistd.h>
# include "Commander.hh"
#include "NamedPipeObjet.hh"
class NamedPipeOutput {
    public:
        NamedPipeOutput(const std::string &path);
        virtual ~NamedPipeOutput();

        void openPipe();
        void closePipe();
        bool writeStr (const std::string &str);
        bool writeSate (const std::string &str);
        bool writeOrder(const Plazza::Commander &cmd);
        std::ofstream &getStream();
        int  getFd() const;
        void operator>>(const Plazza::Commander &cmd);
    private:
        int           _fd;
    FILE * pFile;
        std::string   _name;
        std::ofstream _stream;
};

#endif //CPP_PLAZZA_NAMEDPIPEOUTPUT_HH
