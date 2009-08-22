/* 
 * File:   If.tcc
 * Author: raichoo
 *
 * Created on March 22, 2009, 6:40 PM
 */

#ifndef _IF_TCC
#define	_IF_TCC

namespace Sakura {
    namespace Meta {

        template <bool If, typename Then, typename Else>
        class IfThenElse;

        template <typename Then, typename Else>
        class IfThenElse<true, Then, Else> {
        public:
            typedef Then value;
        };

        template <typename Then, typename Else>
        class IfThenElse<false, Then, Else> {
        public:
            typedef Else value;
        };
    }
}

#endif	/* _IF_TCC */

