#ifndef CPP_PLAZZA_NAMEDPIPE_HH
#define CPP_PLAZZA_NAMEDPIPE_HH

#include "Parsing.hh"

class NamedPipe {
    public:
        NamedPipe(const Plazza::Parsing &pars);
        virtual ~NamedPipe();

        void open();
        void close();
        std::string read();
        std::string write();
        Plazza::Parsing &getStream();

    private:
        Plazza::Parsing _pars;
};


#endif //CPP_PLAZZA_NAMEDPIPE_HH
