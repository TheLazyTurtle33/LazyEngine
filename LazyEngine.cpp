#include "LazyEngine.h"

#include <iostream>

namespace LazyEngine{
    LazyEngine::LazyEngine() = default;

    LazyEngine::~LazyEngine() = default;

    void LazyEngine::addUpdateFunc(void (*func)(int deltaT)) {
        m_update = func;
    }
}
