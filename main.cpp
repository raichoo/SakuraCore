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
        std::cout << self->as< Types::Integer<signed> >()->getValue() << std::endl;
        return 0;
    }
};

class MyApplication : public Application {
    Reference< Types::Integer<signed> > i;
public:
    MyApplication(int argc, const char** argv) { 
        Reference<Message> m;
        i = new Types::Integer<signed>(666);
        std::cout << i->getValue() << std::endl;
        i->attachFunctor(new TestFunctor< Types::Integer<signed> >, "TestFunctor");
        std::cout << "Calling..." << std::endl;
        i->sendMessage(new Message("TestFunctor"));
        std::cout << "End..." << std::endl;
    }
};

int main(int argc, const char **argv) {
    MyApplication app(argc, argv);
    return 0;
}

