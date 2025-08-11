//
// Created by jro03 on 2025/08/11.
//
#include "property.h"

namespace property {
    Property::Property(LazyEngine::Module *parent) {
        m_parent = parent;
    }

    Property::Property() {
        m_parent = nullptr;
    }

    void Property::start() {
    }

    void Property::update(int deltaT) {
    }

    void Property::destroy() {
    }

    void Property::setParent(LazyEngine::Module *parent) {
        m_parent = parent;
    }
}
