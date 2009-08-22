/* 
 * File:   NullpointerException.hpp
 * Author: raichoo
 *
 * Created on May 23, 2009, 9:47 PM
 */

#ifndef _NULLPOINTEREXCEPTION_HPP
#define	_NULLPOINTEREXCEPTION_HPP

#include <Core/Exceptions/ReferenceException.hpp>

namespace Sakura {
    namespace Core {
        namespace Exceptions {

            class NullpointerException : public ReferenceException {};

        }
    }
}

#endif	/* _NULLPOINTEREXCEPTION_HPP */

