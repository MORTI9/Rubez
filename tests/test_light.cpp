#include <gtest/gtest.h>
#include "../src/state_pattern/Light.h"
#include "../src/state_pattern/ConcreteLightStates.h"
using namespace StateMachine;


TEST(LightTest, InitialStateIsOff) {
    Light light;
    EXPECT_EQ(light.getCurrentState(), &LightOff::getInstance());
}


TEST(LightTest, Toggle_OffToLow) {
    Light light;
    light.toggle();
    EXPECT_EQ(light.getCurrentState(), &LowIntensity::getInstance());
}


TEST(LightTest, Toggle_LowToMedium) {
    Light light;
    light.toggle(); // Off -> Low
    light.toggle(); // Low -> Medium
    EXPECT_EQ(light.getCurrentState(), &MediumIntensity::getInstance());
}


TEST(LightTest, Toggle_MediumToHigh) {
    Light light;
    light.toggle(); 
    light.toggle(); 
    light.toggle(); 
    EXPECT_EQ(light.getCurrentState(), &HighIntensity::getInstance());
}


TEST(LightTest, Toggle_HighToOff) {
    Light light;
    light.toggle(); 
    light.toggle(); 
    light.toggle(); 
    light.toggle(); 
    EXPECT_EQ(light.getCurrentState(), &LightOff::getInstance());
}


TEST(LightTest, SetStateCallsEnterAndExit) {
    Light light;

    class TestState1 : public ILightState {
    public:
        void enter(Light* light) override { enter_called = true; }
        void exit(Light* light) override { exit_called = true; }
        void toggle(Light* light) override {}

        bool enter_called = false;
        bool exit_called = false;
    };

    class TestState2 : public ILightState {
    public:
        void enter(Light* light) override { enter_called = true; }
        void exit(Light* light) override {}
        void toggle(Light* light) override {}

        bool enter_called = false;
    };

    TestState1 state1;
    TestState2 state2;

    light.setState(state1); 
    light.setState(state2); 
    EXPECT_TRUE(state1.exit_called);
    EXPECT_TRUE(state2.enter_called);
}
