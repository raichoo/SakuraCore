#include <Core/Object>
#include <Core/Reference>

#ifndef _ABSTRACTFUNCTOR_HPP
#define	_ABSTRACTFUNCTOR_HPP

namespace Sakura {
    namespace Core {

        class AbstractFunctor : public Object {
        public:
            AbstractFunctor();
            
            virtual Reference<Object> operator()(Reference<Object> self, Reference<Object> arg) = 0;
        };

    }
}

#endif	/* _ABSTRACTFUNCTOR_HPP */

