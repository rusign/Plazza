#ifndef CPP_PLAZZA_MANAGETHREAD_HH
#define CPP_PLAZZA_MANAGETHREAD_HH

#include <thread>
#include <mutex>
#include "Parsing.hh"
#include "Commander.hh"
#include "NamedPipe.hh"

class ManageThread {
    public:
        ManageThread();
        virtual ~ManageThread();

        void 		            setOrder(const Plazza::Commander &order);
    void 		            setThread(std::thread *thread);
        Plazza::Commander	    getOrder() const;
        std::thread 	        *getThread() const;
        std::mutex   	        *getMutex() const;
        bool                    isRunning() const;
        void 		            loop();

    private:
        void 		                   clearOrder();

    std::thread                     *_thread;
        std::mutex 	                    *_mutex;
        Plazza::Commander	            _order;
        bool                            _isRunning;
        Plazza::Commander::Information	_information;
        std::vector<std::string>		_file;
};

#endif //CPP_PLAZZA_MANAGETHREAD_HH
