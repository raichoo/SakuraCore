#ifndef _REFERENCE_HPP
#define _REFERENCE_HPP

#include <Core/Object>

namespace Sakura {
    namespace Core {

        template <typename T>
        class Reference {
            T* ref;
        public:
            Reference();
            Reference(const T* rhs);
            Reference(const typename T::value_type& rhs);
            Reference(const Reference<T>& rhs);
            Reference(const T& rhs);

            template <typename U>
            Reference(const Reference<U>& rhs);
            
            ~Reference();

            Reference<T>& operator=(const Reference<T>& rhs);
            //Reference<T>& operator=(const typename T::value_type& rhs);

            T* operator->();
            T* operator&() const;
            T& operator*();
            operator T*();

            template <typename U>
            Reference<T>& operator=(const Reference<U>& rhs);
        };

    }
}

#include <Core/Reference.tcc>

#endif

