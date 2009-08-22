#include <Core/Object.hpp>
#include <Core/Types/CompositeLexicalType.hpp>
#include <Core/Reference.hpp>
#include <Core/Message.hpp>
#include <Core/RTTI.hpp>
#include <Core/AbstractFunctor.hpp>
#include <Core/AbstractClass.hpp>


#include <string>
#include <sstream>

#ifdef DEBUG
#include <iostream>
#endif

namespace Sakura {
    namespace Core {


        Object::Object() : functors(0) {
        }

        Object::~Object() {
            if(this->functors)
                delete this->functors;    
        }

        //TODO: remove me when ClassFactory works
        std::string Object::getTypeID() const {
            return demangle(typeid(*this).name());
        }
/*
        AbstractClass* Object::getClass() {
            return static_cast<AbstractClass*>(0); //TODO: implement me
        }
*/
        Reference<Object> Object::sendMessage(Reference<Message> msg) {
            if(!this->functors)
                return static_cast<Object*>(0);
            AbstractFunctor* func = &((*this->functors)[msg->functorName()->getValue()]);
            this->forwardMessage(msg);
            if(!func) {
                return static_cast<Object*>(0);
            }
            return (*func)(this,msg->arguments());
        }

        Reference<Object> Object::sendMessage(Object* recv, Reference<Message> msg) {
            if (Sakura::Core::gc->containsObject(recv)) {
#ifdef DEBUG
                std::cout << "OB: Object at address " << static_cast<void*>(recv) << " exists" << std::endl;
#endif
                return recv->sendMessage(msg);
            }
            return NULL;
        }

         void Object::attachFunctor(Reference<AbstractFunctor> func, Reference<Types::String> name) {
            if(!this->functors)
                this->functors = new std::map< std::string, Reference<AbstractFunctor> >();
            (*this->functors)[name->getValue()] = func;
        }

         void Object::attachFunctor(Reference<AbstractFunctor> func) {
            if(!this->functors)
                this->functors = new std::map< std::string, Reference<AbstractFunctor> >();
            (*this->functors)[demangle(typeid(*func).name())] = func;
        }
       
        void Object::detachFunctor(Reference<Types::String> name) {
            if(!this->functors)
                return;
            this->functors->erase(name->getValue());
            if(this->functors->size() == 0) {
                delete this->functors;
                this->functors = 0;
            }
        }

        bool Object::respondsToMessage(Reference<Types::String> message) {
            if(!this->functors)
                return false;
            return &((*this->functors)[message->getValue()]);
        }

        void Object::forwardMessage(Reference<Message> msg) {} //HOOK

        void* Object::operator new(size_t size_) {
            void* p = malloc(size_);
            static_cast<Object*>(p)->size = size_;
            return p;
        }

        size_t Object::getSize() const {
            return this->size;
        }

    }
}

