#ifndef LAZYENGINE_LIBRARY_H
#define LAZYENGINE_LIBRARY_H
#include <vector>

#include "property/property.h"

namespace LazyEngine {
    class Entity {
        public:
            void start();
            void update(int dettaT);
            std::vector<property::Property> properties;
    };

    class Engine {
        public:
        Engine();
        ~Engine();

        void addUpdateFunc(void (*func)(int deltaT));



        private:
        void (*m_update)(int deltaT){};

    };

}



#endif //LAZYENGINE_LIBRARY_H