#include <Core/Object>

#ifndef _APPLICATION_HPP
#define _APPLICATION_HPP

namespace Sakura {
    namespace Core {

        class Application : public Object {
        public:
            Application(int argc, const char** argv);
            Application();

            ~Application();
        };
    }
}

#endif
