#include <sys/types.h>
#include <sys/stat.h>
#include "../../include/NamedPipeOutput.hh"

NamedPipeOutput::NamedPipeOutput(const std::string &str) : _name(str){

}

NamedPipeOutput::~NamedPipeOutput() {

}

void NamedPipeOutput::openPipe() {
    mkfifo(_name.c_str(), 0644);
    _fd = open(_name.c_str(), O_WRONLY);
}

void NamedPipeOutput::closePipe() {
    close(_fd);
    std::remove(_name.c_str());
}

bool NamedPipeOutput::writeStr(const std::string &str)
{
if (_fd != -1) {
    write(_fd, str.c_str(), str.size() + 1);
}
    else
        write(_fd, "0\0", 2);
    return (true);
}

bool NamedPipeOutput::writeSate(const std::string &str) {
    if (_fd != -1) {
        write(_fd, str.c_str(), 5);
        return (true);
    }
    return false;

}
bool NamedPipeOutput::writeOrder(const Plazza::Commander &cmd) {
    write(_fd, &cmd, sizeof(cmd));
    return (true);
}

int NamedPipeOutput::getFd() const {
    return (_fd);
}
std::ofstream &NamedPipeOutput::getStream() {
    return (_stream);
}

void		NamedPipeOutput::operator>>(const Plazza::Commander &cmd)
{
    writeOrder(cmd);
}

