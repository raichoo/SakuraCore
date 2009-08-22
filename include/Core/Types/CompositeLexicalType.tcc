#ifndef _COMPOSITELEXICALTYPE_TCC 
#define _COMPOSITELEXICALTYPE_TCC	

#include <Core/RTTI.hpp>

namespace Sakura {
    namespace Core {
        namespace Types {

            template <typename T>
            CompositeLexicalType<T>::CompositeLexicalType(const T& value_) : value(value_) {}

            template <typename T>
            CompositeLexicalType<T>::CompositeLexicalType(const CompositeLexicalType<T>& rhs) : value(rhs.value) {}

            template <typename T>
            CompositeLexicalType<T>::CompositeLexicalType() : value(T()) {}

            template <typename T>
            CompositeLexicalType<T>::~CompositeLexicalType() {}

            template <typename T>
            CompositeLexicalType<T>& CompositeLexicalType<T>::operator=(const T& rhs) {
                this->value = rhs;
                return *this;
            }

            template <typename T>
            CompositeLexicalType<T>& CompositeLexicalType<T>::operator=(const CompositeLexicalType<T>& rhs) {
                this->value = rhs.value;
                return *this;
            }

            template <typename T>
            T CompositeLexicalType<T>::getValue() const {
                return this->value;
            }

        }
    }
}
#endif	

