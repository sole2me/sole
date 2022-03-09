#ifndef _Engine_H_
#define _Engine_H_
#include "ComShare.h"
#include "util/tc_thread_pool.h"

namespace sole{
    class Engine
    {
    public:

        virtual ~Engine() {}
        void exec(sole::Data & d,sole::Data & v);
        void init(size_t num);
        void start();
        void waitForAllDone();
    private:
        tars::TC_ThreadPool m_tp;

    };
}
#endif