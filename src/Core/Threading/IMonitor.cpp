#include <Core/Threading/IMonitor.hpp>

namespace Sakura {
    namespace Core {
        namespace Threading {

            IMonitor::IMonitor() : locked(false) {}

            IMonitor::~IMonitor() {
                this->locked = false;
            }

            bool IMonitor::isLocked() const {
                return this->locked;
            }

            void IMonitor::lock() {
                this->locked = true;
            }

            void IMonitor::unlock() {
                this->locked = false;
            }

        }
    }
}

