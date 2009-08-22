#ifndef _IMONITOR_HPP
#define _IMONITOR_HPP

namespace Sakura {
    namespace Core {
        namespace Threading {

            class IMonitor {
                bool locked;
            public:
                IMonitor();

                ~IMonitor();

                bool isLocked() const;
                void lock();
                void unlock();
            };

        }
    }
}

#endif

