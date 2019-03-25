#ifndef CPP_PLAZZA_NAMEDPIPEOBJET_HH
#define CPP_PLAZZA_NAMEDPIPEOBJET_HH

#include "Commander.hh"

class NamedPipeObjet {
    public:
        NamedPipeObjet();
        NamedPipeObjet(const Plazza::Commander &cmd);
        NamedPipeObjet(const std::string &str);
        NamedPipeObjet(const Plazza::Commander &cmd, const std::string &str);
        ~NamedPipeObjet();

        void                setCommander(const Plazza::Commander &cmd);
        void                setString(const std::string &str);
        std::string         getString() const;
        Plazza::Commander   getCommander() const;
    private:
        bool                      _isStr;
        bool                      _isCommander;
        Plazza::Commander         _cmd;
        std::string               _str;
};


#endif //CPP_PLAZZA_NAMEDPIPEOBJET_HH
