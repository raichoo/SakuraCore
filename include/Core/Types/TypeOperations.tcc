#ifndef _TYPEOPERATIONS_TCC
#define _TYPEOPERATIONS_TCC

namespace Sakura {
    namespace Core {
        namespace Types {

            template <typename T, template <typename> class U>
            U<T> operator+(const U<T>& lhs, const U<T>& rhs) {
                return U<T>(lhs.getValue() + rhs.getValue());
            }   

            template <typename T, template <typename> class U>
            U<T> operator+(const U<T>& lhs, const T& rhs) {
                return U<T>(lhs.getValue() + rhs);
            }   

            template <typename T, template <typename> class U>
            U<T> operator+(const T& lhs, const U<T>& rhs) {
                return U<T>(lhs + rhs.getValue());
            } 


            template <typename T, template <typename> class U>
            U<T> operator-(const U<T>& lhs, const U<T>& rhs) {
                return U<T>(lhs.getValue() - rhs.getValue());
            }   

            template <typename T, template <typename> class U>
            U<T> operator-(const U<T>& lhs, const T& rhs) {
                return U<T>(lhs.getValue() - rhs);
            }   

            template <typename T, template <typename> class U>
            U<T> operator-(const T& lhs, const U<T>& rhs) {
                return U<T>(lhs - rhs.getValue());
            } 


            template <typename T, template <typename> class U>
            U<T> operator*(const U<T>& lhs, const U<T>& rhs) {
                return U<T>(lhs.getValue() * rhs.getValue());
            }   

            template <typename T, template <typename> class U>
            U<T> operator*(const U<T>& lhs, const T& rhs) {
                return U<T>(lhs.getValue() * rhs);
            }   

            template <typename T, template <typename> class U>
            U<T> operator*(const T& lhs, const U<T>& rhs) {
                return U<T>(lhs * rhs.getValue());
            } 


            template <typename T, template <typename> class U>
            U<T> operator/(const U<T>& lhs, const U<T>& rhs) {
                return U<T>(lhs.getValue() / rhs.getValue());
            }   

            template <typename T, template <typename> class U>
            U<T> operator/(const U<T>& lhs, const T& rhs) {
                return U<T>(lhs.getValue() / rhs);
            }   

            template <typename T, template <typename> class U>
            U<T> operator/(const T& lhs, const U<T>& rhs) {
                return U<T>(lhs / rhs.getValue());
            } 

            template <typename T, template <typename> class U>
            U<T> operator%(const U<T>& lhs, const U<T>& rhs) {
                return U<T>(lhs.getValue() % rhs.getValue());
            }   

            template <typename T, template <typename> class U>
            U<T> operator%(const U<T>& lhs, const T& rhs) {
                return U<T>(lhs.getValue() % rhs);
            }   

            template <typename T, template <typename> class U>
            U<T> operator%(const T& lhs, const U<T>& rhs) {
                return U<T>(lhs % rhs.getValue());
            } 

            template <typename T, template <typename> class U>
            U<T> operator==(const U<T>& lhs, const U<T>& rhs) {
                return U<T>(lhs.getValue() == rhs.getValue());
            }   

            template <typename T, template <typename> class U>
            U<T> operator==(const U<T>& lhs, const T& rhs) {
                return U<T>(lhs.getValue() == rhs);
            }   

            template <typename T, template <typename> class U>
            U<T> operator==(const T& lhs, const U<T>& rhs) {
                return U<T>(lhs == rhs.getValue());
            } 

        }
    }
}

#endif
