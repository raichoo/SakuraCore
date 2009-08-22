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
    Reference<Types::String>  s;
    Reference<Types::Integer> i;
public:
    MyApplication(int argc, const char** argv) { 
        i = new synchronized<Types::Integer>(666);
        s = new Types::String("This is a test");
        i->attachFunctor(new TestFunctor<Types::Integer>, "TestFunctor");
        s->attachFunctor(new TestFunctor<Types::String>, "TestFunctor");
        i->sendMessage(new Message("TestFunctor"));
        s->sendMessage(new Message("TestFunctor"));
    }
};

int main(int argc, const char **argv) {
    MyApplication app(argc, argv);
    return 0;
}

