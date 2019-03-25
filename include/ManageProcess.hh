#ifndef CPP_PLAZZA_MANAGEPROCESS_HH
#define CPP_PLAZZA_MANAGEPROCESS_HH

#include "Parsing.hh"
#include "Commander.hh"
#include "NamedPipe.hh"
#include "NamedPipeInput.hh"
#include "NamedPipeOutput.hh"
#include "ManageThread.hh"
#include <time.h>
#include <thread>
class ManageProcess {
    public:
        ManageProcess(const std::string &, int);
        virtual ~ManageProcess();

        void                setOrdersNumber(int);
        std::string         getName() const;
        int                 getOrdersNumber() const;
        NamedPipeInput     	*getToRead();
        NamedPipeOutput     *getToWrite();
        void                sendState(const std::string &);
        bool                finished();
        void 		         run();

    private:
        int                 checkOrderNumber();
        void                sendOrderToThread();
        void                fillOrderVec();
        void                readAndCheckReceiveOrder();
        std::vector<Plazza::Commander>   stringToCommander(const std::string &str);

        std::vector<Plazza::Commander> _orderVec;
        std::vector<Plazza::Commander> cmdvec;

        ManageThread		*_ThreadTab;
        NamedPipeInput		_readPipe;
        NamedPipeOutput		_writePipe;
        std::string 		_name;
        int 				_nbThread;
        int 				_nbOrder;
        unsigned long       _timer;
        unsigned long       _time;
};


#endif //CPP_PLAZZA_MANAGEPROCESS_HH
