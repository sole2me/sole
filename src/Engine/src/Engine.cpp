#include "Engine.h"
#include "Actuator.h"

namespace sole{
    void Engine::exec(sole::Data & d,sole::Data & v)
    {
        shared_ptr<Actuator> actPtr = std::make_shared<Actuator>();
        m_tp.exec(std::bind(&Actuator::doContext, actPtr.get(), std::placeholders::_1, std::placeholders::_2)
            ,ref(d), ref(v));
        
    }

    void Engine::init(size_t num)
    {
        m_tp.init(num);
    }

    void Engine::start()
    {
        m_tp.start();
    }

    void Engine::waitForAllDone()
    {
        m_tp.waitForAllDone();
    }
}