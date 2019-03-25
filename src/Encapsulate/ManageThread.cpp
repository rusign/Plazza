#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Regex.hh"
#include "../../include/ManageThread.hh"

ManageThread::ManageThread() {
    _isRunning = false;
	_thread = nullptr;
	_mutex = new std::mutex();
    _information = Plazza::Commander::Information::NONE;
}

ManageThread::~ManageThread() {
	delete _mutex;
    clearOrder();
}

void 	                	ManageThread::setOrder(const Plazza::Commander &order) {
	_order = order;
    _file = order.getFile();
    _information = order.getInformation();
    _isRunning = true;
}

void 	                	ManageThread::setThread(std::thread *thread) {
	_thread = thread;
}

void 	                 	ManageThread::clearOrder() {
    _file.clear();
    _information = Plazza::Commander::Information::NONE;
    _isRunning = false;
}

Plazza::Commander 		    ManageThread::getOrder() const {
	return (_order);
}

std::thread 		        *ManageThread::getThread() const {
	return (_thread);
}

std::mutex 		            *ManageThread::getMutex() const {
	return (_mutex);
}

bool                        ManageThread::isRunning() const {
    return (_isRunning);
}

void	                   	ManageThread::loop()
{
  while (true)
    {
      if (_file.size() > 0) {
	if (_mutex->try_lock()) {
	  Plazza::Regex *reg;
	  switch (_information) {
	  case 0 :
	    reg = new Plazza::Regex(PHONE);
	    break;
	  case 1 :
	    reg = new Plazza::Regex(EMAIL);
	    break;
	  case 2 :
	    reg = new Plazza::Regex(IP);
	    break;
	  default:
	    break;
	  }
	  reg->get_information(_file[0]);
	  for (int i = 0; i < reg->getRegex().size(); i++) {
	    std::cout << reg->getRegex()[i] << std::endl;
	  }
	  _file.erase(_file.begin());
	  if (_file.size() <= 0) {
	    clearOrder();
	  }
	  _mutex->unlock();
	}
      }
    }
}
