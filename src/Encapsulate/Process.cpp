#include "../../include/Process.hh"
#include "Exceptions.hh"

Process::Process(const std::string &str, int nbThread) {
  _isAlive = true;
  _pid = fork();
  if (_pid == -1) {
    // throw exception::CoreError("Core Error");
      exit(-1);
  }
  else if (_pid ==  0) {
        ManageProcess *manageProcess = new ManageProcess(str, nbThread);
      manageProcess->run();
      _isAlive = false;
  }
    _isAlive = true;

}

Process::~Process() {

}

void Process::wait() {

}
pid_t Process::getPid() const {
    return _pid;
}
bool Process::alive() const {
    return (_isAlive);
}
