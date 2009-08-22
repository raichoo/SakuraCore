#ifndef _TYPEMONITOR_TCC
#define _TYPEMONITOR_TCC

#include <Core/Threading/Spinlock.hpp>

#ifdef DEBUG
#include <iostream>
#endif

namespace Sakura {
    namespace Core {
        namespace Threading {

            template <typename T>
            TypeMonitor<T>::TypeMonitor(const typename T::value_type& val) : T(val) {}

            template <typename T>
            typename T::value_type TypeMonitor<T>::getValue() const {
#ifdef DEBUG
                std::cout << "LK: TypeMonitor LOCK" << std::endl;
#endif
                Spinlock l(this);
#ifdef DEBUG
                std::cout << "LK: TypeMonitor UNLOCK" << std::endl;
#endif
                return T::getValue();
            }

            template <typename T>
            T& TypeMonitor<T>::operator=(const typename T::value_type& rhs) {
#ifdef DEBUG
                std::cout << "LK: TypeMonitor LOCK" << std::endl;
#endif
                Spinlock l(this);
#ifdef DEBUG
                std::cout << "LK: TypeMonitor UNLOCK" << std::endl;
#endif
                return T::operator=(rhs);
            }

            template <typename T>
            T& TypeMonitor<T>::operator=(const T& rhs) {
#ifdef DEBUG
                std::cout << "LK: TypeMonitor LOCK" << std::endl;
#endif
                Spinlock l(this);
#ifdef DEBUG
                std::cout << "LK: TypeMonitor LOCK" << std::endl;
#endif
                return T::operator=(rhs);
            }

        }
    }
}

#endif

