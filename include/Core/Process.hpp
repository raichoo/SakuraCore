#include <Core/Object>

#include <sys/types.h>
#include <unistd.h>

#ifndef _PROCESS_HPP
#define _PROCESS_HPP

namespace Sakura {
    namespace Core {

        class Process : public Object {
            pid_t pid;
            pid_t ppid;
            uid_t uid;
            uid_t euid;
            gid_t gid;
            gid_t egid;
            long hostid;

        public:
            Process();
        };

    }
}

#endif

