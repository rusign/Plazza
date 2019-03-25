#include <sstream>
#include "../../include/ManangeOrder.hh"
#include <csignal>

static bool s_signal = false;

ManangeOrder::ManangeOrder(int nbThread) {
    _nbThread = nbThread;
    _id = 0;
    _myPid = getpid();
}

ManangeOrder::~ManangeOrder() {
}

void 		*theardFunctionOrder(void *param) {
    CCatchLine *catchLine;

    catchLine = (reinterpret_cast<CCatchLine *>(param));
    catchLine->run();
    return (nullptr);
}

void signal_handler(int signal)
{
    s_signal = true;
}

void ManangeOrder::run() {
  int finish = 0;
  int end = 0;
    int nbpross = 0;
    bool eof = false;
    char tmp[4096];
    std::signal(SIGINT,signal_handler);
    std::string line;
    CCatchLine *catchLine;
    catchLine = new CCatchLine();
    catchLine->setThread(new std::thread(theardFunctionOrder, catchLine));
    std::vector<std::string> vecString;
    while (true) {

        line = catchLine->getString();
        catchLine->clear();
        eof = catchLine->getEOF();
        if (s_signal)
            break;
        Plazza::Parsing parse(line);
        line.clear();
	      for (int i = 0; i < parse.getCommander().size(); i++) {
            _cmdVec.push_back(parse.getCommander()[i]);
        }
        for (int i = 0; i < _readVecState.size(); i++) {
            if (selectRead(_readVecState[i]->getFd()))
                vecString.push_back(_readVecState[i]->readPipe());
        }
        for (int i = 0; i < vecString.size(); i++) {
            if (vecString[i] == "QUIT") {
                _readVecState.erase(_readVecState.begin() + i);
                _writeVec.erase(_writeVec.begin() + i);
            }
        }
           if (eof && _writeVec.size() < 1 && _cmdVec.size() < 1){
            break;
	    }
            if (_cmdVec.size() > 0) {
                bool createNewPross = false;
                for (int i = 0; i < _readVecState.size(); i++) {
                    if (selectWrite(_writeVec[i]->getFd())) {
                        if (true) {
                            _writeVec[i]->writeStr(commanderToString(_cmdVec[0]));
                            _cmdVec.erase(_cmdVec.begin() + 0);
                            createNewPross = true;
                            break;
                        }
                    }
                }
                if (!createNewPross && nbpross == 0) {
                    if (eof)
                        nbpross++;
                    createProcess();
                }
            }
        vecString.clear();
    }
}

bool ManangeOrder::selectRead(int fd) {
    fd_set          fdset;
    struct timeval  tv;

    tv.tv_sec = 1;
    tv.tv_usec = 0;
    FD_ZERO(&fdset);
    FD_SET(fd, &fdset);
    if (select(fd + 1, &fdset, NULL, NULL, &tv) <= 0 ) {
        return false;
    }
    if (FD_ISSET (fd, &fdset)) {
        return true;
    }
    return false;
}

bool ManangeOrder::selectWrite(int fd) {
    fd_set          fdset;
    struct timeval  tv;

    tv.tv_sec = 1;
    tv.tv_usec = 0;
    FD_ZERO(&fdset);
    FD_SET(fd, &fdset);
    if (select(fd + 1, NULL, &fdset, NULL, &tv) <= 0 ) {
        return false;
    }
    else if (FD_ISSET (fd, &fdset)) {
        return true;
    }
    return false;
}

std::string ManangeOrder::commanderToString(const Plazza::Commander &cmd) {
    std::string res("");
    for (int i = 0; i < cmd.getFile().size(); i++) {
        res += cmd.getFile()[i];
        res += ' ';
    }
    switch (cmd.getInformation()) {
        case 1:
            res += "EMAIL_ADDRESS" ;
            break;
        case 0:
            res += "PHONE_NUMBER" ;
            break;
        case 2:
            res += "IP_ADDRESS" ;
            break;
        case 3:
            res += "NONE" ;
            break;
    }
    return (res);
}

void ManangeOrder::createProcess() {

    std::stringstream ss;
    ss << _id;
    std::string tmp_c(".Process");
    std::string tmp;
    tmp = ss.str();
    tmp_c += tmp;
    Process *process;
    process = new Process(tmp_c,_nbThread);
    if (getpid() ==_myPid) {
        _process.push_back(process);
        NamedPipeOutput *writePipe;
        writePipe = new NamedPipeOutput(tmp_c);
        tmp_c += "State";
        NamedPipeInput *readPipeState;
        readPipeState = new NamedPipeInput(tmp_c);
        writePipe->openPipe();
        while (!readPipeState->openPipe());
        _writeVec.push_back(writePipe);
        _readVecState.push_back(readPipeState);
        _id++;
    }
}

void ManangeOrder::createFork(const std::string &str, int nbThread) {
    Process *process;
    process = new Process(str,nbThread);
}
std::string ManangeOrder::readThePipe(NamedPipeInput *pr) {
    std::string str;
    pr->openPipe();
    str = pr->readPipe();
    pr->closePipe();
    std::cout << "res pipe read" << str << std::endl;
    return ( str);
}

void ManangeOrder::setCmd(const Plazza::Commander &cmd) {
    _cmdVec.push_back(cmd);
}
