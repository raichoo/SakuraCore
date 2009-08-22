#include <Core/Types/AbstractType.hpp>

#ifndef _COMPOSITELEXICALTYPE_HPP
#define _COMPOSITELEXICALTYPE_HPP	

namespace Sakura {
    namespace Core {
        namespace Types {

            template <typename T>
            class CompositeLexicalType : public AbstractType {
            protected:
                T value;
            public:
                typedef T value_type;

                CompositeLexicalType();
                CompositeLexicalType(const T& value);
                CompositeLexicalType(const CompositeLexicalType<T>& rhs);

                ~CompositeLexicalType();

                T getValue() const;

                CompositeLexicalType<T>& operator=(const T& rhs);
                CompositeLexicalType<T>& operator=(const CompositeLexicalType<T>& rhs);
            };

        }
    }
}

#include <Core/Types/CompositeLexicalType.tcc>
#include <Core/Types/TypeOperations.hpp>

#endif	

