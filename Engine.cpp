#include "Engine.h"

#include <iostream>

namespace LazyEngine{
    Engine::Engine() = default;

    Engine::~Engine() = default;

    void Engine::addUpdateFunc(void (*func)(int deltaT)) {
        m_update = func;
    }

}
