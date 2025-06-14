// ===========================================================================
// LightSwitchMain.cpp // FiniteStateMachine_LightSwitch
// ===========================================================================

#include "../src/state_pattern/Light.h"
#include "../src/state_pattern/ConcreteLightStates.h"

void test_lightSwitch_StateMachine()
{
	using namespace StateMachine;

	Light light{};
	//light.setState(LowIntensity::getInstance());
	//light.setState(HighIntensity::getInstance());
	light.toggle();
	light.toggle();
	light.toggle();
	light.toggle();
	light.toggle();
	light.toggle();
}


// ===========================================================================
// End-of-File
// ===========================================================================
