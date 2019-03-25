#include "../../include/NamedPipeObjet.hh"

NamedPipeObjet::NamedPipeObjet() : _isCommander(false), _isStr(false), _str("")
{

}

NamedPipeObjet::NamedPipeObjet(const Plazza::Commander &cmd) {
    _cmd = cmd;
    _isCommander = true;
    _isStr = false;
}

NamedPipeObjet::NamedPipeObjet(const std::string &str)  {
    _str = str;
    _isCommander = false;
    _isStr = true;
}

NamedPipeObjet::NamedPipeObjet(const Plazza::Commander &cmd, const std::string &str) {
    _cmd = cmd;
    _str = str;
    _isCommander = true;
    _isStr = true;
}
NamedPipeObjet::~NamedPipeObjet(void)
{

}

Plazza::Commander NamedPipeObjet::getCommander() const{
    return (_cmd);
}

std::string NamedPipeObjet::getString() const{
    return (_str);
}

void NamedPipeObjet::setCommander(const Plazza::Commander &cmd) {
    _cmd = cmd;
    _isCommander = true;
}

void NamedPipeObjet::setString(const std::string &str) {
    _str = str;
}
