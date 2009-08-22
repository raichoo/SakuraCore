#include <set>
#include <map>

#ifndef _GARBAGECOLLECTOR_HPP
#define _GARBAGECOLLECTOR_HPP

namespace Sakura {
    namespace Core {

#ifndef _OBJECT_HPP
        class Object;
#endif

        class GarbageCollector {

            std::map< Object*, std::set<void*> > regions;

        public:
            GarbageCollector();

            ~GarbageCollector();

            bool regionsOverlap(Object* obj, void* ref);
            void registerRegion(Object* obj, void* ref);
            void unregisterRegion(Object* obj, void* ref);
            bool containsObject(Object* add);
        };

        extern GarbageCollector* gc;

    }
}

#endif

