#include <Core/Process.hpp>

namespace Sakura {
    namespace Core {

        Process::Process() {
            this->pid = ::getpid();
            this->ppid = ::getppid();
            this->uid = ::getuid();
            this->euid = ::geteuid();
            this->gid = ::getgid();
            this->egid = ::geteuid();
            this->hostid = ::gethostid();
        }

    }
}

