#ifndef _TYPEMONITOR_HPP
#define _TYPEMONITOR_HPP

#include <Core/Threading/IMonitor.hpp>

namespace Sakura {
    namespace Core {
        namespace Threading {

            template <typename T>
            class TypeMonitor : public T, private IMonitor {
            public:
                TypeMonitor(const typename T::value_type& val); 

                typename T::value_type getValue() const; 
                T& operator=(const typename T::value_type& rhs);
                T& operator=(const T& rhs);
            };

        }
    }
}

#include <Core/Threading/TypeMonitor.tcc>

#endif

