#ifndef LAZYENGINE_LIBRARY_H
#define LAZYENGINE_LIBRARY_H
#include <functional>


namespace LazyEngine {
    class LazyEngine {
        public:
        LazyEngine();
        ~LazyEngine();

        void addUpdateFunc(void (*func)(int deltaT));



        private:
        void (*m_update)(int deltaT){};
    };
}



#endif //LAZYENGINE_LIBRARY_H