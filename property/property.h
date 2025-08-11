#ifndef PROPERTY_H
#define PROPERTY_H

#include "transform.h"
#include "rendererable.h"


namespace property {

    // Polymorphic base for all properties/components
    class Property {
    public:
        explicit Property(LazyEngine::Module *parent);
        virtual ~Property() = default;
        virtual void start() = 0;
        virtual void update(int deltaT) = 0;
        virtual void destroy() = 0;

    protected:
        LazyEngine::Module* m_parent = nullptr;
    };

} // namespace property

#endif // PROPERTY_H