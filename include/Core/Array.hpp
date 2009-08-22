#include <Core/Object>

#ifndef _ARRAY_HPP
#define _ARRAY_HPP

namespace Sakura {
    namespace Core {

        template <typename T>
        class Array : public Object {
            std::vector<T> vec;
        public:
            Array() {}
            ~Array() {}

            T& operator[](int pos) {
                return vec[pos];
            }

            int getSize() {
                return vec.size();
            }

        }

    }
}

#endif

