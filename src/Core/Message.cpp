#include <Core/Object.hpp>
#include <Core/AbstractFunctor.hpp>
#include <Core/Types/String.hpp>
#include <Core/Types/String.hpp>
#include <Core/Reference.hpp>
#include <Core/Message.hpp>

namespace Sakura {
    namespace Core {

        Message::Message(Reference<Types::String> functor_, Reference<Object> args_)
        : functor(functor_), args(args_) {}

        Message::Message(Reference<Types::String> functor_) 
        : functor(functor_), args(static_cast<Object*>(0)) {}

        Reference<Sakura::Core::Types::String> Message::functorName() const {
            return this->functor;
        }

        Reference<Object> Message::arguments() {
            return &(this->args);
        }
    }
}

