#include <Core/Object>

#include <string>

#ifndef _ABSTRACTCLASS_HPP
#define	_ABSTRACTCLASS_HPP

namespace Sakura {
    namespace Core {


        class AbstractClass : public Object {
        protected:
            std::string name;

            AbstractClass(std::string name);
        public:
            std::string getName() const;

            virtual Object* newInstance() const = 0;
        };

    }
}

#endif	/* _ABSTRACTCLASS_HPP */

