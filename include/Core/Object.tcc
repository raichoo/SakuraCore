#include <Core/AbstractClass.hpp>
#include <Core/RTTI.hpp>

#ifdef DEBUG
#include <iostream>
#endif

#ifndef _OBJECT_TCC
#define _OBJECT_TCC

namespace Sakura {
    namespace Core {

        template <typename T>
        Reference<T> Object::as() {
            if(dynamic_cast<T*>(this))
                return dynamic_cast<T*>(this);
             else
                 return new T(); //TODO: throw exception
        }   

        template <typename T>
        bool Object::isInstanceOf() const {
#ifdef DEBUG
            std::cout << demangle(typeid(T).name()) << std::endl;
#endif
            if (this->getTypeID() == demangle(typeid(T).name())) {
#ifdef DEBUG
                std::cout << "true:  " << this->getTypeID() << " " << demangle(typeid(T).name()) << std::endl;
#endif
                return true;
            } else {
#ifdef DEBUG
                std::cout << "false: " << this->getTypeID() << " " << demangle(typeid(T).name()) << std::endl;
#endif
                return false;
            }
        }

        template <typename T>
        bool Object::inheritsFrom() const {
            return typeid(*this).before(typeid(T));
        }

    }
}

#endif

