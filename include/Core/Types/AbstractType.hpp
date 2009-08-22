#include <Core/Object>
#include <Core/Reference>

#ifndef _ABSTRACTTYPE_HPP
#define	_ABSTRACTTYPE_HPP

#include <string>

namespace Sakura {
    namespace Core {
        namespace Types {

            class AbstractType : public Object {
            public:
                AbstractType();
                AbstractType(const AbstractType& rhs);

                ~AbstractType();
            };
        }
    }
}

#endif	/* _ABSTRACTTYPE_HPP */

