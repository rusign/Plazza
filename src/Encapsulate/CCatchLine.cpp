#include "../../include/CCatchLine.hh"
#include <chrono>

CCatchLine::CCatchLine() {
    _eof = false;
}

CCatchLine::~CCatchLine() {
}

void CCatchLine::run() {
    std::string line;
    while (true) {
        if (!std::getline(std::cin, line)) {
            _eof = true;
            break;
        }
        _stringVec.push_back(line);
    }
}

void CCatchLine::clear() {
if (_stringVec.size() > 1)
      {
	std::vector<std::string> tmp;
	for (int i = 1 ; i < _stringVec.size();i++)
	  {
	    tmp.push_back(_stringVec[i]);
	  }
	_stringVec = tmp;
      }
}

std::vector<std::string > CCatchLine::getVec() const{
  return _stringVec;
}

void CCatchLine::setThread(std::thread *thread) {
    _thread = thread;
}

std::string CCatchLine::getString() const {
    if (_stringVec.size() > 0)
        return _stringVec[0];
    else
        return ("");
}

bool CCatchLine::getEOF() const {
    return _eof;
}
