#ifndef _FACTORY_TCC
#define	_FACTORY_TCC

namespace Sakura {
    namespace Core {
        namespace Factories {

            template <typename I, typename T>
            T* Factory<I, T>::produce(I name) {
                //Reference<Object> ret_class  = 0;
                Object* ret;
                if (!(this->product_line[name]))
                    return 0;
                ret = this->product_line[name]->newInstance();
                return ret;
            }

            template <typename I, typename T>
            void Factory<I, T>::registerClass(Reference<AbstractClass> cls) {
                this->product_line[cls->getName()] = cls;
            }

        }
    }
}

#endif	/* _FACTORY_TCC */

