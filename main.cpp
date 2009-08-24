#include <Core/Types/Integer>
#include <Core/Object>
#include <Core/Application>
#include <Core/Types/String>
#include <Core/Message>
#include <Core/Reference>

#include <iostream>
#include <string>

using namespace Sakura::Core;

template <typename T>
class TestFunctor : public AbstractFunctor {
public:
    Reference<Object> operator()(Reference<Object> self, Reference<Object> args = 0) {
        std::cout << self->as<T>()->getValue() << std::endl;
        std::cout << "Called" << std::endl;
    }
};

class MyApplication : public Application {
    Reference< Types::String >            s;
    Reference< Types::Integer<signed> >   i;
    Reference< Types::Integer<unsigned> > u;
public:
    MyApplication(int argc, const char** argv) { 
        i = new synchronized< Types::Integer<signed> >(666);
        u = new Types::Integer<unsigned>(666);
        *i = 111 + *i;
        s = new Types::String("This is a test");
        i->attachFunctor(new TestFunctor< Types::Integer<signed> >,   "TestFunctor");
        u->attachFunctor(new TestFunctor< Types::Integer<unsigned> >, "TestFunctor");
        s->attachFunctor(new TestFunctor< Types::String >,            "TestFunctor");
        i->sendMessage(new Message("TestFunctor"));
        u->sendMessage(new Message("TestFunctor"));
        s->sendMessage(new Message("TestFunctor"));
    }
};

int main(int argc, const char **argv) {
    MyApplication app(argc, argv);
    return 0;
}

