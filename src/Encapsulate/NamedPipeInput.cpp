#include <sys/types.h>
#include <sys/stat.h>
#include <sstream>
#include "../../include/NamedPipeInput.hh"

NamedPipeInput::NamedPipeInput(const std::string &str) : _name(str){

}

NamedPipeInput::~NamedPipeInput() {

}

bool NamedPipeInput::openPipe() {
    _fd = open(_name.c_str(), O_RDONLY);
    if (_fd == -1)
        return false;
    return  true;
}

void NamedPipeInput::closePipe() {
    close(_fd);
    std::remove(_name.c_str());
}

std::string NamedPipeInput::readPipe() {
  char tmp[2];
  char tmp2[2];
  std::string final("");
  while (read(_fd, tmp, 1) > 0){
    if (!tmp[0])
      break;
    final += tmp[0];
    tmp[0] = 0;
  }
  return (final);
}

std::string NamedPipeInput::readPipeState() {
    char tmp[6] ;

    std::string final("");
    read(_fd, tmp, 5);
    final += tmp;
    return (final);
}

Plazza::Commander *NamedPipeInput::readOrder() {
    Plazza::Commander	*tmp;
    tmp = new Plazza::Commander;
    read(_fd, tmp, sizeof(Plazza::Commander));
    return (tmp);
}

int NamedPipeInput::getFd() const {
    return (_fd);
}
std::ifstream &NamedPipeInput::getStream() {
    return (_stream);
}

