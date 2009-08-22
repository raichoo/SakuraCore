#ifndef _SYNCHRONIZED_HPP
#define _SYNCHRONIZED_HPP

namespace Sakura {
    namespace Core {
        namespace Threading {

            template <typename T, bool has_value = true>
            class synchronized;

        }
    }
}

#include <Core/Threading/synchronized.tcc>

#endif
