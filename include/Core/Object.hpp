#include <Core/AbstractFunctor>
#include <Core/Reference>
#include <Core/Message>
#include <Core/Types/String>

#include <map>
#include <string>

#ifndef _OBJECT_HPP
#define	_OBJECT_HPP

namespace Sakura {
    namespace Core {

        struct empty;

        class Object {
            size_t size;
            std::map< std::string, Reference<AbstractFunctor> >* functors;
        public:
            typedef empty value_type;

            Object();

            virtual ~Object();
            
            std::string getTypeID() const; 
            virtual Reference<Object> sendMessage(Reference<Message> msg);
            static Reference<Object> sendMessage(Object* recv, Reference<Message> msg);
            virtual void attachFunctor(Reference<AbstractFunctor> func);
            virtual void attachFunctor(Reference<AbstractFunctor> func, Types::String name);
            virtual void detachFunctor(Types::String name);
            bool respondsToMessage(Types::String message); //TODO: make const
            size_t getSize() const;

            template <typename T>
            Reference<T> as();
            template <typename T>
            bool isInstanceOf() const;
            template <typename T>
            bool inheritsFrom() const;

            void* operator new(size_t size);

            virtual void forwardMessage(Reference<Message> msg);
            //virtual AbstractClass* getClass(); //TODO: Implement me
        };

    }
}

#include <Core/Object.tcc>

#endif	

