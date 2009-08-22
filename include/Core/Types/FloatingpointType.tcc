#ifndef _FLOATINGPOINTTYPE_TCC
#define _FLOATINGPOINTTYPE_TCC	

#include <Core/RTTI.hpp>

namespace Sakura {
    namespace Core {
        namespace Types {

            template <typename T>
            FloatingpointType<T>::FloatingpointType(const T& value_) : value(value_) {}

            template <typename T>
            FloatingpointType<T>::FloatingpointType(const FloatingpointType<T>& rhs) : value(rhs.value) {}

            template <typename T>
            FloatingpointType<T>::FloatingpointType() : value(T()) {}

            template <typename T>
            FloatingpointType<T>::~FloatingpointType() {}

            template <typename T>
            FloatingpointType<T>& FloatingpointType<T>::operator=(const T& rhs) {
                this->value = rhs;
                return *this;
            }

            template <typename T>
            FloatingpointType<T>& FloatingpointType<T>::operator=(const FloatingpointType<T>& rhs) {
                this->value = rhs.rhs;
                return *this;
            }

            template <typename T>
            T FloatingpointType<T>::getValue() const {
                return this->value;
            }
            
        }
    }
}
#endif	/* _FLOATINGPOINTTYPE_TCC */

