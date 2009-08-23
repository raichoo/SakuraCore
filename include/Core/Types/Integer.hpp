#include <Core/Threading/TypeMonitor>
#include <Core/Threading/MonitorTrait>
#include <Core/Types/AbstractType>

#ifndef _INTEGER_HPP
#define _INTEGER_HPP

namespace Sakura {
    namespace Core {
        namespace Types {

            class UnsignedInteger : public AbstractType {
                unsigned int value;
            public:
                typedef unsigned int value_type;

                UnsignedInteger();
                UnsignedInteger(const unsigned int& value);
                UnsignedInteger(const UnsignedInteger& rhs);

                virtual unsigned int getValue() const;

                virtual UnsignedInteger& operator=(const UnsignedInteger& rhs);
                virtual UnsignedInteger& operator=(const unsigned int& rhs);
            };

            class SignedInteger : public AbstractType {
                signed int value;
            public:
                typedef signed int value_type;

                SignedInteger();
                SignedInteger(const signed int& value);
                SignedInteger(const SignedInteger& rhs);

                virtual signed int getValue() const;

                virtual SignedInteger& operator=(const SignedInteger& rhs);
                virtual SignedInteger& operator=(const signed int& rhs);
            };

            typedef SignedInteger Integer;

        }

        namespace Threading {

            template <>
            class MonitorTrait<Types::UnsignedInteger> {
            public:
                typedef TypeMonitor<Types::UnsignedInteger> value_type;
            };

            template <>
            class MonitorTrait<Types::SignedInteger> {
            public:
                typedef TypeMonitor< Types::SignedInteger> value_type;
            };

        }

    }
}

#endif

