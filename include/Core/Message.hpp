#include <Core/Object>
#include <Core/Reference>
#include <Core/Types/String>

#ifndef _MESSAGE_HPP
#define _MESSAGE_HPP

namespace Sakura {
    namespace Core {

        class Message : public Object {
            Reference<Types::String> functor;
            Reference<Object> args;
        public:
            Message(Reference<Types::String> functor);
            Message(Reference<Types::String> functor, Reference<Object> args);
            Reference<Types::String> functorName() const;
            Reference<Object> arguments();
        };

    }
}

#endif

