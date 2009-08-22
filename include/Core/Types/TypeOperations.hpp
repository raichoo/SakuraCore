#ifndef _TYPEOPERATIONS_HPP
#define _TYPEOPERATIONS_HPP

namespace Sakura {
    namespace Core {
        namespace Types {

            template <typename T, template <typename> class U>
            U<T> operator+(const U<T>&, const U<T>& rhs);

            template <typename T, template <typename> class U>
            U<T> operator+(const U<T>&, const T& rhs);

            template <typename T, template <typename> class U>
            U<T> operator+(const T&, const U<T>& rhs);

            template <typename T, template <typename> class U>
            U<T> operator-(const U<T>&, const U<T>& rhs);

            template <typename T, template <typename> class U>
            U<T> operator-(const U<T>&, const T& rhs);

            template <typename T, template <typename> class U>
            U<T> operator-(const T&, const U<T>& rhs);

            template <typename T, template <typename> class U>
            U<T> operator*(const U<T>&, const U<T>& rhs);

            template <typename T, template <typename> class U>
            U<T> operator*(const U<T>&, const T& rhs);

            template <typename T, template <typename> class U>
            U<T> operator*(const T&, const U<T>& rhs);

            template <typename T, template <typename> class U>
            U<T> operator/(const U<T>&, const U<T>& rhs);

            template <typename T, template <typename> class U>
            U<T> operator/(const U<T>&, const T& rhs);

            template <typename T, template <typename> class U>
            U<T> operator/(const T&, const U<T>& rhs);

            template <typename T, template <typename> class U>
            U<T> operator%(const U<T>&, const U<T>& rhs);

            template <typename T, template <typename> class U>
            U<T> operator%(const U<T>&, const T& rhs);

            template <typename T, template <typename> class U>
            U<T> operator%(const T&, const U<T>& rhs);

            template <typename T, template <typename> class U>
            U<T> operator==(const U<T>&, const U<T>& rhs);

            template <typename T, template <typename> class U>
            U<T> operator==(const U<T>&, const T& rhs);

            template <typename T, template <typename> class U>
            U<T> operator==(const T&, const U<T>& rhs);

        }
    }
}

#include <Core/Types/TypeOperations.tcc>

#endif
