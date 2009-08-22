#include <Core/Object.hpp>
#include <Core/GarbageCollector.hpp>

#ifdef DEBUG
#include <iostream>
#endif

namespace Sakura {
    namespace Core {

        GarbageCollector::GarbageCollector() {
#ifdef DEBUG
            std::cout << "GC: Setting up GC!" << std::endl;
#endif
        }

        bool GarbageCollector::containsObject(Object* obj) {
            return (this->regions.find(obj) != this->regions.end());
        }

        void GarbageCollector::registerRegion(Object* obj, void* ref) {
            if (obj == 0)
                return;
            this->regions[obj].insert(ref);
#ifdef DEBUG
            std::cout << "GC: register " << obj->getTypeID() 
                << "(" << obj << ") with size " 
                << obj->getSize() << " at " << ref  
                << " to count " << this->regions[obj].size() << std::endl;
#endif
        }

        void GarbageCollector::unregisterRegion(Object* obj, void* ref) {
            if (obj == 0)
                return;
#ifdef DEBUG
            std::cout << "GC: unregister " << obj->getTypeID()
                << "(" << obj << ") with size " 
                << obj->getSize() << " at " << ref  
                << " to count " << this->regions[obj].size() - 1 << std::endl;
#endif
            this->regions[obj].erase(ref);
            if (this->regions[obj].size() == 0) {
#ifdef DEBUG
                std::cout << "GC: Deleting " << obj->getTypeID()
                    << "(" << obj << ")" << std::endl;
#endif
                delete obj;
                this->regions.erase(obj);
            }
        }

        bool regionsContainsReference(Object* obj, void* ref) {
            int diff = reinterpret_cast<Object*>(ref) - obj;
            if (diff < 0)
                return false;
            if (diff < obj->getSize())
                return true;
            else
                return false;
        }

        GarbageCollector::~GarbageCollector() {
#ifdef DEBUG
            std::cout << "GC: Shutting down GC!" << std::endl;
#endif
        }

        GarbageCollector* gc = 0;

    }
}

