/* 
 * File:   Type.hpp
 * Author: raichoo
 *
 * Created on March 22, 2009, 12:22 PM
 */

#ifndef _FLOATINGPOINTTYPE_HPP
#define	_FLOATINGPOINTTYPE_HPP

#include <Core/Types/NumericalType.hpp>

namespace Sakura {
    namespace Core {
        namespace Types {

            template <typename T>
            class FloatingpointType : public NumericalType {
            protected:
                T value;
            public:
                typedef T value_type;

                FloatingpointType();
                FloatingpointType(const T& value);
                FloatingpointType(const FloatingpointType<T>& rhs);

                ~FloatingpointType();

                T getValue() const;

                FloatingpointType<T>& operator=(const T& rhs);
                FloatingpointType<T>& operator=(const FloatingpointType<T>& rhs);
            };
        }
    }
}

#include <Core/Types/FloatingpointType.tcc>
#include <Core/Types/TypeOperations.hpp>

#endif	/* _FLOATINGPOINTTYPE_HPP */

