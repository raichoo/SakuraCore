#ifndef _SYNCHRONIZED_TCC
#define _SYNCHRONIZED_TCC

#include <Core/Threading/MonitorTrait.hpp>

namespace Sakura {
    namespace Core {
        namespace Threading {

            template <typename T>
            class synchronized<T, true> : public MonitorTrait<T>::value_type {
            public:
                synchronized(const typename T::value_type& val) : MonitorTrait<T>::value_type(val) {}
            };

            template <typename T>
            class synchronized<T, false> : public MonitorTrait<T>::value_type {
            public:
                synchronized() {}
            };

        }
    }
}

#endif

