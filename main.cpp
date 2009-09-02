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
    Reference<Object> operator()(Reference<Object> self, Reference<Object> args) {
        std::cout << self->as<T>()->getValue() << std::endl;
        std::cout << "Called" << std::endl;
    }
};

Reference< Types::Integer<signed> > test(Reference< Types::Integer<signed> > i) {
    std::cout << i->getValue() << std::endl;
    return 666;
}

class MyApplication : public Application {
    Reference< Types::Integer<signed> >   i;
public:
    MyApplication(int argc, const char** argv) { 
        i = 666;
        std::cout << i->getValue() << std::endl;
     //   i->attachFunctor(new TestFunctor< Types::Integer<signed> >,   "TestFunctor");
     //   i->sendMessage(new Message("TestFunctor", 0));
    }
};

int main(int argc, const char **argv) {
    MyApplication app(argc, argv);
    return 0;
}

