#include <Core/Threading/Spinlock.hpp>

#ifdef DEBUG
#include <iostream>
#endif

namespace Sakura {
    namespace Core {
        namespace Threading {

            Spinlock::Spinlock(const IMonitor* m) : AbstractLock(m) {
                this->target = const_cast<IMonitor*>(m);
                while(target->isLocked());
#ifdef DEBUG
                std::cout << "Locking" << std::endl;
#endif
                target->lock();
            }

            Spinlock::~Spinlock() {
#ifdef DEBUG
                std::cout << "Unlocking" << std::endl;
#endif
                target->unlock();
            }

        }
    }
}
