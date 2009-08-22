#include <Core/RTTI.hpp>

namespace Sakura {
    namespace Core {

#ifdef __GNUC__
        std::string demangle(const char* name) {
            char buf[1024];
            size_t size = 1024;
            int status;
            char* res;
            res = ::abi::__cxa_demangle(name,
                    buf,
                    &size,
                    &status);
            return res;
        }
#else
        std::string demangle(const char* name) {
            return name;
        }
#endif

    }
}
