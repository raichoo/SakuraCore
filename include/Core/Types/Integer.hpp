#include <Core/Types/IntegralType>
#include <Core/Threading/MonitorTrait>
#include <Core/Threading/TypeMonitor>

#ifndef _INTEGER_HPP
#define _INTEGER_HPP

namespace Sakura {
    namespace Core {

        namespace Types {

            typedef IntegralType<int> Integer;

        }

        namespace Threading {

            template <>
            class MonitorTrait<Sakura::Core::Types::Integer> {
            public:
                typedef TypeMonitor<Sakura::Core::Types::Integer> value_type;
            };

        }

    }
}

#endif

