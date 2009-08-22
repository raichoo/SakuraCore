#include <Core/Reference>
#include <Core/Types/String>
#include <Core/Object>
#include <Core/Threading/IMonitor.hpp>

#ifndef _OBJECTMONITOR_HPP
#define _OBJECTMONITOR_HPP

namespace Sakura {
    namespace Core {
        namespace Threading {

            template <typename T>
            class ObjectMonitor : public T, private IMonitor {
            public:
                Reference<Object> sendMessage(Reference<Message> msg);
                void attachFunctor(Reference<AbstractFunctor> func);
                void attachFunctor(Reference<AbstractFunctor> func, Reference<Types::String> name);
                void detachFunctor(Reference<Types::String> name);
            };

        }
    }
}

#include <Core/Threading/ObjectMonitor.tcc>

#endif

