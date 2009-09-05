#include <Core/Threading/TypeMonitor>
#include <Core/Threading/MonitorTrait>
#include <Core/Types/AbstractType>

#ifndef _INTEGER_HPP
#define _INTEGER_HPP

namespace Sakura {
    namespace Core {
        namespace Types {

            template <typename S_, int B_>
            class IntegerTrait;

            template <>
            class IntegerTrait<signed, 32> {
            public:
                typedef signed int value_type;
                static const bool SIGNED = true;
                static const size_t SIZE = 32;
            };

            template <>
            class IntegerTrait<unsigned, 32> {
            public:
                typedef unsigned int value_type;
                static const bool SIGNED = false;
                static const size_t SIZE = 32;
            };


            template <typename S = signed, int B = 32>
            class Integer : public AbstractType {
                typename IntegerTrait<S, B>::value_type  value;
            public:
                typedef typename IntegerTrait<S, B>::value_type value_type;

                Integer();
                Integer(const typename IntegerTrait<S, B>::value_type& value);
                Integer(const Integer<S, B>& rhs);

                virtual typename IntegerTrait<S ,B>::value_type  getValue() const;

                virtual Integer<S, B>& operator=(const Integer<S, B>& rhs);
                virtual Integer<S, B>& operator=(const typename IntegerTrait<S, B>::value_type& rhs);
                Integer<S, B> operator+(const typename IntegerTrait<S, B>::value_type& rhs);
                Integer<S, B> operator+(const Integer<S, B>& rhs);
                Integer<S, B> operator-(const typename IntegerTrait<S, B>::value_type& rhs);
                Integer<S, B> operator-(const Integer<S, B>& rhs);
                Integer<S, B> operator*(const typename IntegerTrait<S, B>::value_type& rhs);
                Integer<S, B> operator*(const Integer<S, B>& rhs);
                Integer<S, B> operator/(const typename IntegerTrait<S, B>::value_type& rhs);
                Integer<S, B> operator/(const Integer<S, B>& rhs);
                Integer<S, B> operator%(const typename IntegerTrait<S, B>::value_type& rhs);
                Integer<S, B> operator%(const Integer<S, B>& rhs);
            };

            template <typename T>
            class ReverseIntegerTrait;

            template <>
            class ReverseIntegerTrait<signed int> {
            public:
                typedef Integer<signed, 32> value_type;
            };

            template <>
            class ReverseIntegerTrait<unsigned int> {
            public:
                typedef Integer<unsigned, 32> value_type;
            };

            template <typename T>
            typename ReverseIntegerTrait<T>::value_type operator+(const T& lhs, const typename ReverseIntegerTrait<T>::value_type& rhs);
            template <typename T>
            typename ReverseIntegerTrait<T>::value_type operator-(const T& lhs, const typename ReverseIntegerTrait<T>::value_type& rhs);
            template <typename T>
            typename ReverseIntegerTrait<T>::value_type operator*(const T& lhs, const typename ReverseIntegerTrait<T>::value_type& rhs);
            template <typename T>
            typename ReverseIntegerTrait<T>::value_type operator/(const T& lhs, const typename ReverseIntegerTrait<T>::value_type& rhs);
            template <typename T>
            typename ReverseIntegerTrait<T>::value_type operator%(const T& lhs, const typename ReverseIntegerTrait<T>::value_type& rhs);

        }

        namespace Threading {

            template <>
            template <typename S, int B>
            class MonitorTrait< Types::Integer<S, B> > {
            public:
                typedef TypeMonitor< Types::Integer<S, B> > value_type;
            };

        }

    }
}

#include <Core/Types/Integer.tcc>

#endif

