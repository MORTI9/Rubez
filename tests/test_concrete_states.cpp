#include <gtest/gtest.h>
#include "../src/state_pattern/Light.h"
#include "../src/state_pattern/ConcreteLightStates.h"

using namespace StateMachine;


TEST(ConcreteLightStatesTest, LightOff_Toggle_ChangesToLow) {
    Light light;
    light.getCurrentState()->toggle(&light);
    EXPECT_EQ(light.getCurrentState(), &LowIntensity::getInstance());
}


TEST(ConcreteLightStatesTest, LowIntensity_Toggle_ChangesToMedium) {
    Light light;
    light.setState(LowIntensity::getInstance());
    light.toggle();
    EXPECT_EQ(light.getCurrentState(), &MediumIntensity::getInstance());
}


TEST(ConcreteLightStatesTest, MediumIntensity_Toggle_ChangesToHigh) {
    Light light;
    light.setState(MediumIntensity::getInstance());
    light.toggle();
    EXPECT_EQ(light.getCurrentState(), &HighIntensity::getInstance());
}


TEST(ConcreteLightStatesTest, HighIntensity_Toggle_ChangesToOff) {
    Light light;
    light.setState(HighIntensity::getInstance());
    light.toggle();
    EXPECT_EQ(light.getCurrentState(), &LightOff::getInstance());
}


TEST(ConcreteLightStatesTest, SingletonGetInstance) {
    EXPECT_EQ(&LightOff::getInstance(), &LightOff::getInstance());
    EXPECT_EQ(&LowIntensity::getInstance(), &LowIntensity::getInstance());
    EXPECT_EQ(&MediumIntensity::getInstance(), &MediumIntensity::getInstance());
    EXPECT_EQ(&HighIntensity::getInstance(), &HighIntensity::getInstance());
}
