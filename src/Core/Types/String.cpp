#include <Core/Types/String.hpp>

namespace Sakura {
    namespace Core {
        namespace Types {

            String::String() : value("") {}

            String::String(const char* value_) {
                this->value = value_;
            }

            String::String(const String& rhs) {
                this->value = rhs.getValue();
            }

            const char* String::getValue() const {
                return this->value.c_str();
            }

            String& String::operator=(const char* value_) {
                this->value = value_;
                return *this;
            }

            String& String::operator=(const String& rhs) {
                this->value = rhs.getValue();
                return *this;
            }

        }
    }
}

