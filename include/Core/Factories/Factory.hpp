#include <Core/Object>
#include <Core/Reference>
#include <Core/AbstractClass.hpp>
#include <Core/Factories/AbstractFactory.hpp>

#include <map>
#include <string>

#ifndef _FACTORY_HPP
#define	_FACTORY_HPP

namespace Sakura {
    namespace Core {
        namespace Factories {

            template <typename I = std::string, typename T = Object>
            class Factory : public AbstractFactory {
                std::map<I, Reference<AbstractClass> > product_line;
            public:
                T* produce(I name);
                void registerClass(Reference<AbstractClass> cls);
            };

        }
    }
}

#include <Core/Factories/Factory.tcc>

#endif	/* _FACTORY_HPP */

