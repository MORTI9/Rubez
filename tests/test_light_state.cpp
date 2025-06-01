#include <gtest/gtest.h>
#include "../src/state_pattern/Light.h"
#include "../src/state_pattern/ConcreteLightStates.h"

using namespace StateMachine;

TEST(ILightStateTest, EnterMethodCalled) {
    struct TestLight : public Light {};

    class TestState : public ILightState {
    public:
        void enter(Light* light) override { called = true; }
        void toggle(Light* light) override {}
        void exit(Light* light) override {}

        bool called = false;
    };

    TestLight light;
    TestState testState;

    testState.enter(&light);
    EXPECT_TRUE(testState.called);
}


TEST(ILightStateTest, ExitMethodCalled) {
    struct TestLight : public Light {};

    class TestState : public ILightState {
    public:
        void enter(Light* light) override {}
        void toggle(Light* light) override {}
        void exit(Light* light) override { called = true; }

        bool called = false;
    };

    TestLight light;
    TestState testState;

    testState.exit(&light);
    EXPECT_TRUE(testState.called);
}
