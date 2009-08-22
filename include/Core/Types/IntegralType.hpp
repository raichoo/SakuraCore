#include <Core/Types/NumericalType>

#ifndef _INTEGRALTYPE_HPP
#define	_INTEGRALTYPE_HPP

namespace Sakura {
    namespace Core {
        namespace Types {

            template <typename T>
            class IntegralType : public NumericalType {
            protected:
                T value;
            public:
                typedef T value_type;

                IntegralType();
                IntegralType(const T& value);
                IntegralType(const IntegralType<T>& rhs);

                ~IntegralType();

                virtual T getValue() const;

                virtual IntegralType<T>& operator=(const T& rhs);
                virtual IntegralType<T>& operator=(const IntegralType<T>& rhs);
            };

        }
    }
}

#include <Core/Types/IntegralType.tcc>
#include <Core/Types/TypeOperations.hpp>

#endif	/* _INTEGRALTYPE_HPP */

