#include <Core/RTTI.hpp>

#ifndef _CLASS_TCC
#define	_CLASS_TCC

namespace Sakura {
    namespace Core {

        template <typename T>
        std::string Class<T>::getName() {
            return demangle(typeid(T).name());
        }

        template <typename T>
        Object* Class<T>::newInstance() const {
            return new T();
        }

        template <typename T>
        Class<T>::Class() : AbstractClass(demangle(typeid(T).name())) { }
    }
}

#endif	/* _CLASS_TCC */

