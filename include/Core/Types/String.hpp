#include <Core/Types/AbstractType.hpp>

#include <string>

#ifndef _STRING_HPP
#define _STRING_HPP

namespace Sakura {
    namespace Core {
        namespace Types {

            class String : public AbstractType {
                std::string value;
            public:
                typedef const char* value_type;
                
                String();
                String(const char* value);
                String(const String& rhs);

                const char* getValue() const;

                String& operator=(const char* value);
                String& operator=(const String& rhs);
            };

        }
    }
}

#endif

