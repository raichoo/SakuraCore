/* 
 * File:   RTTI.hpp
 * Author: raichoo
 *
 * Created on May 31, 2009, 2:25 PM
 */

#ifndef _RTTI_HPP
#define	_RTTI_HPP

#include <typeinfo>
#include <string>

#ifdef __GNUC__
#include <cxxabi.h>
#endif

namespace Sakura {
    namespace Core {

        std::string demangle(const char* name);

    }
}

#endif	/* _RTTI_HPP */

