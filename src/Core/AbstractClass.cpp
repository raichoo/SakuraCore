#include <Core/AbstractClass.hpp>

namespace Sakura {
    namespace Core {

        AbstractClass::AbstractClass(std::string name_) : name(name_) { }

        std::string AbstractClass::getName() const {
            return std::string(this->name);
        }
    }
}
