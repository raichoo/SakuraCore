#ifndef _TYPEMONITOR_TCC
#define _TYPEMONITOR_TCC

#include <Core/Threading/Spinlock.hpp>
#include <Core/Reference.hpp>
#include <Core/Object.hpp>
#include <Core/Message.hpp>
#include <Core/Types/String.hpp>
#include <Core/AbstractFunctor.hpp>

namespace Sakura {
    namespace Core {
        namespace Threading {

            template <typename T>
            Reference<Object> ObjectMonitor<T>::sendMessage(Reference<Message> msg) {
                Spinlock l(this);
                return T::sendMessage(msg);
            }

            template <typename T>
            void ObjectMonitor<T>::attachFunctor(Reference<AbstractFunctor> func) {
                Spinlock l(this);
                T::attachFunctor(func);
            }

            template <typename T>
            void ObjectMonitor<T>::attachFunctor(Reference<AbstractFunctor> func, Reference<Types::String> name) {
                Spinlock l(this);
                T::attachFunctor(func, name);
            }

            template <typename T>
            void ObjectMonitor<T>::detachFunctor(Reference<Types::String> name) {
                Spinlock l(this);
                T::detachFunctor(name);
            }

        }
    }
}

#endif

