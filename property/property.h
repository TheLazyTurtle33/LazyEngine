#ifndef PROPERTY_H
#define PROPERTY_H

namespace property {

    // Polymorphic base for all properties/components
    class Property {
    public:
        virtual ~Property() = default;
    };

} // namespace property

#endif // PROPERTY_H