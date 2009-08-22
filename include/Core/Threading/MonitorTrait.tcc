#ifndef _MONITORTRAIT_TCC
#define _MONITORTRAIT_TCC

#include <Core/Threading/ObjectMonitor.hpp>

namespace Sakura {
    namespace Core {
        namespace Threading {

            template <typename T>
            class MonitorTrait {
                public:
                typedef ObjectMonitor<T> value_type;
            };

        }
    }
}

#endif

