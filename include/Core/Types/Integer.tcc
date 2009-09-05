#ifndef _INTEGER_TCC
#define _INTEGER_TCC

namespace Sakura {
    namespace Core {
        namespace Types {

            template <typename S, int B>
            Integer<S, B>::Integer() : value(0) {}

            template <typename S, int B>
            Integer<S, B>::Integer(const typename IntegerTrait<S, B>::value_type& value_) : value(value_) {}

            template <typename S, int B>
            Integer<S, B>::Integer(const Integer& rhs) : value(rhs.getValue()) {}

            template <typename S, int B>
            Integer<S, B>& Integer<S, B>::operator=(const typename IntegerTrait<S, B>::value_type& rhs) {
                this->value = rhs;
                return *this;
            }

            template <typename S, int B>
            Integer<S, B>& Integer<S, B>::operator=(const Integer<S, B>& rhs) {
                this->value = rhs.getValue();
                return *this;
            }

            template <typename S, int B>
            typename IntegerTrait<S, B>::value_type Integer<S, B>::getValue() const {
                return this->value;
            }

            template <typename S, int B>
            Integer<S, B> Integer<S, B>::operator+(const typename IntegerTrait<S, B>::value_type& rhs) {
                return this->value + rhs;
            }

            template <typename S, int B>
            Integer<S, B> Integer<S, B>::operator+(const Integer<S, B>& rhs) {
                return this->value + rhs.getValue();
            }

            template <typename S, int B>
            Integer<S, B> Integer<S, B>::operator-(const typename IntegerTrait<S, B>::value_type& rhs) {
                return this->value - rhs;
            }

            template <typename S, int B>
            Integer<S, B> Integer<S, B>::operator-(const Integer<S, B>& rhs) {
                return this->value - rhs.getValue();
            }

            template <typename S, int B>
            Integer<S, B> Integer<S, B>::operator*(const typename IntegerTrait<S, B>::value_type& rhs) {
                return this->value * rhs;
            }

            template <typename S, int B>
            Integer<S, B> Integer<S, B>::operator*(const Integer<S, B>& rhs) {
                return this->value * rhs.getValue();
            }

            template <typename S, int B>
            Integer<S, B> Integer<S, B>::operator/(const typename IntegerTrait<S, B>::value_type& rhs) {
                return this->value / rhs;
            }

            template <typename S, int B>
            Integer<S, B> Integer<S, B>::operator/(const Integer<S, B>& rhs) {
                return this->value / rhs.getValue();
            }

            template <typename S, int B>
            Integer<S, B> Integer<S, B>::operator%(const typename IntegerTrait<S, B>::value_type& rhs) {
                return this->value % rhs;
            }

            template <typename S, int B>
            Integer<S, B> Integer<S, B>::operator%(const Integer<S, B>& rhs) {
                return this->value % rhs.getValue();
            }

            template <typename T>
            typename ReverseIntegerTrait<T>::value_type operator+(const T& lhs, const typename ReverseIntegerTrait<T>::value_type& rhs) {
                return lhs + rhs.getValue();
            }
            
            template <typename T>
            typename ReverseIntegerTrait<T>::value_type operator-(const T& lhs, const typename ReverseIntegerTrait<T>::value_type& rhs) {
                return lhs - rhs.getValue();
            }
            
            template <typename T>
            typename ReverseIntegerTrait<T>::value_type operator*(const T& lhs, const typename ReverseIntegerTrait<T>::value_type& rhs) {
                return lhs * rhs.getValue();
            }
            
            template <typename T>
            typename ReverseIntegerTrait<T>::value_type operator/(const T& lhs, const typename ReverseIntegerTrait<T>::value_type& rhs) {
                return lhs / rhs.getValue();
            }

            template <typename T>
            typename ReverseIntegerTrait<T>::value_type operator%(const T& lhs, const typename ReverseIntegerTrait<T>::value_type& rhs) {
                return lhs % rhs.getValue();
            }

        }
    }
}

#endif

