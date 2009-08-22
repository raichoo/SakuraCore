#include <Core/Object>
#include <Core/AbstractClass>

#include <string>

#ifndef _CLASS_HPP
#define	_CLASS_HPP

namespace Sakura {
    namespace Core {

        template <typename T>
        class Class : public AbstractClass {
        public:
            Class();

            Object* newInstance() const;

            static std::string getName();
        };
        
    }
}

#include <Core/Class.tcc>

#endif	/* _CLASS_HPP */

