#include <Core/Object.hpp>
#include <Core/AbstractFunctor.hpp>
#include <Core/Types/String.hpp>
#include <Core/Types/String.hpp>
#include <Core/Reference.hpp>
#include <Core/Message.hpp>

#include <iostream>

namespace Sakura {
    namespace Core {

        Message::Message(Types::String functor_, Reference<Object> args_)
        : functor(functor_), args(args_) {}

        Message::Message(Types::String functor_) 
        : functor(functor_) {}

        Types::String Message::functorName() const {
            return this->functor;
        }

        Reference<Object> Message::arguments() {
            return &(this->args);
        }
    }
}

