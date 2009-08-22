#include <iostream>
#include <string>
#include <map>

#include <Core/Object.hpp>
#include <Core/AbstractFunctor.hpp>
#include <Core/Reference.hpp>
#include <Core/Factories/AbstractFactory.hpp>
#include <Core/Factories/Factory.hpp>

using Sakura::Core::Reference;

class Type : public Sakura::Core::Object {
    void *val;
    std::string type;
public:
    Type(int val_) : val(new int(val_)), type("int") {
        std::cout << "Creating int\n";    
    }

    Type(long val_) : val(new long(val_)), type("long") {
        std::cout << "Creating long\n";    
    }

    Type(char val_) : val(new char(val_)), type("char") {
        std::cout << "Creating char\n";    
    }

    Type(float val_) : val(new float(val_)), type("float") {
        std::cout << "Creating float\n";    
    }

    Type(double val_) : val(new double(val_)), type("double") {
        std::cout << "Creating double\n";    
    }

    operator int() {
        if (this->type == "int")
            return *static_cast<int*>(val);
    }

    operator float() {
        if (this->type == "float")
            return *static_cast<float*>(val);
    }

    operator double() {
        if (this->type == "double")
            return *static_cast<double*>(val);
    }

    std::string getType() {
        return this->type;
    }
};

class SimpleFactory : public Sakura::Core::Factories::Factory<> {
    public:
        SimpleFactory() {
            this->registerClass(new Sakura::Core::Class<Object>);
        }   
};


int main() {
    Reference<SimpleFactory> sf = new SimpleFactory();
    Reference<Sakura::Core::Object> value = sf->produce("Sakura::Core::Object");
    Reference<Sakura::Core::Object> test = value;
    return 0;
}
