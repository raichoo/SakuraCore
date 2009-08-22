#ifndef _SPINLOCK_HPP
#define _SPINLOCK_HPP

#include <Core/Threading/AbstractLock.hpp>
#include <Core/Threading/IMonitor.hpp>

namespace Sakura {
    namespace Core {
        namespace Threading {

            class Spinlock : public AbstractLock {
            public:
                Spinlock(const IMonitor* m);

                ~Spinlock();
            };

        }
    }
}

#endif

