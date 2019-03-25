//
// Created by rusign on 4/23/16.
//

#ifndef CPP_PLAZZA_CCATCHLINE_HH
#define CPP_PLAZZA_CCATCHLINE_HH

#include <string>
#include <iostream>
#include <thread>
#include <vector>
class CCatchLine {
    public:
        CCatchLine();
        ~CCatchLine();

        std::string getString() const;
    void 		            setThread(std::thread *thread);
    void                    clear();
  std::vector<std::string > getVec() const;
  bool        getEOF() const;
        void        run();
    private:
        std::thread                     *_thread;
       
        std::vector<std::string> _stringVec;
        bool        _eof;
};


#endif //CPP_PLAZZA_CCATCHLINE_HH
