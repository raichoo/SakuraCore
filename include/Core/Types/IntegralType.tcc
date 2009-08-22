#ifndef _INTEGRALTYPE_TCC
#define	_INTEGRALTYPE_TCC

#include <Core/RTTI.hpp>

namespace Sakura {
    namespace Core {
        namespace Types {

            template <typename T>
            IntegralType<T>::IntegralType(const T& value_) : value(value_) {}

            template <typename T>
            IntegralType<T>::IntegralType(const IntegralType<T>& rhs) : value(rhs.value) {}

            template <typename T>
            IntegralType<T>::IntegralType() : value(T()) {}

            template <typename T>
            IntegralType<T>::~IntegralType() {}

            template <typename T>
            IntegralType<T>& IntegralType<T>::operator=(const T& rhs) {
                this->value = rhs;
                return *this;
            }

            template <typename T>
            IntegralType<T>& IntegralType<T>::operator=(const IntegralType<T>& rhs) {
                this->value = rhs.value;
                return *this;
            }

            template <typename T>
            T IntegralType<T>::getValue() const {
                return this->value;
            }

        }
    }
}
#endif	/* _INTEGRALTYPE_TCC */

