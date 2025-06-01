#include "LightState.h"
#include <iostream>

namespace StateMachine
{
    // Реализация методов интерфейса ILightState
    void ILightState::enter(Light* light)
    {
        // Можно оставить пустым или добавить отладочную печать
        std::cout << "Entering state" << std::endl;
    }

    void ILightState::toggle(Light* light)
    {
        // По умолчанию: переход к следующему состоянию
        std::cout << "Toggling state" << std::endl;
    }

    void ILightState::exit(Light* light)
    {
        std::cout << "Exiting state" << std::endl;
    }
}
