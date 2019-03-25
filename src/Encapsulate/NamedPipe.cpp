#include "../../include/NamedPipe.hh"

NamedPipe::NamedPipe(const Plazza::Parsing &pars) : _name(pars){

}

NamedPipe::~NamedPipe() {

}

void NamedPipe::open() {
    struct stat sb;

    if ((stat(_pars. .c_str(), &sb) < 0) && (mkfifo(_name.c_str(), 0644) < 0))
        exit(-1);
    _stream.open(_name.c_str());
    if (_stream.fail())
        exit(-1);
}

void NamedPipe::close() {
    struct stat sb;

    _stream.close();
    if (_stream.fail() || (!stat(_name.c_str(), &sb)))
        exit(-1);
}

std::string NamedPipe::read() {
    std::string read;
    std::stringstream ss;

    ss << _stream.rdbuf();
    read = ss.str();
    return (read);
}

std::ifstream &NamedPipe::getStream() {
    return (_stream);
}

