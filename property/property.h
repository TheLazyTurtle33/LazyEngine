#ifndef PROPERTY_H
#define PROPERTY_H

#include "../Module.h"

namespace LazyEngine {
    class Module;
}

namespace property {

    // Polymorphic base for all properties/components
    class Property {
    public:
        explicit Property(LazyEngine::Module *parent);
        Property();
        ~Property() = default;
        void start();
        void update(int deltaT);
        void destroy();
        void setParent(LazyEngine::Module* parent);

    protected:
        LazyEngine::Module* m_parent = nullptr;
    };

} // namespace property

#endif // PROPERTY_H