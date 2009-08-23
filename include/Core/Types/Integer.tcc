#ifndef _INTEGER_TCC
#define _INTEGER_TCC

namespace Sakura {
    namespace Core {
        namespace Types {

            Integer<unsigned>::Integer() : value(0) {}

            Integer<unsigned>::Integer(const unsigned int& value_) : value(value_) {}

            Integer<unsigned>::Integer(const Integer<unsigned>& rhs) : value(rhs.getValue()) {}

            Integer<unsigned>& Integer<unsigned>::operator=(const unsigned int& rhs) {
                this->value = rhs;
                return *this;
            }

            Integer<unsigned>& Integer<unsigned>::operator=(const Integer<unsigned>& rhs) {
                this->value = rhs.getValue();
                return *this;
            }

            unsigned int Integer<unsigned>::getValue() const {
                return this->value;
            }

            Integer<signed>::Integer() : value(0) {}

            Integer<signed>::Integer(const signed int& value_) : value(value_) {}

            Integer<signed>::Integer(const Integer<signed>& rhs) : value(rhs.getValue()) {}

            Integer<signed>& Integer<signed>::operator=(const signed int& rhs) {
                this->value = rhs;
                return *this;
            }

            Integer<signed>& Integer<signed>::operator=(const Integer<signed>& rhs) {
                this->value = rhs.getValue();
                return *this;
            }

            signed int Integer<signed>::getValue() const {
                return this->value;
            }

        }
    }
}

#endif

