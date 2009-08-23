#include <Core/Threading/TypeMonitor>
#include <Core/Threading/MonitorTrait>
#include <Core/Types/AbstractType>

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

                virtual unsigned int getValue() const;

                virtual Integer<unsigned>& operator=(const Integer<unsigned>& rhs);
                virtual Integer<unsigned>& operator=(const unsigned int& rhs);
            };

            template <>
            class Integer<signed> : public AbstractType {
                signed int value;
            public:
                typedef signed int value_type;

                Integer();
                Integer(const signed int& value);
                Integer(const Integer<signed>& rhs);

                virtual signed int getValue() const;

                virtual Integer<signed>& operator=(const Integer<signed>& rhs);
                virtual Integer<signed>& operator=(const signed int& rhs);
            };

        }

        namespace Threading {

            template <>
            class MonitorTrait< Types::Integer<unsigned> > {
            public:
                typedef TypeMonitor< Types::Integer<unsigned> > value_type;
            };

            template <>
            class MonitorTrait< Types::Integer<signed> > {
            public:
                typedef TypeMonitor< Types::Integer<signed> > value_type;
            };

        }

    }
}

#endif

