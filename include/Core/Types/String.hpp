#include <Core/Types/CompositeLexicalType>
#include <Core/Threading/MonitorTrait>
#include <Core/Threading/TypeMonitor>

#include <string>

#ifndef _STRING_HPP
#define _STRING_HPP

namespace Sakura {
    namespace Core {

        namespace Types {

            typedef CompositeLexicalType<const char*> String;

        }

        namespace Threading {

            template <>
            class MonitorTrait<Sakura::Core::Types::String> {
            public:
                typedef TypeMonitor<Sakura::Core::Types::String> value_type;
            };

        }

    }
}

#endif
