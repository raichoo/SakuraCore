#include <Core/Application.hpp>
#include <Core/GarbageCollector.hpp>

namespace Sakura {
    namespace Core {

        Application::Application(int argc, const char** argv) {
            Sakura::Core::gc = new GarbageCollector();
        }

        Application::Application() {
            Sakura::Core::gc = new GarbageCollector();
        }

        Application::~Application() {
            delete Sakura::Core::gc;
        }

    }
}
