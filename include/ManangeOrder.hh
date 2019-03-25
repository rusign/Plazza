#ifndef CPP_PLAZZA_MANANGEORDER_HH
#define CPP_PLAZZA_MANANGEORDER_HH

#include <vector>
#include "Parsing.hh"
#include "Commander.hh"
#include "NamedPipe.hh"
#include "NamedPipeOutput.hh"
#include "NamedPipeInput.hh"
#include "ManageThread.hh"
#include "Process.hh"
#include "CCatchLine.hh"

class ManangeOrder {
    public:
        ManangeOrder(int nbThread);
        virtual ~ManangeOrder();

        void                run();
        bool                selectRead(int fd);
        bool                selectWrite(int fd);
        void                createProcess();
        void                setCmd(const Plazza::Commander &cmd);

private:
        std::string                 commanderToString(const Plazza::Commander &cmd);
        std::string                readThePipe(NamedPipeInput *pr);
        void                       createFork(const std::string &str, int nbThread);

        int                             _nbThread;
        std::vector<Plazza::Commander>  _cmdVec;
        int                             _id;
    pid_t                               _myPid;
        std::vector<Process *>            _process;
        std::vector<NamedPipeInput *>     _readVec;
        std::vector<NamedPipeOutput *>    _writeVec;
        std::vector<NamedPipeInput *>     _readVecState;
        std::vector<NamedPipeOutput *>    _writeVecState;
};


#endif //CPP_PLAZZA_MANANGEORDER_HH
