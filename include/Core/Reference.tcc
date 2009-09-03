#ifndef _REFERENCE_TCC
#define	_REFERENCE_TCC

#include <Core/GarbageCollector.hpp>
#include <Core/Exceptions/NullpointerException.hpp>

#ifdef DEBUG
#include <iostream>
#include <Core/RTTI.hpp>
#endif

namespace Sakura {
    namespace Core {

        template <typename T>
        Reference<T>::Reference(const Reference<T>& rhs) : ref(0) {
#ifdef DEBUG
            std::cout << "RF: Creating(Reference<T>&) Reference<" 
                << demangle(typeid(T).name())  
                << "> for " 
                << &rhs << " at " << this << std::endl;
#endif
            *this = rhs;
        }

        template <typename T>
        template <typename U>
        Reference<T>::Reference(const Reference<U>& rhs) : ref(0) {
#ifdef DEBUG
            std::cout << "RF: Creating(Reference<U>&) Reference<" 
                << demangle(typeid(T).name())  
                << "> for " 
                << &rhs << " at " << this << std::endl;
#endif
            *this = rhs;
        }

        template <typename T>
        Reference<T>::Reference() : ref(0) {
#ifdef DEBUG
            std::cout << "RF: Creating() Reference<"
                << demangle(typeid(T).name()) << "> at " << this << std::endl;    
#endif
        }

        template <typename T>
        Reference<T>::Reference(const T* rhs) {
            //this->ref = dynamic_cast<T*>(const_cast<T*>(rhs));
            this->ref = const_cast<T*>(rhs);
#ifdef DEBUG
            std::cout << "RF: Creating(T*) Reference<" 
                << demangle(typeid(T).name())  
                << "> for " 
                << rhs << " at " << this << std::endl;
#endif
            if (this->ref != 0) {
                Sakura::Core::gc->registerRegion(this->ref,this);
            }
        }

        template <typename T>
        Reference<T>::~Reference() {
#ifdef DEBUG
            std::cout << "RF: Destryoing Reference<"
                << demangle(typeid(T).name()) << "> to " << this->ref
                << " at " << this << std::endl;
#endif
            if(this->ref != 0)
                Sakura::Core::gc->unregisterRegion(this->ref,this);
        }

        template <typename T>
        Reference<T>& Reference<T>::operator=(const Reference<T>& rhs) {
#ifdef DEBUG
            std::cout << "RF: Assigning(T&) Reference<" 
                << demangle(typeid(T).name())  
                << "> to " 
                << &rhs << " at " << this << std::endl;
#endif
            if (this->ref == &rhs)
                return *this;
            Sakura::Core::gc->unregisterRegion(this->ref,this);
            this->ref = &rhs;
            Sakura::Core::gc->registerRegion(this->ref,this);
            return *this;
        }

        template <typename T>
        template <typename U>
        Reference<T>& Reference<T>::operator=(const Reference<U>& rhs) {
#ifdef DEBUG
            std::cout << "RF: Assigning(U&) Reference<" 
                << demangle(typeid(T).name())  
                << "> to " 
                << &rhs << " at " << this << std::endl;
#endif
            if (this->ref == &rhs)
                return *this;
            Sakura::Core::gc->unregisterRegion(this->ref,this);
            if (dynamic_cast<T*>(&rhs)) {
                this->ref = dynamic_cast<T*>(&rhs);
                Sakura::Core::gc->registerRegion(this->ref,this);
            } else {
                this->ref = 0;
            }
            return *this;
        }

        template <typename T>
        T* Reference<T>::operator->() {
            if(this->ref == 0)
                throw new Exceptions::NullpointerException();
            return this->ref;
        }

        template <typename T>
        T* Reference<T>::operator &() const {
            return this->ref;
        }

        template <typename T>
        T& Reference<T>::operator *() {
            if(this->ref == 0)
                throw new Exceptions::NullpointerException();
            return *this->ref;
        }

        template <typename T>
        Reference<T>::operator T*() {
            return this->ref;
        }
    }
}

#endif	/* _REFERENCE_TCC */

