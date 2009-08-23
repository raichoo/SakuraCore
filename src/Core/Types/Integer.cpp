#include <Core/Types/String.hpp>
#include <Core/Types/Integer.hpp>

namespace Sakura {
    namespace Core {
        namespace Types {

            UnsignedInteger::UnsignedInteger() : value(0) {}

            UnsignedInteger::UnsignedInteger(const unsigned int& value_) : value(value_) {}

            UnsignedInteger::UnsignedInteger(const UnsignedInteger& rhs) : value(rhs.getValue()) {}

            UnsignedInteger& UnsignedInteger::operator=(const unsigned int& rhs) {
                this->value = rhs;
                return *this;
            }

            UnsignedInteger& UnsignedInteger::operator=(const UnsignedInteger& rhs) {
                this->value = rhs.getValue();
                return *this;
            }

            unsigned int UnsignedInteger::getValue() const {
                return this->value;
            }

            SignedInteger::SignedInteger() : value(0) {}

            SignedInteger::SignedInteger(const signed int& value_) : value(value_) {}

            SignedInteger::SignedInteger(const SignedInteger& rhs) : value(rhs.getValue()) {}

            SignedInteger& SignedInteger::operator=(const signed int& rhs) {
                this->value = rhs;
                return *this;
            }

            SignedInteger& SignedInteger::operator=(const SignedInteger& rhs) {
                this->value = rhs.getValue();
                return *this;
            }

            signed int SignedInteger::getValue() const {
                return this->value;
            }

        }
    }
}

