#include <Core/Reference>
#include <Core/Types/AbstractType.hpp>

#ifndef _NUMERICALTYPE_HPP
#define	_NUMERICALTYPE_HPP

namespace Sakura {
    namespace Core {
        namespace Types {

            class NumericalType : public AbstractType {
            public:
                NumericalType(const NumericalType& rhs);
                NumericalType();

                ~NumericalType();
            };
        }
    }
}

#endif	/* _NUMERICALTYPE_HPP */

