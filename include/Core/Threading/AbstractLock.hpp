#include <Core/Object>
#include <Core/Threading/IMonitor.hpp>

#ifndef _ABSTRACTLOCK_HPP
#define _ABSTRACTLOCK_HPP
namespace Sakura {
    namespace Core {
        namespace Threading {

            class AbstractLock : public Object {
            protected:
                IMonitor* target;
            public:
                AbstractLock(const IMonitor* m); 

                ~AbstractLock();
            };

        }
    }
}

#endif

