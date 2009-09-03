#include <Core/Object>
#include <Core/Reference>
#include <Core/Types/String>

#ifndef _MESSAGE_HPP
#define _MESSAGE_HPP

namespace Sakura {
    namespace Core {

        class Message : public Object {
            Types::String functor;
            Reference<Object> args;
        public:
            Message(Types::String functor);
            Message(Types::String functor, Reference<Object> args);
            Types::String functorName() const;
            Reference<Object> arguments();
        };

    }
}

#endif

