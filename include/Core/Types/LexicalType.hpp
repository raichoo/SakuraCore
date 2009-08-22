#ifndef _LEXICALTYPE_HPP
#define	_LEXICALTYPE_HPP


#include <Core/Types/AbstractType.hpp>
#include <Core/Reference>

namespace Sakura {
    namespace Core {
        namespace Types {

            class LexicalType : public AbstractType {
            public:
                LexicalType(const LexicalType& rhs);
                LexicalType();

                ~LexicalType();
            };
        }
    }
}

#endif	

