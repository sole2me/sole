#ifndef _Schedule_H_
#define _Schedule_H_
#include "ComShare.h"

namespace sole
{
    class Schedule
    {
        public:
            virtual ~Schedule() {}
            void doEvent(sole::Event & e,sole::Data & v);
            static void doTest();
    };
}
#endif