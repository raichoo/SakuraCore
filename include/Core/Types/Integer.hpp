#include <Core/Types/AbstractType.hpp>

#ifndef _INTEGER_HPP
#define _INTEGER_HPP

namespace Sakura {
    namespace Core {
        namespace Types {

            template <typename S>
            class Integer;

            template <>
            class Integer<unsigned> : public AbstractType {
                unsigned int value;
            public:
                typedef unsigned int value_type;

                Integer();
                Integer(const unsigned int& value);
                Integer(const Integer<unsigned>& rhs);

                unsigned int getValue() const;

                Integer<unsigned>& operator=(const Integer<unsigned>& rhs);
                Integer<unsigned>& operator=(const unsigned int& rhs);
            };

            template <>
            class Integer<signed> : public AbstractType {
                signed int value;
            public:
                typedef signed int value_type;

                Integer();
                Integer(const signed int& value);
                Integer(const Integer<signed>& rhs);

                signed int getValue() const;

                Integer<signed>& operator=(const Integer<signed>& rhs);
                Integer<signed>& operator=(const signed int& rhs);
            };

        }
    }
}

#include <Core/Types/Integer.tcc>

#endif

