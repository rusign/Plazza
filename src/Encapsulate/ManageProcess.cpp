#include "../../include/ManageProcess.hh"

void 		*theardFunction(void *param) {
    ManageThread *manageThread;

    manageThread = (reinterpret_cast<ManageThread *>(param));
    manageThread->loop();
    return (nullptr);
}

ManageProcess::ManageProcess(const std::string &name, int nbThread) : _readPipe(name), _writePipe(name + "State") {
    ManageThread *manageThread;
    int 		i = 0;

    _name = name;
    _nbThread = nbThread;
    _nbOrder = 0;
    _timer = 5;
    _time = clock();
    _ThreadTab = new ManageThread[nbThread];
    while (i != nbThread)
    {
       manageThread= &(_ThreadTab[i]);
        _ThreadTab[i].setThread(new std::thread(theardFunction, &(_ThreadTab[i])));
        ++i;
    }
}

ManageProcess::~ManageProcess() {
}

bool            ManageProcess::finished() {
    unsigned long check = 0;

    if (_orderVec.size() > 0){
        _time = clock();
        return (false);
    }

    for (int i = 0; i < _nbThread; i++) {
        if (_ThreadTab[i].isRunning()) {
            _time = clock();
            return (false);
        }
    }
    if (check = ((clock() - _time) / CLOCKS_PER_SEC) > _timer)
        return (true);
    return (false);
}

void            ManageProcess::run()
{
    fd_set          fdset;
    struct timeval  tv;

    tv.tv_sec = 1;
    tv.tv_usec = 0;
    while (!_readPipe.openPipe());
    _writePipe.openPipe();
    FD_ZERO(&fdset);
    FD_SET(_readPipe.getFd(), &fdset);
    while (!finished()){
        readAndCheckReceiveOrder();
        if ((select(_readPipe.getFd() + 1, &fdset, NULL, NULL, &tv) > 0 ) &&  (FD_ISSET (_readPipe.getFd(), &fdset))) {
            cmdvec = stringToCommander(_readPipe.readPipe());
        }
        fillOrderVec();
        sendOrderToThread();
    }
    _writePipe.writeStr("QUIT");
    _readPipe.closePipe();
    _writePipe.closePipe();
    exit(0);
}

void ManageProcess::readAndCheckReceiveOrder() {
    fd_set          fdsetw;
    struct timeval  tv;

    tv.tv_sec = 1;
    tv.tv_usec = 0;
    FD_ZERO(&fdsetw);
    FD_SET(_writePipe.getFd(), &fdsetw);
    if ((select(_writePipe.getFd() + 1, NULL, &fdsetw, NULL, &tv) > 0 )  && (FD_ISSET (_writePipe.getFd(), &fdsetw))) {
        if (_orderVec.size() < _nbThread) {
            _writePipe.writeStr("FREE");
        }
        else {
            _writePipe.writeStr("BUZY");
        }
    }
}

void ManageProcess::fillOrderVec() {
    if (cmdvec.size() > 0) {
        _nbOrder++;
        _orderVec.push_back(cmdvec[0]);
        cmdvec.clear();
    }
}

void ManageProcess::sendOrderToThread() {
    if (_orderVec.size() > 0) {
        for (int i = 0; i < _nbThread; i++) {
            if (!_ThreadTab[i].isRunning()) {
                _ThreadTab[i].setOrder(_orderVec[0]);
                _orderVec.erase(_orderVec.begin() + 0);
                break;
            }
        }
    }
}

std::vector<Plazza::Commander> ManageProcess::stringToCommander(const std::string &str) {
    Plazza::Parsing *parse;
    parse = new Plazza::Parsing(str);
    return parse->getCommander();
}

int             ManageProcess::checkOrderNumber() {
    int res = 0;

    for (int i = 0; i < _nbThread; i++) {
        if (!_ThreadTab[i].isRunning())
            res++;
    }
    if (res == 0 && _orderVec.size() < _nbThread)
        return 1;
    return (res);
}

void            ManageProcess::setOrdersNumber(int nbOrder) {
    _nbOrder = nbOrder;
}

std::string     ManageProcess::getName() const {
    return (_name);
}

int             ManageProcess::getOrdersNumber() const {
    return (_nbOrder);
}

void ManageProcess::sendState(const std::string &str) {
    _writePipe.writeStr(str);
}

NamedPipeInput	    *ManageProcess::getToRead() {
    return (&_readPipe);
}

NamedPipeOutput	    *ManageProcess::getToWrite() {
    return (&_writePipe);
}
